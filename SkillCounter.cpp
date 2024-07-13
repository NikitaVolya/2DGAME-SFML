#include "SkillCounter.h"
#include "GameObject.h"
#include "Engine2D.h"
#include "Projectile.h"

#include "setup.h"

#define GAME_OBJECT_LIST skillOwner.getOwner().getGame()->getGameObjects()


SkillCounter::SkillCounter(GameObject& pOwner, float pDelay, void(*func)(SkillCounter& skillOwner)) : owner(pOwner), timer(0), delay(0), action(func)
{
	delay = static_cast<size_t>(pDelay * FRAME_RATE_F);
}

size_t SkillCounter::update()
{
	if (timer > 0)
		timer -= 1;
	return timer;
}

void SkillCounter::execute()
{
	if (timer == 0)
	{
		action(*this);
		timer = delay;
	}
}

void Dash_function(SkillCounter& skillOwner)
{
	sf::Vector2f direction = skillOwner.getOwner().getDirectionToMouse() * PIXEL_SIZE_F * 50.f;
	skillOwner.getOwner().addImpuls(direction);
}

void GraviBomb_function(SkillCounter& skillOwner)
{
	float strange = PIXEL_SIZE_F * 20.f;
	float radius = PIXEL_SIZE_F * 3.f;
	for (auto it = GAME_OBJECT_LIST.begin(); it; ++it)
	{
		if (*it == &skillOwner.getOwner())
			continue;
		if ((*it)->getDistanceTo(skillOwner.getOwner()) <= radius)
		{
			sf::Vector2f direction = (*it)->getDirectionTo(skillOwner.getOwner()) * strange;
			(*it)->addImpuls(direction);
		}
	}
}

void create_fire_ball(SkillCounter& skillOwner, const sf::Vector2f& direction)
{
	GameObject& entity = skillOwner.getOwner();
	Engine2D& game = *entity.getGame();

	Projectiles::FireBall* tmp = new Projectiles::FireBall(game, &entity, entity.getPositionCenter(), direction, 2);
	sf::Vector2f launchePosition = entity.getPositionCenter() + direction * tmp->getSize().x - tmp->getSize() * .5f;

	tmp->setPosition(launchePosition);

	game.addEntity(tmp);
}

void create_fire_ball(SkillCounter& skillOwner)
{
	create_fire_ball(skillOwner, skillOwner.getOwner().getDirectionToMouse());
}

void Skill::FireBall::execute(const sf::Vector2f& direction)
{
	if (timer == 0)
	{
		create_fire_ball(*this, direction);
		timer = delay;
	}
}
#pragma once


#ifndef SKILL_COUNTER_H
#define SKILL_COUNTER_H

#include "GameObject.h"

class GameObject;

class SkillCounter
{
protected:
	GameObject& owner;

	size_t timer;
	size_t delay;
	void (*action)(SkillCounter& skillOwner);
public:
	SkillCounter(GameObject& pOwner, float pDelay, void (*func)(SkillCounter& skillOwner));

	GameObject& getOwner() { return owner; }

	size_t getCD() const { return timer; }
	size_t getDelay() const { return delay; }

	size_t update();
	void execute();
};

void Dash_function(SkillCounter& skillOwner);

void GraviBomb_function(SkillCounter& skillOwner);

void create_fire_ball(SkillCounter& skillOwner, const sf::Vector2f& direction);

void create_fire_ball(SkillCounter& skillOwner);



namespace Skill
{
	class Dash : public SkillCounter 
	{ public: Dash(GameObject& pOwner, float pDelay) : SkillCounter(pOwner, pDelay, Dash_function) {}; };

	class GraviBomb : public SkillCounter
	{
	public: GraviBomb(GameObject& pOwner, float pDelay) : SkillCounter(pOwner, pDelay, GraviBomb_function) {};
	};

	class FireBall : public SkillCounter
	{
	public: FireBall(GameObject& pOwner, float pDelay) : SkillCounter(pOwner, pDelay, create_fire_ball) {};
		  void execute(const sf::Vector2f& direction);
	};
}



#endif // !SKILL_COUNTER_H
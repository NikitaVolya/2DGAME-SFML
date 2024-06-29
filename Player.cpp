#include "Player.h"
#include "Engine2D.h"
#include "MyFunctions.h"

#define KeyBoardManager game.getKeyBoardManager()

Player::Player(Engine2D& pGame, const sf::Vector2f& pPosition) : Entity(pGame, pPosition)
{
}

void Player::update()
{
	sf::Vector2f direction{ 0, 0 };

	if (KeyBoardManager.getUp())
		direction.y -= 1;
	if (KeyBoardManager.getBottom())
		direction.y += 1;
	if (KeyBoardManager.getLeft())
		direction.x -= 1;
	if (KeyBoardManager.getRight())
		direction.x += 1;

	direction = MyFuncs::normolize(direction) * speed * PIXEL_SIZE_F;
	addImpuls(direction);

	Entity::update();
}

#include "Player.h"

sf::Vector2f Player::getDirectionVector()
{
	sf::Vector2f moveVector(0.f, 0.f);

	if (kbc->getUp())
		moveVector.y -= 1;
	if (kbc->getLeft())
		moveVector.x -= 1;
	if (kbc->getRight())
		moveVector.x += 1;
	if (kbc->getBottom())
		moveVector.y += 1;

	return MyFuncs::normolize(moveVector);
}

Player::Player(KeyBoardManager* pKBC, sf::Vector2f pPosition) : Entity(pPosition)
{
	kbc = pKBC;
	setSpeed(1);

	loadTexture("resources\\sprites\\characters\\skeleton\\skeleton2_v2_1.png");
}

void Player::update(MapManager* mapM)
{
	sf::Vector2f moveVector = getDirectionVector() * speed;

	if (moveVector.x != 0)
		if (moveVector.x < 0)
			flipToLeft();
		else
			flipToRight();

	addMovementImpulse(moveVector);

	Entity::update(mapM);
}

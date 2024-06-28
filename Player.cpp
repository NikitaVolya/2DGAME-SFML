#include "Player.h"

sf::Vector2f Player::getDirectionVector()
{
	sf::Vector2f moveVector(0.f, 0.f);

	if (kbc.getUp())
		moveVector.y -= 1;
	if (kbc.getLeft())
		moveVector.x -= 1;
	if (kbc.getRight())
		moveVector.x += 1;
	if (kbc.getBottom())
		moveVector.y += 1;

	return MyFuncs::normolize(moveVector);
}

sf::Vector2f Player::getVectorToMouse()
{
	sf::Vector2f vectorToMouse = kbc.getMousePositionF() - (getCenterPosition()  - camera.getPosition());
	return MyFuncs::normolize(vectorToMouse);
}

Player::Player(KeyBoardManager& pKBC, Camera& pCamera, sf::Vector2f pPosition) : kbc(pKBC), camera(pCamera), Entity(pPosition), actionCD(0)
{
	setSpeed(1);
}

void Player::events()
{
	if (!actionCD && kbc.getMouseLeft())
	{
		actionCD = FRAME_RATE * 2;
		addMovementImpulse(getVectorToMouse() * 45.f * (float)PIXEL_SIZE);
	}
	if (actionCD) actionCD--;

	sf::Vector2f moveVector = getDirectionVector() * getSpeed();
	addMovementImpulse(moveVector);

	if (movementVector.x != 0)
		if (movementVector.x < 0)
			setRotate(true);
		else
			setRotate(false);
}

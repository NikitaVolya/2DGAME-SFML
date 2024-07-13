#include "Player.h"
#include "Engine2D.h"
#include "MyFunctions.h"

#define KeyBoardManager game.getKeyBoardManager()

Player::Player(Engine2D& pGame, const sf::Vector2f& pPosition) : Entity(pGame, pPosition), skill(*this, 0.5f)
{
}

void Player::update()
{

	sf::Vector2f impulsVector{ 0, 0 };

	if (KeyBoardManager.getUp())
		impulsVector.y -= 1;
	if (KeyBoardManager.getBottom())
		impulsVector.y += 1;
	if (KeyBoardManager.getLeft())
		impulsVector.x -= 1;
	if (KeyBoardManager.getRight())
		impulsVector.x += 1;

	impulsVector = MyFuncs::normolize(impulsVector) * speed * PIXEL_SIZE_F;
	addImpuls(impulsVector);

	if (game.getKeyBoardManager().getMouseLeft())
		skill.execute(getDirectionToMouse());
	skill.update();


	Entity::update();
}

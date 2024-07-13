#include "GameSprite.h"

GameSprite::GameSprite(const char* href, const sf::Vector2f& pSize) : rotate(false), size(pSize)
{
	if (!texture.loadFromFile(href))
	{
	
	}

	sprite.setTexture(texture);

	sf::Vector2u textureSize = texture.getSize();
	sprite.setScale(pSize.x / textureSize.x, pSize.y / textureSize.x);
}

void GameSprite::rotateRight()
{
	if (!rotate)
		return;
	rotateSprite();
}

void GameSprite::rotateLeft()
{
	if (rotate)
		return;
	rotateSprite();
}

void GameSprite::rotateSprite()
{
	sprite.setScale(-sprite.getScale().x, sprite.getScale().y);
	rotate = !rotate;
}

void GameSprite::draw(sf::RenderWindow* window, const sf::Vector2f& pPosition)
{
	sf::Vector2f drawPosition = pPosition;
	if (rotate)
		drawPosition.x += size.x;
	sprite.setPosition(drawPosition);
	window->draw(sprite);
}

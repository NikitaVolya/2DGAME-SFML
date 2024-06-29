#include "GameSprite.h"

GameSprite::GameSprite(const char* href) : rotate(false)
{
	if (!texture.loadFromFile(href))
	{
		
	}

	sprite.setTexture(texture);

	sf::Vector2u textureSize = texture.getSize();
	sprite.setScale(static_cast<float>(PIXEL_SIZE) / textureSize.x, static_cast<float>(PIXEL_SIZE) / textureSize.x);
}

void GameSprite::draw(sf::RenderWindow* window, const sf::Vector2f& pPosition)
{
	sprite.setPosition(pPosition);
	window->draw(sprite);
}

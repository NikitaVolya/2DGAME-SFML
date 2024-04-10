#include "Tile.h"

const TileData Tile::toTileData() const
{
    return TileData { colision, textureHref };
}

void Tile::setTextrure(const char* pImage)
{
    char loadHref[66] = TILES_FILES;

    MyFuncs::CharCpy(loadHref + 23, pImage, 43);
    MyFuncs::loadTexture(loadHref, &texture, &sprite, PIXEL_SIZE);
}

void Tile::draw(sf::RenderWindow* window, const sf::Vector2f pPosition, const float pScale)
{
    sprite.setPosition(pPosition);
    MyFuncs::setScale(&sprite, pScale);
    window->draw(sprite);
}

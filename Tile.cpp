#include "Tile.h"

const TileData Tile::toTileData()
{
    return TileData { colision, textureHref };
}

void Tile::setTextrure(const char* pImage)
{
    char loadHref[64] = TILES_FILES;

    int i = 0;
    for (; i < 43 && pImage[i]; i++)
    {
        loadHref[i + 23] = pImage[i];
        textureHref[i] = pImage[i];
    }
    loadHref[i + 24] = '\0';

    MyFuncs::loadTexture(loadHref, &texture, &sprite, PIXEL_SIZE);
}

void Tile::draw(sf::RenderWindow* window, sf::Vector2f pPosition, const float pScale)
{
    sprite.setPosition(pPosition);
    MyFuncs::setScale(&sprite, pScale);
    window->draw(sprite);
}

#include "MyFunctions.h"

sf::Vector2i MyFuncs::toVectorInteger(sf::Vector2f& pVector)
{
    return sf::Vector2i((int)pVector.x, (int)pVector.y);
}

sf::Vector2i MyFuncs::toVectorInteger(sf::Vector2u& pVector)
{
    return sf::Vector2i((int)pVector.x, (int)pVector.y);
}

sf::Vector2f MyFuncs::toVectorFloat(sf::Vector2i& pVector)
{
    return sf::Vector2f((float)pVector.x, (float)pVector.y);
}

sf::Vector2f MyFuncs::toVectorFloat(sf::Vector2u& pVector)
{
    return sf::Vector2f((float)pVector.x, (float)pVector.y);
}

sf::Vector2f MyFuncs::divisionVector(sf::Vector2f& a, sf::Vector2f& b)
{
    return sf::Vector2f(a.x / b.x, a.y / b.y);
}

sf::Vector2f MyFuncs::divisionVector(sf::Vector2f& a, float number)
{
    return sf::Vector2f(a.x / number, a.y / number);
}

sf::Vector2f MyFuncs::divisionVector(sf::Vector2f& a, int number)
{
    return sf::Vector2f(a.x / number, a.y / number);
}

sf::Vector2i MyFuncs::divisionVector(sf::Vector2i& a, sf::Vector2i& b)
{
    return sf::Vector2i(a.x / b.x, a.y / b.y);
}

sf::Vector2i MyFuncs::divisionVector(sf::Vector2i& a, float number)
{
    return sf::Vector2i(a.x / number, a.y / number);
}

sf::Vector2i MyFuncs::divisionVector(sf::Vector2i& a, int number)
{
    return sf::Vector2i(a.x / number, a.y / number);
}

sf::Vector2f& MyFuncs::normolize(sf::Vector2f& pVector)
{
    double lenghtV = lenghtVector(pVector);
    if (lenghtV == 0)
        return pVector;

    pVector.x = pVector.x / lenghtV;
    pVector.y = pVector.y / lenghtV;

    return pVector;
}

double MyFuncs::lenghtVector(sf::Vector2f& pVector)
{
    return sqrt(pVector.x * pVector.x + pVector.y * pVector.y);
}

void MyFuncs::loadTexture(const char* pFile, sf::Texture* texture, sf::Sprite* sprite, sf::Vector2f& size)
{
    texture->loadFromFile(pFile);
    sf::Vector2u textureSize = texture->getSize();

    sprite->setTexture(*texture);
    sprite->setScale(size.x / textureSize.x, size.y / textureSize.y);
}

void MyFuncs::loadTexture(const char* pFile, sf::Texture* texture, sf::Sprite* sprite, float size)
{
    texture->loadFromFile(pFile);
    sf::Vector2u textureSize = texture->getSize();

    sprite->setTexture(*texture);
    sprite->setScale( size / textureSize.x, size / textureSize.y);
}

void MyFuncs::setScale(sf::Sprite* sprite, const float pScale)
{
    sf::Vector2u size = sprite->getTexture()->getSize();
    sprite->setScale(PIXEL_SIZE * pScale / size.x , PIXEL_SIZE * pScale / size.y);
}

void MyFuncs::CharCopy(char* value, const char* source, const int size)
{
    for (int i = 0; i < size; i++)
        value[i] = source[i];
}

#include "MyFunctions.h"

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

sf::Vector2f& MyFuncs::normolize(sf::Vector2f& pVector)
{
    float lenghtV = lenghtVector(pVector);
    if (lenghtV == 0)
        return pVector;

    pVector.x = pVector.x / lenghtV;
    pVector.y = pVector.y / lenghtV;

    return pVector;
}

float MyFuncs::lenghtVector(sf::Vector2f& pVector)
{
    return sqrt(pVector.x * pVector.x + pVector.y * pVector.y);
}

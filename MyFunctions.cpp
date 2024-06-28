#include "MyFunctions.h"


sf::Vector2i MyFuncs::toVectorInteger(sf::Vector2f& pVector)
{
    return sf::Vector2i(static_cast<int>(pVector.x), static_cast<int>(pVector.y));
}

sf::Vector2i MyFuncs::toVectorInteger(sf::Vector2u& pVector)
{
    return sf::Vector2i(static_cast<int>(pVector.x), static_cast<int>(pVector.y));
}


sf::Vector2f MyFuncs::toVectorFloat(sf::Vector2i& pVector)
{
    return sf::Vector2f(static_cast<float>(pVector.x), static_cast<float>(pVector.y));
}

sf::Vector2f MyFuncs::toVectorFloat(sf::Vector2u& pVector)
{
    return sf::Vector2f(static_cast<float>(pVector.x), static_cast<float>(pVector.y));
}

sf::Vector2f& MyFuncs::normolize(sf::Vector2f& pVector)
{
    double lenghtV = lenghtVector(pVector);
    if (lenghtV == 0)
        return pVector;

    pVector.x = static_cast<float>(pVector.x / lenghtV);
    pVector.y = static_cast<float>(pVector.y / lenghtV);

    return pVector;
}

double MyFuncs::lenghtVector(const sf::Vector2f& pVector)
{
    return sqrt(pVector.x * pVector.x + pVector.y * pVector.y);
}

bool MyFuncs::questionYesNo(const char* pString)
{
    char rep;
    std::cout << pString << " [ y / n ]?\n";
    while (true)
    {
        std::cin >> rep;
        switch (rep)
        {
        case 'Y': case 'y': case 1:
            return true;
        case 'N': case 'n': case 0:
            return false;
        }
    }
}

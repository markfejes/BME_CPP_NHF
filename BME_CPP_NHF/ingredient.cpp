#include <iostream>
#include <cmath>
#include "ingredient.h"


void Ingredient::takeSome(double amount)
{
    if (isThereSome(std::abs(amount)))
    {
        inStock -= std::abs(amount);
    }
    else
        throw "There is not enought to take!!\n"; // TODO custom exception
}

void Ingredient::addSome(double amount)
{
    inStock += std::abs(amount);
}

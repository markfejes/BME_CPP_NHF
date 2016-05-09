#include <iostream>
#include <cmath>
#include "memtrace.h"
#include "ingredient.h"

bool Ingredient::isThereSome(double amount) const
{
    if (amount == 0)
    {
        return inStock > 0;
    }

    return amount <= inStock;
}

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

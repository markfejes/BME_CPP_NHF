#include <iostream>
#include "memtrace.h"
#include "ingredient.h"
#include "ingredientPair.hpp"
#include "ingredientMap.h"

void IngredientMap::addNewIngredient(Ingredient& ingredient, double amount)
{
    IngredientPair* tempArray = new IngredientPair[this->sizeOfMap + 1];

    if (this->sizeOfMap != 0)
    {
        for (int i = 0; i < sizeOfMap; i++)
        {
            tempArray[i] = this->ingredientMap[i];
        }
    }

    tempArray[this->sizeOfMap].getIngredient() = &ingredient;
    tempArray[this->sizeOfMap].getAmountNeeded() = amount;

    delete[] this->ingredientMap;
    this->ingredientMap = tempArray;
    this->sizeOfMap++;
}

IngredientPair& IngredientMap::operator[] (int index)
{
    if (index >= sizeOfMap) throw std::out_of_range("Wrong index given in the ingredientMap's [] operator!");
    return this->ingredientMap[index];
}


#include <iostream>
#include <sstream>
#include "memtrace.h"
#include "refrigerator.h"


void Refrigerator::addNewIngredient(Ingredient* newIngredient)
{
    if (allocatedSize == numberOfIngredients)
    {
        auto tempArray = new Ingredient[allocatedSize += 10];

        for (auto i = 0; i < allocatedSize; i++)
        {
            tempArray[i] = this->ingredientArray[i];
        }

        delete[] ingredientArray;
        ingredientArray = tempArray;
    }
    else
    {
        ingredientArray[numberOfIngredients++] = *newIngredient;
    }
}

void Refrigerator::printFridge() const
{
    for (auto i = 0; i < numberOfIngredients; i++)
    {
        std::cout << ingredientArray[i].getName();
        ingredientArray[i].addSome(500);
    }
}

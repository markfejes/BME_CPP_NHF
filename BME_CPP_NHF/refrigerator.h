#pragma once

#include "ingredient.h"

class Refrigerator
{
    Ingredient* ingredientArray;
    size_t      allocatedSize;
    size_t      numberOfIngredients;

public:

    Refrigerator(size_t initialSize = 10)
    {
        allocatedSize = initialSize;
        numberOfIngredients = 0;
        ingredientArray = new Ingredient[allocatedSize];
    }

    void addNewIngredient(Ingredient* newIngredient);
    void printFridge() const;

    ~Refrigerator()
    {
        delete[] ingredientArray;
    }

};
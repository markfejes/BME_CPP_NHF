#pragma once

#include "ingredient.h"

class IngredientMap
{
    Ingredient* ingredientArray;


public:
    IngredientMap();


    ~IngredientMap()
    {
        delete[] ingredientArray;
    };
};
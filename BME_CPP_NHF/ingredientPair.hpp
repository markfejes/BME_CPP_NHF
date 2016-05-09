#pragma once
#include "memtrace.h"

#include "ingredient.h"

class IngredientPair
{
    Ingredient* ingredient;
    double amount;

public:
    IngredientPair(Ingredient* ingredient_in = nullptr, double amountNeeded = 0) : amount (amountNeeded)
    {
        this->ingredient = ingredient_in;
    };

    Ingredient*& getIngredient()
    {
        return ingredient;
    }

    double& getAmountNeeded()
    {
        return amount;
    }
};


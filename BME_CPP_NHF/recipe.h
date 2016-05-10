#pragma once

#include "ingredientMap.h"

class Recipe
{
    std::string name;
    std::string description;
    IngredientMap ingredientsNeeded;


public:
    Recipe(std::string name, std::string description) : name(name), description(description) {};

    bool canWeCookSome(int amount = 1);

    void addNewIngredient(Ingredient* ingredient, double amountNeeded)
    {
        this->ingredientsNeeded.addNewIngredient(ingredient, amountNeeded);
    }

    void cookSome(int amount = 1);

    void editName (std::string& name)
    {
        this->name = name;
    }

    void editDescription(std::string& desc)
    {
        this->description = desc;
    }


    friend std::ostream& operator<<(std::ostream& os, const Recipe& rhs_recipe);

};

std::ostream& operator<<(std::ostream& os, const Recipe& rhs_recipe);
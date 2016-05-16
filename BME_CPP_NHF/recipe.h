#pragma once
#include <iostream>
#include "ingredientMap.h"


/** Recept osztaly*/
class Recipe
{
    std::string name;
    std::string description;
    IngredientMap ingredientsNeeded;

public:
    Recipe(std::string name = "", std::string description = "") : name(name), description(description) {};
    
    /** Ellenorizzuk, hogy el tudunk-e kesziteni megadott mennyiseget. */
    bool canWeCookSome(int amount = 1);

    /** Uj osszetevo paros hozzaadasa */
    void addNewIngredient(Ingredient& ingredient, double amountNeeded)
    {
        this->ingredientsNeeded.addNewIngredient(ingredient, amountNeeded);
    }

    /**
    * Elkeszitunk par adagot az adott receptbol ellenorzes utan
    */
    void cookSome(int amount = 1);

    /** Setter a nevhez */
    void editName (std::string& name)
    {
        this->name = name;
    }

    /** Setter a Desc.-hez */
    void editDescription(std::string& desc)
    {
        this->description = desc;
    }

    IngredientMap& getIngredientsNeeded()
    {
        return ingredientsNeeded;
    }

	std::string& getName() { return name; };
	std::string& getDesc() { return description; };

    friend std::ostream& operator<<(std::ostream& os, Recipe& rhs_recipe);
    friend std::istream& operator>>(std::istream& is, Recipe& rhs_recipe);
};

/** Read/Write */
std::ostream& operator<<(std::ostream& os, Recipe& rhs_recipe);
std::istream& operator>>(std::istream& is, Recipe& rhs_recipe);

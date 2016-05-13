#pragma once

#include "ingredientMap.h"

/*Recept osztaly*/
class Recipe
{
    std::string name;
    std::string description;
    IngredientMap ingredientsNeeded;


public:
    Recipe(std::string name, std::string description) : name(name), description(description) {};
    
    /* Ellenorizzuk, hogy el tudunk-e kesziteni megadott mennyiseget.*/
    bool canWeCookSome(int amount = 1);

    /* Uj osszetevo paros hozzaadasa*/
    void addNewIngredient(Ingredient* ingredient, double amountNeeded)
    {
        this->ingredientsNeeded.addNewIngredient(ingredient, amountNeeded);
    }

    /**
    * Elk�sz�t�nk p�r adagot az adott receptb�l ellenorzes utan
    */
    void cookSome(int amount = 1);

    /* Setter a nevhez*/
    void editName (std::string& name)
    {
        this->name = name;
    }

    /* Setter a Desc.-hez*/
    void editDescription(std::string& desc)
    {
        this->description = desc;
    }


    friend std::ostream& operator<<(std::ostream& os, const Recipe& rhs_recipe);

};

/* Megkonnyitjuk a recept nev�nek kiirasat*/
std::ostream& operator<<(std::ostream& os, const Recipe& rhs_recipe);
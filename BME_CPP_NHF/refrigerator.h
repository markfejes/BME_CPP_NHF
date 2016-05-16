#pragma once

#include "ingredient.h"
#ifndef ingredient_sep
#define ingredient_sep ';'
#endif
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
    /** Hozzaad egy uj osszetevot */
    void addNewIngredient(const std::string name, const std::string unit, double initAmount);

    ~Refrigerator()
    {
        delete[] ingredientArray;
    }
    /**Visszaadja a keresett osszetevore mutato pointert */
    Ingredient* getIngredient(Ingredient ingredientIn);
    Ingredient* getIngredient(std::string name, std::string unit);


    friend std::ostream& operator<<(std::ostream& os, Refrigerator& rhs_refrigerator);
    friend std::istream& operator>>(std::istream& is, Refrigerator& rhs_refrigerator);

};

/** Read/Write */
std::ostream& operator<<(std::ostream& os, Refrigerator& rhs_refrigerator);
std::istream& operator>>(std::istream& is, Refrigerator& rhs_refrigerator);

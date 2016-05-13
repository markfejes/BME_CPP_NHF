#pragma once

#include "ingredient.h"
#include "ingredientPair.h"

/*std::map alapu tarolo osszetevoknek*/
class IngredientMap
{
    IngredientPair* ingredientMap;
    size_t sizeOfMap;

public:
    class iterator;

    iterator begin()
    {
        return iterator(*this);
    }

    iterator end()
    {
        return iterator(*this, sizeOfMap);
    }

    IngredientMap() : ingredientMap(nullptr), sizeOfMap(0) {}

    ~IngredientMap()
    {
        delete[] ingredientMap;
    }

    bool isEmpty() const
    {
        return sizeOfMap == 0;
    }

    /* Uj paros hozzaadasa */
    void addNewIngredient (Ingredient* ingredient, double amount);
    
    IngredientPair& operator[](int index);

    /* Standard iterator a hozzavalok konnyebb listazasa erdekeben*/
    class iterator
    {
        IngredientPair *p, *pe;

    public:
        iterator() : p(nullptr), pe(nullptr) {};

        iterator(IngredientMap& curr, size_t size = 0) : p(curr.ingredientMap + size), pe(curr.ingredientMap + curr.sizeOfMap) {};
        
        iterator& operator++()
        {
            if (p != pe) ++p;
            return *this;
        }

        bool operator!=(const iterator& i) const
        {
            return (p != i.p);
        }

        IngredientPair& operator*()
        {
            if (p != pe) return *p;
            else throw std::out_of_range("Incorrect dereference!");
        }
        IngredientPair* operator->()
        {
            if (p != pe) return p;
            else throw std::out_of_range("Incorrect dereference!");
        }

    };

};
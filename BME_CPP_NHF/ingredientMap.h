#pragma once
#include "memtrace.h"

#include "ingredientPair.hpp"

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

    IngredientMap()
    {
        sizeOfMap = 0;
    }

    ~IngredientMap()
    {
        delete[] ingredientMap;
    };

    void addNewIngredient (Ingredient& ingredient, double amount);
    
    IngredientPair& operator[](int index);

    class iterator
    {
        IngredientPair *p, *pe;

    public:
        iterator() : p(0), pe(0) {};
        iterator(IngredientMap& curr, size_t size = 0) : p(curr.ingredientMap + size), pe(curr.ingredientMap + curr.sizeOfMap) {};
        
        iterator& operator++()
        {
            if (p != pe) ++p;
            return *this;
        }

        bool operator!=(const iterator& i)
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
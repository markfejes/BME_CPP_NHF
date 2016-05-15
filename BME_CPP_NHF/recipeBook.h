#pragma once

#include "refrigerator.h"

class RecipeBook
{
    static Refrigerator fridge;
public:
    
    RecipeBook()
    {
    }

    ~RecipeBook();
    /**Getter a statikus fridge-hez */
    static Refrigerator& getFridge()
    {
        return fridge;
    }
};
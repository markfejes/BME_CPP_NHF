#pragma once


/** std::pair alapu pair osztaly*/
class IngredientPair
{
    Ingredient* ingredient;
    double amount;

public:
    IngredientPair(Ingredient* ingredient_in = 0, double amountNeeded = 0) : amount (amountNeeded)
    {
        this->ingredient = ingredient_in;
    };

    /** Visszaad egy modosithato pointert az osszetevore */
    Ingredient*& getIngredient()
    {
        return ingredient;
    }

    /**Referencia a kello mennyisegre*/
    double& getAmountNeeded()
    {
        return amount;
    }

    friend std::ostream& operator<<(std::ostream& os, IngredientPair & rhs_IP);
    friend std::istream& operator>>(std::istream& os, IngredientPair & rhs_IP);

};

/** Megkonnyitjuk a par kiirasat*/
std::ostream& operator<<(std::ostream& os, IngredientPair & rhs_IP);
std::istream& operator>>(std::istream& is, IngredientPair & rhs_IP);
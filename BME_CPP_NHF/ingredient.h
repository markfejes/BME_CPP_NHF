#pragma once
/**
* \file ingredient.h
*
* A hozzávalókat tároló Osztály
*
* Feladat:
*   Receptkönv készítés
*/

class Ingredient
{
    const  std::string name;
    std::string unit;
    double inStock;

public:
    Ingredient(const std::string name, const std::string unit, double initAmount = 0 ) : name    (name)
                                                                                       , unit    (unit)
                                                                                       , inStock (initAmount) {};
    bool isThereSome(double amount = 0) const;

    void takeSome(double amount);

    void addSome(double amount);
    
    std::string getUnit() const { return unit; };

    std::string getName() const { return name; };

    bool operator==(const Ingredient& rhs_ingredient) const;
    bool Ingredient::operator!=(const Ingredient& rhs_ingredient) const;
};


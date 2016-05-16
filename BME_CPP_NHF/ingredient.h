#pragma once
#include <iostream>
#ifndef ingredient_sep
#define ingredient_sep ';'
#endif


/**
 \file ingredient.h

A hozzavalokat tarola Osztaly

Feladat:
  Receptkonyv keszites
*/
class Ingredient
{
    std::string name;
    std::string unit;
    double inStock;

public:
    Ingredient(const std::string name = "", const std::string unit = "", double initAmount = 0 ) : name    (name)
                                                                                                 , unit    (unit)
                                                                                                 , inStock (initAmount) {};
    /** Ellenorzi, hogy van-e annyi amennyit megadtunk neki */
    bool isThereSome(double amount = 0) const;

    /**Elvesz a keszletbol*/
    void takeSome(double amount);

    /**Hozzaad a keszlethez*/
    void addSome(double amount);
    

    std::string getUnit() const { return unit; };
    void setUnit(const std::string unit) { this->unit = unit; };

    std::string getName() const { return name; };
    void setName(const std::string name) { this->name = name; };

    double getStock() const { return inStock; };
    bool operator==(const Ingredient& rhs_ingredient) const;
    bool operator!=(const Ingredient& rhs_ingredient) const;

    friend std::ostream& operator<<(std::ostream& os, Ingredient& rhs_ingredient);
    friend std::istream& operator>>(std::istream& is, Ingredient& rhs_ingredient);

};

/** Read/Write*/
std::ostream& operator<<(std::ostream& os, Ingredient& rhs_ingredient);

std::istream& operator>>(std::istream& is, Ingredient& rhs_ingredient);

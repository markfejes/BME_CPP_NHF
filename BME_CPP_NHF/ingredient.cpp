
#include <cmath>
#include <sstream>
#include "memtrace.h"
#include "ingredient.h"


bool Ingredient::isThereSome(double amount) const
{
    if (amount == 0)
    {
        return inStock > 0;
    }

    return amount <= inStock;
}

void Ingredient::takeSome(double amount)
{
    if (isThereSome(std::abs(amount)))
    {
        inStock -= std::abs(amount);
    }
    else
    {
        std::stringstream err;
        err << "There is not enough of " << name << " to take!";
        throw err.str();
    }
}

void Ingredient::addSome(double amount)
{
    inStock += std::abs(amount);
}

bool Ingredient::operator==(const Ingredient& rhs_ingredient) const
{
    return (this->unit == rhs_ingredient.unit && this->name == rhs_ingredient.name);
}

bool Ingredient::operator!=(const Ingredient& rhs_ingredient) const
{
    return (this->unit != rhs_ingredient.unit || this->name != rhs_ingredient.name);
}

std::ostream& operator<<(std::ostream& os, Ingredient& rhs_ingredient)
{
    os << rhs_ingredient.name << ingredient_sep << rhs_ingredient.inStock << ingredient_sep << rhs_ingredient.unit << ingredient_sep;

    return os;
}

std::istream& operator>>(std::istream& is, Ingredient& rhs_ingredient)
{
    std::string inStock;

    std::getline(is, rhs_ingredient.name, ingredient_sep);
    std::getline(is, inStock, ingredient_sep);
    std::getline(is, rhs_ingredient.unit, ingredient_sep);

    rhs_ingredient.inStock = atof(inStock.c_str());

    return is;
}

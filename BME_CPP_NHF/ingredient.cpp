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
        throw err;
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

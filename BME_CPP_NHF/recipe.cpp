#include <sstream>
#include "memtrace.h"
#include "recipe.h"


bool Recipe::canWeCookSome(int amount)
{
    if (ingredientsNeeded.isEmpty())
    {
        std::stringstream err;
        err << "There are no ingredient list for: " << name;
        throw err.str();
    }

    for (auto i1 = ingredientsNeeded.begin(); i1 != ingredientsNeeded.end(); ++i1)
    {
        if (i1->getIngredient()->isThereSome(i1->getAmountNeeded() * amount) == false)
        {
            return false;
        }
    }
    return true;
}



void Recipe::cookSome(int amount)
{
    if (this->canWeCookSome(amount) == false)
    {
        std::stringstream err;
        err << "There are not enough ingredients to make " << amount << " of " << name;
        throw err.str();
    }

    for (auto i1 = ingredientsNeeded.begin(); i1 != ingredientsNeeded.end(); ++i1)
    {
        i1->getIngredient()->takeSome(i1->getAmountNeeded());
    }
}

std::ostream& operator<<(std::ostream& os, const Recipe& rhs_recipe)
{
    os << rhs_recipe.name;
    return os;
}

#include <sstream>
#include "memtrace.h"
#include "ingredient.h"
#include "ingredientPair.h"

std::ostream& operator<<(std::ostream& os, IngredientPair & rhs_IP)
{
    os << rhs_IP.getIngredient()->getName() << ": " << rhs_IP.getAmountNeeded() << rhs_IP.getIngredient()->getUnit();
    return os;
}

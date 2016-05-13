#include <sstream>
#include "memtrace.h"
#include "ingredient.h"
#include "ingredientPair.h"

std::ostream& operator<<(std::ostream& os, IngredientPair & rhs_IP)
{
    os << rhs_IP.getIngredient();
    return os;
}

std::istream& operator>>(std::istream& is, IngredientPair& rhs_IP)
{


    return is;
}

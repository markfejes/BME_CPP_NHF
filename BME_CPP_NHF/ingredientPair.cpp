#include "memtrace.h"
#include "ingredient.h"
#include "ingredientPair.h"
#include "refrigerator.h"
#include "recipeBook.h"

void IngredientPair::setIngredient(Ingredient& ingredient_in)
{
	ingredient = RecipeBook::getFridge().getIngredient(ingredient_in);
}

std::ostream& operator<<(std::ostream& os, IngredientPair& rhs_IP)
{
    os << *RecipeBook::getFridge().getIngredient(rhs_IP.getIngredient()) << rhs_IP.amount;
    return os;
}

std::istream& operator>>(std::istream& is, IngredientPair& rhs_IP)
{
    Ingredient temp;
    double amount;

    is >> temp;
    is >> amount;

    rhs_IP.amount = amount;
    rhs_IP.ingredient = RecipeBook::getFridge().getIngredient(temp);

    return is;
}

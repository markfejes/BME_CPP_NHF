#include <iostream>

#include "memtrace.h"
#include "recipeBook.h"
#include "ingredientMap.h"


using namespace std;

int main()
{
    RecipeBook::getFridge().addNewIngredient("cukor", "g", 10000);
    RecipeBook::getFridge().addNewIngredient("so", "g", 5000);
    RecipeBook::getFridge().addNewIngredient("tej", "l", 100);

    IngredientMap map = IngredientMap();
    
    cin >> map;

    cout << map;
    return 0;
}
#include <iostream>
#define ingredient_sep ';'
#define ingredientPair_sep ';'
#include "memtrace.h"

#include "ingredient.h"
#include "recipe.h"
#include "ingredientMap.h"
#include "ingredientPair.h"
#include "refrigerator.h"

using namespace std;

int main()
{
    auto huto = Refrigerator();

    huto.addNewIngredient(new Ingredient("Sugar", "g", 1000));
    huto.printFridge();
    cout << endl;


}

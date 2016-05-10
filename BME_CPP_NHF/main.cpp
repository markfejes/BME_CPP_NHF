#include <iostream>
#include "memtrace.h"

#include "ingredient.h"
#include "recipe.h"
#include "ingredientMap.h"
#include "ingredientPair.h"

using namespace std;

int main()
{
    auto sugar  = new Ingredient("Sugar", "g", 1000);
    auto lofasz = new Ingredient("lofasz", "db", 10);
    auto lohugy = new Ingredient("lohugy", "l", 0);
    auto uborka = new Ingredient("uborka", "db", 10);
    
    IngredientMap map;
        
    map.addNewIngredient(sugar, 500);
    map.addNewIngredient(lofasz, 1);
    map.addNewIngredient(lohugy, 6);

    cout << "Amount needed: " << map[0].getAmountNeeded() << endl;
    cout << "Amount needed: " << map[1].getAmountNeeded() << endl;

    auto test = Recipe("lofaszos krumpli", "egy kis lofasz, krumplival megkenve");

    cout << test << endl;

    delete sugar;
    delete lofasz;
    delete lohugy;
    delete uborka;

}

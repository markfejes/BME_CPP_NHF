#include <iostream>
#include <cmath>
#include "memtrace.h"

#include "ingredient.h"
#include "recipe.h"
#include "ingredientMap.h"

using namespace std;

int main()
{
    Ingredient sugar  = Ingredient("Sugar", "g", 1000);
    Ingredient lofasz = Ingredient("lofasz", "db", 10);
    Ingredient lohugy = Ingredient("lohugy", "l", 0);
    
    IngredientMap map;

    map.addNewIngredient(sugar, 500);
    map.addNewIngredient(lofasz, 1);
    map.addNewIngredient(lohugy, 6);

    cout << "Amount needed: " << map[0].getAmountNeeded() << endl;
    cout << "Amount needed: " << map[1].getAmountNeeded() << endl;

    for (IngredientMap::iterator i1 = map.begin(); i1 != map.end(); ++i1)
    {
        cout << ((*i1).getIngredient())->getName().c_str() << endl;

        cout << i1->getIngredient()->isThereSome() << endl;
    }

}

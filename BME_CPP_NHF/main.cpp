#include <iostream>
#include "memtrace.h"
#include "recipe.h"
#include "recipeBook.h"


using namespace std;

int main()
{
	try
	{
		RecipeBook::readSavedRefrigerator();
		RecipeBook::readSavedRecipes();

		//RecipeBook::getRecipe(0).cookSome(1);

        RecipeBook::writeRecipes(cout); 
        //cout << endl;

		RecipeBook::saveRecipes();
		RecipeBook::saveRefrigerator();
	}
	catch (char* err)
	{
		cerr << err << endl;
	}

	RecipeBook::deleteRecipes();
    return 0;
}
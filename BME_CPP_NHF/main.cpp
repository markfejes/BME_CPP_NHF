
#include <iostream>
#include "memtrace.h"
#include "recipe.h"
#include "recipeBook.h"
#include "menu.hpp"
#include "utils.hpp"

using namespace std;

int main()
{
	try
	{
		RecipeBook::readSavedRefrigerator();
		RecipeBook::readSavedRecipes();

		Menu::initMenu();

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
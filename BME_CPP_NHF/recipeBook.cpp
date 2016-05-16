#include <iostream>
#include <fstream>
#include <sstream>
#include "memtrace.h"
#include "recipeBook.h"

Refrigerator RecipeBook::fridge = Refrigerator();
size_t       RecipeBook::allocatedSize = 10;
size_t       RecipeBook::numberOfRecipes = 0;
Recipe*      RecipeBook::recipes = new Recipe[RecipeBook::allocatedSize];

Recipe& RecipeBook::getRecipe(size_t index)
{
	return recipes[index];
}

void RecipeBook::addNewRecipe(std::string name, std::string description)
{
	if (allocatedSize == numberOfRecipes)
	{
        allocatedSize = allocatedSize + 10;
		Recipe* tempArray = new Recipe[allocatedSize];

		for (size_t i = 0; i < numberOfRecipes; i++)
		{
			tempArray[i] = recipes[i];
		}

		delete[] recipes;
		recipes = tempArray;
	}

	recipes[numberOfRecipes++] = Recipe(name, description);
}

void RecipeBook::readSavedRefrigerator()
{
	std::ifstream refrigeratorDat;
	refrigeratorDat.open("refrigerator.dat");
	if (refrigeratorDat.is_open())
	{
		refrigeratorDat >> getFridge();
		refrigeratorDat.close();
	}
}

void RecipeBook::saveRefrigerator()
{
	std::ofstream refrigeratorDat;
	refrigeratorDat.open("refrigerator.dat", std::ios::trunc);
	if (refrigeratorDat.is_open())
	{
		refrigeratorDat << getFridge();
		refrigeratorDat.close();
	}
	else
	{
		throw "Unable to write 'refrigerator.dat'";
	}
}

void RecipeBook::writeRecipes(std::ostream& os)
{
	for (size_t i = 0; i < numberOfRecipes; i++)
	{
        os << recipes[i].getName() << std::endl;
        os << recipes[i].getDesc() << std::endl;
		os << recipes[i];
	}
}


void RecipeBook::readRecipes(std::istream& is)
{
    while(is.peek() != EOF)
    {
        std::string name, desc;

        std::getline(is, name);
        std::getline(is, desc);

        addNewRecipe(name, desc);

		is >> recipes[numberOfRecipes - 1];
    }
}


//void RecipeBook::readRecipes(std::istream& is)
//{
//    while (is.peek() != '\n' && (is >> addNewRecipe()))
//    {
//        if (recipes[numberOfRecipes - 1].getName() == "")
//        {
//            numberOfRecipes--;
//        }
//    }
//}

void RecipeBook::readSavedRecipes()
{
	std::ifstream recipesDat;
	recipesDat.open("recipes.dat");
	if (recipesDat.is_open())
	{
		readRecipes(recipesDat);
		recipesDat.close();
	}
}

void RecipeBook::saveRecipes()
{
	std::ofstream recipesDat;
	recipesDat.open("recipes.dat", std::ios::trunc);
	if (recipesDat.is_open())
	{
		writeRecipes(recipesDat);
		recipesDat.close();
	}
	else
	{
		throw "Unable to write 'recipes.dat'";
	}
}

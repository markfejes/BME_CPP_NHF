#pragma once
#include <iostream>
#include <string>
#include "memtrace.h"

/** A kiirast megknnyito eszkozok*/
namespace Utils
{
	using namespace std;

	void listRefrigerator()
	{
		size_t numberOfIngredients = RecipeBook::getFridge().getNumberOfIngredients();

		for (size_t i = 0; i < numberOfIngredients; i++)
		{
			cout << RecipeBook::getFridge()[i].getName() << " - in Stock: " << RecipeBook::getFridge()[i].getStock() << RecipeBook::getFridge()[i].getUnit() << endl;
		}
	}
}

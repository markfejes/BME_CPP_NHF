#pragma once
#include <iostream>
#include "memtrace.h"
#include "utils.hpp"

/** Menuvezerlo namespace*/
namespace Menu
{
	void ingredientsMenu();
	void initMenu();

	using namespace std;

	inline void initMenu()
	{
		while (true)
		{
			int num;
			cout << "-----------------------------------------------" << endl;
			cout << "1. Ingredients" << endl;
			cout << "2. Recipes" << endl;
			cout << "3. Quit" << endl;
			cin >> num;

			switch (num)
			{
			case 1:
				ingredientsMenu();
				break;
			case 3:
				return;
			}
			cout << endl;
		}
	}

	inline void ingredientsMenu()
	{
		while (true)
		{
			int num;
			cout << "-----------------------------------------------" << endl;
			cout << "1. List all Ingredients in the refrigerator" << endl;
			cout << "2. Add new Ingredient" << endl;
			cout << "3. Back" << endl;
			cin >> num;

			switch (num)
			{
			case 1:
				Utils::listRefrigerator();
				break;
			case 3:
				return;
			}
			cout << endl;
		}
	}





}

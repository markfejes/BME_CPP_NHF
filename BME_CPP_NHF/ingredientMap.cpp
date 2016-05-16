
#include <sstream>
#include "memtrace.h"

#include "ingredient.h"
#include "ingredientPair.h"
#include "ingredientMap.h"

void IngredientMap::addNewIngredient(Ingredient ingredient, double amount)
{
	std::cout << "halihó!" << std::endl << ingredient << std::endl;
    IngredientPair* tempArray = new IngredientPair[this->sizeOfMap + 1];

    for (size_t i = 0; i < sizeOfMap; i++)
    {
        tempArray[i] = this->ingredientMap[i];
    }

    tempArray[this->sizeOfMap].setIngredient(ingredient);
    tempArray[this->sizeOfMap].setAmountNeeded(amount);

    delete[] this->ingredientMap;
    ingredientMap = tempArray;
	sizeOfMap++;
}

IngredientPair& IngredientMap::operator[] (size_t index)
{
    if (index >= sizeOfMap) throw std::out_of_range("Wrong index given in the ingredientMap's [] operator!");
    return this->ingredientMap[index];
}

std::ostream& operator<<(std::ostream& os, IngredientMap& rhs_ingredient_map)
{
    for (IngredientMap::iterator iter = rhs_ingredient_map.begin(); iter != rhs_ingredient_map.end(); ++iter)
    {
        os << *iter << std::endl;
    }

    os << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, IngredientMap& rhs_ingredient_map)
{
    std::stringstream input;
    std::string inputStr;
    IngredientPair temp;

    while (std::getline(is, inputStr) && inputStr.length() > 0)
    {
        input.str(inputStr);

        input >> temp;

        rhs_ingredient_map.addNewIngredient(temp.getIngredient(), temp.getAmountNeeded());

        input.clear();
        input.str(std::string());
    }


    return is;
}

#include <sstream>
#include "memtrace.h"
#include "refrigerator.h"

void Refrigerator::addNewIngredient(const std::string name, const std::string unit, double initAmount = 0)
{
    if (allocatedSize == numberOfIngredients)
    {
        Ingredient* tempArray = new Ingredient[allocatedSize += 10];

        for (size_t i = 0; i < allocatedSize; i++)
        {
            tempArray[i] = ingredientArray[i];
        }

        delete[] ingredientArray;
        ingredientArray = tempArray;
    }

    ingredientArray[numberOfIngredients++] = Ingredient(name, unit, initAmount);

}
Ingredient* Refrigerator::getIngredient(Ingredient& ingredientIn)
{
    Ingredient temp = ingredientIn;

    for (size_t i = 0; i < numberOfIngredients; i++)
    {
        if (ingredientArray[i] == temp)
        {
            return &ingredientArray[i];
        }
    }
    return 0;
}

Ingredient* Refrigerator::getIngredient(std::string name, std::string unit)
{
    Ingredient temp = Ingredient(name, unit);

    for (size_t i = 0; i < numberOfIngredients; i++)
    {
        if (ingredientArray[i] == temp)
        {
            return &ingredientArray[i];
        }
    }
    return 0;
}

std::ostream& operator<<(std::ostream& os, Refrigerator& rhs_refrigerator)
{
    for (size_t i = 0; i < rhs_refrigerator.numberOfIngredients; i++)
    {
        os << rhs_refrigerator.ingredientArray[i] << std::endl;
    }
    return os;
}


std::istream& operator>>(std::istream& is, Refrigerator& rhs_refrigerator)
{
    std::stringstream input;
    std::string inputStr;
    Ingredient temp;

    while (std::getline(is, inputStr))
    {
        input.str(inputStr);
        
        input >> temp;
        rhs_refrigerator.addNewIngredient(temp.getName(), temp.getUnit(), temp.getStock());
        
        input.clear();
        input.str(std::string());
    }

    return is;
}

#pragma once
class Recipe
{
    std::string name;
    std::string description;
    // TODO IngredientArray Class


public:
    Recipe(std::string name, std::string description) : name(name), description(description) {};
    ~Recipe();

    void canWeCookSome();
    void cookSome(int amount);
};


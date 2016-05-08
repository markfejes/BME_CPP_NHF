#include <iostream>
#include <cmath>
#include "ingredient.h"
#include "recipe.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    Ingredient sugar         = Ingredient("Cukor", "g", 1000);
    Ingredient cayannePepper = Ingredient("Cayanne Bors", "g", 50);
    Ingredient milk          = Ingredient("Tej", "l", 5);
    Ingredient apple         = Ingredient("Alma", "db", 10);

    cout << "van 250g cukor: " << sugar.isThereSome(250) << endl;
    cout << "van 11db alma: " << apple.isThereSome(11) << endl;

    try
    {
        cout << "Próbáljunk meg elvenni 5 db almát!" << endl;
        apple.takeSome(5);
        cout << "Nincs hiba." << endl;
        cout << "Próbáljunk meg elvenni 7 db almát! Reméljük hibát okoz," << endl;
        apple.takeSome(7);
        cout << "Ez ne írodjon ki :)" << endl;
    }
    catch (const char* error)
    {
        cout << "És bizony hiba jött:" << endl;
        cout << error;
    }
}

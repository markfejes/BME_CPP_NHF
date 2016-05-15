#pragma once
#include "recipe.h"
#include "refrigerator.h"
/** \static
*	Statikus osztaly a receptek es a huto tarolasara
*/
class RecipeBook
{
    static Refrigerator fridge;
    static size_t       allocatedSize;
    static size_t       numberOfRecipes;
    static Recipe*      recipes;

public:

	/** Felszabaditja a statikus Recipe din. tombot*/
	static void deleteRecipes()
    {
        delete[] recipes;
    }
	static Recipe& getRecipe(size_t index);

	/** Letrehoz egy uj receptet a memoriaba */
	static Recipe & addNewRecipe(std::string name = "", std::string description = "");

    /**Getter a statikus fridge-hez */
    static Refrigerator& getFridge()
    {
        return fridge;
    }

	/** Beolvassa az elmentett refrigerator.dat fajlt */
	static void readSavedRefrigerator();

	/** Kiirja a jelenlegi huto allasat fajlba*/
	static void saveRefrigerator();

	/** Kiirja a recepteket az atadott ostream-re */
	static void writeRecipes(std::ostream& os);

	/** Beolvassa a receteket a atadott istream-rol */
	static void readRecipes (std::istream& is);
	
	static void readSavedRecipes();
	static void saveRecipes();
};

#include "cook.hpp"
#include <iterator>

Cook::Cook(){};

Cook::Cook(const list<ingred> &ingredient_list,
           const list<Recipe> &recipe_list) {
    ingredients = ingredient_list;
    entire_recipes = recipe_list;
}

void Cook::set_ingredients(const list<ingred> &ingredient_list) {
    ingredients = ingredient_list;
}

void Cook::set_entire_recipes(const list<Recipe> &recipe_list) {
    entire_recipes = recipe_list;
}

void Cook::arrange_recipes() {
    cookable_recipes.clear();
    uncookable_recipes.clear();

    vector<string>::iterator it_ingred;
    list<Recipe>::iterator it_recipe;

    for (it_recipe = entire_recipes.begin(); it_recipe != entire_recipes.end();
         ++it_recipe) {
        Recipe recipe = *it_recipe;
        vector<string> ingreds = recipe.get_recipe_ingredient();
        for (it_ingred = ingreds.begin(); it_ingred != ingreds.end();
             ++it_ingred) {
            if (is_lack(*it_ingred, ingredients))
                recipe.lacking_ingredients.push_back(*it_ingred);
        }

        if (recipe.lacking_ingredients.size() == 0)
            cookable_recipes.push_back(recipe);
        else
            uncookable_recipes.push_back(recipe);
    }

    return;
}

vector<Recipe> Cook::get_cookable() { return cookable_recipes; }
vector<Recipe> Cook::get_uncookable() { return uncookable_recipes; }

bool is_lack(const string &target, list<ingred> ingredients) {
    list<ingred>::iterator iter;
    for (iter = ingredients.begin(); iter != ingredients.end(); ++iter) {
        ingred ingredient = *iter;
        if (ingredient.get_ingredient_name() == target)
            return false;
    }
    return true;
}

void use_ingredients(vector<string> using_ingreds, list<ingred> &ingreds) {
    vector<string>::iterator it_use;
    list<ingred>::iterator it_ingred;
    string using_ingred;
    ingred modifying;

    for (it_use = using_ingreds.begin(); it_use != using_ingreds.end();
         ++it_use) {
        using_ingred = *it_use;
        for (it_ingred = ingreds.begin(); it_ingred != ingreds.end();
             ++it_ingred) {
            modifying = *it_ingred;
            if (modifying.get_ingredient_name() == using_ingred)
                break;
        }
        ingreds.erase(it_ingred);
        modifying.set_ingredient_quantity(modifying.get_ingredient_quantity() -
                                          1);
        if (modifying.get_ingredient_quantity() > 0)
            ingreds.push_back(modifying);
    }

    return;
}

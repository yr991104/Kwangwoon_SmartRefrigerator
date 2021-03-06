#include "recipe.hpp"

Recipe::Recipe() {
    recipe_name = "";
    recipe_difficulty = "";
    recipe_time = 0;
}

Recipe::Recipe(string name, vector<string> content,
               vector<string> list_for_ingerdient, string difficulty,
               int time) {
    recipe_name = name;
    recipe_content = content;
    recipe_ingredient_list = list_for_ingerdient;
    recipe_difficulty = difficulty;
    recipe_time = time;
}

string Recipe::get_recipe_name() { return recipe_name; }
vector<string> Recipe::get_recipe_content() { return recipe_content; }
vector<string> Recipe::get_recipe_ingredient() {
    return recipe_ingredient_list;
}
string Recipe::get_recipe_difficulty() { return recipe_difficulty; }
int Recipe::get_recipe_time() { return recipe_time; }

void Recipe::set_recipe_name(string name) { this->recipe_name = name; }
void Recipe::set_recipe_content(vector<string> content) {
    this->recipe_content.assign(content.begin(), content.end());
}
void Recipe::set_recipe_ingredient(vector<string> ingredient) {

    this->recipe_ingredient_list.assign(ingredient.begin(), ingredient.end());
}

void Recipe::set_recipe_difficulty(string difficulty) {
    this->recipe_difficulty = difficulty;
}
void Recipe::set_recipe_time(int time) { this->recipe_time = time; }

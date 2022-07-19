export interface Ingredient {
    id : string,
    ingred : string,
    store : string,
    selected : boolean,
}

export interface Meal{
    selected : boolean,
    ingreds : Ingredient[],
}

export interface mealList {
    [name : string] : Meal;
}
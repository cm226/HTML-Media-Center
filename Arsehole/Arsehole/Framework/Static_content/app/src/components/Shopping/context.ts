import React from 'react'

import {Dispatcher} from '../../Dispatcher'

import SelectedMeal from './stores/selectedMeals'
import IngredientsStore from './stores/ingredientsStore'
import FullMealListStore from './stores/fullMealListStore'

const selectedMeals = new SelectedMeal();
const sainsIngred = new IngredientsStore();
const aldiIngreds = new IngredientsStore();
const fullMealList = new FullMealListStore();
const dispacher = new Dispatcher();

selectedMeals.register(dispacher);
sainsIngred.register(dispacher, 'sains');
aldiIngreds.register(dispacher, 'aldi');
fullMealList.register(dispacher);

export const ShoppingContext = React.createContext({
  dispacher : dispacher,
  selectedMeals : selectedMeals,
  sainsIngred : sainsIngred,
  aldiIngreds : aldiIngreds,
  fullMealList : fullMealList
});
import React from 'react'

import {Dispatcher} from '../../Dispatcher'

import SelectedMeal from './stores/selectedMeals'
import IngredientsStore from './stores/ingredientsStore'
import DisplayedViewStore from './stores/DisplayedViewStore'
import WorkerStatusStore from './stores/WorkerStatusStore'
import FilterViewStore from './stores/FilterViewStore'

const selectedMeals = new SelectedMeal();
const sainsIngred = new IngredientsStore();
const aldiIngreds = new IngredientsStore();
const displayedView = new DisplayedViewStore();
const workerStatus = new WorkerStatusStore();
const dispacher = new Dispatcher();
const filerViewStore = new FilterViewStore();

selectedMeals.register(dispacher);
sainsIngred.register(dispacher, 'sains');
aldiIngreds.register(dispacher, 'aldi');
displayedView.register(dispacher);
workerStatus.register(dispacher);
filerViewStore.register(dispacher);

export const ShoppingContext = React.createContext({
  dispacher : dispacher,
  selectedMeals : selectedMeals,
  sainsIngred : sainsIngred,
  aldiIngreds : aldiIngreds,
  displayedView : displayedView,
  workerStatus : workerStatus,
  filter : filerViewStore
});
import React from 'react'

import {Dispatcher} from '../../Dispatcher'

import IngredientsStore from './stores/ingredientsStore'
import DisplayedViewStore from './stores/DisplayedViewStore'
import {WorkerStatusStore} from './stores/WorkerStatusStore'
import FilterViewStore from './stores/FilterViewStore'
import ExtrasStore from './stores/extrasStore'
import CheckedIngredStore from './stores/checkedIngredStore'

const extrasStore = new ExtrasStore();
const sainsIngred = new IngredientsStore();
const displayedView = new DisplayedViewStore();
const workerStatus = new WorkerStatusStore();
const dispacher = new Dispatcher();
const filerViewStore = new FilterViewStore();
const checkedIngredStore = new CheckedIngredStore();

extrasStore.register(dispacher);
sainsIngred.register(dispacher);
displayedView.register(dispacher);
workerStatus.register(dispacher);
filerViewStore.register(dispacher);
checkedIngredStore.register(dispacher);

export const ShoppingContext = React.createContext({
  dispacher : dispacher,
  sainsIngred : sainsIngred,
  extras : extrasStore,
  displayedView : displayedView,
  workerStatus : workerStatus,
  filter : filerViewStore,
  checkedIngredStore :checkedIngredStore
});
import React, {useEffect} from 'react';
import Time from './components/time'
import Plugins from './components/Plugins'
import loadedPluginStore from './stores/LoadedPlugins'
import RootURLStore from './stores/RootURLStore'
import VersionStore from './stores/VersionStore'
import {homeContext} from './contexts/homeContext'
import './App.css';
import { strict } from 'assert';
import ServerTimeStore from './stores/serverTimeStore';
import Version from './components/Version'
import Shopping from './components/Shopping/Shopping'

import {
  BrowserRouter as Router,
  Switch,
  Route,
  Link
} from "react-router-dom";

const stores = {
  urlStore : new RootURLStore(),
  loadedPluginStore: new loadedPluginStore(),
  serverTimeStore : new ServerTimeStore(),
  versionStore : new VersionStore()
}

stores.urlStore.setRootURL()

function App() {
  useEffect(() => {
    stores.loadedPluginStore.updatePlugins(
      stores.urlStore.rootURL
    );
    stores.serverTimeStore.getServerTime(
      stores.urlStore.rootURL
    );
    stores.versionStore.getVerion(
      stores.urlStore.rootURL
    )
  });
  return (
    <homeContext.Provider value={stores}>
    <div className="App">
    <Router>
    <Switch>
          <Route path="/app/build/Shopping.html">
            <Shopping />
          </Route>
          <Route path="/">
            <Time/>
            <Plugins/>
          </Route>
    </Switch>
    </Router>
     <Version />
    </div>
    </homeContext.Provider>
  );
}

export default App;

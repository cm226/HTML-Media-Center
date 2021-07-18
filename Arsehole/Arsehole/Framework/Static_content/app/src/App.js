import React, {useEffect} from 'react';
import Time from './components/time'
import Plugins from './components/Plugins'
import loadedPluginStore from './stores/LoadedPlugins'
import RootURLStore from './stores/RootURLStore'
import VersionStore from './stores/VersionStore'
import {homeContext} from './contexts/homeContext'
import './App.css';
import ServerTimeStore from './stores/serverTimeStore';
import Version from './components/Version'
import Shopping from './components/Shopping/Shopping'
import Invest from './components/Invest/Invest'
import Editor from './components/ConfigEditor/Components/Editor'

import {
  BrowserRouter as Router,
  Switch,
  Route
} from "react-router-dom";

const stores = {
  urlStore : new RootURLStore(),
  loadedPluginStore: new loadedPluginStore(),
  serverTimeStore : new ServerTimeStore(),
  versionStore : new VersionStore()
}

stores.urlStore.setRootURL()

// install our service worker
if ('serviceWorker' in navigator) {
  navigator.serviceWorker.register(stores.urlStore.rootURL +'shopping-worker.js',
   {scope : './'});
}

navigator.serviceWorker.ready.then(function(swRegistration) {
  return swRegistration.sync.register('sync');
});

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
          <Route path="/app/build/config.html">
            <Editor/>
          </Route>
          <Route path="/app/build/Invest.html">
            <Invest />
          </Route>
          <Route path="/">
            <Time/>
            <Plugins/>
            <Version />
          </Route>
    </Switch>
    </Router>
    </div>
    </homeContext.Provider>
  );
}

export default App;

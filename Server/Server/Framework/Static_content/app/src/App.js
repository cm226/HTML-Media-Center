import React, {useEffect} from 'react';
import Plugins from './components/Plugins'
import AppHeaderContent from './components/AppHeaderContent'
import loadedPluginStore from './stores/LoadedPlugins'
import RootURLStore from './stores/RootURLStore'
import VersionStore from './stores/VersionStore'
import {homeContext} from './contexts/homeContext'
import './App.css';
import ServerTimeStore from './stores/serverTimeStore';
import Version from './components/Version'
import Shopping from './components/Shopping/Shopping'
import Editor from './components/ConfigEditor/Components/Editor'
import LogViewer from './components/LogViewer/LogViewer'
import Lighting from './components/Lighting/Lighting'
import { StyledEngineProvider } from '@mui/material/styles';

import {
  BrowserRouter as Router,
  Switch,
  Route
} from "react-router-dom";

import { Layout } from 'antd';
const { Header, Footer, Content } = Layout;

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
    <StyledEngineProvider injectFirst>
    <homeContext.Provider value={stores}>
    <Router>
    <Layout style={{minHeight:"100vh"}}>
    <Header style={{backgroundColor: "#262626"}}><AppHeaderContent /></Header>
    <Content>
        <Switch>
              <Route path="/plugins/Shopping_content">
                <Shopping />
              </Route>
              <Route path="/plugins/ConfigEditor_content">
                <Editor/>
              </Route>
              <Route path="/plugins/LogViewer_content">
                <LogViewer />
              </Route>
              <Route path="/plugins/Lighting_content">
                <Lighting />
              </Route>
              <Route path="/">
                <Plugins/>
              </Route>
          </Switch>
    </Content>
    <Footer><Version /></Footer>
    </Layout>
    </Router>
    </homeContext.Provider>
    </StyledEngineProvider>
  );
}

export default App;

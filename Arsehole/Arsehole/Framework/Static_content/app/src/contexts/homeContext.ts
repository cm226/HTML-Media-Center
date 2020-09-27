import React from 'react'
import LoadedPlugin from '../stores/LoadedPlugins'
import serverTimeStore from '../stores/serverTimeStore'
import VersionStore from '../stores/VersionStore'
import RootURLStore from '../stores/RootURLStore'

export const homeContext = React.createContext({
  urlStore : new RootURLStore(),
  loadedPluginStore: new LoadedPlugin(),
  serverTimeStore : new serverTimeStore(),
  versionStore : new VersionStore()
})
import React from 'react'
import LoadedPlugin from '../stores/LoadedPlugins'
import serverTimeStore from '../stores/serverTimeStore'
import VersionStore from '../stores/VersionStore'

export const homeContext = React.createContext({
  loadedPluginStore: new LoadedPlugin(),
  serverTimeStore : new serverTimeStore(),
  versionStore : new VersionStore()
})
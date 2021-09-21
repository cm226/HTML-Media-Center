import React from 'react';
import {observer} from 'mobx-react'
import { homeContext } from '../contexts/homeContext'

import * as CSS from 'csstype';

function Plugins() {
        const store = React.useContext(homeContext)

        const contentstyle: CSS.Properties = {
            width : '100%'
        }

        const wrapperStyle: CSS.Properties = {
            width: '90%',
            margin : 'auto'
        }

        return (
            <div id="pluginContent" style={contentstyle}>
                <div style={wrapperStyle} dangerouslySetInnerHTML={{__html: store.loadedPluginStore.plugins}}></div>
            </div>
        );
    }   

export default (observer(Plugins));
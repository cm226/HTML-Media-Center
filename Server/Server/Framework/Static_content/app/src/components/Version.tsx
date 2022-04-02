import React from 'react';
import {observer} from 'mobx-react'
import { homeContext } from '../contexts/homeContext'

import * as CSS from 'csstype';

function Version() {
        const store = React.useContext(homeContext)

        const style: CSS.Properties = {
            textAlign : 'center'
          }

        return (
            <div style={style}>
                {store.versionStore.version}
            </div>
        );
    }   

export default (observer(Version));
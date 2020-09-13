import React from 'react';
import {observer} from 'mobx-react'
import { homeContext } from '../../contexts/homeContext'

import * as CSS from 'csstype';

function Shopping() {
        const store = React.useContext(homeContext);

        return (
            <div>
                List Chan
            </div>
        );
    }   

export default (observer(Shopping));
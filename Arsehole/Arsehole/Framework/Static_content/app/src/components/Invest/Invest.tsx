import React from 'react';
import {observer} from 'mobx-react'
import {homeContext} from '../../contexts/homeContext'
import Summary from './Summary'
import GainLoss from './GainLoss'

function Invest() {
    const home = React.useContext(homeContext);

    return (
        <div>
        <Summary gain_loss={10} day_change={10} value={10}/>
        <GainLoss />
        </div>
    )
};   

export default (observer(Invest));

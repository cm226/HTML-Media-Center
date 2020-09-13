import React ,{useEffect} from 'react';
import {observer} from 'mobx-react'
import {homeContext} from '../contexts/homeContext'

import * as CSS from 'csstype';
 

function Time() {
  const store = React.useContext(homeContext)

  useEffect(() => {
    const timer = setTimeout(() => {
      store.serverTimeStore.UpdateServerTime()
    }, 1000);
  });

  const style: CSS.Properties = {
    fontFamily : 'Roboto, sans-serif',
    fontSize : '40px',
    fontWeight : 1000
  }

  return (
    <div style={style}>
      {store.serverTimeStore.serverTime.getHours()} :
      {store.serverTimeStore.serverTime.getMinutes()} : 
      {store.serverTimeStore.serverTime.getSeconds()} 
    </div>
  );
}

export default (observer(Time));
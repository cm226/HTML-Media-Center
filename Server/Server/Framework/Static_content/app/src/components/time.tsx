import React ,{useEffect} from 'react';
import {observer} from 'mobx-react'
import {homeContext} from '../contexts/homeContext'

import * as CSS from 'csstype';
 

function Time() {
  const store = React.useContext(homeContext)

  useEffect(() => {
    setTimeout(() => {
      store.serverTimeStore.UpdateServerTime()
    }, 1000);
  });

  const style: CSS.Properties = {
    color :'white',
    fontFamily : 'Roboto, sans-serif',
    fontSize : '40px',
    fontWeight : 1000
  }

  return (
    <div style={style}>
      {store.serverTimeStore.serverTime.getHours().toString().padStart(2,'0')} :
      {store.serverTimeStore.serverTime.getMinutes().toString().padStart(2,'0')} : 
      {store.serverTimeStore.serverTime.getSeconds().toString().padStart(2,'0')} 
    </div>
  );
}

export default (observer(Time));
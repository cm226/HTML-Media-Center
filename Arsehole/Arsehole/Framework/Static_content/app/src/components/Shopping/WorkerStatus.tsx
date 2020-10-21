import React from 'react';
import {observer} from 'mobx-react'
import {WorkerStatusStore, Status} from './stores/WorkerStatusStore'

import * as CSS from 'csstype'

interface IProps{
    statusStore : WorkerStatusStore
}

function WrokerStatus(props : IProps) {



    let inputStyle : CSS.Properties ={
        position: "absolute",
        width: "100vw",
        background: "linear-gradient(180deg, rgba(15,217,0,1) 0%, rgba(0,0,0,0) 100%)",
        zIndex: -1,
        height: "20px"
      };
    
    if(props.statusStore.status === Status.OFFLINE){
        inputStyle.background = "linear-gradient(180deg, rgba(217,15,0,1) 0%, rgba(0,0,0,0) 100%)"
    }


    return (
        <div style={inputStyle}>
        </div>
    );
}   

export default observer(WrokerStatus);
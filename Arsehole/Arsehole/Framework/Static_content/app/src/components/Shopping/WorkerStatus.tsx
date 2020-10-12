import React from 'react';
import WorkerStatusStore from './stores/WorkerStatusStore'

interface IProps{
    statusStore : WorkerStatusStore
}

function WrokerStatus(props : IProps) {
    return (
        <div>
            {props.statusStore.status}
        </div>
    );
}   

export default (WrokerStatus);
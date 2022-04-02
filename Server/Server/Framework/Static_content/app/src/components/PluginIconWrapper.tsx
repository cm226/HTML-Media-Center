import React from 'react';
import LightbulbIcon from '@mui/icons-material/Lightbulb';
import LocalGroceryStoreIcon from '@mui/icons-material/LocalGroceryStore';

import * as CSS from 'csstype';

interface IProps {
    pluginName : string
}


function PluginIconWrapper(props : IProps) {   

    const largeIcon : CSS.Properties = {
        transform: 'scale(5)',
        margin : 'auto'
    }

    let icon = <LightbulbIcon style={largeIcon} />

    if(props.pluginName === 'Listu Chan'){
        icon = <LocalGroceryStoreIcon style={largeIcon}/>
    }
    return icon;
    }   

export default PluginIconWrapper;
import React from 'react';
import {observer} from 'mobx-react'
import Stack from '@mui/material/Stack/Stack';
import Card from '@mui/material/Card';
import CardContent from '@mui/material/CardContent';
import CardHeader from '@mui/material/CardHeader/CardHeader'
import Switch from '@mui/material/Switch';
import { CardActionArea } from '@mui/material';
import FormGroup from '@mui/material/FormGroup';
import FormControlLabel from '@mui/material/FormControlLabel';
import NightlightIcon from '@mui/icons-material/Nightlight';
import WbSunnyIcon from '@mui/icons-material/WbSunny';

import LightingStore, {light} from './LightingStore';

let store = new LightingStore();


interface LightProps {
    light : light
}

const Light = observer(function (props : LightProps){
    return <div style={{"margin" : "auto"}}>
        <CardHeader title={props.light.name}/>
        <img src={"/assets/lighting/" + (props.light.state === '0'?'off.png':'on.png')}/>
    </div>
});

function Lighting() {
    const classes = {
        root: {
            display: 'flex',
            flexDirection: 'column',
            alignItems: 'center',
            width : '100%',
            height: '100%'
        },
        stack: {
            flexGrow : '1',
            margin: 'auto'
        },
        form: {
            marginTop:'50px',
            marginLeft: 'auto',
            marginRight: 'auto',
            height: '50px',
            borderTop: 'solid 1px grey',
            width: '70%'
        }
    };
    return (
        <div style={classes.root as React.CSSProperties}>
            <Stack style={classes.stack} >
                {store.lights.map((light)=>{
                return <Card sx={{ minWidth: 150, maxWidth: 200 }}>
                <CardActionArea onClick={()=>{store.ToggleLight(light)}}>
                    <CardContent>
                        <Light light={light} />
                    </CardContent>
                </CardActionArea>
                </Card>
                })}
            </Stack>
            <div style={classes.form} >
                <div style={{margin:'auto', width:'fit-content'}}>
                    <span>Sleeping: </span>
                    <Switch 
                        checkedIcon={<NightlightIcon />}
                        icon={<WbSunnyIcon style={{color: 'black'}}/>}
                        checked={store.sleeping}
                        onChange={(event, checked)=>{store.setSleeping(checked)}}
                    />
                </div>
            </div>
        </div>
    );
    }

export default (observer(Lighting));
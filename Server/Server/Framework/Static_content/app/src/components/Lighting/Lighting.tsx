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
    return <div style={{"width" :"70%", "margin" : "auto"}}>
        <CardHeader title={props.light.name}/>
        <img src={"/assets/lighting/" + (props.light.state === '0'?'off.png':'on.png')}/>
    </div>
});

function Lighting() {
    const classes = {
        root: {
            display: 'flex',
            flexDirection: 'column',
            width : '100%',
            height: '100%'
        },
        stack: {
            flexGrow : '1'
        },
        footer: {
            background : 'black',
        },
        form: {
            margin: 'auto',
            height: '50px'
        }
    };
    return (
        <div style={classes.root as React.CSSProperties}>
            <h2>Lighting</h2>
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
            <div style={classes.footer}> 
                <div style={classes.form} >
                    <Switch 
                        checkedIcon={<NightlightIcon />}
                        icon={<WbSunnyIcon/>}
                        checked={store.sleeping}
                        onChange={(event, checked)=>{store.setSleeping(checked)}}
                    />
                </div>
            </div>
        </div>
    );
    }

export default (observer(Lighting));
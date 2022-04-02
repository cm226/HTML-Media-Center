import React, { useRef } from 'react';
import {observer} from 'mobx-react'
import { homeContext } from '../contexts/homeContext'
import Box from '@mui/material/Box';
import Grow from '@mui/material/Grow';
import Paper from '@mui/material/Paper';
import Grid from '@mui/material/Grid';
import Typography from '@mui/material/Typography/Typography';
import {
    Link
  } from "react-router-dom";
import LightbulbIcon from '@mui/icons-material/Lightbulb';

import * as CSS from 'csstype';
import { Container } from '@mui/material';
import PluginIconWrapper from './PluginIconWrapper';


function Plugins() {
        const store = React.useContext(homeContext)

        console.log("rendering plugins "+ store.loadedPluginStore.plugins)


        const containerHack : CSS.Properties = {
            paddingTop:'25px'
        }

        const cardStyle : CSS.Properties = {
            margin: 'auto',
            display: 'flex',
            flexDirection: 'column',
            alignItems: 'center',
            flexWrap: 'nowrap'
        }

        const largeIcon : CSS.Properties = {
            transform: 'scale(5)',
            margin : 'auto'
        }
 
        return (
            <Container style={containerHack}>
                <Grid container spacing={3}>
                {store.loadedPluginStore.plugins.map((plugin)=>{
                    return <Grid item xs>
                        <Grow in={true}>
                            <Link to={plugin.url}>
                            <Paper sx={{ width: 150, height : 200 }} elevation={4} style={cardStyle}>
                                <Typography variant="h6" textAlign='center'>
                                {plugin.name}
                                </Typography>
                                <PluginIconWrapper pluginName={plugin.name} />
                            </Paper>
                            </Link>
                        </Grow>
                    </Grid>
                })}
                </Grid>
                
                <div dangerouslySetInnerHTML={{__html: store.loadedPluginStore.widgits}}></div>
            </Container>
        );
    }   

export default (observer(Plugins));
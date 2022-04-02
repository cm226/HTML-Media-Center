import React from 'react';
import {observer} from 'mobx-react'
import { homeContext } from '../contexts/homeContext'
import Time from './time'
import * as CSS from 'csstype';
import SettingsIcon from '@mui/icons-material/Settings';
import FeedIcon from '@mui/icons-material/Feed';
import {Link} from "react-router-dom";

function AppHeaderContent() {
        const store = React.useContext(homeContext)        

        const headerStyle:CSS.Properties ={
            display:'flex',
            flexDirection:'row'
        }   

        const mainBox:CSS.Properties ={
            flexGrow:'1'
        };

        const Icons : CSS.Properties= {
            'verticalAlign': 'middle',
            'color': 'white',
            'marginRight' : '10px'
        }

        return (
            <div style={headerStyle}>
                <div style={mainBox}>
                    <Link to='/'>
                        <Time/>
                    </Link>
                </div>
                <div >
                    <Link to='/plugins/ConfigEditor_content'><SettingsIcon fontSize="medium" style={Icons}/></Link>
                    <Link to='/plugins/LogViewer_content'><FeedIcon fontSize="medium" style={Icons}/></Link>
                </div>
                
            </div>
        );
    }   

export default (observer(AppHeaderContent));
import React from 'react';
import {observer} from 'mobx-react'

import * as CSS from 'csstype';
import ConfigStore from '../Stores/ConfigStore';

let store = new ConfigStore();

function Editor() {
    
        const div_container : CSS.Properties ={
            width: "80%",
            margin: "auto"
          };

          const table_style : CSS.Properties = {
              marginLeft : "auto",
              marginRight : "auto"
          };

          const inputStyle : CSS.Properties ={
            height: "40px",
            borderRadius: "10px",
            borderWidth : "0px",
            boxShadow:"inset 1px 1px 4px 0px rgba(0,0,0,0.44)",
            width: "100%",
            fontSize: "1em",
            paddingLeft:"1em"
          };

        return (
            <div style={div_container}>
                <h2>Config</h2>
                <table style={table_style}>
                    <tbody>
                    <tr>
                        <td><label>DBName</label></td>
                        <td><input defaultValue={store.DBName} style={inputStyle} type="text" onBlur={(e)=>store.SetDBName(e.currentTarget.value)} ></input></td>
                    </tr>
                    <tr>
                        <td><label>DBUser</label></td>
                        <td><input defaultValue={store.DBUser} style={inputStyle} onBlur={(e)=>store.SetDBUser(e.currentTarget.value)} type="text"></input></td>
                    </tr>
                    <tr>
                        <td><label>DBPW</label></td>
                        <td><input defaultValue={store.DBPW} style={inputStyle} onBlur={(e)=>store.SetDBPW(e.currentTarget.value)} type="text"></input></td>
                    </tr>
                    <tr>
                        <td><label>MetOfficeKey</label></td>
                        <td><input defaultValue={store.MetOfficeKey} style={inputStyle} onBlur={(e)=>store.SetMetofficeKey  (e.currentTarget.value)} type="text"></input></td>
                    </tr>
                    </tbody>
                </table>
                
                <button disabled={!store.changed} onClick={()=>store.CommitConfig()}>Submit</button>
            </div>
        );
    }   

export default (observer(Editor));
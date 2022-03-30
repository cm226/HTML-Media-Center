import React from 'react';
import {observer} from 'mobx-react'
import { Button, Table, Tag } from 'antd';
import 'antd/dist/antd.css'

import LogStore from './LogStore';

let store = new LogStore();

const columns = [
    {
      title: 'TimeStamp',
      dataIndex: 'ts',
      key: 'ts',
      width: '200px',
    },
    {
      title: 'Severity',
      dataIndex: 'sev',
      key: 'sev',
      render: (sev:string) =>
          {
            let color = 'grey'
            if (sev === 'Warning') {
              color = 'yellow'
            } else if(sev === 'Error') {
                color = 'red'
            }
            return (
              <Tag color={color} key={sev}>
                {sev.toUpperCase()}
              </Tag>
            );
          }
    },
    {
      title: 'Message',
      dataIndex: 'msg',
      key: 'msg',
    },
  ];

function LoadMore() {
  store.SetNumEntries(store.LogSize + 50)
}

function LogViewer() {
    return (
        <div>
        <Table
            dataSource={store.logs}
            columns={columns}
            pagination={false}
            size="small"/>
        <Button type="primary" loading={store.loading} onClick={() => {LoadMore()}}>
            LoadMore
        </Button>
        </div>
    );
}   

export default (observer(LogViewer));
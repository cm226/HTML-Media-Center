#!/bin/bash

cd ../Server/Docker

sudo docker run -p 8442:8442 -v ~/mdbdata/Server:/var/lib/mysql -v /etc/localtime:/etc/localtime:ro --env build_type=Release media
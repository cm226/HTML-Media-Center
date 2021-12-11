#!/bin/bash

# Build a docker container with all the build tools inside
cd ../Server/Docker
sudo docker-compose -f docker-compose-dev.yml run --service-ports --rm media_dev
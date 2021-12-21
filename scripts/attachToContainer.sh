#!/bin/bash

read -p "Enter container ID " container
container=${container}
sudo docker exec -it ${container} bash
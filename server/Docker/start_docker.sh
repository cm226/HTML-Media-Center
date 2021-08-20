# this is a script desgned to be run on startup of the target machine 
# it starts the docker service if required, then starts the docker container. s

if [! systemctl  is-active --quiet docker]

echo 'starting docker service'
sudo systemctl start docker

fi

if [ sudo docker ps | grep media ]; then
  echo "containter already running not starting"
else
  echo "starting container"
  sudo docker run -p 8442:8442 -v ~/mdbdata/Server:/var/lib/mysql -t media
fi
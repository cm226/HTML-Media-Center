# Run this file to do a release build for deployment

if [ ! -f "test.crt" ] || [ ! -f "test.key" ]; then
    echo 'Missing certs for docker file, Downloading from NAS'
    source ./Util/FtpSSHFiles.sh
fi

read -p "Enter your Registry to push to [192.168.1.85]: " registry
registry=${registry:-192.168.1.85}
echo $registry

read -p "Enter the commit hash to use [origin/master]: " commit
commit=${commit:-origin/master}
echo $commit

sudo docker build --build-arg build_type=Release --build-arg buildCommit=$commit -t $registry:5000/media .


--target Develop
# If this command fails make sure you have added the repository as insecure 

# Create or edit /etc/docker/daemon.json and make sure it has the following:
# {
#     "insecure-registries" : [ "<<HOSTNAME>>:5000" ]
# }
# then restart docker : sudo service docker restart
sudo docker push $registry:5000/media
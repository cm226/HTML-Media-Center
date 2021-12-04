# Run this file to do a release build for deployment

if [ ! -f "test.crt" ] || [ ! -f "test.key" ]; then
    echo 'Missing certs for docker file, Downloading from NAS'
    source ./Util/FtpSSHFiles.sh
fi

sudo docker build --build-arg build_type=Release -t media_release .
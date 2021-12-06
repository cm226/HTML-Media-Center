# Build a docker container with all the build tools inside

sudo docker build --target Develop --build-arg build_type=Debug -t media_dev .
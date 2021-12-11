#!/bin/bash

# Runs the server in the container so that it can be debugged from vscode
# Run this script in the container and start the VS code debug config

pushd bin
gdbserver :9091 ./Server
popd
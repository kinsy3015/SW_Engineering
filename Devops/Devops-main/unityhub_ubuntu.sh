#!/bin/bash

sudo sh -c 'echo "deb https://hub.unity3d.com/linux/repos/deb stable main" > /etc/apt/sources.list.d/unityhub.list'
wget -qO - https://hub.unity3d.com/linux/keys/public | sudo apt-key add -
sudo apt update -y
sudo apt-get install unityhub -y

#reference site : 

#https://docs.unity3d.com/hub/manual/InstallHub.html#install-hub-linux

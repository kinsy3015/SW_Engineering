#!/bin/bash

sudo apt-get remove docker docker-engine docker.io containerd runc -y
sudo apt-get update -y

sudo apt-get install ca-certificates curl gnupg lsb-release -y

curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /usr/share/keyrings/docker-archive-keyring.gpg

echo \
  "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/docker-archive-keyring.gpg] https://download.docker.com/linux/ubuntu \
  $(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null




# install docker engine
# sudo apt-get update -y
#sudo apt-get install docker-ce docker-ce-cli containerd.io -y
#apt-cache madison docker-ce
#sudo apt-get install docker-ce=<VERSION_STRING> docker-ce-cli=<VERSION_STRING> containerd.io
#sudo docker run hello-world




# upgrade docker engine
# https://download.docker.com/linux/ubuntu/dists/
# sudo dpkg -i /path/to/package.deb
# sudo docker run hello-world


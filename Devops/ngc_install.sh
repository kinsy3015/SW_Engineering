#!/bin/bash
echo ngc API Key Location : nvidia-developer, setup, Generate Key 

curl https://get.docker.com | sh  && sudo systemctl start docker && sudo systemctl enable docker

distribution=$(. /etc/os-release;echo $ID$VERSION_ID) && curl -s -L https://nvidia.github.io/nvidia-docker/gpgkey | sudo apt-key add - && curl -s -L https://nvidia.github.io/nvidia-docker/$distribution/nvidia-docker.list | sudo tee /etc/apt/sources.list.d/nvidia-docker.list

sudo apt-get install -y nvidia-docker2 $ sudo systemctl restart docker

sudo apt-get update

# check install docker-nvidia command : sudo docker run --rm --gpus all nvidia/cuda:11.0-base nvidia-smi

wget -O ngccli_cat_linux.zip https://ngc.nvidia.com/downloads/ngccli_cat_linux.zip && unzip -o ngccli_cat_linux.zip && chmod u+x ngc

md5sum -c ngc.md5

echo "export PATH=\"\$PATH:$(pwd)\"" >> ~/.bash_profile && source ~/.bash_profile

# ngc config set

# sudo docker login nvcr.io



sudo apt-get install virtualenv -y
sudo apt-get install virtualenvwrapper -y

sudo apt-get install python3-pip -y

export VIRTUALENVWRAPPER_PYTHON=/usr/bin/python3



sudo pip3 install virtualenvwrapper
sudo pip3 install virtualenv
source `which virtualenvwrapper.sh`
export WORKON_HOME=~/.virtualenvs

sudo pip3 install jupyter


wget --content-disposition https://api.ngc.nvidia.com/v2/resources/nvidia/tao/cv_samples/versions/v1.2.0/zip -O cv_samples_v1.2.0.zip
 unzip -u cv_samples_v1.2.0.zip  -d ./cv_samples_v1.2.0 && rm -rf cv_samples_v1.2.0.zip && cd ./cv_samples_v1.2.0


jupyter notebook --ip 0.0.0.0 --port 8888 --allow-root




# reference site : 


# https://github-wiki-see.page/m/pantelis-classes/omniverse-ai/wiki/TAO-%28NVIDIA-Train%2C-Adapt%2C-and-Optimize%29

# https://eehoeskrap.tistory.com/526

# https://developer.nvidia.com/blog/real-time-redaction-app-nvidia-deepstream-part-1-training/

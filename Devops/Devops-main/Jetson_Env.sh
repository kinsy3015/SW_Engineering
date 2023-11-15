#!/bin/bash
# Jetpack 4.6



sudo apt-get update -y

sudo apt-get upgrade -y

sudo apt-get install python-pip -y

sudo -H pip install -U jetson-stats

sudo apt-get install dphys-swapfile -y

wget https://github.com/Qengineering/Install-OpenCV-Jetson-Nano/raw/main/OpenCV-4-5-4.sh

wget https://nvidia.box.com/shared/static/p57jwntv436lfrd78inwl7iml6p13fzh.whl -O torch-1.8.0-cp36-cp36m-linux_aarch64.whl

sudo apt-get install python3-pip libopenblas-base libopenmpi-dev -y

pip3 install Cython
pip3 install numpy torch-1.8.0-cp36-cp36m-linux_aarch64.whl

sudo apt-get install libjpeg-dev zlib1g-dev libpython3-dev libavcodec-dev libavformat-dev libswscale-dev -y

git clone --branch v0.9.0 https://github.com/pytorch/vision torchvision

cd torchvision

export BUILD_VERSION=0.9.0

python3 setup.py install --user

cd ..

sudo apt-get install lightdm -y

sudo apt-get purge gdm3 -y

# ubuntu startup-application cli :
# gnome-session-properties 

# gsettings set org.gnome.Vino require-encryption false
# sudo ufw allow from 192.168.0.133 to any port 5900 proto tcp

# sudo apt-get install dconf-editor -y

# OR if you haven't installed vino yet, do both together:

# sudo apt-get install vino dconf-editor

# CONFIGURATION:

# a. Open dconf-editor, then:
# b. VNC settings can be accessed under org -> gnome -> desktop  -> remote-access


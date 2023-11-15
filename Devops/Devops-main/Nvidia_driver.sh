#!/bin/bash
# this method of manually install nvidia-driver

echo "go nvidia-driver install homepage and compatablie version download"


sudo /etc/init.d/lightdm stop

sudo vim /etc/modprobe.d/blacklist.conf

# add line blacklist nouveau

echo options nouveau modeset=0 | sudo tee -a /etc/modprobe.d/nouveau-kms.conf


sudo update-initramfs -u

sudo add-apt-repository ppa:graphics-drivers/ppa
sudo apt-get update -y
echo "Please enter your nvidia-driver-xxx sudo apt-get install"

https://drive.google.com/file/d/19sS1aPK7c6zpP1QTBCObvPFiF1YEVjgn/view?usp=sharing
echo "Please disable security booting"https://drive.google.com/file/d/19s

#reference site :https://forums.developer.nvidia.com/t/ubuntu-18-04-login-loop-after-installing-nvidia-driver/81280

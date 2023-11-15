#!/bin/bash


echo this scripts must after execute Nvidia_install.sh scripts

# env : ubuntu 18.04
# gpu card : GeForce GTX 1060
# cuda compate version : Pascal( 6.0 )
# cuda toolkit compate version : 8.0
sudo apt-get update
sudo apt-get install dkms -y
sudo apt install libglvnd-dev -y 

sudo add-apt-repository ppa:graphics-drivers/ppa
# sudo ubuntu-drivers autoinstall



# ./cuda_8.0.61_375.26_linux.run --tar mxvf
# sudo cp cuda/InstallUtils.pm /usr/lib/x86_64-linux-gnu/perl-base/

# sudo bash cuda_8.0.61_375.26_linux.run --override

# only nvidia-375 not install !!

# 






#### Nvidia driver remove method
# sudo apt-get purge nvidia*
# sudo apt-get autoremove
# sudo apt-get autoclean

#### CUDA remove method
# sudo rm -rf /usr/local/cuda*
# sudo apt-get --purge remove 'cuda*'
# sudo apt-get autoremove --purge 'cuda*'

# check !!
# sudo dpkg -l | grep nvidia
# sudo apt-get remove --purge ...
# sudo dpkg -l | grep cuda
# sudo apt-get remove --purge ...


# reference site : 
# https://rodrigodzf.github.io/setup/cuda/2019/04/15/cuda-setup.html
# https://forums.developer.nvidia.com/t/ubuntu-18-04-login-loop-after-installing-nvidia-driver/81280
# https://hyunsoft.tistory.com/m/entry/%EB%A6%AC%EB%88%85%EC%8A%A4-nvidia-driver-%EC%9E%AC%EC%84%A4%EC%B9%98-%EC%98%A4%EB%A5%98
# https://forums.developer.nvidia.com/t/ubuntu-18-04-login-loop-after-installing-nvidia-driver/81280

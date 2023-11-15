#!/bin/bash


sudo apt-get update && sudo apt-get upgrade -y
sudo apt-get install vim tmux cmake make gcc ibus-hangul build-essential docker.io -y
sudo add-apt-repository multiverse
sudo apt-get update
sudo apt install ubuntu-restricted-extras -y
sudo apt autoremove -y

sudo echo -e "set number \ncolo darkblue \nsyntax on" >> ~/.vimrc

ibus restart

#!/bin/bash

sudo apt-get install openssh-server -y

sudo apt-get install ufw -y

sudo update-rc.d ssh defaults

systemctl enable ssh.socket

sudo ufw enable

sudo ufw allow 22/tcp

sudo ufw allow 5900

sudo echo -e "sudo service ssh start" >> ~/.bashrc

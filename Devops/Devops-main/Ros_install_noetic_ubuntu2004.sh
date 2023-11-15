#!/bin/bash

sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'

sudo apt install curl -y # if you haven't already installed curl

curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo apt-key add -

sudo apt update -y

sudo apt install ros-noetic-desktop-full -y

sudo apt install ros-noetic-slam-gmapping -y

echo "source /opt/ros/noetic/setup.bash" >> ~/.bashrc

source ~/.bashrc

sudo apt install python3-rosdep python3-rosinstall python3-rosinstall-generator python3-wstool build-essential -y

sudo apt install python3-rosdep -y

sudo rosdep init

rosdep update

#mkdir -p ~/catkin_ws/src

#cd ~/catkin_ws

#source ~/.bashrc

#catkin_make

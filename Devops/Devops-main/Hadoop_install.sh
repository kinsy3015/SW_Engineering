#!/bin/bash
# env version ubuntu18.04
sudo addgroup --gid 2021 hdfs
sudo addgroup --gid 2022 yarn
sudo useradd --create-home --shell /bin/bash --uid 2021 --gid 2021 hdfs
sudo useradd --create-home --shell /bin/bash --uid 2022 --gid 2022 yarn
echo "enter hdfs password"
sudo passwd hdfs
echo "enter yarn password"
sudo passwd yarn
sudo mkdir -p /data/hdfs/namenode && sudo mkdir -p /data/hdfs/jornalnode && sudo chown -R hdfs:hdfs /data/hdfs && sudo mkdir -p /data/yarn && sudo chown -R yarn:yarn /data/hdfs
sudo mkdir -p /data/hdfs/datanode && sudo chown -R hdfs:hdfs /data/hdfs && sudo mkdir -p /data/yarn && sudo chown -R yarn:yarn /data/yarn
ssh-keygen ssh-copy-id {hostname}



wget https://dlcdn.apache.org/hadoop/common/hadoop-3.3.1/hadoop-3.3.1-src.tar.gz
wget https://dlcdn.apache.org/hadoop/common/hadoop-3.3.1/hadoop-3.3.1.tar.gz
tar xf hadoop-3.3.1-src.tar.gz
sudo apt-get install -y openjdk-8-jdk

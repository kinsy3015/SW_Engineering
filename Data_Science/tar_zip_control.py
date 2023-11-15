import zipfile
import tarfile
import sys
import os

import shutil

import torch
from torch.utils.data import Dataset, DataLoader

path_prefix = '/home/shkim/Data/AIHUB/'

path_to_zip_file = ''
directory_to_extract_zip = ''

path_to_tar_exist_dir = 'Training/'
directory_to_extract_tar = 'Training_untar/'

str_src = '[원천]'
str_label = '[라벨]'


class ArgosDataset(Dataset):
    def __init__(self, t):
        self.t = t

    def __len__(self):
        return self.t

    def __getitem__(self, idx):
        return torch.LongTensor([idx])

def get_members(tar, prefix):
    if not prefix.endswith('/'):
        prefix += '/'
    offset = len(prefix)
    for tarinfo in tar.getmembers():
        if tarinfo.name.startswith(prefix):
            tarinfo.name = tarinfo.name[offset:]
            yield tarinfo


def ZiptoUnzip(path):
    zip_ref = zipfile.ZipFile(path, 'r')
    zip_ref.extractall(directory_to_extract_zip)


def TartoUntar_dir(old_path, new_path):


    file_list = os.listdir(old_path)
    for file in file_list:
        filename, fileExtension = os.path.splitext(file)
        if fileExtension == '.tar' and filename[0:4] == str_src :
            print('find [원천] tar file and untar')
            tar = tarfile.open( old_path + file )
            tar.extractall(new_path + filename)
        if fileExtension == '.tar' and filename[0:4] == str_label :
            print('find [라벨] tar file and untar')
            tar = tarfile.open( old_path + file )
            tar.extractall(new_path + filename)
            src = new_path + filename + '/' + filename[4:] + '/'
            print(src)
            json_list = os.listdir(src)
            for json in json_list:
                filename1, fileExtension1 = os.path.splitext(json)
                if fileExtension1 == '.json':
                    dir = new_path + filename + '/'
                    shutil.move(src + json , dir + json)
                    print(src + json)
                    print(dir + json)


            if os.path.exists(src):
                shutil.rmtree(src)






old_path_dir = path_prefix + path_to_tar_exist_dir
new_path_dir = path_prefix + directory_to_extract_tar


TartoUntar_dir(old_path_dir, new_path_dir)

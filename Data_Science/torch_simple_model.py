import torch
import torch.nn as nn
import torch.nn.functional as F
import torchvision


class Flatten(nn.Module):
    def forward(self, input):
        return input.view(input.size(0),-1)


vgg16_torch = nn.Sequential(
    nn.Conv2d(3, 64, 3),
    nn.ReLU(),
    nn.Conv2d(64, 64, 3),
    nn.ReLU(),
    nn.MaxPool2d(2,2),
    nn.Conv2d(64, 128, 3),
    nn.ReLU(),
    nn.Conv2d(128, 128, 3),
    nn.ReLU(),
    nn.MaxPool2d(2,2),
    nn.Conv2d(128, 256, 3),
    nn.ReLU(),
    nn.Conv2d(256, 256, 3),
    nn.ReLU(),
    nn.Conv2d(256, 256, 3),
    nn.ReLU(),
    nn.MaxPool2d(2, 2),
    nn.Conv2d(256, 512, 3),
    nn.ReLU(),
    nn.Conv2d(512, 512, 3),
    nn.ReLU(),
    nn.Conv2d(512, 512, 3),
    nn.ReLU(),
    nn.MaxPool2d(2, 2),
    nn.Conv2d(512, 512, 3),
    nn.ReLU(),
    nn.Conv2d(512, 512, 3),
    nn.ReLU(),
    nn.Conv2d(512, 512, 3),
    nn.ReLU(),
    nn.MaxPool2d(2, 2),
    nn.ReLU(),
    Flatten(),
    nn.Linear(512, 256),
    nn.ReLU(),
    nn.Dropout(0.5),
    nn.Linear(256, 1000)
)





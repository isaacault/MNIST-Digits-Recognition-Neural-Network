# MNIST Digits Recognition Neural Network

This is my first neural netowrk. The purpose of this project is to familiarize myself with the concepts of neural networks (such as backpropogation using using gradient descent) as well as implement features that I have worked on in school but never on a personal project (forking, shared memory, mutexes, and template classes) by creating a C++ program that can recognize hand written digits.

## Current State

The neural network is fully functional, however the learning rate is slow. By modifying BATCH_SIZE in defs.h to 1, it takes ~58 iterations for the network to get the correct answer. Leaving as is, after 10 000 iteration on a batch size of 100, the network attained a success rate of 41% on the final iteration.

## Future Plans

The first step to improve the network will be to decrease the time to convergence. There are numerous steps to this, but the first to begin looking at invlove
    * Optimizing the algorithm and code
    * Potentially forking the network into multiple networks that each handle their own batch, and then morphing/collapsing these into one master network

Other future plans include creating a GUI that will display images of the digits being read, and perhaps create a program to scan images and feed them into the network.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

A C++ Compiler such as GCC's G++


### Compiling

Open the project folder in terminal and execute "make".


### Executing

The binary will be called "network". To execute, run "./network".




## Built With

* [Ubuntu 18](https://www.ubuntu.com/download/desktop) - The OS used
* GCC 7.3.0 - GNU Compiling Collection version used


## Authors

* **Isaac Ault** - [isaacault](https://github.com/isaacault)

See also the list of [contributors](https://github.com/isaacault/MNIST-Digits-Recognition-Neural-Network/contributors) who participated in this project.


## Acknowledgments

* [Vinh Nguyen](https://www.youtube.com/watch?v=KkwX7FkLfug) for providing a tutorial to follow along and create a base neural network
* [3Blue1Brown](https://www.youtube.com/channel/UCYO_jab_esuFRV4b17AJtAw) for inspiration into the topic

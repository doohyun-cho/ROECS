# ROECS: Robust Online Extrinsics Correction for the Surround-view system


# 0. Dataset at
\\\\10.50.20.16\LDP_Team\CORETF\ROECS_dataset

# 1. Prerequisites
We have tested the library in **Ubuntu 20.04**, but it should be easy to compile in other platforms.

## C++14 Compiler
We use the new thread and chrono functionalities of C++14.

## Sophus
This is an Lie algebra library. More details can be found in https://github.com/strasdat/Sophus.

## OpenCV
We use [OpenCV](http://opencv.org) to manipulate images and features. Dowload and install instructions can be found at: http://opencv.org. version 4.4.0.

## Eigen3
Download and install instructions can be found at: http://eigen.tuxfamily.org.

## g2o
We use [g2o](https://github.com/RainerKuemmerle/g2o) library to perform non-linear optimizations.

# 2. Building the project
```
cd ROECS/
mkdir build
cd build
cmake ..
make
```
There has been no rules for "make install" yet, so if you want to use the library in other project, maybe you can copy the headers and the lib file to system path by hand.

# 3. Run the project
After compile and build the project, some executable files will be stored in the ./bin/ .


**For the correction process:**
```
./bin/main_pipeline  ./data_path  
```

# https://jaggu-iitm.medium.com/setting-up-deep-learning-with-cuda-tensorflow-and-keras-on-arch-linux-with-dual-gpu-nvidia-gpu-82963d2ecb75


# https://www.jeremymorgan.com/tutorials/linux/how-to-opencv-cuda-arch-linux/
# https://bbs.archlinux.org/viewtopic.php?id=291002
# https://medium.com/@vanshkathnawal0942/deep-learning-and-python-with-tensorflow-gpu-setup-on-arch-linux-the-easy-way-81097a82fa8c

#  sudo pacman -S opencv-cuda
# import cv2
#
# print("OpenCV version:", cv2.__version__)
# print("CUDA supported:", cv2.cuda.getCudaEnabledDeviceCount() > 0)
#
# pip install opencv-python
#
# gpg --keyserver keyserver.ubuntu.com --recv-key 04C367C218ADD4FF
# git clone https://aur.archlinux.org/python2.git && cd python2
# makepkg -si
#
# sudo pacman -S base-devel cmake git python python-numpy python-opencv openmpi python-mpi4py boost
# sudo pacman -S nvidia nvidia-utils nvidia-settings cuda
# lspci -v | grep VGA
# git clone https://github.com/opencv/opencv.git
# git clone https://github.com/opencv/opencv_contrib.git
# /src/opencv
# /src/opencv_contrib
# /src/build
# cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D CMAKE_PREFIX_PATH=/usr/lib
# \  -D OPENCV_EXTRA_MODULES_PATH=../opencv_contrib/modules -D WITH_CUDA=ON -D CUDA_ARCH_BIN=8.9  \
# -D ARCH=sm_89  \
# -D gencode=arch=compute_89,code=sm_89  \
#
#
#


from numba import jit, cuda
import numpy as np
# to measure exec time
from timeit import default_timer as timer   

# normal function to run on cpu
def func(a):                                
    for i in range(10000000):
        a[i]+= 1      

# function optimized to run on gpu 
@jit(target_backend='cuda')                         
def func2(a):
    for i in range(10000000):
        a[i]+= 1
if __name__=="__main__":
    n = 10000000                            
    a = np.ones(n, dtype = np.float64)
    
    start = timer()
    func(a)
    print("without GPU:", timer()-start)    
    
    start = timer()
    func2(a)
    print("with GPU:", timer()-start)
    
    

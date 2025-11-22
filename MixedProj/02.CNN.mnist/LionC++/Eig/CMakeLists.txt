cmake_minimum_required(VERSION 4.0)
project(Eig)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(main.cu
        gpuBackend.cuh
        kernels.cu
        KERNELS.cuh
        layer_types.cuh
        load_mnist.cuh
        loadcsv.cuh
        main.cu
        matrix.cu
        matrix.cuh
        NeuralNetwork.cuh
        typedefs.cuh
        utility.cuh
        main.cu)

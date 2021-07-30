project(cuda_sample_program)
cmake_minimum_required(VERSION 3.1)                                                                                                                                                                         
find_package(CUDA)
cuda_add_executable(main vector_add.cu OPTIONS)
# cuda_add_executable(main vector_add.cu OPTIONS -G)# -G is the option for debug in cuda-gdb
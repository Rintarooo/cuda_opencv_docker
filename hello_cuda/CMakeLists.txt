project(cuda_sample_program)
cmake_minimum_required(VERSION 3.1)                                                                                                                                                                         
find_package(CUDA)

# set(CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS};-gencode arch=compute_20,code=sm_20)
# cuda_compile(exe vector_add.cu OPTIONS -G)
cuda_add_executable(exe vector_add.cu OPTIONS -G)# -G is the option for debug in cuda-gdb
cmake_minimum_required(VERSION 3.0.2)
project(imcv)

## Compile as C++11
add_compile_options(-std=c++11)

find_package(OpenCV REQUIRED)
set(CMAKE_CUDA_COMPILER  /usr/local/cuda/bin/nvcc)
find_package(CUDA REQUIRED)

include_directories(
  ${OpenCV_INCLUDE_DIRS}
  ${CUDA_INCLUDE_DIRS}
)

# add_subdirectory(src/directory)

## cuda_add_library() is same as cuda_add_executable() except that a library is created.
# cuda_add_library(cuda_node src/lib_cuda_code.cu src/libe_none_cuda_code.cpp )

## create executable file named "main"
cuda_add_executable(main
  main.cpp)

target_link_libraries(main
  ${OpenCV_LIBRARIES}
  ${CUDA_LIBRARIES}
)


message("-- CUDA --")
message("Version: " ${CUDA_VERSION})
message("Library: " ${CUDA_CUDA_LIBRARY})
message("Runtime: " ${CUDA_CUDART_LIBRARY})
message("Library: " ${CUDA_INCLUDE_DIRS})

MESSAGE(WARNING "prefix ${CMAKE_PREFIX_PATH}")    
MESSAGE(WARNING "version ${OpenCV_VERSION}")
MESSAGE(WARNING "install path ${OpenCV_INSTALL_PATH}") 
MESSAGE(WARNING "config path ${OpenCV_CONFIG_PATH}") # look at the output of this message
MESSAGE(WARNING "include dirs ${OpenCV_INCLUDE_DIRS}")
MESSAGE(WARNING "libs ${OpenCV_LIBS}")

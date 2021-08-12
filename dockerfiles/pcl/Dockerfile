FROM rin/cuda:10.1-cudnn7-ubuntu18.04-opencv3.4.11-CC5.0-gdb

# ======== Installing VTK ========
RUN apt-get update && apt-get install -y \
    libxt-dev 

RUN wget https://www.vtk.org/files/release/8.2/VTK-8.2.0.tar.gz \
    && tar -xf VTK-8.2.0.tar.gz \
    && cd VTK-8.2.0 && mkdir build && cd build \
    && cmake .. -DVTK_MODULE_ENABLE_VTK_RenderingContextOpenGL2=YES \
                -DCMAKE_BUILD_TYPE=Release \
    && make -j$(nproc) \
    && make install


# ======== Installing PCL library ========
# WORKDIR /tmp
ENV PCL_VERSION="1.11.0"
# ENV PCL_VERSION="1.8.1"
# ENV PCL_VERSION="1.9.1"

# PCL dependencies
RUN apt-get install -y \
    libeigen3-dev \
    libflann-dev \
    libglu1-mesa-dev \
    freeglut3-dev \
    mesa-common-dev \
    libboost-all-dev \
    libusb-1.0-0-dev \
    libusb-dev \
    libopenni-dev \
    libopenni2-dev \
    libpcap-dev \
    libpng-dev \
    mpi-default-dev \
    openmpi-bin \
    openmpi-common \
    libqhull-dev \
    libgtest-dev

RUN wget https://github.com/PointCloudLibrary/pcl/archive/pcl-${PCL_VERSION}.tar.gz \
    && tar -xf pcl-${PCL_VERSION}.tar.gz \
    && cd pcl-pcl-${PCL_VERSION} \
    && mkdir build \
    && cd build \
    && cmake .. -DCMAKE_BUILD_TYPE=Release \
                -DVTK_RENDERING_BACKEND=OpenGL2 \
                -DWITH_CUDA:BOOL=ON \
    && make -j$(nproc)\
    && make install
                # -DBUILD_CUDA=ON \
                # -DBUILD_GPU=ON \

RUN apt-get update && apt-get install -y pcl-tools


## ======== install sublime text ==========
RUN wget -qO - https://download.sublimetext.com/sublimehq-pub.gpg | sudo apt-key add -
RUN sudo apt-get install apt-transport-https
RUN echo "deb https://download.sublimetext.com/ apt/stable/" | sudo tee /etc/apt/sources.list.d/sublime-text.list
RUN sudo apt-get update
RUN sudo apt-get install sublime-text
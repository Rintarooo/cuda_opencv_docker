# Docker for CUDA enabled OpenCV


modify `dockerfiles/Dockerfile` depending on your environment
(such as your desired OpenCV version, Compute Capability(CC) of your GPU).
```bash
docker build -t $(id -un)/cuda:10.1-cudnn7-ubuntu18.04-opencv3.4.11-CC5.0 ./dockerfiles/
```
<br>

make sure you built successfully
```bash
docker images | head
```
<br>

run container, -v option is for mounting your local dir `$HOME/coding` into `/opt/`
```bash
docker run --rm -it --runtime=nvidia -v $HOME/coding/:/opt $(id -un)/cuda:10.1-cudnn7-ubuntu18.04-opencv3.4.11-CC5.0
```
<br>

## CUDA enabled OpenCV

```bash
cd lenna
```
<br>

build sample source code
```bash
./run.sh
```
<br>

```bash
./build/main lenna.png
```
<br>

you can successfully see `Result.png` generated in `lenna`
<br>

## CUDA
check installed cuda version
```bash
nvcc -V
```
<br>


```bash
cd hello_cuda
```
<br>

build [sample source code](https://cuda-tutorial.readthedocs.io/en/latest/tutorials/tutorial01/)
```bash
nvcc vector_add.cu
```
<br>

if you want debug with `cuda-gdb`, 
```bash
nvcc -G vector_add.cu
```
<br>

run `cuda-gdb` 
```bash
cuda-gdb a.out
```
<br>

set breakpoint at kernel function `vector_add`, which is kernel function name(not filename) 
```bash
(cuda-gdb) b vector_add
```
<br>

start program
```bash
(cuda-gdb) r
```
<br>


run
```bash
./a.out
```

you can successfully see the output, `3.000000`
<br>


## Environment
I leave my own environment below. 
* OS:
	* Linux(Ubuntu 20.04.2 LTS) 
* GPU:
	* NVIDIA® GeForce® GTX TITAN X
* CPU:
	* Intel® Core i9-7920X CPU @ 2.90GHz
	* `$ nproc` outputs 24	
* NVIDIA® Driver = 460.91.03
* Docker = 20.10.7
* [nvidia-docker2](https://github.com/NVIDIA/nvidia-docker)(for GPU)



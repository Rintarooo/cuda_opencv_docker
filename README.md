# Docker for CUDA enabled OpenCV

make sure you've already installed nvidia-docker2
<br>


```bash
cd dockerfiles
```
<br>

modify `dockerfiles/Dockerfile` depending on yout environment.
```bash
docker build -t $(whoami)/cuda:10.1-cudnn7-ubuntu18.04-opencv3.4.11-CC5.0 ./
```
<br>

make sure you built successfully
```bash
docker images | head
```
<br>

run container
```bash
docker run --rm -it --runtime=nvidia -v $HOME/coding/:/opt $(whoami)/cuda:10.1-cudnn7-ubuntu18.04-opencv3.4.11-CC5.0
```
<br>

```bash
cd lenna
```
<br>

build source code
```bash
./run.sh
```
<br>

```bash
./build/main lenna.png
```
<br>


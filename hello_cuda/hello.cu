#include <stdio.h>

__global__ void cuda_hello(){
    printf("Hello World from GPU!\n");
}

int main() {
    // kernel function name <<< number of block, number of thread >>> (arguments)
    cuda_hello<<<1,1>>>();
    
    // https://qiita.com/JmpM/items/ada670ec80be9566269e
    // CPU waits for GPU operation
    cudaDeviceSynchronize();
    return 0;
}
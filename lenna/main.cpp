#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/version.hpp>

#include <opencv2/core/cuda.hpp>
#include<opencv2/cudaimgproc.hpp>
#include <opencv2/cudaarithm.hpp>
 
int main (int argc, char* argv[])
{
    if (argc < 2){
        std::cerr << "argc: " << argc << "should be 2";
        return 1;
    }
    try
    {
        // cv::Mat src_host = cv::imread("lena.png");
        cv::Mat src_host = cv::imread(argv[1]);
        if (src_host.empty()) {
            std::cout << "failed to load image." << std::endl;
            return 1;
        }
        std::cout << "loaded image size: " << src_host.size() << std::endl;
        cv::cuda::GpuMat dst, src;
        src.upload(src_host);
 
        // // cuda operation
        cv::cuda::threshold(src, dst, 120, 255, cv::THRESH_BINARY);
        // cv::cuda::cvtColor(src, dst, cv::COLOR_BGR2GRAY);
        // cv::cuda::resize(src, dst, cv::Size(300, 300));
 
        cv::Mat result_host;
        dst.download(result_host);

        cv::imwrite("Result.png", result_host);
        
        // cv::imshow("Result", result_host);
        // cv::waitKey();
    }
    catch(const cv::Exception& ex)
    {
        std::cout << "Error: " << ex.what() << std::endl;
    }
    return 0;
}


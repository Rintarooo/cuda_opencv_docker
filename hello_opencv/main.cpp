#include <iostream>
#include <opencv2/opencv.hpp>
 
int main (int argc, char* argv[])
{
    if (argc < 2){
        std::cerr << "argc: " << argc << "should be 2";
        return 1;
    }
    try
    {
        cv::Mat src = cv::imread(argv[1]);
        if (src.empty()) {
            std::cout << "failed to load image." << std::endl;
            return 1;
        }
        std::cout << "loaded image size: " << src.size() << std::endl;
        cv::Mat dst = src.clone();
        for(int y = 0; y < src.rows; ++y){
            for(int x = 0; x < src.cols; ++x){
                cv::Vec3b bgr = src.at<cv::Vec3b>(y, x);
                unsigned int b = bgr[0];
                unsigned int g = bgr[1];
                unsigned int r = bgr[2];
                dst.at<cv::Vec3b>(y, x)[0] = b;
                dst.at<cv::Vec3b>(y, x)[1] = 0;
                dst.at<cv::Vec3b>(y, x)[2] = 0;
            }
        }
        cv::imwrite("Result.png", dst);// only blue color
        
        // cv::imshow("Result", dst);
        // cv::waitKey();
    }
    catch(const cv::Exception& ex)
    {
        std::cout << "Error: " << ex.what() << std::endl;
    }
    return 0;
}


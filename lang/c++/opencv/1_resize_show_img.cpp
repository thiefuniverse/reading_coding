#include <iostream>
#include <opencv2/opencv.hpp>   
#include <opencv2/highgui/highgui.hpp>
#include <unistd.h>

using namespace std;
using namespace cv;

//图片的缩小与放大
int main(int argc, char* argv[])
{
    if (argc < 2 ) {
        std::cout<<"you need one image argument."<<std::endl;
        return 1;
    }
    if (access(argv[1], F_OK) == -1) {
        std::cout<<"file path not valid"<<std::endl;
        return 0;
    }
    Mat img = imread(argv[1], IMREAD_GRAYSCALE);
    if (img.empty()) {
        std::cout<<"load img error"<<std::endl;
        return 1;
    }
    char *window_name = "show_img";
    namedWindow(window_name);


    // for (int i = 0; i < img.rows; i++) {
    //     for (int j = 0; j < img.cols; j++) {
    //         // std::cout<<"img["<<i<<"]["<<j<<"]="<<img.at(i,j, 0)<<std::endl;
            
    //     }
    // }
    
    Mat dst = Mat::zeros(512, 512, CV_8UC3);
    resize(img, dst, dst.size());

    imshow("尺寸调整之后", dst);

    waitKey(0);
    destroyWindow(window_name);

}
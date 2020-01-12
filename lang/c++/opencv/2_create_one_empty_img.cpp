#include <iostream>
#include <opencv2/opencv.hpp>   
#include <opencv2/highgui/highgui.hpp>
#include <unistd.h>

using namespace std;
using namespace cv;

//图片的缩小与放大
int main(int argc, char* argv[])
{
    Mat img(800,600, CV_8UC3, Scalar(255,0,255));
    if (img.empty()) {
        std::cout<<"load img error"<<std::endl;
        return 1;
    }
    char *window_name = "show_img";
    namedWindow(window_name);
    
    Mat dst = Mat::zeros(512, 512, CV_8UC3);
    resize(img, dst, dst.size());

    imshow("尺寸调整之后", dst);

    waitKey(0);
    destroyWindow(window_name);

}
#include <iostream>
#include <opencv2/opencv.hpp>   
#include <opencv2/highgui/highgui.hpp>
#include <unistd.h>

using namespace std;
using namespace cv;

//图片的缩小与放大
int main(int argc, char* argv[])
{
    if (argc < 3 ) {
        std::cout<<"Usage:  "<<argv[0]<<" img_input  img_output"<<std::endl;
        
        std::cout<<"you missed arguments."<<std::endl;
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

    Mat dst = Mat::zeros(512, 512, CV_8UC3);
    resize(img, dst, dst.size());
    bool ret = imwrite(argv[2], dst);
    if (!ret) {
        std::cout<<"write img error"<<std::endl;
        return 1;
    }

    imshow("尺寸调整之后", dst);

    waitKey(0);
    destroyWindow(window_name);

}
#include <iostream>
#include <opencv2/opencv.hpp>   
#include <opencv2/highgui/highgui.hpp>
#include <unistd.h>

using namespace std;
using namespace cv;

void modifyMat(Mat& m, int w, int h, int c, int modify) {
    Mat n;
    m.copyTo(n);
    for (int i = 0; i < w; i ++) {
        for (int j = 0; j < h; j ++) {
            for (int z = 0; z < c; z++) {
                int v = (*n.ptr(i, j, z));
                v += modify;
                if (v < 0 ) {
                    v = 0;
                }
                if ( v > 255) {
                    v = 255;
                }
                *n.ptr(i, j, z) = v;
            }
        }
    }
    std::cout<<"one time"<<std::endl;
    
    n.copyTo(m);
    return;
}

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
    Mat img = imread(argv[1]);
    if (img.empty()) {
        std::cout<<"load img error"<<std::endl;
        return 1;
    }
    char *window_name = "show_img";
    namedWindow(window_name);

    int w = 512, h = 512;
    Mat dst = Mat::zeros(w, h, CV_8UC4);
    std::cout<<(int)(*(dst.ptr(0,0,0)))<<std::endl;
    resize(img, dst, dst.size());
    int c = 4;
    while (true) {
        imshow(window_name, dst);
        char key = waitKey(20);
        if ( key == 61) {
           modifyMat(dst, w, h, c, 20); 
        }

        if (key == 45) {
           modifyMat(dst, w, h, c, -20); 
        }
        if (key == '0') {
            std::cout<<"return now"<<std::endl;
            break;
        }
    }
    destroyWindow(window_name);

}
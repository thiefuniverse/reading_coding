#include <iostream>
#include <opencv2/opencv.hpp>   
#include <opencv2/highgui/highgui.hpp>
#include <unistd.h>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
    if (argc < 3 ) {
        std::cout<<"Usage:  "<<argv[0]<<" video_path video_output_path"<<std::endl;
        std::cout<<"you missed arguments."<<std::endl;        
        return 1;
    }
    if (access(argv[1], F_OK) == -1) {
        std::cout<<"file path not valid"<<std::endl;
        return 0;
    }
    VideoCapture cap(argv[1]);
    if (!cap.isOpened()) {
        std::cout<<"open video error"<<std::endl;
        return 1;
    }
    double fps = cap.get(CV_CAP_PROP_FPS);
    std::cout<<"fps:"<<fps<<std::endl;

    char *window_name = "show_img";

    // WINDOW_NORMAL make this window can be resizable.
    // default it will be WINDOW_AUTOSIZE, window will show orginal image.
    namedWindow(window_name, WINDOW_NORMAL);
    int target_width = 300, target_height = 300;
    resizeWindow(window_name, target_width, target_height);

    // init video writer
    Size frame_size(target_width, target_height);
    int frames_per_second = 10;
    VideoWriter vWriter(argv[2], CV_FOURCC('M', 'J', 'P', 'G'), frames_per_second, frame_size, true);

    while(true) {
        Mat f;
        bool ret = cap.read(f);
        if (!ret) {
            std::cout<<"end now."<<std::endl;
            break;
        }
        Mat s = Mat::zeros(target_width, target_height, CV_8UC3);
        resize(f, s, s.size());

        vWriter.write(s);
        imshow(window_name, f);
        // wait 10 ms and check ESC key is pressed or not.
        if (waitKey(10) == 27) {
            std::cout<<"esc key done."<<std::endl;
            break;
        }
    }
    return 0;
}
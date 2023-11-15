#include <ros/ros.h>
#include <opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>
#include <iostream>
#include <string>

std::string gstreamer_pipeline(
    int sensor_id,
    int capture_width,
    int capture_height,
    int display_width,
    int display_height,
    int framerate,
    int flip_method
    )
{
    return "nvarguscamerasrc sensor_id=" + std::to_string(sensor_id) + " ! video/x-raw(memory:NVMM), width=(int)" + std::to_string(capture_width) + ", height=(int)" + std::to_string(capture_height) + ", format=(string)NV12, framerate=(fraction)" + std::to_string(framerate) + "/1 ! nvvidconv flip-method=" + std::to_string(flip_method) + " ! video/x-raw, width=(int)" + std::to_string(display_width) + ", height=(int)" + std::to_string(display_height) + ", format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink max-buffers=2 drop=true";
}

int main (int argc, char** argv){

    // Image params
    int32_t W_input  = 1280;
    int32_t H_input  = 720;
    int32_t W_stereo  = 480;
    int32_t H_stereo = 270;
    int32_t FPS = 30;
    int32_t FLIP_METHOD = 0;

    std::string pipeline_right = gstreamer_pipeline(1, W_input, H_input, W_input, H_input, FPS, FLIP_METHOD);
    std::string pipeline_left = gstreamer_pipeline(0, W_input, H_input, W_input, H_input, FPS, FLIP_METHOD);
    cv::VideoCapture cap_l(pipeline_left, cv::CAP_GSTREAMER);
    cv::VideoCapture cap_r(pipeline_right, cv::CAP_GSTREAMER);

        cv::Mat frame;

        if(cap_l.isOpened()){
                while(true){
                        cap_l.read(frame);
                        cv::imshow("cap", frame);
                        if(cv::waitKey(1) == 27) break;
                }
        }
        else{
                std::cout << "NO FRAME, CHECK YOUR CAMERA!" << std::endl;
        }
        cv::destroyAllWindows();

        return 0;
}

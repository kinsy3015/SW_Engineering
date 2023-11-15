#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


#define MAX_THESH 255;

//void setwindowSettings(){
//	namedWindow("Contours", WINDOW_AUTOSIZE);
//
//	createTrackbar("LowerC", "Contours", &lowerC, 255, NULL);
//	createTrackbar("UpperC", "Contours", &upperC, 255, NULL);
//
//}

void wait(void){

	long t=3000000;
	while(t--);

}

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
    return "nvarguscamerasrc sensor_id=" + to_string(sensor_id) + " ! video/x-raw(memory:NVMM), width=(int)" + to_string(capture_width) + ", height=(int)" + to_string(capture_height) + ", format=(string)NV12, framerate=(fraction)" + to_string(framerate) + "/1 ! nvvidconv flip-method=" + to_string(flip_method) + " ! video/x-raw, width=(int)" + to_string(display_width) + ", height=(int)" + to_string(display_height) + ", format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink drop=true";
}



int main (int argc, char** argv){
    int thresh = 200;
    // Image params
    int32_t W_input  = 1280;
    int32_t H_input  = 720;
    int32_t W_stereo  = 480;
    int32_t H_stereo = 270;
    int32_t FPS = 30;
    int32_t FLIP_METHOD = 0;

    string pipeline_right = gstreamer_pipeline(1, W_input, H_input, W_input, H_input, FPS, FLIP_METHOD);
    string pipeline_left = gstreamer_pipeline(0, W_input, H_input, W_input, H_input, FPS, FLIP_METHOD);
    VideoCapture cap_l(pipeline_left, CAP_GSTREAMER);
    VideoCapture cap_r(pipeline_right, CAP_GSTREAMER);
	
    Mat frame_l, frame_r;
    Mat canny_out_l, canny_out_r;
    vector<vector<Point> > contours_l, contours_r;
    vector<Vec4i> hierarchy_l, hierarchy_r;
    Mat drawing_l, drawing_r, image1, image2, foreground_l, foreground_r;
    RNG rng(12345);


    vector<int> classIds;
    vector<float> confidences;
    //std::vector<Rect> boxes;
	
    namedWindow("Capture", WINDOW_AUTOSIZE);
    //setwindowSettings();


    if(!cap_l.isOpened() && !cap_r.isOpened() ){

	return -1;
    }
    cout<<"debug section1"<<endl;
    while(cv::waitKey(1) != 27) {

	    cap_l >> frame_l;
	    cap_r >> frame_r;

	    if (frame_l.empty() && frame_r.empty()){
		    break;
	    }	

	    cout<<"debug section1"<<endl;
	    image1 = frame_l.clone();
	    image2 = frame_r.clone();

	    // void cv::Canny( InputArray image, OutputArray edges, double threshold1, double threshold2,int apertureSize = 3, bool L2gradient = false )	
	    cout<<"debug section2"<<endl;

	    cvtColor(image1, foreground_l, CV_BGR2GRAY);
	    cvtColor(image2, foreground_r, CV_BGR2GRAY);
	    GaussianBlur(foreground_l, foreground_l, Size(9,11),0,0);
	    GaussianBlur(foreground_r, foreground_r, Size(9,11),0,0);

	    Canny(foreground_l , canny_out_l , thresh, thresh*2 );
	    Canny(foreground_r , canny_out_r , thresh, thresh*2 );
	    cout<<"debug section3"<<endl;
	    findContours( canny_out_l , contours_l, hierarchy_l, RETR_TREE, CHAIN_APPROX_SIMPLE);
	    findContours( canny_out_r , contours_r, hierarchy_r, RETR_TREE, CHAIN_APPROX_SIMPLE);
	    cout<<"debug section4"<<endl;

	    drawing_l = Mat::zeros( canny_out_l.size(), CV_8UC1 );
	    drawing_r = Mat::zeros( canny_out_r.size(), CV_8UC1 );
	    cout<<"debug section5"<<endl;

	    for( size_t i = 0; i < contours_l.size(); i++ )
	    {
		    Scalar color = Scalar( rng.uniform(0, 256), rng.uniform(0,256), rng.uniform(0,256) );
		    drawContours( drawing_l , contours_l, (int)i , color, 2, LINE_8, hierarchy_l, 0 );
		    drawContours( drawing_r , contours_r, (int)i , color, 2, LINE_8, hierarchy_r, 0 );
	    }
	    cout<<"debug section6"<<endl;
	    imshow("l_contours ", drawing_l);
	    imshow("r_contours ", drawing_r);
	    // just output stream test
	    //cv::imshow("cap_l", frame_l);
	    //cv::imshow("cap_r", frame_r);

	    // Ros	
	    // ros::init(argc, argv, "sung_bridge");

	    //if(cv::waitKey(1) == 27) break;
    }
destroyAllWindows();

return 0;
}

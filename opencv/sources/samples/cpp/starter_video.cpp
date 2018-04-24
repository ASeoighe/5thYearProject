/*
* starter_video.cpp
*
*  Created on: Nov 23, 2010
*      Author: Ethan Rublee
*
<<<<<<< HEAD
* A starter sample for using opencv, get a video stream and display the images
* easy as CV_PI right?
*/
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <vector>
=======
*  Modified on: April 17, 2013
*      Author: Kevin Hughes
*
* A starter sample for using OpenCV VideoCapture with capture devices, video files or image sequences
* easy as CV_PI right?
*/

#include <opencv2/highgui/highgui.hpp>

#include <iostream>
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
#include <stdio.h>

using namespace cv;
using namespace std;

<<<<<<< HEAD


//hide the local functions in an anon namespace
namespace {
    void help(char** av) {
        cout << "\nThis program justs gets you started reading images from video\n"
            "Usage:\n./" << av[0] << " <video device number>\n"
            << "q,Q,esc -- quit\n"
            << "space   -- save frame\n\n"
            << "\tThis is a starter sample, to get you up and going in a copy pasta fashion\n"
            << "\tThe program captures frames from a camera connected to your computer.\n"
            << "\tTo find the video device number, try ls /dev/video* \n"
            << "\tYou may also pass a video file, like my_vide.avi instead of a device number"
            << endl;
=======
//hide the local functions in an anon namespace
namespace {
    void help(char** av) {
        cout << "The program captures frames from a video file, image sequence (01.jpg, 02.jpg ... 10.jpg) or camera connected to your computer." << endl
             << "Usage:\n" << av[0] << " <video file, image sequence or device number>" << endl
             << "q,Q,esc -- quit" << endl
             << "space   -- save frame" << endl << endl
             << "\tTo capture from a camera pass the device number. To find the device number, try ls /dev/video*" << endl
             << "\texample: " << av[0] << " 0" << endl
             << "\tYou may also pass a video file instead of a device number" << endl
             << "\texample: " << av[0] << " video.avi" << endl
             << "\tYou can also pass the path to an image sequence and OpenCV will treat the sequence just like a video." << endl
             << "\texample: " << av[0] << " right%%02d.jpg" << endl;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    }

    int process(VideoCapture& capture) {
        int n = 0;
        char filename[200];
        string window_name = "video | q or esc to quit";
        cout << "press space to save a picture. q or esc to quit" << endl;
<<<<<<< HEAD
        namedWindow(window_name, CV_WINDOW_KEEPRATIO); //resizable window;
        Mat frame;
=======
        namedWindow(window_name, WINDOW_NORMAL); //resizable window;
        Mat frame;

>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        for (;;) {
            capture >> frame;
            if (frame.empty())
                break;
<<<<<<< HEAD
            imshow(window_name, frame);
            char key = (char)waitKey(5); //delay N millis, usually long enough to display and capture input
            switch (key) {
        case 'q':
        case 'Q':
        case 27: //escape key
            return 0;
        case ' ': //Save an image
            sprintf(filename,"filename%.3d.jpg",n++);
            imwrite(filename,frame);
            cout << "Saved " << filename << endl;
            break;
        default:
            break;
=======

            imshow(window_name, frame);
            char key = (char)waitKey(30); //delay N millis, usually long enough to display and capture input

            switch (key) {
            case 'q':
            case 'Q':
            case 27: //escape key
                return 0;
            case ' ': //Save an image
                sprintf(filename,"filename%.3d.jpg",n++);
                imwrite(filename,frame);
                cout << "Saved " << filename << endl;
                break;
            default:
                break;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
            }
        }
        return 0;
    }
<<<<<<< HEAD

=======
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
}

int main(int ac, char** av) {

    if (ac != 2) {
        help(av);
        return 1;
    }
    std::string arg = av[1];
<<<<<<< HEAD
    VideoCapture capture(arg); //try to open string, this will attempt to open it as a video file
    if (!capture.isOpened()) //if this fails, try to open as a video camera, through the use of an integer param
        capture.open(atoi(arg.c_str()));
    if (!capture.isOpened()) {
        cerr << "Failed to open a video device or video file!\n" << endl;
=======
    VideoCapture capture(arg); //try to open string, this will attempt to open it as a video file or image sequence
    if (!capture.isOpened()) //if this fails, try to open as a video camera, through the use of an integer param
        capture.open(atoi(arg.c_str()));
    if (!capture.isOpened()) {
        cerr << "Failed to open the video device, video file or image sequence!\n" << endl;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        help(av);
        return 1;
    }
    return process(capture);
}

/*
 *
 *  Example by Sam Siewert 
 *
 *  Comments by Trevor Sribar
 * 
 */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

// brings the Symbols form openCV & the standard C++ library into the scope of this file
using namespace cv;
using namespace std;

// defining resolution
#define HRES 640
#define VRES 480


int main( int argc, char** argv )
{
    // initializaion
    cvNamedWindow("Capture Example", CV_WINDOW_AUTOSIZE);
    CvCapture* capture = cvCreateCameraCapture(1);

    // iteration variable
    IplImage* frame;

    // changes the width and height to match the resolution we defined
    cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, HRES);
    cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, VRES);

    while(1)
    {
        // pull the next frame
        frame=cvQueryFrame(capture);
     
        // brak if there was an error w/ the camera (probably a disconnect)
        if(!frame) break;

        // display the image
        cvShowImage("Capture Example", frame);

        // waits 33ms for a keypress
        char c = cvWaitKey(33);
        if( c == 27 ) break; // if it was esc, break
    }

    // frees mem & closes the GUI
    cvReleaseCapture(&capture);
    cvDestroyWindow("Capture Example");
    
};

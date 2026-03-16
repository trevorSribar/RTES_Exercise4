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


int main( int argc, char** argv )
{
    //creates a GUI window which is autosized to fit the image captured
    cvNamedWindow("Capture Example", CV_WINDOW_AUTOSIZE);

    // Opens camera 0 and saves it's location
    CvCapture* capture = cvCreateCameraCapture(0);

    // creates image structure that will hold each frame of the video
    IplImage* frame;

    // frame capturing
    while(1)
    {
        // grabs image from the camera
        frame=cvQueryFrame(capture);
     
        // if camera is disconnected
        if(!frame) break;

        // Renders the image captured
        cvShowImage("Capture Example", frame);

        // waits 33ms for a keypress
        char c = cvWaitKey(33);
        if( c == 27 ) break; // if the key pressed was the ESC key, leave the loop
    }

    // frees mem & closes the GUI
    cvReleaseCapture(&capture);
    cvDestroyWindow("Capture Example");
    
};


///////////////////////////////////////////////////////////////////////////////
//
// Horn_Schunck
//
// Modified version of the code from (example 10-1b):
//
//   Learning OpenCV: Computer Vision with the OpenCV Library
//     by Gary Bradski and Adrian Kaehler
//     Published by O'Reilly Media, October 3, 2008
//
///////////////////////////////////////////////////////////////////////////////

#include "Horn_Schunck.h"

#include<iostream>
#include<string>
#include<sstream>

using namespace std;

#define CVX_GRAY50 cvScalar(100)
#define CVX_WHITE  cvScalar(255)

string itos2(int i);

int outNum = 0;

void initHornSchunck ()
{

    cvNamedWindow("OpticalFlow0");
    cvNamedWindow("OpticalFlow1");
    cvNamedWindow("Flow Results");
}

void endHornSchunck ()
{
    // destroy windows
    cvDestroyWindow("OpticalFlow0");
    cvDestroyWindow("OpticalFlow1");
    cvDestroyWindow("Flow Results");

}

int runHornSchunck (IplImage *imgA, IplImage *imgB)
{
    IplImage* velx = cvCreateImage(cvGetSize(imgA), IPL_DEPTH_32F, 1);
    printf("HS::created velx\n");

    IplImage* vely = cvCreateImage(cvGetSize(imgA), IPL_DEPTH_32F, 1);
    printf("HS::created vely\n");

    IplImage* imgC = cvCreateImage(cvGetSize(imgA), IPL_DEPTH_8U, 3);
    printf("HS::created imgc\n");

    cvShowImage("OpticalFlow0", imgA);
    cvShowImage("OpticalFlow1", imgB);

    // call the actual Horn and Schunck algorithm
    cvCalcOpticalFlowHS(imgA, imgB, 0, velx, vely, 0.10, cvTermCriteria(CV_TERMCRIT_ITER | CV_TERMCRIT_EPS, imgA->width, 1e-6));

    // how show what we are looking at
    cvZero(imgC);
    int step = 4;
    for (int y=0; y<imgC->height; y += step) {
        float *px = (float*) (velx->imageData + y * velx->widthStep);
        float *py = (float*) (vely->imageData + y * vely->widthStep);
        for (int x=0; x<imgC->width; x += step) {
            if (px[x]>1 && py[x]>1) {
                cvCircle(imgC, cvPoint(x, y), 2, CVX_GRAY50, -1);
                cvLine(imgC, cvPoint(x, y), cvPoint( x+px[x]/2, y+py[x]/2 ), CV_RGB(255,0,0), 1, 0);
            }
        }
    }

    // show tracking
    cvShowImage("Flow Results",imgC);

    // save the output to /tmp
    string fileName = "/tmp/out" + itos2(outNum) + ".bmp";
    cvSaveImage(fileName.c_str(), imgC);
    outNum++;
    
    cvWaitKey(10);

    // release memory
    cvReleaseImage( &imgA );
    cvReleaseImage( &imgB );
    cvReleaseImage( &imgC );

    return 0;
}

///////////////////////////////////////////////////////////////////////////////
//
// itos
//
///////////////////////////////////////////////////////////////////////////////

string itos2(int i)
{
    stringstream s;
    s << i;
    return s.str();
}


///////////////////////////////////////////////////////////////////////////////
//
// Code was adapted from Damien Stewart's blog at opencv.damienstewart.net
//
///////////////////////////////////////////////////////////////////////////////

//#include "stdafx.h"
#include <stdio.h>
#include <ctype.h>

#include <cv.h>
#include <cxcore.h>
#include <highgui.h>

#include<iostream>
#include<string>
#include<sstream>

using namespace std;

#pragma warning(disable : 4996)

IplImage *image1 = NULL;

#define FARNEBECK 1

int outNumF = 0;

///////////////////////////////////////////////////////////////////////////////
//
// forward declarations
//
///////////////////////////////////////////////////////////////////////////////

string itos3(int i);

///////////////////////////////////////////////////////////////////////////////
//
// allocateOnDemand
//
///////////////////////////////////////////////////////////////////////////////

inline static void allocateOnDemand( IplImage **img, CvSize size, int depth, int channels )
{
	if (*img != NULL) {
		return;
	}

	*img = cvCreateImage( size, depth, channels );
	if (*img == NULL) {
		fprintf(stderr, "Error: Couldn't allocate image.  Out of memory?\n");
		exit(-1);
	}

}

///////////////////////////////////////////////////////////////////////////////
//
// initFarneback
//
///////////////////////////////////////////////////////////////////////////////

void initFarneback()
{
    cvNamedWindow("Image 1",  CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Image 2",  CV_WINDOW_AUTOSIZE);
    cvNamedWindow("GFB Flow", CV_WINDOW_AUTOSIZE);

}


///////////////////////////////////////////////////////////////////////////////
//
// endFarneback
//
///////////////////////////////////////////////////////////////////////////////

void endFarneback()
{
    cvDestroyWindow("Image 1");
    cvDestroyWindow("Image 2");
    cvDestroyWindow("GFB Flow");

}


///////////////////////////////////////////////////////////////////////////////
//
// runFarneback
//
///////////////////////////////////////////////////////////////////////////////

int runFarneback(IplImage *image1, IplImage *image2)
{
#ifdef FARNEBECK 
    IplImage *image1_grey = NULL, *image2_grey = NULL;
    IplImage *flow = NULL;
    IplImage *velx = NULL, *vely = NULL, *vel = NULL;

    int imageCounter = 0;
    int c = 0;
    bool loadedRef = false;

    CvSize image1_size, image2_size;
    image1_size.height = image1->height;
    image1_size.width = image1->width;
    image2_size.height= image2->height;
    image2_size.width = image2->width;

    // convert both images to 1 channel, 8-bit grayscale
    allocateOnDemand(&image1_grey, image1_size, IPL_DEPTH_8U, 1);
    allocateOnDemand(&image2_grey, image2_size, IPL_DEPTH_8U, 1);
    cvConvertImage(image1, image1_grey, 0);
    cvConvertImage(image2, image2_grey, 0);

    // show the images
    cvShowImage("Image 1", image1);
    cvShowImage("Image 2", image2);
    cvWaitKey(10);
		
    // Now show the greyscale versions
    cvShowImage("Image 1", image1_grey);
    cvShowImage("Image 2", image2_grey);
    cvWaitKey(10);

    // Setup our velocity(x) and velocity(y) images and flow scratch area
    allocateOnDemand(&velx, image1_size, IPL_DEPTH_32F, 1);
    allocateOnDemand(&vely, image1_size, IPL_DEPTH_32F, 1);
    allocateOnDemand(&vel, image1_size, IPL_DEPTH_8U, 3);
    allocateOnDemand(&flow, image1_size, IPL_DEPTH_32F, 2);

    // Run GFB optical flow analysis
    cv::Mat im1 = cv::cvarrToMat(image1_grey), im2 = cv::cvarrToMat(image2_grey);
    cv::Mat _flow = cv::cvarrToMat(flow);
    cv::calcOpticalFlowFarneback( im1, im2, _flow, 0.5, 2, 5, 2, 7, 1.5, cv::OPTFLOW_FARNEBACK_GAUSSIAN);
    cv::calcOpticalFlowFarneback( im1, im2, _flow, 0.5, 2, 10, 2, 14, 2.0, cv::OPTFLOW_FARNEBACK_GAUSSIAN);
		
    float pyrScale = 1.0;
    int levels = 5;
    int winSize = 20;
    int iterations = 4;
    int polyN = 14;
    float polySigma = 3.0;

    cv::calcOpticalFlowFarneback( im1, im2, _flow, pyrScale, levels, winSize, iterations, polyN, polySigma, cv::OPTFLOW_FARNEBACK_GAUSSIAN);

    // Extract from flow field, velx and vely
    for (int y = 0; y<flow->height; y++) {

        float *vx = (float*)(velx->imageData + velx->widthStep*y);
        float *vy = (float*)(vely->imageData + vely->widthStep*y);
        const float* f = (const float*)(flow->imageData + flow->widthStep*y);
        for (int x = 0; x < flow->width; x++) {
            vx[x] = f[2*x];
            vy[x] = f[2*x+1];
        }
    }

    // Clear the previous pixels
    cvZero(vel);

    int count=0;

    // Workout what pixels shifted from image1_grey compared to the extracted flow data
    for (int y = 0; y < image1_grey->height; y++) {
        for (int x = 0; x < image1_grey->width; x++) {

            double dx = cvGetReal2D(velx, y, x);
            double dy = cvGetReal2D(vely, y, x);

            CvPoint p = cvPoint(x, y);
				
            // This function sets a basic threshold for drawing on the image
            double l = sqrt(dx*dx + dy*dy);
            if (l > 1) {
                //CvPoint p2 = cvPoint(p.x + (int)(dx * 10 + .5), p.y + (int)(dy * 10 + .5));
                CvPoint p2 = cvPoint(p.x + (int)(dx), p.y + (int)(dy));
                cvLine(vel, p, p2, CV_RGB(0,255,0), 1, 8);
                count++;

                // draw these on the original images
                cvCircle(image1, p,  3, CV_RGB(0,255,0), -1, 8, 0);
                cvCircle(image2, p2, 3, CV_RGB(0,255,0), -1, 8, 0);

            }
        }
    }

    cvShowImage("Image 1", image1);
    cvShowImage("Image 2", image2);

    cvShowImage("GFB Flow", vel);

    // save the output to /tmp
    string fileName = "/tmp/out" + itos3(outNumF) + ".bmp";
    cvSaveImage(fileName.c_str(), vel);
    outNumF++;

    // free the allocated memory
    cvReleaseImage(&velx);
    cvReleaseImage(&vely);
    cvReleaseImage(&vel);
    cvReleaseImage(&flow);
    cvReleaseImage(&image2);
    cvReleaseImage(&image2_grey);

#else

    printf("FARNEBACK currently set to NOT RUN......\n");
    
#endif

    return 0;
}


///////////////////////////////////////////////////////////////////////////////
//
// itos
//
///////////////////////////////////////////////////////////////////////////////

string itos3(int i)
{
    stringstream s;
    s << i;
    return s.str();
}

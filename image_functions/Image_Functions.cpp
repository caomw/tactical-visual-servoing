#include "Image_Functions.h"

///////////////////////////////////////////////////////////////////////////////
//
// constructor
//
///////////////////////////////////////////////////////////////////////////////

ImageFunctions::ImageFunctions()
{
    captureAVIInitialized = false;
    captureAVIFrames = 0;
    captureAVICurrentFrameNumber = 0;

} // end constructor


///////////////////////////////////////////////////////////////////////////////
//
// destructor
//
///////////////////////////////////////////////////////////////////////////////

ImageFunctions::~ImageFunctions()
{

} // end destructor


///////////////////////////////////////////////////////////////////////////////
//
// aviInitialize
//
///////////////////////////////////////////////////////////////////////////////

void ImageFunctions::aviInitialize(string fileName)
{
    if (captureAVIInitialized == false) {

        captureAVI = cvCaptureFromFile(fileName.c_str());

        // get the number of frames
        captureAVIFrames = (int)cvGetCaptureProperty(captureAVI, CV_CAP_PROP_FRAME_COUNT);

        captureAVIInitialized = true;

        // grab the first frame so we can set the height and width
        IplImage *frame = cvQueryFrame(captureAVI);
        width  = frame->width;
        height = frame->height;
    }

} // end aviInitialize


///////////////////////////////////////////////////////////////////////////////
//
// aviGrabFrame
//
///////////////////////////////////////////////////////////////////////////////

IplImage *ImageFunctions::aviGrabFrame(int frameNumber)
{
    cvSetCaptureProperty(captureAVI, CV_CAP_PROP_POS_FRAMES, frameNumber);

    IplImage *temp = cvQueryFrame(captureAVI);

    // this comes in as BGR, we have to flip it to RGB
    IplImage *ret = cvCreateImage(cvSize(temp->width, temp->height), IPL_DEPTH_8U, 3);

    cvConvertImage(temp, ret, CV_CVTIMG_SWAP_RB);

    return ret;

} // end aviGrabFrame


///////////////////////////////////////////////////////////////////////////////
//
// aviClose
//
///////////////////////////////////////////////////////////////////////////////

void ImageFunctions::aviClose()
{
    cvReleaseCapture(&captureAVI);

} // end aviClose

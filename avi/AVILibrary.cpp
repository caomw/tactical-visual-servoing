#include "AVILibrary.h"

///////////////////////////////////////////////////////////////////////////////
//
// constructor
//
///////////////////////////////////////////////////////////////////////////////

AVILibrary::AVILibrary()
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

AVILibrary::~AVILibrary()
{

} // end destructor


///////////////////////////////////////////////////////////////////////////////
//
// aviInitialize
//
///////////////////////////////////////////////////////////////////////////////

void AVILibrary::aviInitialize(string fileName)
{
    if (captureAVIInitialized == false) {

        captureAVI = cvCaptureFromFile(fileName.c_str());

        // grab the first frame so we can get the height and width
        IplImage *frame = cvQueryFrame(captureAVI);

        width  = frame->width;
        height = frame->height;

        // get the number of frames
        captureAVIFrames = (int)cvGetCaptureProperty(captureAVI, CV_CAP_PROP_FRAME_COUNT);

        captureAVIInitialized = true;
    }

} // end aviInitialize


///////////////////////////////////////////////////////////////////////////////
//
// aviGrabFrame
//
///////////////////////////////////////////////////////////////////////////////

IplImage *AVILibrary::aviGrabFrame(int frameNumber)
{
    //cout << "from aviGrabFrame :: trying to set frameNumber to = " << frameNumber << " of " << captureAVIFrames << "\n";

    cvSetCaptureProperty(captureAVI, CV_CAP_PROP_POS_FRAMES, frameNumber);

    IplImage *temp = cvQueryFrame(captureAVI);

    // this comes in as BGR, we have to flip it to RGB
    IplImage *ret = cvCreateImage(cvSize(temp->width, temp->height), IPL_DEPTH_8U, 3);

    cvConvertImage(temp, ret, CV_CVTIMG_SWAP_RB);

    return ret;

} // end aviGrabFrame


///////////////////////////////////////////////////////////////////////////////
//
// aviNextGrabFrame
//
///////////////////////////////////////////////////////////////////////////////

IplImage *AVILibrary::aviGrabNextFrame(string fileName)
{
    printf("Grabbing next frame from %s\n", fileName.c_str());

    if (captureAVIInitialized == false) {
        aviInitialize(fileName);
        frameNumber=0;
        captureAVIInitialized = true;
    }

    if (frameNumber < captureAVIFrames) {
        cvSetCaptureProperty(captureAVI, CV_CAP_PROP_POS_FRAMES, frameNumber);

        IplImage *temp = cvQueryFrame(captureAVI);

        // this comes in as BGR, we have to flip it to RGB
        IplImage *ret = cvCreateImage(cvSize(temp->width, temp->height), IPL_DEPTH_8U, 3);

        cvConvertImage(temp, ret, CV_CVTIMG_SWAP_RB);

        frameNumber++;

        return ret;

    } else {

        return NULL;

    }

} // end aviGrabFrame


///////////////////////////////////////////////////////////////////////////////
//
// aviClose
//
///////////////////////////////////////////////////////////////////////////////

void AVILibrary::aviClose()
{
    cvReleaseCapture(&captureAVI);

} // end aviClose


///////////////////////////////////////////////////////////////////////////////
//
// KLT tracker
//
// This uses OpenCV's implementation of the KLT tracker.
//
///////////////////////////////////////////////////////////////////////////////

#include "KLT.h"

#define DEBUG_KLT 1

///////////////////////////////////////////////////////////////////////////////
//
// constructor
//
///////////////////////////////////////////////////////////////////////////////

KLT::KLT()
{
    printf("KLT :: in constructor\n");

    quality = 0.01;
    minDistance = 10;
    winSize = 30;
    numLevels = 5;

    lkInitialized = false;
    lkFlags = 0;
    lkRanOnce = false;

    count = 0;

    printf("KLT :: out constructor\n");

    if (lkInitialized == false) printf("init is FALSE\n");
    if (lkInitialized == true)  printf("init is TRUE\n");
    printf("quality = %lf, minDistance = %lf, winSize = %d, numLevels = %d\n", quality, minDistance, winSize, numLevels);

} // end constructor


///////////////////////////////////////////////////////////////////////////////
//
// destructor
//
///////////////////////////////////////////////////////////////////////////////

KLT::~KLT()
{

} // end destructor


///////////////////////////////////////////////////////////////////////////////
//
// lkOpticalFlow
//
// This function takes in an RGB image.  This needs to be changed to take in
//  the grayscale image instead.
//
///////////////////////////////////////////////////////////////////////////////

void KLT::lkOpticalFlow (IplImage *frame)
{
    printf("KLT is starting....%d\n", count);
    printf("frame is [%d,%d] and %d channels\n", frame->height, frame->width, frame->nChannels);

    // initialize our buffers
    if (lkInitialized == false) {
        lkImage = cvCreateImage(cvGetSize(frame), 8, 3);
        lkImage->origin = frame->origin;
        lkGrey = cvCreateImage(cvGetSize(frame), 8, 1);
        lkPrevGrey = cvCreateImage(cvGetSize(frame), 8, 1);
        lkPyramid = cvCreateImage(cvGetSize(frame), 8, 1);
        lkPrevPyramid = cvCreateImage(cvGetSize(frame), 8, 1);
        lkPoints[0] = (CvPoint2D32f *)cvAlloc(MAX_COUNT * sizeof(lkPoints[0][0]));
        lkPoints[1] = (CvPoint2D32f *)cvAlloc(MAX_COUNT * sizeof(lkPoints[0][0]));
        lkStatus = (char *)cvAlloc(MAX_COUNT);
        lkFeatureError = (float *)cvAlloc(MAX_COUNT);
    }

    cvCopy(frame, lkImage, 0);
    cvCvtColor(lkImage, lkGrey, CV_BGR2GRAY);

    if (DEBUG_KLT) {
        printf("end copy and convert color...\n");
    }

    if (lkInitialized == false) printf("init is FALSE\n");
    if (lkInitialized == true)  printf("init is TRUE\n");

    if (lkInitialized == false) {

        printf("klt :: here1\n");

        IplImage *eig  = cvCreateImage(cvGetSize(lkGrey), 32, 1);
        IplImage *temp = cvCreateImage(cvGetSize(lkGrey), 32, 1);

        lkCount = MAX_COUNT;

        cvGoodFeaturesToTrack(lkGrey, eig, temp, lkPoints[1], &lkCount, quality, minDistance, 0, 3, 0, 0.04);

        cvFindCornerSubPix(lkGrey, lkPoints[1], lkCount, cvSize(winSize, winSize), cvSize(-1,-1),
            cvTermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS, 20, 0.03));

        printf("klt :: here2\n");
        printf("lkCount = %d\n", lkCount);

        cvReleaseImage(&eig);
        cvReleaseImage(&temp);

        lkInitialized = true;

        printf("klt :: here3\n");
        printf("lkCount = %d\n", lkCount);

    } else if (lkCount > 0) {

        /**sth
        cvCalcOpticalFlowPyrLK(lkPrevGrey, lkGrey, lkPrevPyramid, lkPyramid, lkPoints[0],
            lkPoints[1], lkCount, cvSize(winSize, winSize), 3, lkStatus, 0,
            cvTermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS, 20, 0.03), lkFlags);
        lkFlags |= CV_LKFLOW_PYR_A_READY;
        **/
        lkRanOnce = true;

    }

    CV_SWAP(lkPrevGrey, lkGrey, lkSwapTemp);
    CV_SWAP(lkPrevPyramid, lkPyramid, lkSwapTemp);
    CV_SWAP(lkPoints[0], lkPoints[1], lkSwapPoints);

    printf("Done swapping...\n");

    count++;

} // end lkOpticalFlow


///////////////////////////////////////////////////////////////////////////////
//
// lkResetOpticalFlow
//
///////////////////////////////////////////////////////////////////////////////

void KLT::lkResetOpticalFlow ()
{
    if (lkRanOnce == true) {
        lkInitialized = false;
        lkRanOnce = false;

        cvReleaseImage(&lkGrey);
        cvReleaseImage(&lkPrevGrey);
        cvReleaseImage(&lkPyramid);
        cvReleaseImage(&lkPrevPyramid);

        cvFree(&lkPoints[1]);
        cvFree(&lkPoints[0]);
        cvFree(&lkStatus);

    }

} // end lkResetOpticalFlow


///////////////////////////////////////////////////////////////////////////////
//
// reset
//
///////////////////////////////////////////////////////////////////////////////

void KLT::reset (int releaseMemory)
{
    if (lkRanOnce == true) {
        lkInitialized = false;
        lkRanOnce = false;

        cvReleaseImage(&lkGrey);
        cvReleaseImage(&lkPrevGrey);
        cvReleaseImage(&lkPyramid);
        cvReleaseImage(&lkPrevPyramid);

        cvFree(&lkPoints[1]);
        cvFree(&lkPoints[0]);
        cvFree(&lkStatus);

    }

} // end reset


///////////////////////////////////////////////////////////////////////////////
//
// drawFeatures
//
// This function will draw all of the current features on an IplImage
//
///////////////////////////////////////////////////////////////////////////////

void KLT::drawFeatures (IplImage *draw)
{
    printf("KLT :: drawing %d features...\n", lkCount);
    int i=0, k=0;
    for (k=i=0; i<lkCount; i++) {
        lkPoints[1][k++] = lkPoints[1][i];
        cvCircle(draw, cvPointFrom32f(lkPoints[1][i]), 3, CV_RGB(0,0,255), -1, 8, 0);
    }

} // end drawFeatures

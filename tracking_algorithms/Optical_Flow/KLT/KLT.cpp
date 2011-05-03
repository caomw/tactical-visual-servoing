
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
    winSize = 0;
    numLevels = 0;

    winSize = 30;
    numLevels = 5;

    lkInitialized = false;
    lkFlags = 0;
    lkRanOnce = false;
}

///////////////////////////////////////////////////////////////////////////////
//
// destructor
//
///////////////////////////////////////////////////////////////////////////////

KLT::~KLT()
{
}

///////////////////////////////////////////////////////////////////////////////
//
// lkOpticalFlow
//
///////////////////////////////////////////////////////////////////////////////

void KLT::lkOpticalFlow (IplImage *frame)
{
    printf("KLT is starting....\n");

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

    if (lkInitialized == false) {

        if (lkGrey != NULL) {

            IplImage *eig  = cvCreateImage(cvGetSize(lkGrey), 32, 1);
            IplImage *temp = cvCreateImage(cvGetSize(lkGrey), 32, 1);

            lkCount = MAX_COUNT;

            cvGoodFeaturesToTrack(lkGrey, eig, temp, lkPoints[1], &lkCount, quality, minDistance, 0, 3, 0, 0.04);

            cvFindCornerSubPix(lkGrey, lkPoints[1], lkCount, cvSize(winSize, winSize), cvSize(-1,-1),
                cvTermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS, 20, 0.03));

            if (eig != NULL) {
                cvReleaseImage(&eig);
            }

            if (temp != NULL) {
                cvReleaseImage(&temp);
            }

            lkInitialized = true;

            if (DEBUG_KLT) {
                printf("end lkInitialized == false...\n");
            }

        }

    } else if(lkCount > 0) {

//        cvCalcOpticalFlowPyrLK(lkPrevGrey, lkGrey, lkPrevPyramid, lkPyramid, lkPoints[0],
//            lkPoints[1], lkCount, cvSize(winSize, winSize), 3, lkStatus, 0,
//            cvTermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS, 20, 0.03), lkFlags);
//        lkFlags |= CV_LKFLOW_PYR_A_READY;

        cvCalcOpticalFlowPyrLK(lkPrevGrey, lkGrey, lkPrevPyramid, lkPyramid, lkPoints[0],
            lkPoints[1], lkCount, cvSize(winSize, winSize), numLevels, lkStatus, lkFeatureError,
            cvTermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS, 20, 0.3), 0);

        if (DEBUG_KLT) {
            printf("Made OpenCV OF call...\n");
        }

    }

    CV_SWAP(lkPrevGrey, lkGrey, lkSwapTemp);
    CV_SWAP(lkPrevPyramid, lkPyramid, lkSwapTemp);
    CV_SWAP(lkPoints[0], lkPoints[1], lkSwapPoints);

    if (DEBUG_KLT) {
        printf("Done swapping...\n");
    }


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
        if (lkGrey != NULL) {
            cvReleaseImage(&lkGrey);
            if (DEBUG_KLT) {
                printf("Freed: lkGrey\n");
            }
        }
        if (lkPrevGrey != NULL) {
            cvReleaseImage(&lkPrevGrey);
            if (DEBUG_KLT) {
                printf("Freed: lkPrevGrey\n");
            }
        }
        if (lkPyramid != NULL) {
            cvReleaseImage(&lkPyramid);
            if (DEBUG_KLT) {
                printf("Freed: lkPyramid\n");
            }
        }
        if (lkPrevPyramid != NULL) {
            cvReleaseImage(&lkPrevPyramid);
            if (DEBUG_KLT) {
                printf("Freed: lkPrevPyramid\n");
            }
        }
        if (lkPoints != NULL) {
            cvFree(&lkPoints[1]);
            cvFree(&lkPoints[0]);
            if (DEBUG_KLT) {
                printf("Freed: lkPoints\n");
            }
        }
        if (lkStatus != NULL) {
            cvFree(&lkStatus);
            if (DEBUG_KLT) {
                printf("Freed: lkStatus\n");
            }
        }
    }

} // end lkResetOpticalFlow



///////////////////////////////////////////////////////////////////////////////
//
// reset
//
///////////////////////////////////////////////////////////////////////////////

void KLT::reset (int releaseMemory)
{
    lkInitialized = false;
    lkRanOnce = false;
    lkFlags = 0;

    if (lkImage != NULL) {
        cvReleaseImage(&lkImage);
        if (DEBUG_KLT) {
            printf("Freed: lkImage\n");
        }
    }
    if (lkGrey != NULL) {
        cvReleaseImage(&lkGrey);
        if (DEBUG_KLT) {
            printf("Freed: lkGrey\n");
        }
    }
    if (lkPrevGrey != NULL) {
        cvReleaseImage(&lkPrevGrey);
        if (DEBUG_KLT) {
            printf("Freed: lkPrevGrey\n");
        }
    }
    if (lkPyramid != NULL) {
        cvReleaseImage(&lkPyramid);
        if (DEBUG_KLT) {
            printf("Freed: lkPyramid\n");
        }
    }
    if (lkPrevPyramid != NULL) {
        cvReleaseImage(&lkPrevPyramid);
        if (DEBUG_KLT) {
            printf("Freed: lkPrevPyramid\n");
        }
    }
    if (lkPoints[1] != NULL) {
        cvFree(&lkPoints[1]);
        if (DEBUG_KLT) {
            printf("Freed: lkPoints[1]\n");
        }
    }
    if (lkPoints[0] != NULL) {
        cvFree(&lkPoints[0]);
        if (DEBUG_KLT) {
            printf("Freed: lkPoints[0]\n");
        }
    }
    if (lkStatus != NULL) {
        cvFree(&lkStatus);
        if (DEBUG_KLT) {
            printf("Freed: lkStatus\n");
        }
    }
    if (lkFeatureError != NULL) {
        cvFree(&lkFeatureError);
        if (DEBUG_KLT) {
            printf("Freed: lkFeatureError\n");
        }
    }

    if (DEBUG_KLT) {
        printf("Done with the reset...\n");
    }

} // end reset

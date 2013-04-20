#ifndef _AVI_LIBRARY
#define _AVI_LIBRARY

//#include "cv.h"
//#include "highgui.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/legacy/legacy.hpp>

#include <stdlib.h>
#include <stdio.h>

#include <string>
#include <iostream>

using namespace std;

class AVILibrary
{
    public:

        AVILibrary();
        ~AVILibrary();

        int captureAVIFrames;

        void aviInitialize(string fileName);

        IplImage *aviGrabFrame(int frameNumber);
        IplImage *aviGrabNextFrame(string fileName);

        void aviClose();

    private:

        int frameNumber;
        int height;
        int width;
        CvCapture *captureAVI;
        bool captureAVIInitialized;
        int captureAVICurrentFrameNumber;

};

#endif

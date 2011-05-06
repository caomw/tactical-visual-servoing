#ifndef _AVI_LIBRARY
#define _AVI_LIBRARY

#include "cv.h"
#include "highgui.h"

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

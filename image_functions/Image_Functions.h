#ifndef _IMAGE_FUNCTIONS
#define _IMAGE_FUNCTIONS

#include "cv.h"
#include "highgui.h"

#include <string>
#include <iostream>

using namespace std;

class ImageFunctions
{
    public:

        ImageFunctions();
        ~ImageFunctions();

        int captureAVIFrames;

        void aviInitialize(string fileName);

        IplImage *aviGrabFrame(int frameNumber);

        void aviClose();

    private:

        int height;
        int width;
        CvCapture *captureAVI;
        bool captureAVIInitialized;
        int captureAVICurrentFrameNumber;

};

#endif

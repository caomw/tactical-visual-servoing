#ifndef _IMAGE_FUNCTIONS
#define _IMAGE_FUNCTIONS

//#include "cv.h"
//#include "highgui.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/legacy/legacy.hpp>

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

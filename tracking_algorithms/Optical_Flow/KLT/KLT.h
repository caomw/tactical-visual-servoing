
#ifndef _KLT
#define _KLT

#include "cv.h"
#include "highgui.h"

// gsl includes
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_blas.h>

#define MAX_COUNT 500

class KLT
{
    public:

        int numLevels;
        int winSize;

        bool lkInitialized;
        bool lkRanOnce;

        IplImage *lkGrey;
        IplImage *lkPrevGrey;
        IplImage *lkPyramid;
        IplImage *lkPrevPyramid;
        IplImage *lkSwapTemp;

        char *lkStatus;

        // this is the RMS of the error of the pixel intensity values
        //  between the template and the matched region
        float *lkFeatureError;

        int lkCount;
        int lkFlags;
        CvPoint2D32f *lkPoints[2], *lkSwapPoints;
        IplImage *lkImage;

        double quality;
        double minDistance;

        int count;

        KLT();
        ~KLT();

        int numberGoodFeatures;

        int findGoodFeatures (IplImage *);
        void lkOpticalFlow (IplImage *);
        void lkResetOpticalFlow();
        void drawFeatures(IplImage *);
        void reset(int releaseMemory);

    private:

};

#endif


///////////////////////////////////////////////////////////////////////////////
///
/// TuringTracking.h
///
/// Modification History:
///
/// 6-April-2008	- Version 1.0, Original Release
/// 20-April-2008	- Version 1.1, Added Doxygen Comments
///
///////////////////////////////////////////////////////////////////////////////

#ifndef _TURINGTRACKING
#define _TURINGTRACKING

#ifdef WIN32
#include "windows.h"
#endif

#ifdef linux
#include "SimpleIni.h"
#endif

#include "math.h"
#include <iostream>
#include <fstream>
#include <string>

#include <cv.h>

typedef unsigned char BYTE;

using namespace std;

/// turingTracking class

class turingTracking
{
	public:

		/// constellation-point tracking; 1=center, 2=above, 3=below, 4=right, 5=left
		int rLast[5], cLast[5];

		/// constellation metrics
		float correlationError, constellationExpansion, surfacePitch, surfaceYaw;
		float degeneracy, shapeChange, rejectionRate;

		/// single-point tracking
		int rLastOnePoint, cLastOnePoint;

		/// flag to see if tracking is currently running
		bool trackingActivated;

        // good features to track
        CvPoint2D32f *points[2], *swap_points;

        char *lkStatus;
        int lkCount;
        int lkFlags;
        CvPoint2D32f *lkPoints[2], *lkSwapPoints;
        IplImage *lkImage;

		///////////////////////////////////////////////////////////////////////
		///
		/// function prototypes
		///
		///////////////////////////////////////////////////////////////////////

		turingTracking(const char * rows, const char *cols);

		void constellationTrackWrapper(BYTE **aNewImageInt, int trackX, int trackY);
		void constellationTrackWrapper(int **imageBuffer, int trackX, int trackY);

		void constellationTrackWrapperStereo(BYTE **aLeftImage, BYTE **aRightImage, int trackX, int trackY);

		void constellationTrackWrapperOnePoint(BYTE **aNewImage, int trackX, int trackY);
		void constellationTrackWrapperOnePoint(int **aNewImage, int trackX, int trackY);
		void reset();
		void test();

        int findGoodFeatures (IplImage *frame);
        void lkOpticalFlow (IplImage *frame);
        void lkResetOpticalFlow ();

		~turingTracking();	

	private:

		bool executedInitialTrackingLoop, keepHistory;

		int continueTest, counter, intOrByte;

		// INI variables
		int rgb, constellationOffset, searchRadius, searchLevels, fovealKernelNumLevels, fovealKernelTypeSpacing,
			starOutOfBounds, centerOutOfBounds, source, startNumber, stopNumber, numberImages, saveImages, saveAVI,
			debugFlag, debugPosition, debugRow, debugCol, imgNum, numberOfFramesInAVI, height, width;
		
		float minSampleProportion, fovealKernelBaseConstant, correlationErrorThresh, degeneracyThresh, shapeChangeThresh,
			rejectionRateTimeConstant, rejectionRateThresh, constellationExpansionThresh, inverseConstellationExpansionThresh;

		string inputImagePath, inputBaseFileName, inputAVIPath, outputImagePath, outputBaseFileName,
			inputFileName, outputFileName, outputAVIName;

		int fovealKernelRows, searchWidth;
		float twoExpLevels, oneMinusRejectionRateTimeConstant;

		int **fovealKernelList;

		BYTE **aLastImage;
		int **aLastImageInt;

		// history
		float aCorrelationError[10000], aDegeneracy[10000], aShapeChange[10000], aRejectionRate[10000];
		float aConstellationOffset[10000], aConstellationExpansion[10000], aSurfacePitch[10000], aSurfaceYaw[10000];

        // good features to track
        bool lkInitialized;
        bool lkRanOnce;
        IplImage *lkGrey;
        IplImage *lkPrevGrey;
        IplImage *lkPyramid;
        IplImage *lkPrevPyramid;
        IplImage *lkSwapTemp;

        ///////////////////////////////////////////////////////////////////////
		//
		// function prototypes
		//
		///////////////////////////////////////////////////////////////////////

		BYTE *convert2DArrayTo1D (BYTE **arrayIn, int height, int width);
		BYTE **make2DArray(int rows, int cols, int dummy1, int dummy2);

		double GetPrivateProfileFloat (const char *section, const char *key, double def_value, const char *filename);
		double **make2DArray(int rows, int cols, int x);
		double maxElement(double *arrayIn, int numElements);
		double mean2 (BYTE **imageIn, int rows, int cols, int planes);
		double mean2 (int **imageIn, int rows, int cols, int planes);
		double meanElements(double *arrayIn, int numElements);
		double meanElements(int *arrayIn, int numElements);
		double minElement(double *arrayIn, int numElements);

		int **createFovealKernel (float baseConstant, int numLevels, int typeSpacing, int *fovealKernelNumRows);
		int **createFovealKernel2 (float baseConstant, int numLevels, int typeSpacing, int *fovealKernelNumRows);
		int **make2DArray(int rows, int cols);

		int maxElement(int *arrayIn, int numElements);
		int minElement(int *arrayIn, int numElements);
		int round (double in);
		int sign (double numberIn);
		int sign (int numberIn);

		float maxElement(float *arrayIn, int numElements);
		float minElement(float *arrayIn, int numElements);
		float triangleDegeneracy (int r1, int c1, int r2, int c2, int r3, int c3, int signSwitch);

		void constellationTracker5Point(BYTE **testImage, BYTE **refImage, int *rLast, int *cLast, int **fovealKernelList, int fovealKernelRows,
			int searchRadius, int searchWidth, int levels, int twoExpLevels, int imageRows, int imageCols,
			int *rNew, int *cNew, float *correlationError, float *degeneracy, float *shapeChange);

		void constellationTracker5Point(int **testImage, int **refImage, int *rLast, int *cLast, int **fovealKernelList, int fovealKernelRows,
			int searchRadius, int searchWidth, int levels, int twoExpLevels, int imageRows, int imageCols,
			int *rNew, int *cNew, float *correlationError, float *degeneracy, float *shapeChange);

		void convertRGBToBMPBufferInline (BYTE *Buffer, int width, int height);
		void copyArray(int **arrayIn, int rows, int cols, int **arrayOut);
		void copyArray(int **lastImage, int **newImage, int rows, int cols);
		void copyArray(BYTE **lastImage, BYTE **newImage, int rows, int cols);		
		void free2DArray(BYTE **p, int rows);
		void free2DArray(double **p, int rows);
		void free2DArray(int **p, int rows);

		void mrTrackPoint2(BYTE **testImage, BYTE **refImage, 
			  int rGoal, int cGoal,  int **fovealKernelList, int fovealKernelRows,
			  int searchRadius, int searchWidth, int levels, int twoExpLevels,
			  int refImageRows, int refImageCols, int *rGoalEst, int *cGoalEst, float *currentMetric);

		void mrTrackPoint2(int **testImageInt, int **refImageInt, 
			  int rGoal, int cGoal,  int **fovealKernelList, int fovealKernelRows,
			  int searchRadius, int searchWidth, int levels, int twoExpLevels,
			  int refImageRows, int refImageCols, int *rGoalEst, int *cGoalEst, float *currentMetric);

		void mrTrackPoint3(BYTE **testImage, BYTE **refImage, 
			  int rGoal, int cGoal,  int **fovealKernelList, int fovealKernelRows,
			  int searchRadius, int searchWidth, int levels, int twoExpLevels, int minSamples,
			  int refImageRows, int refImageCols, int *rGoalEst, int *cGoalEst, 
			  float *currentMetric);

		void mrTrackPoint3(int **testImageInt, int **refImageInt, 
			  int rGoal, int cGoal,  int **fovealKernelList, int fovealKernelRows,
			  int searchRadius, int searchWidth, int levels, int twoExpLevels, int minSamples,
			  int refImageRows, int refImageCols, int *rGoalEst, int *cGoalEst, 
			  float *currentMetric);

		void printArray (double *arrayIn, int size);
		void printArray (int *arrayIn, int size);
		void printArray (double **arrayIn, int height, int width);
		void printArray (int **arrayIn, int height, int width);
		void readINI();
		void writeArrayToFile (string fileName, int *arrayIn, int height);
		void writeArrayToFile (string fileName, float *arrayIn, int height);
		void writeArrayToFile (string fileName, int **arrayIn, int height, int width);
		void trackingCleanup();
		void zeroArray (double **arrayIn, int rows, int cols);
		void zeroArray (int **arrayIn, int rows, int cols);
		void zeroArray (int *arrayIn, int size);
		void zeroArray (float *arrayIn, int size);
		void zeroArray (double *arrayIn, int size);



};

#endif

/**********************************************************************
Finds the 150 best features in an image and tracks them through the 
next two images.  The sequential mode is set in order to speed
processing.  The features are stored in a feature table, which is then
saved to a text file; each feature list is also written to a PPM file.
**********************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "pnmio.h"
#include "klt.h"

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

/**
#define REPLACE
**/

string itos(int i);

int runSeries()
{
	string path = "C:\\Documents and Settings\\Shawn\\Desktop\\Homography_Data\\Zoom and Rotation\\boat\\";
	string imgFileName;
	string flFileName;
	string ftFileName;

	unsigned char *img1, *img2;
	char fnamein[100], fnameout[100];
	
	KLT_TrackingContext tc;
	KLT_FeatureList fl;
	KLT_FeatureTable ft;
	
	int nFeatures = 150, nFrames = 7;
	int ncols, nrows;
	int i=0;
	int frameCounter = 1;
	int start=1, stop=7;

	tc = KLTCreateTrackingContext();
	fl = KLTCreateFeatureList(nFeatures);
	ft = KLTCreateFeatureTable(nFrames, nFeatures);
	tc->sequentialMode = TRUE;
	tc->writeInternalImages = FALSE;
	tc->affineConsistencyCheck = 2;  /* set this to 2 to turn on affine consistency check, -1 turns it off */
 
	// load in the first image of our set
	imgFileName = path + "img" + itos(start) + ".pgm";
	img1 = pgmReadFile((char *)imgFileName.c_str(), NULL, &ncols, &nrows);
	img2 = (unsigned char *) malloc(ncols*nrows*sizeof(unsigned char));

	KLTSelectGoodFeatures(tc, img1, ncols, nrows, fl);
	KLTStoreFeatureList(fl, ft, 0);

	flFileName = path + "features\\feat" + itos(frameCounter) + ".ppm";
	KLTWriteFeatureListToPPM(fl, img1, ncols, nrows, (char *)flFileName.c_str());

	frameCounter++;
	start++;

	for (i=start; i<stop; i++)  {

		imgFileName = path + "img" + itos(i) + ".pgm";
		cout << "Reading :: " << imgFileName << "\n";
		pgmReadFile((char *)imgFileName.c_str(), img2, &ncols, &nrows);
		KLTTrackFeatures(tc, img1, img2, ncols, nrows, fl);

		#ifdef REPLACE
		KLTReplaceLostFeatures(tc, img2, ncols, nrows, fl);
		#endif
    	
		KLTStoreFeatureList(fl, ft, frameCounter);
		flFileName = path + "features\\feat" + itos(frameCounter) + ".ppm";
		KLTWriteFeatureListToPPM(fl, img2, ncols, nrows, (char *)flFileName.c_str());

		frameCounter++;
	}
  
	ftFileName = path + "features\\feat.ft";
	KLTWriteFeatureTable(ft, (char *)ftFileName.c_str(), NULL);

	ftFileName = path + "features\\feat.txt";
	KLTWriteFeatureTable(ft, (char *)ftFileName.c_str(), "%5.1f");

	KLTFreeFeatureTable(ft);
	KLTFreeFeatureList(fl);
	KLTFreeTrackingContext(tc);
	free(img1);
	free(img2);

	return 0;
}

// convert int to string
string itos(int i)	
{
	stringstream s;
	s << i;
	return s.str();
}

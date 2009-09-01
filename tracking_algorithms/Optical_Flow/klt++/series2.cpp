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

string itos(int i);


/* #define REPLACE */

#ifdef WIN32
int RunSeries2()
#else
int main()
#endif
{
	unsigned char *img1, *img2;
	char fnamein[100], fnameout[100];
	KLT_TrackingContext tc;
	KLT_FeatureList fl;
	KLT_FeatureTable ft;
	int nFeatures = 500, nFrames = 6;
	int ncols, nrows;
	int i;
	string path = "C:\\Documents and Settings\\Shawn\\Desktop\\Homography_Data\\Zoom and Rotation\\boat\\";
	string imgFileName;
  
	tc = KLTCreateTrackingContext();
	fl = KLTCreateFeatureList(nFeatures);
	ft = KLTCreateFeatureTable(nFrames, nFeatures);
	tc->sequentialMode = TRUE;
	tc->writeInternalImages = FALSE;
	tc->affineConsistencyCheck = -1;  /* set this to 2 to turn on affine consistency check */
 
	imgFileName = path + "img1.pgm";
	img1 = pgmReadFile((char *)imgFileName.c_str(), NULL, &ncols, &nrows);
	img2 = (unsigned char *) malloc(ncols*nrows*sizeof(unsigned char));

	KLTSelectGoodFeatures(tc, img1, ncols, nrows, fl);
	KLTStoreFeatureList(fl, ft, 0);
	KLTWriteFeatureListToPPM(fl, img1, ncols, nrows, "feat1.ppm");

	for (i = 1 ; i < nFrames ; i++)  {
		string fname = path + "img" + itos(i+1) + ".pgm";
		//sprintf(fnamein, "img%d.pgm", i);
		pgmReadFile((char *)fname.c_str(), img2, &ncols, &nrows);
		KLTTrackFeatures(tc, img1, img2, ncols, nrows, fl);

		#ifdef REPLACE
		KLTReplaceLostFeatures(tc, img2, ncols, nrows, fl);
		#endif
    
		KLTStoreFeatureList(fl, ft, i);
		sprintf(fnameout, "feat%d.ppm", i+1);
		KLTWriteFeatureListToPPM(fl, img2, ncols, nrows, fnameout);
	}
  
	KLTWriteFeatureTable(ft, "features.txt", "%5.1f");
	KLTWriteFeatureTable(ft, "features.ft", NULL);

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
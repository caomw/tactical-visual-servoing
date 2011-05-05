
#ifdef WIN32
#include <windows.h>
#include "SDL.h"
#include "SDL_image.h"
#endif

#ifdef unix
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#endif

#include "cv.h"

#include <stdio.h>
#include <stdlib.h>

#include <iostream>

// template libary
#include "third_party/tnt/tnt.h"

double mean2 (int **imageBuffer, int rows, int cols, int numberPlanes);

int *SDLImageTo1DArrayOnePlane (SDL_Surface *image, int rows, int cols, int plane);

int **make2DArray(int rows, int cols);
int **SDLImageTo2DArrayOnePlane (SDL_Surface *image, int rows, int cols, int plane); 

IplImage *ImageArray1DToIplImageOnePlane (int *imageIn, int rows, int cols);
IplImage *ImageArray1DToIplImageThreePlanes (int *imageIn, int rows, int cols);

IplImage *ImageArray2DToIplImageOnePlane (int **imageIn, int rows, int cols);
IplImage *ImageArray2DToIplImageThreePlanes (int **imageIn, int rows, int cols);

void free2DArray(int **p, int rows);

Uint32 getpixel(SDL_Surface *surface, int x, int y);
int **SDLImageTo2DArrayOnePlane2 (SDL_Surface *image, int rows, int cols, int plane);

TNT::Array1D <long int> getHistogram (TNT::Array2D <double>);
TNT::Array2D <double> histogramEqualization(TNT::Array2D <double> array);

IplImage  *getIplImageFromArray(const TNT::Array2D<double> &array);
IplImage  *getIplImageFromArray2(const TNT::Array2D<double> &array);

TNT::Array2D<double> getArrayFromIplImage(IplImage *frame);
TNT::Array1D <long int> getHistogram (TNT::Array2D <double> array);
TNT::Array2D <double> runHistogramEqualization(TNT::Array2D <double> array);

TNT::Array1D <int> findLUT(TNT::Array2D <double> array, int r1, int s1, int r2, int s2);
void getIplImageFromArray2(const TNT::Array2D<double> &array, IplImage *imageWork);
TNT::Array2D <double> logarithm(TNT::Array2D <double> array, float constant);
TNT::Array2D <double> laplacian(TNT::Array2D <double> array);
int max (TNT::Array2D <double> array, int k, int width, int height, int x, int y);
int meanArithmetic(TNT::Array2D <double> array, int k, int width, int height, int x, int y);
int meanContraharmonic (TNT::Array2D <double> array, int k, int width, int height, int x, int y, float q);
int meanGeometric(TNT::Array2D <double> array, int k, int width, int height, int x, int y);
int meanHarmonic (TNT::Array2D <double> array, int k, int width, int height, int x, int y);
int meanLocal (TNT::Array2D <double> array, int k, int width, int height, int x, int y);
int median (TNT::Array2D <double> array, int k, int width, int height, int x, int y);
int min (TNT::Array2D <double> array, int k, int width, int height, int x, int y);
TNT::Array2D <double> negative(TNT::Array2D <double> array);
int findYCoordRect (int x, int x0, int y0, int x1, int y1);
TNT::Array1D <double> getHessian (TNT::Array1D <double> c);
TNT::Array2D <double> getHorizontalGradient(TNT::Array2D <double> array, double tolerance);
TNT::Array2D <double> getHorizontalHessian(TNT::Array2D <double> array, double tolerance);
double getInitialAntiCausalCoefficientMirrorOnBounds(TNT::Array1D <double> line, double z, double tolerance);
double getInitialCausalCoefficientMirrorOnBounds(TNT::Array1D <double> line, double z, double tolerance);
TNT::Array1D <double> getRow(TNT::Array2D <double> array, int row);
TNT::Array1D <double> getRow2(TNT::Array2D <double> array, int row);
TNT::Array1D <double> getSplineInterpolationCoefficients(TNT::Array1D <double> line, double tolerance);
TNT::Array2D <double> getVerticalGradient(TNT::Array2D <double> array, double tolerance);
TNT::Array2D <double> getVerticalHessian(TNT::Array2D <double> array, double tolerance);
TNT::Array2D <double> gradient(TNT::Array2D <double> array);
void sortArray(int *arrayIn, int size);
TNT::Array1D <double> symmetricFirMirrorOnBounds(TNT::Array1D <double> h, TNT::Array1D <double> c);
TNT::Array1D <double> getGradient (TNT::Array1D <double> c);
void putRow2(TNT::Array2D <double> *array, int width, int height, TNT::Array1D <double> rowIn, int row);
TNT::Array1D <double> convert2DTo1D(TNT::Array2D <double> arrayIn);
TNT::Array1D <double> getCol2(TNT::Array2D <double> array, int col);
TNT::Array1D <double> getCol(TNT::Array2D <double> array, int col);
void putCol2(TNT::Array2D <double> *array, int width, int height, TNT::Array1D <double> colIn, int col);
TNT::Array1D <double> antiSymmetricFirMirrorOnBounds(TNT::Array1D <double> h, TNT::Array1D <double> c);
TNT::Array2D <double> convert1DTo2D(TNT::Array1D <double> arrayIn, int width, int height);


#ifdef WIN32
#include <windows.h>
#endif

#include "SDL/SDL.h"
//#include "SDL/SDL_net.h"
#include "SDL/SDL_image.h"

#include "cv.h"

#include <stdio.h>
#include <stdlib.h>

#include <iostream>

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

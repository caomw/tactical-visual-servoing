
#ifndef HORN_SCHUNCK_H
#define HORN_SCHUNCK_H

#include "cv.h"
#include "highgui.h"
#include <math.h>
#include <stdio.h>

void initHornSchunck ();
void endHornSchunck ();
int runHornSchunck (IplImage *imgA, IplImage *imgB);

#endif

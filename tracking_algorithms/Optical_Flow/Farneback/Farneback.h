
#ifndef FARNEBACK_H
#define FARNEBACK_H

#include "cv.h"
#include "highgui.h"
#include <math.h>
#include <stdio.h>

void initFarneback ();
void endFarneback ();
int runFarneback (IplImage *imgA, IplImage *imgB);

#endif

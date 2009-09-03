
#ifndef LK_OPENCV_H
#define LK_OPENCV_H

#include "cv.h"
#include "highgui.h"
#include <math.h>
#include <stdio.h>

void initLKOpenCV ();
void endLKOpenCV ();
int runLKOpenCV (IplImage *imgA);
void on_mouse (int event, int x, int y, int flags, void *param);

#endif


#ifndef LK_OPENCV_H
#define LK_OPENCV_H

//#include "cv.h"
//#include "highgui.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/legacy/legacy.hpp>

#include <math.h>
#include <stdio.h>

void initLKOpenCV ();
void endLKOpenCV ();
int runLKOpenCV (IplImage *imgA);
void on_mouse (int event, int x, int y, int flags, void *param);

#endif

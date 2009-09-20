
///////////////////////////////////////////////////////////////////////////////
//
// LK_OpenCV.cpp
//
// OpenCV's canned example LK program, modified to run within TACTICAL
//
///////////////////////////////////////////////////////////////////////////////

#include "LK_OpenCV.h"

IplImage *image = 0, *grey = 0, *prev_grey = 0, *pyramid = 0, *prev_pyramid = 0, *swap_temp;

int win_size = 10;
const int MAX_COUNT = 500;
CvPoint2D32f* points[2] = {0,0}, *swap_points;
char* status = 0;
int count = 0;
int need_to_init = 1;
int night_mode = 0;
int flags = 0;
int add_remove_pt = 0;
CvPoint pt;

void initLKOpenCV ()
{
    cvNamedWindow("LK_OpenCV");
}

void endLKOpenCV ()
{
    // destroy windows
    cvDestroyWindow("LK_OpenCV");
}

int runLKOpenCV (IplImage *imgA)
{
    int i=0, k=0, c=0;


    if (!image) {
        // allocate all the buffers
        image = cvCreateImage(cvGetSize(imgA), 8, 3);
        image->origin = imgA->origin;
        grey = cvCreateImage(cvGetSize(imgA), 8, 1);
        prev_grey = cvCreateImage(cvGetSize(imgA), 8, 1);
        pyramid = cvCreateImage(cvGetSize(imgA), 8, 1);
        prev_pyramid = cvCreateImage(cvGetSize(imgA), 8, 1);
        points[0] = (CvPoint2D32f*)cvAlloc(MAX_COUNT * sizeof(points[0][0]));
        points[1] = (CvPoint2D32f*)cvAlloc(MAX_COUNT * sizeof(points[0][0]));
        status = (char*)cvAlloc(MAX_COUNT);
        flags = 0;
    }

    // convert to grayscale
    cvCopy(imgA, image, 0);
    cvCvtColor(image, grey, CV_BGR2GRAY);

    if (need_to_init) {

        // automatic initialization
        IplImage *eig  = cvCreateImage(cvGetSize(grey), 32, 1);
        IplImage *temp = cvCreateImage(cvGetSize(grey), 32, 1);
        double quality = 0.01;
        double min_distance = 10;

        count = MAX_COUNT;
        cvGoodFeaturesToTrack(grey, eig, temp, points[1], &count, quality, min_distance, 0, 3, 0, 0.04);
        cvFindCornerSubPix(grey, points[1], count, cvSize(win_size,win_size), cvSize(-1,-1),
                cvTermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS,20,0.03));
        cvReleaseImage(&eig);
        cvReleaseImage(&temp);

        add_remove_pt = 0;

    } else if (count > 0) {

        cvCalcOpticalFlowPyrLK( prev_grey, grey, prev_pyramid, pyramid,
                points[0], points[1], count, cvSize(win_size,win_size), 3, status, 0,
                cvTermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS,20,0.03), flags );
        flags |= CV_LKFLOW_PYR_A_READY;

        for (i = k = 0; i < count; i++) {

            if (add_remove_pt) {

                double dx = pt.x - points[1][i].x;
                double dy = pt.y - points[1][i].y;

                if (dx*dx + dy*dy <= 25) {
                    add_remove_pt = 0;
                    continue;
                }
            }

            if (!status[i]) {
                continue;
            }

            points[1][k++] = points[1][i];
            cvCircle( image, cvPointFrom32f(points[1][i]), 3, CV_RGB(0,255,0), -1, 8,0);
        }
        count = k;
    }

    if (add_remove_pt && count < MAX_COUNT) {
        points[1][count++] = cvPointTo32f(pt);
        cvFindCornerSubPix( grey, points[1] + count - 1, 1, cvSize(win_size,win_size), cvSize(-1,-1),
                cvTermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS,20,0.03));
        add_remove_pt = 0;
    }

    CV_SWAP(prev_grey, grey, swap_temp);
    CV_SWAP(prev_pyramid, pyramid, swap_temp);
    CV_SWAP(points[0], points[1], swap_points);

    need_to_init = 0;
    cvShowImage("LK_OpenCV", image);
    c = cvWaitKey(10);
//
//    if ((char)c == 27) {
//        break;
//    }
    switch ((char) c) {
    case 'r':
        need_to_init = 1;
        break;
    case 'c':
        count = 0;
        break;
    case 'n':
        night_mode ^= 1;
        break;
    default:
        ;
    }

    return 0;
}



void on_mouse( int event, int x, int y, int flags, void* param )
{
    if( !image )
        return;

    if( image->origin )
        y = image->height - y;

    if( event == CV_EVENT_LBUTTONDOWN )
    {
        pt = cvPoint(x,y);
        add_remove_pt = 1;
    }
}

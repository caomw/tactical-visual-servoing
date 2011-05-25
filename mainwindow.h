
///////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2011 Shawn T. Hunt
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use,
// copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following
// conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>

#include <QTimer>
#include <QGraphicsScene>
#include <QFileDialog>
#include <QDir>
#include <QtCore/QStringList>

#include "VideoDisplay.h"

// move these
#include "cv.h"
#include "highgui.h"

#include "image_functions/Image_Functions.h"
#include "utilities/utilities.h"
//#include "tracking_algorithms/correlation/TuringTracking.h"

#include "tracking_algorithms/Optical_Flow/KLT/KLT.h"

// avi functions
#include "avi/AVILibrary.h"

#ifdef linux
#include "SimpleIni.h"
#endif

#include "ImageProcessing.h"

#include "segmentation.h"

// template libary
#include "third_party/tnt/tnt.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QTimer timer;
    QGraphicsView *graphicsView;
    void trace(QString str);

    // declare image functions
    Utilities *utilities;
    ImageFunctions *imageFunctions;
    //TuringTracking *turingTracking;

    KLT *klt;

    AVILibrary *avi;

private:

    Ui::MainWindow *ui;

    void createActions();
    void listFiles(QString);
    void resetDisplay();

    string itos(int i);

    QGraphicsScene *scene;
    //QGraphicsScene *scene2;
    QGraphicsScene *scene3;

    VideoDisplay *video;

    bool datasetLoaded;
    QString datasetName;
    QString datasetPath;
    string t;
    QStringList files;
    int datasetWidth;
    int datasetHeight;

    int fitImageToWindow;

    bool windowHeight;
    bool windowWidth;

    bool swapRedBlue;

    string iniFile;
    string dPath;

    int displayOption;
    //int edgeFilter;

    int r1;
    int s1;
    int r2;
    int s2;

    int bitPlane;

    bool histogramEqualization;

    bool gltBitPlane;
    bool gltContrastStretching;
    bool gltLogarithm;
    bool gltNegative;
    bool gltPowerLaw;

    bool sharpening;
    bool smoothing;

    bool addGaussianNoise;
    bool addGammaNoise;
    bool addImpulseNoise;

    double gltLogarithmConstant;
    double gltPowerLawConstant;
    double gltPowerLawGamma;

    int processingAVI1Files2;

    int sharpeningAlgorithm;
    int smoothingFilter;
    int smoothingMask;

    int impulseNoise;

    bool segment;
    double sigma;
    int k;
    int minSize;

    bool applyFilter;
    int edgeFilter;

    bool opticalFlow;
    bool opticalFlowShowFeatures;
    int opticalFlowAlgorithm;

    double kltQuality;
    int kltMinDist;
    int kltWindowSize;
    int kltNumLevels;

protected:

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

protected Q_SLOTS:

    void getBitPlane(int);
    void getDisplayOption(int);
    void getEdgeFilter(int);
    void getImpulseNoise(int);
    void getKLTQuality(double);
    void getKLTMinDist(int);
    void getKLTWindowSize(int);
    void getKLTNumLevels(int);
    void getLogarithmConstant(double);
    void getOFAlgorithm(int);
    void getPowerLawConstant(double);
    void getPowerLawGamma(double);
    void getR1(int);
    //void getEdgeFilter(int);
    void getK(int);
    void getMinSize(int);
    void getSharpeningAlgorithm(int);
    void getSigma(double);
    void getSmoothingFilter(int);
    void getSmoothingMask(int);

    void exitApplication();
    void openImageDirectory();
    void toggleAddGaussianNoise();
    void toggleAddGammaNoise();
    void toggleAddImpulseNoise();
    void toggleBitPlaneSlicing();
    void toggleContrastStretching();
    void toggleFilter();
    void toggleFitToWindow();
    void toggleHistogramEqualization();
    void toggleLogarithm();
    void toggleNegative();
    void toggleOpticalFlow();
    void togglePowerLaw();
    void toggleSegmentation();
    void toggleSharpeningAlgorithm();
    void toggleSmoothing();
    void toggleSwapRedBlue();
    void updateImageNumber(int);

private slots:

    void timerEvent(QTimerEvent *);
    void on_pushButtonTrack_clicked();

};

#endif // MAINWINDOW_H


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

#include "mainwindow.h"
#include "ui_mainwindow.h"

#define COLS 640
#define ROWS 480

#define SECOND_DISPLAY_BLANK 0
#define SECOND_DISPLAY_PROCESSED 1

#define SHARPENING_LAPLACIAN 0
#define SHARPENING_GRADIENT 1

#define SMOOTHING_MF_ARITHMETIC 0
#define SMOOTHING_MF_GEOMETRIC 1
#define SMOOTHING_MF_CONTRAHARMONIC 2
#define SMOOTHING_MF_HARMONIC 3
#define SMOOTHING_OS_MEDIAN 4
#define SMOOTHING_OS_MAX 5
#define SMOOTHING_OS_MIN 6
#define SMOOTHING_OS_MID 7
#define SMOOTHING_OS_ALPHA 8
#define SMOOTHING_ADAPT_LOCAL_NOISE 9
#define SMOOTHING_ADAPT_MED_ 10

///////////////////////////////////////////////////////////////////////////////
//
// MainWindow constructor
//
///////////////////////////////////////////////////////////////////////////////

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    windowWidth = COLS;
    windowHeight = ROWS;

    ui->setupUi(this);

    createActions();

    // instantiations
    utilities = new Utilities();
    klt = new KLT();
    imageFunctions = new ImageFunctions();

    avi = new AVILibrary();

    // turingTracking = new TuringTracking();

    // set the scene up with the graphicsview
    scene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);

    // second display
    scene2 = new QGraphicsScene(ui->graphicsView_2);
    ui->graphicsView_2->setScene(scene2);

    fitImageToWindow = 0;

    ui->statusBar->showMessage("NO DATASET LOADED");

    //iniFile = "TACTICAL.ini";

    //CSimpleIniA ini(true, true, true);
    //SI_Error rc = ini.LoadFile(iniFile.c_str());

    displayOption = 0;
    //edge = 0;

    r1 = s1 = r2 = s2 = 0;

    bitPlane = 7;

    histogramEqualization = false;
    gltBitPlane = false;
    gltContrastStretching = false;
    gltLogarithm = false;
    gltNegative = false;
    gltPowerLaw = false;

    sharpening = false;
    smoothing = false;

    addGaussianNoise = false;
    addGammaNoise = false;
    addImpulseNoise = false;

    gltLogarithmConstant = 0.0;

    processingAVI1Files2 = 0;

    sharpeningAlgorithm = 0;
    smoothing = 0;
    smoothingMask = 0;

    swapRedBlue = false;

    impulseNoise = 0;

    segment = false;
    sigma = 0.5;
    k = 500;
    minSize = 50;

    applyFilter = false;
    edgeFilter = 0;

} // end constructor


///////////////////////////////////////////////////////////////////////////////
//
// MainWindow destructor
//
///////////////////////////////////////////////////////////////////////////////

MainWindow::~MainWindow()
{
    // clean up memory
    delete ui;
    delete utilities;
    delete imageFunctions;
    delete klt;
    delete avi;
    //delete turingTracking;

} // end destructor


///////////////////////////////////////////////////////////////////////////////
//
// on_pushButtonTrack_clicked
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::on_pushButtonTrack_clicked()
{

} // end on_pushButtonTrack_clicked


///////////////////////////////////////////////////////////////////////////////
//
// createActions
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::createActions()
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(timeout()));

    // file open
    connect(ui->action_Open_Sequence, SIGNAL(triggered()), this, SLOT(openImageDirectory()) );

    // exit
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(exitApplication()));

    // scroll bar
    connect(ui->imageScrollBar, SIGNAL(valueChanged(int)), this, SLOT(updateImageNumber(int)));

    // fit image to window
    connect(ui->checkBoxFitToWindow, SIGNAL(clicked()), this, SLOT(toggleFitToWindow()));

    // display option
    connect(ui->comboBoxSecondWindow, SIGNAL(currentIndexChanged(int)), this, SLOT(getDisplayOption(int)));

    // swap red and blue?
    connect(ui->checkBoxSwapRedBlue, SIGNAL(clicked()), this, SLOT(toggleSwapRedBlue()));

    // mouse events
    connect(ui->graphicsView, SIGNAL(mousePressEvent(QGraphicsSceneMouseEvent *)), this, SLOT(mousePressEvent(QGraphicsSceneMouseEvent *)));

    // histogram equalization
    connect(ui->checkBoxHistogramEqualization, SIGNAL(clicked()), this, SLOT(toggleHistogramEqualization()));

    // sharpening algorithm
    connect(ui->checkBoxSharpening, SIGNAL(clicked()), this, SLOT(toggleSharpeningAlgorithm()));
    connect(ui->comboBoxSharpeningAlgorithm, SIGNAL(currentIndexChanged(int)), this, SLOT(getSharpeningAlgorithm(int)));

    // smoothing filter
    connect(ui->checkBoxSmoothing, SIGNAL(clicked()), this, SLOT(toggleSmoothing()));
    connect(ui->comboBoxSmoothingFilter, SIGNAL(currentIndexChanged(int)), this, SLOT(getSmoothingFilter(int)));
    connect(ui->comboBoxSmoothingMask, SIGNAL(currentIndexChanged(int)), this, SLOT(getSmoothingMask(int)));

    // glt negative
    connect(ui->checkBoxNegative, SIGNAL(clicked()), this, SLOT(toggleNegative()));

    // glt logarithm
    connect(ui->checkBoxLogarithm, SIGNAL(clicked()), this, SLOT(toggleLogarithm()));
    connect(ui->doubleSpinBoxLogarithmConstant, SIGNAL(valueChanged(double)), this, SLOT(getLogarithmConstant(double)));

    // glt contrast stretching
    connect(ui->checkBoxContrastStretching, SIGNAL(clicked()), this, SLOT(toggleContrastStretching()));
    connect(ui->horizontalSliderR1, SIGNAL(valueChanged(int)), this, SLOT(getR1(int)));

    // glt power law
    connect(ui->checkBoxPowerLaw, SIGNAL(clicked()), this, SLOT(togglePowerLaw()));
    connect(ui->doubleSpinBoxPowerLawConstant, SIGNAL(valueChanged(double)), this, SLOT(getPowerLawConstant(double)));
    connect(ui->doubleSpinBoxPowerLawGamma, SIGNAL(valueChanged(double)), this, SLOT(getPowerLawGamma(double)));

    // glt bit plane slicing
    connect(ui->checkBoxBitPlaneSlicing, SIGNAL(clicked()), this, SLOT(toggleBitPlaneSlicing()));
    connect(ui->comboBoxBitPlane, SIGNAL(currentIndexChanged(int)), this, SLOT(getBitPlane(int)));

    // noise
    connect(ui->checkBoxAddGaussianNoise, SIGNAL(clicked()), this, SLOT(toggleGaussianNoise()));

    connect(ui->checkBoxAddGammaNoise, SIGNAL(clicked()), this, SLOT(toggleGammaNoise()));

    connect(ui->checkBoxAddImpulseNoise, SIGNAL(clicked()), this, SLOT(toggleAddImpulseNoise()));
    connect(ui->spinBoxImpulseNoise, SIGNAL(valueChanged(int)), this, SLOT(getImpulseNoise(int)));

    // segmentation
    connect(ui->checkBoxSegmentation, SIGNAL(clicked()), this, SLOT(toggleSegmentation()));
    connect(ui->doubleSpinBoxSigma, SIGNAL(valueChanged(double)), this, SLOT(getSigma(double)));
    connect(ui->spinBoxK, SIGNAL(valueChanged(int)), this, SLOT(getK(int)));
    connect(ui->spinBoxMinSize, SIGNAL(valueChanged(int)), this, SLOT(getMinSize(int)));

    // edge filter
    connect(ui->checkBoxFilter, SIGNAL(clicked()), this, SLOT(toggleFilter()));
    connect(ui->comboBoxEdgeFilter, SIGNAL(currentIndexChanged(int)), this, SLOT(getEdgeFilter(int)));

} // end createActions


///////////////////////////////////////////////////////////////////////////////
//
// exitApplication
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::exitApplication()
{
    QApplication::exit();

} // end exitApplication


///////////////////////////////////////////////////////////////////////////////
//
// getBitPlane
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::getBitPlane(int value)
{
    char msg[128];
    sprintf(msg, "getBitPlane :: The value is %d\n", value);
    trace(msg);

    if (value == 0) {
        bitPlane = 7;
    } else if (value == 1) {
        bitPlane = 6;
    } else if (value == 2) {
        bitPlane = 5;
    } else if (value == 3) {
        bitPlane = 4;
    } else if (value == 4) {
        bitPlane = 3;
    } else if (value == 5) {
        bitPlane = 2;
    } else if (value == 6) {
        bitPlane = 1;
    }

} // end getBitPlane


///////////////////////////////////////////////////////////////////////////////
//
// getDisplayOption
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::getDisplayOption(int value)
{
    char msg[128];
    sprintf(msg, "getDisplayOption :: The value is %d\n", value);
    trace(msg);

    displayOption = value;

} // end getDisplayOption


///////////////////////////////////////////////////////////////////////////////
//
// getLogarithmConstant
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::getLogarithmConstant(double value)
{
    char msg[128];
    sprintf(msg, "getLogarithmConstant :: The value is %lf\n", value);
    trace(msg);

    gltLogarithmConstant = value;

} // end getLogarithmConstant


///////////////////////////////////////////////////////////////////////////////
//
// getEdgeFilter
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::getEdgeFilter(int value)
{
    char msg[128];
    sprintf(msg, "getEdgeFilter :: The value is %d\n", value);
    trace(msg);

    edgeFilter = value;

} // end getEdgeFilter


///////////////////////////////////////////////////////////////////////////////
//
// getImpulseNoise
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::getImpulseNoise(int value)
{
    char msg[128];
    sprintf(msg, "getImpulseNoise :: The value is %d\n", value);
    trace(msg);

    impulseNoise = value;

} // end getImpulseNoise


///////////////////////////////////////////////////////////////////////////////
//
// getK
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::getK(int value)
{
    char msg[128];
    sprintf(msg, "getK :: The value is %d\n", value);
    trace(msg);

    k = value;

} // end getK


///////////////////////////////////////////////////////////////////////////////
//
// getMinSize
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::getMinSize(int value)
{
    char msg[128];
    sprintf(msg, "getMinSize :: The value is %d\n", value);
    trace(msg);

    minSize = value;

} // end getMinSize


///////////////////////////////////////////////////////////////////////////////
//
// getSigma
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::getSigma(double value)
{
    char msg[128];
    sprintf(msg, "getSigma :: The value is %lf\n", value);
    trace(msg);

    sigma = value;

} // end getSigma


///////////////////////////////////////////////////////////////////////////////
//
// getSmoothingFilter
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::getSmoothingFilter(int value)
{
    char msg[128];
    sprintf(msg, "getSmoothingFilter :: The value is %d\n", value);
    trace(msg);

    smoothingFilter = value;

} // end getSmoothingFilter


///////////////////////////////////////////////////////////////////////////////
//
// getSmoothingMask
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::getSmoothingMask(int value)
{
    char msg[128];
    sprintf(msg, "getSmoothingMask :: The value is %d\n", value);
    trace(msg);

    if (value == 0) {
        smoothingMask = 1;
    } else if (value == 1) {
        smoothingMask = 3;
    } else if (value == 2) {
        smoothingMask = 5;
    } else if (value == 3) {
        smoothingMask = 7;
    }

} // end getSmoothingMask


///////////////////////////////////////////////////////////////////////////////
//
// getPowerLawConstant
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::getPowerLawConstant(double value)
{
    char msg[128];
    sprintf(msg, "getPowerLawConstant :: The value is %lf\n", value);
    trace(msg);

    gltPowerLawConstant = value;

} // end getPowerLawConstant


///////////////////////////////////////////////////////////////////////////////
//
// getPowerLawGamma
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::getPowerLawGamma(double value)
{
    char msg[128];
    sprintf(msg, "getPowerLawGamma :: The value is %lf\n", value);
    trace(msg);

    gltPowerLawGamma = value;

} // end getPowerLawGamma


///////////////////////////////////////////////////////////////////////////////
//
// getSharpeningAlgorithm
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::getSharpeningAlgorithm(int value)
{
    char msg[128];
    sprintf(msg, "getSharpeningAlgorithm :: The value is %d\n", value);
    trace(msg);

    sharpeningAlgorithm = value;

} // end getSharpeningAlgorithm


///////////////////////////////////////////////////////////////////////////////
//
// getR1
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::getR1(int value)
{
    char msg[128];
    sprintf(msg, "getR1 :: The value is %d\n", value);
    trace(msg);

    r1 = value;

} // end getEdgeFilter


///////////////////////////////////////////////////////////////////////////////
//
// listFiles
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::listFiles(QString directoryName)
{
    QDir directory = QDir(directoryName);

    //QString fileName = "*.bmp; *.png; *.ppm";
    QString fileName = "*.bmp";


    t = directoryName.toStdString();
    datasetPath = t.c_str();

    printf("datasetPath = %s\n", t.c_str());

    if (fileName.isEmpty()) {
        fileName = "*";
    }

    // this will contain the list of images
    files = directory.entryList(QStringList(fileName), QDir::Files | QDir::NoSymLinks);

    // display for debug purposes
    for (int i=0; i<files.size(); i++) {
        QString temp = files.value(i);
        trace(temp);
    }

    // set the scroll bar to the number of images
    ui->imageScrollBar->setMaximum(files.size());

} // end listFiles


///////////////////////////////////////////////////////////////////////////////
//
// mousePressEvent
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    trace("mouse pressed");
    printf("Mouse pressed...\n");

} // end mousePressEvent


///////////////////////////////////////////////////////////////////////////////
//
// openImageDirectory
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::openImageDirectory()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select the first image or a movie file"));

    // first look and see if we have an avi file
    string t = fileName.toStdString();

    string toFind = ".avi";
    int found = 0;
    found = t.find(toFind);

    if (found > 0) {

        // go ahead and try to open it
        avi->aviInitialize(t);

        // if this is > 0, then we can read it
        if (avi->captureAVIFrames > 0) {

            // set the flag
            processingAVI1Files2 = 1;

            // and set the boundaries of the user interface bar
            ui->imageScrollBar->setMaximum(avi->captureAVIFrames);

        }

    } else {

        string toFind = "/";
        int  found = 0;
        found = t.find_last_of(toFind);

        string path;
        if (found > 0) {
            path = t.substr(0, found);
        }

        QString path2 = QString::fromStdString(path);
        trace(path2);

        dPath = path2.toStdString();

        char msg[128];
        sprintf(msg, "Found at %d", found);
        trace(msg);

        trace(fileName);

        listFiles(path2);

        // set the flag
        processingAVI1Files2 = 2;

    }

} // end openImageDirectory


///////////////////////////////////////////////////////////////////////////////
//
// resetDisplay
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::resetDisplay ()
{
    displayOption = SECOND_DISPLAY_BLANK;
    ui->comboBoxSecondWindow->setCurrentIndex(0);
    scene2->clear();
    scene->update();
    QApplication::processEvents();

} // end resetDisplay


///////////////////////////////////////////////////////////////////////////////
//
// timerEvent
//
// Might be useful at some point to have a timer event function set to go
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::timerEvent(QTimerEvent *)
{

    trace("timer event");

} // end timerEvent


///////////////////////////////////////////////////////////////////////////////
//
// trace
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::trace(QString str)
{

    ui->plainTextEditTrace->appendPlainText(str);

} // end trace


///////////////////////////////////////////////////////////////////////////////
//
// toggleAddGaussianNoise
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::toggleAddGaussianNoise()
{
    if (addGaussianNoise == 0) {
        addGaussianNoise = 1;
        trace("addGaussianNoise is TRUE");
    } else {
        addGaussianNoise = 0;
        trace("addGaussianNoise is FALSE");
    }

} // end toggleAddGaussianNoise


///////////////////////////////////////////////////////////////////////////////
//
// toggleFilter
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::toggleFilter()
{
    if (applyFilter == 0) {
        applyFilter = 1;
        trace("applyFilter is TRUE");
    } else {
        applyFilter = 0;
        trace("applyFilter is FALSE");
    }

} // end toggleFilter


///////////////////////////////////////////////////////////////////////////////
//
// toggleAddGammaNoise
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::toggleAddGammaNoise()
{
    if (addGammaNoise == 0) {
        addGammaNoise = 1;
        trace("addGammaNoise is TRUE");
    } else {
        addGammaNoise = 0;
        trace("addGammaNoise is FALSE");
    }

} // end toggleAddGammaNoise


///////////////////////////////////////////////////////////////////////////////
//
// toggleAddImpulseNoise
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::toggleAddImpulseNoise()
{
    if (addImpulseNoise == 0) {
        addImpulseNoise = 1;
        trace("addImpulseNoise is TRUE");
    } else {
        addImpulseNoise = 0;
        trace("addImpulseNoise is FALSE");
    }

} // end toggleAddImpulseNoise


///////////////////////////////////////////////////////////////////////////////
//
// toggleBitPlaneSlicing
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::toggleBitPlaneSlicing()
{
    if (gltBitPlane == 0) {
        gltBitPlane = 1;
        trace("bitPlaneSlicing is TRUE");
    } else {
        gltBitPlane = 0;
        trace("bitPlaneSlicing is FALSE");
    }

} // end toggleBitPlaneSlicing


///////////////////////////////////////////////////////////////////////////////
//
// toggleFitToWindow
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::toggleFitToWindow()
{
    if (fitImageToWindow == 0) {
        fitImageToWindow = 1;
        trace("fitToWindow is TRUE");
    } else {
        fitImageToWindow = 0;
        trace("fitToWindow is FALSE");
    }

} // end toggleFitToWindow


///////////////////////////////////////////////////////////////////////////////
//
// toggleContrastStretching
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::toggleContrastStretching()
{
    if (gltContrastStretching == 0) {
        gltContrastStretching = 1;
        trace("contrastStretching is TRUE");
    } else {
        gltContrastStretching = 0;
        trace("contrastStretching is FALSE");
    }

} // end toggleContrastStretching


///////////////////////////////////////////////////////////////////////////////
//
// toggleHistogramEqualization
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::toggleHistogramEqualization()
{
    if (histogramEqualization == 0) {
        histogramEqualization = 1;
        trace("histogramEqualization is TRUE");
    } else {
        histogramEqualization = 0;
        trace("histogramEqualization is FALSE");
    }

} // end toggleHistogramEqualization


///////////////////////////////////////////////////////////////////////////////
//
// toggleLogarithm
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::toggleLogarithm()
{
    if (gltLogarithm == 0) {
        gltLogarithm = 1;
        trace("gltLogarithm is TRUE");
    } else {
        gltNegative = 0;
        trace("gltLogarithm is FALSE");
        resetDisplay();
    }

} // end toggleLogarithm


///////////////////////////////////////////////////////////////////////////////
//
// toggleNegative
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::toggleNegative()
{
    if (gltNegative == 0) {
        gltNegative = 1;
        trace("gltNegative is TRUE");
    } else {
        gltNegative = 0;
        trace("gltNegative is FALSE");
        resetDisplay();
    }

} // end toggleNegative


///////////////////////////////////////////////////////////////////////////////
//
// togglePowerLaw
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::togglePowerLaw()
{
    if (gltPowerLaw == 0) {
        gltPowerLaw = 1;
        trace("powerLaw is TRUE");
    } else {
        gltPowerLaw = 0;
        trace("powerLaw is FALSE");
    }

} // end togglePowerLaw


///////////////////////////////////////////////////////////////////////////////
//
// toggleSegmentation
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::toggleSegmentation()
{
    if (segment == 0) {
        segment = 1;
        trace("segment is TRUE");
    } else {
        segment = 0;
        trace("segment is FALSE");
    }

} // end toggleSegmentation


///////////////////////////////////////////////////////////////////////////////
//
// toggleSharpeningAlgorithm
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::toggleSharpeningAlgorithm()
{
    if (sharpening == 0) {
        sharpening = 1;
        trace("sharpening is TRUE");
    } else {
        sharpening = 0;
        trace("sharpening is FALSE");
    }

} // end toggleSharpeningAlgorithm


///////////////////////////////////////////////////////////////////////////////
//
// toggleSmoothing
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::toggleSmoothing()
{
    if (smoothing == 0) {
        smoothing = 1;
        trace("smoothing is TRUE");
    } else {
        smoothing = 0;
        trace("smoothing is FALSE");
    }

} // end toggleSmoothing


///////////////////////////////////////////////////////////////////////////////
//
// toggleSwapRedBlue
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::toggleSwapRedBlue()
{
    if (swapRedBlue == 0) {
        swapRedBlue = 1;
        trace("swapRedBlue is TRUE");
    } else {
        swapRedBlue = 0;
        trace("swapRedBlue is FALSE");
    }

} // end toggleSwapRedBlue


///////////////////////////////////////////////////////////////////////////////
//
// updateImageNumber
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::updateImageNumber(int value)
{
    QString t = files.value(value);
    char t2[64];
    sprintf(t2, "%s", qPrintable(t));
    QString msg2 = t2;
    trace(msg2);

    char fileName[256];

    printf("%s\n", dPath.c_str());

    sprintf(fileName, "%s/%s", dPath.c_str(), t2);
    printf("%s\n", fileName);
    QString t3 = fileName;
    trace(fileName);

    // load the current frame
    IplImage *frame;
    if (processingAVI1Files2 == 1) {

        frame = avi->aviGrabFrame(ui->imageScrollBar->value()-1);

    } else if (processingAVI1Files2 == 2) {

        frame = cvLoadImage(fileName);
    }

    // swap red and blue
    if (swapRedBlue == true) {
        cvConvertImage(frame, frame, CV_CVTIMG_SWAP_RB);
    }

    // allocate room for the processed image
    //IplImage *processed = cvCreateImage(cvGetSize(frame), frame->depth, frame->nChannels);
    IplImage *processed;

    bool freeProcessedImage = false;
\
    ///////////////////////////////////////////////////////////////////////////
    //
    // apply any requested image processing
    //
    ///////////////////////////////////////////////////////////////////////////


    /////////////////////////////////////////////////////////////////
    //
    // histogram equalization
    //
    /////////////////////////////////////////////////////////////////

    if (histogramEqualization == true) {

        // histogram equalization
        TNT::Array2D<double> array = getArrayFromIplImage(frame);
        TNT::Array2D<double> temp;
        temp = runHistogramEqualization(array);

        //getIplImageFromArray2(temp, processed);
        processed = getIplImageFromArray2(temp);

        printf("ran histogram...,\n");

        freeProcessedImage = true;

    } // end histogram equalization


    /////////////////////////////////////////////////////////////////
    //
    // sharpening algorithms
    //
    /////////////////////////////////////////////////////////////////

    if (sharpening == true) {

        TNT::Array2D<double> array = getArrayFromIplImage(frame);
        TNT::Array2D<double> temp;

        if (sharpeningAlgorithm == SHARPENING_LAPLACIAN) {

            temp = laplacian(array);

        } else if (sharpeningAlgorithm == SHARPENING_GRADIENT) {

            temp = gradient(array);
        }

        //getIplImageFromArray2(temp, processed);
        processed = getIplImageFromArray2(temp);

        printf("ran sharpening...\n");

        freeProcessedImage = true;

    }

    /////////////////////////////////////////////////////////////////
    //
    // smoothing algorithms
    //
    /////////////////////////////////////////////////////////////////

    if (smoothing == true) {

        TNT::Array2D<double> array = getArrayFromIplImage(frame);
        TNT::Array2D<double> temp;

        // ???
        float q = 1.0;

        if (smoothingFilter == SMOOTHING_MF_ARITHMETIC) {
            temp = applyMeanFilter(array, smoothingMask);
        } else if (smoothingFilter == SMOOTHING_MF_GEOMETRIC) {
            temp = applyGeometricFilter(array, smoothingMask);
        } else if (smoothingFilter == SMOOTHING_MF_CONTRAHARMONIC) {
            temp = applyContraharmonicFilter(array, smoothingMask, q);
        } else if (smoothingFilter == SMOOTHING_MF_HARMONIC) {
            temp = applyHarmonicFilter(array, smoothingMask);
        } else if (smoothingFilter == SMOOTHING_OS_MEDIAN) {
            temp = applyMedianFilter(array, smoothingMask);
        } else if (smoothingFilter == SMOOTHING_OS_MAX) {
            temp = applyMaxFilter(array, smoothingMask);
        } else if (smoothingFilter == SMOOTHING_OS_MIN) {
            temp = applyMinFilter(array, smoothingMask);
        } else if (smoothingFilter == SMOOTHING_OS_MID) {
            temp = applyMidpointFilter(array, smoothingMask);
        } else if (smoothingFilter == SMOOTHING_OS_ALPHA) {
            temp = applyAlphaTrimmed(array, smoothingMask);
        } else if (smoothingFilter == SMOOTHING_ADAPT_LOCAL_NOISE) {
            temp = applyAdaptiveFilter(array, smoothingMask);
//        } else if (smoothingFilter == SMOOTHING_ADAPT_MED_FILTER) {
//            temp = applyAdaptiveMedianFilter(array, smoothingMask);
        }

        //getIplImageFromArray2(temp, processed);
        processed = getIplImageFromArray2(temp);

        printf("ran smoothing...\n");

        freeProcessedImage = true;
    }

    /////////////////////////////////////////////////////////////////
    //
    // grey level transformation :: negative
    //
    /////////////////////////////////////////////////////////////////

    if (gltNegative == true) {

        // grey level transformation :: negative
        TNT::Array2D<double> array = getArrayFromIplImage(frame);
        TNT::Array2D<double> temp;
        temp = negative(array);

        //getIplImageFromArray2(temp, processed);
        processed = getIplImageFromArray2(temp);

        printf("ran negative...\n");

        freeProcessedImage = true;

    }

    /////////////////////////////////////////////////////////////////
    //
    // grey level transformation :: logarithm
    //
    /////////////////////////////////////////////////////////////////

    if (gltLogarithm == true) {

        // grey level transformation :: logarithm
        TNT::Array2D<double> array = getArrayFromIplImage(frame);
        TNT::Array2D<double> temp;
        temp = logarithm(array, gltLogarithmConstant);

        //getIplImageFromArray2(temp, processed);
        processed = getIplImageFromArray2(temp);

        printf("ran negative...\n");

        freeProcessedImage = true;

    }

    /////////////////////////////////////////////////////////////////
    //
    // grey level transformation :: contrast stretching
    //
    /////////////////////////////////////////////////////////////////

    if (gltContrastStretching == true) {

        // grey level transformation :: piecewise linear
        TNT::Array2D<double> array = getArrayFromIplImage(frame);
        TNT::Array2D<double> temp;
        TNT::Array1D<int> lut;

        lut = findLUT(array, r1, s1, r2, s2);

        temp = contrastStretching(array, lut);

        //getIplImageFromArray2(temp, processed);
        processed = getIplImageFromArray2(temp);

        printf("ran contrast stretching...\n");

        freeProcessedImage = true;

    }

    /////////////////////////////////////////////////////////////////
    //
    // grey level transformation :: power law
    //
    /////////////////////////////////////////////////////////////////

    if (gltPowerLaw == true) {

        // grey level transformation :: power law
        TNT::Array2D<double> array = getArrayFromIplImage(frame);
        TNT::Array2D<double> temp;
        temp = powerLaw(array, gltPowerLawConstant, gltPowerLawGamma);

        //getIplImageFromArray2(temp, processed);
        processed = getIplImageFromArray2(temp);

        printf("ran power law...\n");

        freeProcessedImage = true;

    }

    /////////////////////////////////////////////////////////////////
    //
    // grey level transformation :: bit plane slicing
    //
    /////////////////////////////////////////////////////////////////

    if (gltBitPlane == true) {

        // grey level transformation :: bit plane slicing
        TNT::Array2D<double> array = getArrayFromIplImage(frame);
        TNT::Array2D<double> temp;
        temp = bitPlaneSlicing(array, bitPlane);

        //getIplImageFromArray2(temp, processed);
        processed = getIplImageFromArray2(temp);

        printf("ran bit plane slicing...\n");

        freeProcessedImage = true;

    }

    /////////////////////////////////////////////////////////////////
    //
    // edge detection
    //
    /////////////////////////////////////////////////////////////////

    if (applyFilter == true) {

        if (edgeFilter == 0) {

            processed = runCannyEdge(frame);
            freeProcessedImage = true;

        } else if (edgeFilter == 1) {

            processed = runSobelEdge(frame);
            freeProcessedImage = true;

        } else if (edgeFilter == 2) {

            processed = convolveWithOpenCV(frame, 1);
            freeProcessedImage = true;

        } else if (edgeFilter == 3) {

            // convert to grayscale.....
            IplImage *gray = cvCreateImage(cvGetSize(frame), 8, 1);
            cvCvtColor(frame, gray, CV_RGB2GRAY);
            printf("before convolve....");
            processed = convolveWithOpenCV(frame, 2);
            printf("after convolve....");
            cvReleaseImage(&gray);
            freeProcessedImage = true;
        }

    }

    /////////////////////////////////////////////////////////////////
    //
    // add noise
    //
    /////////////////////////////////////////////////////////////////

    if (addGaussianNoise == 1) {

    } else if (addGammaNoise == 1) {

    } else if (addImpulseNoise == 1) {

        TNT::Array2D<double> array = getArrayFromIplImage(frame);
        TNT::Array2D<double> temp;

        float percent = (float)impulseNoise * 0.01;
        temp = addNoiseImpulse(array, percent);

        //getIplImageFromArray2(temp, processed);
        processed = getIplImageFromArray2(temp);

        printf("ran impulse noise...\n");

        freeProcessedImage = true;

    }


    /////////////////////////////////////////////////////////////////
    //
    // segmentation algorithm
    //
    /////////////////////////////////////////////////////////////////

    if (segment == true) {

        processed = segmentation(frame, sigma, k, minSize);
        freeProcessedImage = true;

    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // handle the second display
    //
    ///////////////////////////////////////////////////////////////////////////

    if (displayOption == SECOND_DISPLAY_PROCESSED) {

        if (processed != NULL && fitImageToWindow == 0) {

            printf("trying to do the second display, no fitting\n");

            // update the display
            uchar *cv = (uchar*)(processed->imageData);
            QImage img(cv, processed->width, processed->height, QImage::Format_RGB888);

            scene2->clear();
            scene2->setSceneRect(0, 0, processed->width, processed->height);
            scene2->addPixmap(QPixmap::fromImage(img));
            scene2->update();
            QApplication::processEvents();

            printf("here3\n");

        } else if  (processed != NULL && fitImageToWindow == 1) {

            printf("trying to do the second display, fitting\n");

            IplImage *resized = cvCreateImage(cvSize(COLS, ROWS), processed->depth, processed->nChannels);

            trace("hist .... fitting to window....");
            cvResize(processed, resized, CV_INTER_LINEAR);

            // update the display
            uchar *cv = (uchar*)(resized->imageData);
            QImage img(cv, resized->width, resized->height, QImage::Format_RGB888);

            scene2->clear();
            scene2->setSceneRect(0, 0, resized->width, resized->height);
            scene2->addPixmap(QPixmap::fromImage(img));
            scene2->update();
            QApplication::processEvents();

            cvReleaseImage(&resized);

        }

    }

    // release the processing frame?
    if (freeProcessedImage == true) {
        cvReleaseImage(&processed);
        freeProcessedImage = false;
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    // main display image
    //
    ///////////////////////////////////////////////////////////////////////////

    if (frame != NULL && fitImageToWindow == 0) {

        // update the display
        uchar *cv = (uchar*)(frame->imageData);
        QImage img(cv, frame->width, frame->height, QImage::Format_RGB888);

        scene->clear();
        scene->setSceneRect(0, 0, frame->width, frame->height);
        scene->addPixmap(QPixmap::fromImage(img));
        scene->update();
        QApplication::processEvents();

    } else if (frame != NULL && fitImageToWindow == 1) {

        // swap red and blue
        cvConvertImage(frame, frame, CV_CVTIMG_SWAP_RB);

        IplImage *resized = cvCreateImage(cvSize(COLS, ROWS), frame->depth, frame->nChannels);

        trace("fitting to window....");
        cvResize(frame, resized, CV_INTER_LINEAR);

        // update the display
        uchar *cv = (uchar*)(resized->imageData);
        QImage img(cv, resized->width, resized->height, QImage::Format_RGB888);

        scene->clear();
        scene->setSceneRect(0, 0, resized->width, resized->height);
        scene->addPixmap(QPixmap::fromImage(img));
        scene->update();
        QApplication::processEvents();

        cvReleaseImage(&resized);

    }

    // update the status bar
    QString msg3 = fileName;
    ui->statusBar->showMessage(msg3);

    // release the current frame if we are loading from files
    if (processingAVI1Files2 == 1) {
        cvReleaseImage(&frame);
    }

} // end updateImageNumber

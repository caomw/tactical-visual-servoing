#include "mainwindow.h"
#include "ui_mainwindow.h"

#define COLS 640
#define ROWS 480

#define SECOND_DISPLAY_BLANK 0
#define SECOND_DISPLAY_PROCESSED 1
#define SECOND_DISPLAY_PREVIOUS 2

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
    edgeFilter = 0;

    histogramEqualization = false;
    gltNegative = false;

} // end contrsuctor


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

    // mouse events
    connect(ui->graphicsView, SIGNAL(mousePressEvent(QGraphicsSceneMouseEvent *)), this, SLOT(mousePressEvent(QGraphicsSceneMouseEvent *)));

    // histogram equalization
    connect(ui->checkBoxHistogramEqualization, SIGNAL(clicked()), this, SLOT(toggleHistogramEqualization()));

    // glt negative
    connect(ui->checkBoxNegative, SIGNAL(clicked()), this, SLOT(toggleNegative()));

    // edge filters
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
// listFiles
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::listFiles(QString directoryName)
{
    QDir directory = QDir(directoryName);
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

    string t = fileName.toStdString();
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
    IplImage *frame = cvLoadImage(fileName);

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
    // edge detection
    //
    /////////////////////////////////////////////////////////////////

    if (edgeFilter == 1) {

        runCannyEdge(frame, processed);

        freeProcessedImage = true;

    } else if (edgeFilter == 2) {

        runSobelEdge(frame, processed);

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

        // swap red and blue
        cvConvertImage(frame, frame, CV_CVTIMG_SWAP_RB);

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

    // release the current frame
    cvReleaseImage(&frame);

} // end updateImageNumber

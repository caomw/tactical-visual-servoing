#include "mainwindow.h"
#include "ui_mainwindow.h"

#define COLS 640
#define ROWS 480

//using namespace libmv;

///////////////////////////////////////////////////////////////////////////////
//
// function prototypes
//
///////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
//
// MainWindow constructor
//
///////////////////////////////////////////////////////////////////////////////

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    windowWidth = 640;
    windowHeight = 480;

    ui->setupUi(this);

    createActions();

    //timer.start(50);

    // instantiations
    utilities = new Utilities();
    imageFunctions = new ImageFunctions();
  //  turingTracking = new TuringTracking();

    // set the scene up with the graphicsview
    scene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);

    fitImageToWindow = 0;

    //windowWidth = ui->graphicsView->width();
    //windowHeight = ui->graphicsView->height();


    ui->statusBar->showMessage("NO DATASET LOADED");

    //iniFile = "TACTICAL.ini";

    //CSimpleIniA ini(true, true, true);
    //SI_Error rc = ini.LoadFile(iniFile.c_str());

}


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
    //delete turingTracking;
}

///////////////////////////////////////////////////////////////////////////////
//
// trace
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::trace(QString str)
{
    ui->plainTextEditTrace->appendPlainText(str);
}


///////////////////////////////////////////////////////////////////////////////
//
// on_pushButtonTrack_clicked
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::on_pushButtonTrack_clicked()
{
    // display for debug purposes
    for (int i=0; i<files.size(); i++) {

        QString temp = files.value(i);

        string t2 = temp.toStdString();

        string name = t + '/' + t2;

        printf("loading...%s\n", name.c_str());

        IplImage *tmp = cvLoadImage(name.c_str());

        // swap red and blue
        cvConvertImage(tmp, tmp, CV_CVTIMG_SWAP_RB);

        printf("%d, %d...\n", tmp->height, tmp->width);

        // update the display
        IplImage *resized = cvCreateImage(cvSize(windowHeight, windowWidth), tmp->depth, tmp->nChannels);

        // fit the image to the window?
        if (fitImageToWindow == 1) {
            trace("fitting to window....");
            cvResize(tmp, resized, CV_INTER_LINEAR);
            cvSaveImage("resized.bmp", resized);
            printf("resized...[%d,%d]\n", windowWidth, windowHeight);
            printf("resized...[%d,%d]\n", ui->graphicsView->width(), ui->graphicsView->height());
        }

//        uchar *cv = (uchar*)(tmp->imageData);
//        QImage img(cv, tmp->width, tmp->height, QImage::Format_RGB888);

        uchar *cv;
        QImage *img;

        if (fitImageToWindow == 1) {
            cv = (uchar*)(resized->imageData);
            img = new QImage(cv, resized->width, resized->height, QImage::Format_RGB888);
        } else {
            cv = (uchar*)(tmp->imageData);
            img = new QImage(cv, tmp->width, tmp->height, QImage::Format_RGB888);
        }

        // TODO :: this needs some work yet because i cannot refresh the screen properly with the new image coming in
        scene->clear();
        scene->setSceneRect(0, 0, tmp->width, tmp->height);
        scene->addPixmap(QPixmap::fromImage(*img));
        scene->update();
        QApplication::processEvents();

        cvReleaseImage(&tmp);
        cvReleaseImage(&resized);

        // update the status bar
        QString msg2 = name.c_str();
        ui->statusBar->showMessage(msg2);


    }

    /**

    string msg = "Current tab index = " + utilities->itos(ui->tabWidget->currentIndex());
    trace(msg.c_str());

    // correlation tracking
    if (ui->tabWidget->currentIndex() == 0) {

        // grab the current values set and set those in the tracking algorithms


    QAction *action_Open_Sequence;
    QAction *action_About;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tabCorrelation;
    QLabel *labelConstOffset;
    QSpinBox *spinBoxConstOffset;
    QLabel *labelSearchRadius;
    QSpinBox *spinBoxSearchRadius;
    QLabel *labelSearchLevels;
    QSpinBox *spinBoxSearchLevels;
    QLabel *labelMinSample;
    QLabel *labelFovealKernelBaseConstant;
    QLabel *labelFovealKernelNumLevels;
    QLabel *labelFovealKernelTypeSpacing;
    QCheckBox *checkBoxDisplayFovealKernel;
    QDoubleSpinBox *doubleSpinBoxMinSample;
    QDoubleSpinBox *doubleSpinBoxFovealKernelBaseConstant;
    QSpinBox *spinBoxFovealKernelNumLevels;
    QComboBox *comboBoxFovealKernelTypeSpacing;
    QLabel *labelCorrErrorThresh;
    QLabel *labelDegeneracyThresh;
    QLabel *labelShapeChangeThresh;
    QLabel *labelRejectionRateTimeConstant;
    QLabel *labelRejectionRateThresh;
    QLabel *labelConstExpansionThresh;
    QLabel *labelInverseConstellationExpansionThresh;
    QLabel *labelStarOutOfBounds;
    QLabel *labelCenterOutOfBounds;
    QDoubleSpinBox *doubleSpinBoxCorrErrorThresh;
    QDoubleSpinBox *doubleSpinBoxDegeneracyThresh;
    QDoubleSpinBox *doubleSpinBoxShapeChangeThresh;
    QDoubleSpinBox *doubleSpinBoxRejectionRateTimeConstant;
    QDoubleSpinBox *doubleSpinBoxRejectionRateThresh;
    QSpinBox *spinBoxConstExpansionThresh;
    QDoubleSpinBox *doubleSpinBoxInverseConstellationExpansionThresh;
    QSpinBox *spinBoxStarOutOfBounds;
    QSpinBox *spinBoxCenterOutOfBounds;
    QWidget *tabOpticalFlow;
    QWidget *tabBlob;
    QGraphicsView *graphicsView;
    QPlainTextEdit *plainTextEditTrace;
    QPushButton *pushButtonTrack;
    QCheckBox *checkBox_2;
    QScrollBar *horizontalScrollBar;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Help;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;


        ///////////////////////////////////////////////////////////////////////
        // GOOD FEATURES


        // find good features using Shi and Tomasi

        // first, allocate the storage
        IplImage *curr  = imageFunctions->aviGrabFrame(ui->horizontalScrollBar->value());
        IplImage *grey  = cvCreateImage(cvSize(datasetWidth, datasetHeight), 8, 1);
        IplImage *eigen = cvCreateImage(cvSize(datasetWidth, datasetHeight), IPL_DEPTH_32F, 1);
        IplImage *temp  = cvCreateImage(cvSize(datasetWidth, datasetHeight), IPL_DEPTH_32F, 1);
        CvPoint2D32f features[500];
        int numberFeatures = 500;

        // convert the frame to grayscale
        cvCvtColor(curr, grey, CV_BGR2GRAY);

        // parameters:
        //  grey: input greyscale image
        //  eigen: working storage
        //  temp: working storage
        //  features: this will contain the feature points
        //  minQuality: minimum quality of the features based on the eigenvalues
        //  minDistance: minimum Euclidean distance between features
        float minQuality  = 0.01;
        float minDistance = 5.0;
        cvGoodFeaturesToTrack(grey, eigen, temp, features, &numberFeatures, minQuality, minDistance, NULL);

        IplImage *draw = cvCreateImage(cvSize(datasetWidth, datasetHeight), 8, 3);

        cvCopy(curr, draw, 0);
        for (int i=0; i<numberFeatures; i++) {
            cvCircle(draw, cvPointFrom32f(features[i]), 3, CV_RGB(0,255,0), -1, 8, 0);
        }

        // update the display
        uchar *cv = (uchar*)(draw->imageData);

        QImage img(cv, temp->width, temp->height, QImage::Format_RGB888);

        scene->clear();
        scene->addPixmap(QPixmap::fromImage(img));
        scene->update();

        // release memory
        cvReleaseImage(&curr);
        cvReleaseImage(&eigen);
        cvReleaseImage(&temp);
        cvReleaseImage(&draw);
        cvReleaseImage(&grey);


        // END GOOD FEATURES
        ///////////////////////////////////////////////////////////////////////
    }
**/

}


///////////////////////////////////////////////////////////////////////////////
//
// timerEvent
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::timerEvent(QTimerEvent *)
{
    trace("timer event");
}

///////////////////////////////////////////////////////////////////////////////
//
// updateImageNumber
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::updateImageNumber(int value)
{

    QString t = files.value(value);
    char t2[64];
    sprintf(t2, "%s\0", qPrintable(t));
    QString msg2 = t2;
    trace(msg2);

    char fileName[256];

    printf("%s\n", dPath.c_str());

    sprintf(fileName, "%s/%s\0", dPath.c_str(), t2);
    printf("%s\n", fileName);
    QString t3 = fileName;
    trace(fileName);

    IplImage *tmp = cvLoadImage(fileName);

    if (tmp != NULL && fitImageToWindow == 0) {

        // swap red and blue
        cvConvertImage(tmp, tmp, CV_CVTIMG_SWAP_RB);

        // update the display
        uchar *cv = (uchar*)(tmp->imageData);
        QImage img(cv, tmp->width, tmp->height, QImage::Format_RGB888);

        scene->clear();
        scene->setSceneRect(0, 0, tmp->width, tmp->height);
        scene->addPixmap(QPixmap::fromImage(img));
        scene->update();
        QApplication::processEvents();

        cvReleaseImage(&tmp);

    } else if (tmp != NULL && fitImageToWindow == 1) {

        // swap red and blue
        cvConvertImage(tmp, tmp, CV_CVTIMG_SWAP_RB);

        //IplImage *resized = cvCreateImage(cvSize(windowHWidth, windowHeight), tmp->depth, tmp->nChannels);
        IplImage *resized = cvCreateImage(cvSize(640, 480), tmp->depth, tmp->nChannels);

        trace("fitting to window....");
        cvResize(tmp, resized, CV_INTER_LINEAR);
        //cvSaveImage("resized.bmp", resized);
        printf("resized...[%d,%d]\n", windowWidth, windowHeight);
        printf("resized...[%d,%d]\n", ui->graphicsView->width(), ui->graphicsView->height());
        printf("resized...[%d,%d]\n", COLS, ROWS);

        // update the display
        uchar *cv = (uchar*)(resized->imageData);
        QImage img(cv, resized->width, resized->height, QImage::Format_RGB888);

        scene->clear();
        scene->setSceneRect(0, 0, resized->width, resized->height);
        scene->addPixmap(QPixmap::fromImage(img));
        scene->update();
        QApplication::processEvents();

        cvReleaseImage(&tmp);
        cvReleaseImage(&resized);

    }

     // update the status bar
     QString msg3 = fileName;
     ui->statusBar->showMessage(msg3);

}


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

    // mouse events
    connect(ui->graphicsView, SIGNAL(mousePressEvent(QGraphicsSceneMouseEvent *)), this, SLOT(mousePressEvent(QGraphicsSceneMouseEvent *)));

}


///////////////////////////////////////////////////////////////////////////////
//
// exitApplication
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::exitApplication()
{
    QApplication::exit();
}


///////////////////////////////////////////////////////////////////////////////
//
// mousePressEvent
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    trace("mouse pressed");
    printf("Mouse pressed...\n");

}

///////////////////////////////////////////////////////////////////////////////
//
// openImageDirectory
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::openImageDirectory()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select the first image or a movie file"));

    // This shows fine in Linux, but not under Windows.....reverting back to getOpenFileName
    //QString fileName = QFileDialog::getExistingDirectory(this, tr("Select the directory containing bitmap images"));

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
    sprintf(msg, "Found at %d\0", found);
    trace(msg);

    trace(fileName);

    //listFiles(fileName);
    listFiles(path2);



//    //QString fileName = QFileDialog::getOpenName(this, tr("Select the first image or a movie file"));
//    QString fileName = QFileDialog::getExistingDirectory(this, tr("Select the directory containing bitmap images"));
//    trace(fileName);

//    listFiles(fileName);
    
/**    

    // try opening the avi
    imageFunctions->aviInitialize(fileName.toStdString());
    int numFrames = imageFunctions->captureAVIFrames;

    if (numFrames > 0) {

        datasetName = fileName;
        datasetLoaded = true;

        // set the bounds of the horizontal scroll bar
        ui->horizontalScrollBar->setMaximum(numFrames);

        ui->statusBar->showMessage("Dataset loaded...");

        // load the first image so we can get the height and width
        //  and load the first image on the ui
        IplImage *temp = imageFunctions->aviGrabFrame(0);
        datasetHeight = temp->height;
        datasetWidth  = temp->width;

        uchar *cv = (uchar*)(temp->imageData);

        QImage img(cv, temp->width, temp->height, QImage::Format_RGB888);

        scene->clear();
        scene->addPixmap(QPixmap::fromImage(img));
        scene->update();
    }
 **/   

}

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

    //datasetPath = directoryName;
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
}

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

}


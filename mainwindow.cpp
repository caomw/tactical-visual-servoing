#include "mainwindow.h"
#include "ui_mainwindow.h"

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

    ui->statusBar->showMessage("NO DATASET LOADED");
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
        uchar *cv = (uchar*)(tmp->imageData);

        QImage img(cv, tmp->width, tmp->height, QImage::Format_RGB888);

        // TODO :: this needs some work yet because i cannot refresh the screen properly with the new image coming in
        scene->clear();
        scene->setSceneRect(0, 0, tmp->width, tmp->height);
        scene->addPixmap(QPixmap::fromImage(img));
        scene->update();
        QApplication::processEvents();

        cvReleaseImage(&tmp);

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
    /**
    // load an IplImage
    CvSize size;
    size.height = datasetHeight;
    size.width  = datasetWidth;

    IplImage *temp = imageFunctions->aviGrabFrame(value-1);
    uchar *cv = (uchar*)(temp->imageData);

    string msg = "AVI :: frame = " + utilities->itos(value-1);
    trace(msg.c_str());

    QImage img(cv, temp->width, temp->height, QImage::Format_RGB888);

    scene->clear();
    scene->addPixmap(QPixmap::fromImage(img));
    scene->update();

    // update the status bar
    string tmp = datasetName.toStdString() + "  " + utilities->itos(value) + "/" + utilities->itos(imageFunctions->captureAVIFrames);
    QString msg2 = tmp.c_str();
    ui->statusBar->showMessage(msg2);

    // free memory
    cvReleaseImage(&temp);
    **/
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

    // scroll bar
    connect(ui->horizontalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(updateImageNumber(int)));

}

///////////////////////////////////////////////////////////////////////////////
//
// mousePressEvent
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    trace("mouse pressed");

}

///////////////////////////////////////////////////////////////////////////////
//
// openImageDirectory
//
///////////////////////////////////////////////////////////////////////////////

void MainWindow::openImageDirectory()
{
    //QString fileName = QFileDialog::getOpenName(this, tr("Select the first image or a movie file"));
    QString fileName = QFileDialog::getExistingDirectory(this, tr("Select the directory containing bitmap images"));
    trace(fileName);

    listFiles(fileName);
    
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
}


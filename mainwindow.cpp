#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace libmv;

void WriteOutputImage(const FloatImage &image,
                      CorrespondencesView<KLTPointFeature>::Iterator features,
                      const char *output_filename);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createActions();

    timer.start(50);

    // instantiations
    utilities = new Utilities();
    imageFunctions = new ImageFunctions();
  //  turingTracking = new TuringTracking();

    // set the scene up with the graphicsview
    scene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);

    ui->statusBar->showMessage("NO DATASET LOADED");
}

MainWindow::~MainWindow()
{
    // clean up memory
    delete ui;
    delete utilities;
    delete imageFunctions;
    //delete turingTracking;
}

void MainWindow::trace(QString str){
    ui->plainTextEditTrace->appendPlainText(str);
}

void MainWindow::on_pushButtonTrack_clicked()
{



/** klt stuff
    vector<string> files;
    string path = "/home/lab/Desktop/WoodPile/";
    string base = "captured";
    for (int i=503; i<730; i++) {
        string fileName = path + base + utilities->itos(i) + ".pgm";
        files.push_back(fileName);
        trace(fileName.c_str());
    }

    ImageCache cache;
    ImageSequence *source = ImageSequenceFromFiles(files, &cache);
    PyramidSequence *pyramid_sequence = MakePyramidSequence(source, 5, 1.5);

    KLTContext klt;
    Correspondences correspondences;

    // TODO(keir): Really have to get a scoped_ptr<> implementation!
    // Consider taking the one from boost but editing out the cruft.
    ImagePyramid *pyramid = pyramid_sequence->Pyramid(0);
    KLTContext::FeatureList features;
    klt.DetectGoodFeatures(pyramid->Level(0), &features);
    int i = 0;
    for (KLTContext::FeatureList::iterator it = features.begin();
        it != features.end(); ++it, ++i) {
        correspondences.Insert(0, i, *it);
    }

    CorrespondencesView<KLTPointFeature> klt_correspondences(&correspondences);
    WriteOutputImage(pyramid_sequence->Pyramid(0)->Level(0), klt_correspondences.ScanFeaturesForImage(0),(files[0]+".out.ppm").c_str());

    // TODO(keir): Use correspondences here!
    for (size_t i = 1; i < files.size(); ++i) {
        printf("Tracking %2zd features in %s\n", features.size(), files[i].c_str());

        CorrespondencesView<KLTPointFeature>::Iterator it =
        klt_correspondences.ScanFeaturesForImage(i-1);
        for (; !it.Done(); it.Next()) {
        KLTPointFeature *next_position = new KLTPointFeature;
        if (klt.TrackFeature(pyramid_sequence->Pyramid(i-1), *it.feature(), pyramid_sequence->Pyramid(i), next_position)) {
            correspondences.Insert(i, it.track(), next_position);
        } else {
            delete next_position;
        }
    }

    //
        WriteOutputImage(pyramid_sequence->Pyramid(i)->Level(0), klt_correspondences.ScanFeaturesForImage(i),
            (files[i]+".out.ppm").c_str());
        }
        **/


    string msg = "Current tab index = " + utilities->itos(ui->tabWidget->currentIndex());
    trace(msg.c_str());

    // correlation tracking
    if (ui->tabWidget->currentIndex() == 0) {

        // grab the current values set and set those in the tracking algorithms

    /**
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
    **/

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

}

void MainWindow::timerEvent(QTimerEvent *)
{
    trace("timer event");
}

void MainWindow::updateImageNumber(int value)
{
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
}


void MainWindow::createActions()
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(timeout()));

    // file open
    connect(ui->action_Open_Sequence, SIGNAL(triggered()), this, SLOT(openImageDirectory()) );

    // scroll bar
    connect(ui->horizontalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(updateImageNumber(int)));

}

void MainWindow::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    trace("mouse pressed");

}

void MainWindow::openImageDirectory()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select the first image or a movie file"));
    trace(fileName);

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

}

void MainWindow::listFiles()
{
    QDir directory = QDir("C:\\Data_Collection\\21\\bmps\\");
    QString fileName = "*.bmp";
    QStringList files;
    if (fileName.isEmpty())
        fileName = "*";
    files = directory.entryList(QStringList(fileName), QDir::Files | QDir::NoSymLinks);

    for (int i=0; i<files.size(); i++) {
        QString temp = files.value(i);
        trace(temp);
    }
}

void WriteOutputImage(const FloatImage &image,
                      CorrespondencesView<KLTPointFeature>::Iterator features,
                      const char *output_filename) {
 /**
  FloatImage output_image(image.Height(), image.Width(), 3);
  for (int i = 0; i < image.Height(); ++i) {
    for (int j = 0; j < image.Width(); ++j) {
      output_image(i,j,0) = image(i,j);
      output_image(i,j,1) = image(i,j);
      output_image(i,j,2) = image(i,j);
    }
  }

  Vec3 green;
  green << 0, 1, 0;
  for (; !features.Done(); features.Next()) {
    DrawFeature(*features.feature(), green, &output_image);
  }

  WritePnm(output_image, output_filename);
  **/
}

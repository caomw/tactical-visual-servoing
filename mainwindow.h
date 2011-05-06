#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>

#include <QTimer>
#include <QGraphicsScene>
#include <QFileDialog>
#include <QDir>
#include <QtCore/QStringList>

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
    QGraphicsScene *scene2;

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

    string iniFile;
    string dPath;

    int displayOption;
    int edgeFilter;

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

    double gltLogarithmConstant;
    double gltPowerLawConstant;
    double gltPowerLawGamma;

    int processingAVI1Files2;

protected:

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

protected Q_SLOTS:

    void getBitPlane(int);
    void getDisplayOption(int);
    void getLogarithmConstant(double value);
    void getPowerLawConstant(double value);
    void getPowerLawGamma(double value);
    void getR1(int);
    void getEdgeFilter(int);
    void exitApplication();
    void openImageDirectory();
    void toggleBitPlaneSlicing();
    void toggleContrastStretching();
    void toggleFitToWindow();
    void toggleHistogramEqualization();
    void toggleLogarithm();
    void toggleNegative();
    void togglePowerLaw();
    void updateImageNumber(int);

private slots:

    void timerEvent(QTimerEvent *);
    void on_pushButtonTrack_clicked();

};

#endif // MAINWINDOW_H

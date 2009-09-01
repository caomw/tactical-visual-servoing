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

// move these too, this is just a test for libmv
#include <algorithm>
#include <vector>
#include "libmv/image/image.h"
#include "libmv/image/image_io.h"
#include "libmv/image/image_pyramid.h"
#include "libmv/image/image_sequence_io.h"
#include "libmv/image/cached_image_sequence.h"
#include "libmv/image/pyramid_sequence.h"
#include "libmv/correspondence/correspondence.h"
#include "libmv/correspondence/feature.h"
#include "libmv/correspondence/klt.h"

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

private:
    Ui::MainWindow *ui;
    void createActions();
    void listFiles(QString);
    string itos(int i);
    QGraphicsScene *scene;

    bool datasetLoaded;
    QString datasetName;
    QString datasetPath;
    string t;
    QStringList files;
    int datasetWidth;
    int datasetHeight;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

protected Q_SLOTS:
    void openImageDirectory();
    void updateImageNumber(int);

private slots:
    void timerEvent(QTimerEvent *);
    void on_pushButtonTrack_clicked();

};

#endif // MAINWINDOW_H

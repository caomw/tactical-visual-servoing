/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed May 25 10:53:24 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      36,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x09,
      29,   11,   11,   11, 0x09,
      51,   11,   11,   11, 0x09,
      70,   11,   11,   11, 0x09,
      91,   11,   11,   11, 0x09,
     120,   11,   11,   11, 0x09,
     140,   11,   11,   11, 0x09,
     168,   11,   11,   11, 0x09,
     193,   11,   11,   11, 0x09,
     204,   11,   11,   11, 0x09,
     214,   11,   11,   11, 0x09,
     230,   11,   11,   11, 0x09,
     258,   11,   11,   11, 0x09,
     275,   11,   11,   11, 0x09,
     299,   11,   11,   11, 0x09,
     321,   11,   11,   11, 0x09,
     339,   11,   11,   11, 0x09,
     360,   11,   11,   11, 0x09,
     385,   11,   11,   11, 0x09,
     407,   11,   11,   11, 0x09,
     431,   11,   11,   11, 0x09,
     455,   11,   11,   11, 0x09,
     482,   11,   11,   11, 0x09,
     497,   11,   11,   11, 0x09,
     517,   11,   11,   11, 0x09,
     547,   11,   11,   11, 0x09,
     565,   11,   11,   11, 0x09,
     582,   11,   11,   11, 0x09,
     602,   11,   11,   11, 0x09,
     619,   11,   11,   11, 0x09,
     640,   11,   11,   11, 0x09,
     668,   11,   11,   11, 0x09,
     686,   11,   11,   11, 0x09,
     706,   11,   11,   11, 0x09,
     729,   11,   11,   11, 0x08,
     754,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0getBitPlane(int)\0"
    "getDisplayOption(int)\0getEdgeFilter(int)\0"
    "getImpulseNoise(int)\0getLogarithmConstant(double)\0"
    "getOFAlgorithm(int)\0getPowerLawConstant(double)\0"
    "getPowerLawGamma(double)\0getR1(int)\0"
    "getK(int)\0getMinSize(int)\0"
    "getSharpeningAlgorithm(int)\0"
    "getSigma(double)\0getSmoothingFilter(int)\0"
    "getSmoothingMask(int)\0exitApplication()\0"
    "openImageDirectory()\0toggleAddGaussianNoise()\0"
    "toggleAddGammaNoise()\0toggleAddImpulseNoise()\0"
    "toggleBitPlaneSlicing()\0"
    "toggleContrastStretching()\0toggleFilter()\0"
    "toggleFitToWindow()\0toggleHistogramEqualization()\0"
    "toggleLogarithm()\0toggleNegative()\0"
    "toggleOpticalFlow()\0togglePowerLaw()\0"
    "toggleSegmentation()\0toggleSharpeningAlgorithm()\0"
    "toggleSmoothing()\0toggleSwapRedBlue()\0"
    "updateImageNumber(int)\0timerEvent(QTimerEvent*)\0"
    "on_pushButtonTrack_clicked()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: getBitPlane((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: getDisplayOption((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: getEdgeFilter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: getImpulseNoise((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: getLogarithmConstant((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: getOFAlgorithm((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: getPowerLawConstant((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: getPowerLawGamma((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: getR1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: getK((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: getMinSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: getSharpeningAlgorithm((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: getSigma((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: getSmoothingFilter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: getSmoothingMask((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: exitApplication(); break;
        case 16: openImageDirectory(); break;
        case 17: toggleAddGaussianNoise(); break;
        case 18: toggleAddGammaNoise(); break;
        case 19: toggleAddImpulseNoise(); break;
        case 20: toggleBitPlaneSlicing(); break;
        case 21: toggleContrastStretching(); break;
        case 22: toggleFilter(); break;
        case 23: toggleFitToWindow(); break;
        case 24: toggleHistogramEqualization(); break;
        case 25: toggleLogarithm(); break;
        case 26: toggleNegative(); break;
        case 27: toggleOpticalFlow(); break;
        case 28: togglePowerLaw(); break;
        case 29: toggleSegmentation(); break;
        case 30: toggleSharpeningAlgorithm(); break;
        case 31: toggleSmoothing(); break;
        case 32: toggleSwapRedBlue(); break;
        case 33: updateImageNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: timerEvent((*reinterpret_cast< QTimerEvent*(*)>(_a[1]))); break;
        case 35: on_pushButtonTrack_clicked(); break;
        default: ;
        }
        _id -= 36;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

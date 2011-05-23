/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon May 23 08:24:35 2011
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
      35,   14, // methods
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
      97,   91,   11,   11, 0x09,
     126,   91,   11,   11, 0x09,
     154,   91,   11,   11, 0x09,
     179,   11,   11,   11, 0x09,
     190,   11,   11,   11, 0x09,
     200,   11,   11,   11, 0x09,
     216,   11,   11,   11, 0x09,
     244,   11,   11,   11, 0x09,
     261,   11,   11,   11, 0x09,
     285,   11,   11,   11, 0x09,
     307,   11,   11,   11, 0x09,
     325,   11,   11,   11, 0x09,
     346,   11,   11,   11, 0x09,
     371,   11,   11,   11, 0x09,
     393,   11,   11,   11, 0x09,
     417,   11,   11,   11, 0x09,
     441,   11,   11,   11, 0x09,
     468,   11,   11,   11, 0x09,
     483,   11,   11,   11, 0x09,
     503,   11,   11,   11, 0x09,
     533,   11,   11,   11, 0x09,
     551,   11,   11,   11, 0x09,
     568,   11,   11,   11, 0x09,
     588,   11,   11,   11, 0x09,
     605,   11,   11,   11, 0x09,
     626,   11,   11,   11, 0x09,
     654,   11,   11,   11, 0x09,
     672,   11,   11,   11, 0x09,
     692,   11,   11,   11, 0x09,
     715,   11,   11,   11, 0x08,
     740,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0getBitPlane(int)\0"
    "getDisplayOption(int)\0getEdgeFilter(int)\0"
    "getImpulseNoise(int)\0value\0"
    "getLogarithmConstant(double)\0"
    "getPowerLawConstant(double)\0"
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
        case 5: getPowerLawConstant((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: getPowerLawGamma((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: getR1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: getK((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: getMinSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: getSharpeningAlgorithm((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: getSigma((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: getSmoothingFilter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: getSmoothingMask((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: exitApplication(); break;
        case 15: openImageDirectory(); break;
        case 16: toggleAddGaussianNoise(); break;
        case 17: toggleAddGammaNoise(); break;
        case 18: toggleAddImpulseNoise(); break;
        case 19: toggleBitPlaneSlicing(); break;
        case 20: toggleContrastStretching(); break;
        case 21: toggleFilter(); break;
        case 22: toggleFitToWindow(); break;
        case 23: toggleHistogramEqualization(); break;
        case 24: toggleLogarithm(); break;
        case 25: toggleNegative(); break;
        case 26: toggleOpticalFlow(); break;
        case 27: togglePowerLaw(); break;
        case 28: toggleSegmentation(); break;
        case 29: toggleSharpeningAlgorithm(); break;
        case 30: toggleSmoothing(); break;
        case 31: toggleSwapRedBlue(); break;
        case 32: updateImageNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: timerEvent((*reinterpret_cast< QTimerEvent*(*)>(_a[1]))); break;
        case 34: on_pushButtonTrack_clicked(); break;
        default: ;
        }
        _id -= 35;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

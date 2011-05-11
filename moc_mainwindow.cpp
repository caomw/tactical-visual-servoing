/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed May 11 09:44:25 2011
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
      29,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x09,
      29,   11,   11,   11, 0x09,
      51,   11,   11,   11, 0x09,
      78,   72,   11,   11, 0x09,
     107,   72,   11,   11, 0x09,
     135,   72,   11,   11, 0x09,
     160,   11,   11,   11, 0x09,
     171,   11,   11,   11, 0x09,
     190,   11,   11,   11, 0x09,
     218,   11,   11,   11, 0x09,
     242,   11,   11,   11, 0x09,
     264,   11,   11,   11, 0x09,
     282,   11,   11,   11, 0x09,
     303,   11,   11,   11, 0x09,
     328,   11,   11,   11, 0x09,
     350,   11,   11,   11, 0x09,
     374,   11,   11,   11, 0x09,
     398,   11,   11,   11, 0x09,
     425,   11,   11,   11, 0x09,
     445,   11,   11,   11, 0x09,
     475,   11,   11,   11, 0x09,
     493,   11,   11,   11, 0x09,
     510,   11,   11,   11, 0x09,
     527,   11,   11,   11, 0x09,
     555,   11,   11,   11, 0x09,
     573,   11,   11,   11, 0x09,
     593,   11,   11,   11, 0x09,
     616,   11,   11,   11, 0x08,
     641,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0getBitPlane(int)\0"
    "getDisplayOption(int)\0getImpulseNoise(int)\0"
    "value\0getLogarithmConstant(double)\0"
    "getPowerLawConstant(double)\0"
    "getPowerLawGamma(double)\0getR1(int)\0"
    "getEdgeFilter(int)\0getSharpeningAlgorithm(int)\0"
    "getSmoothingFilter(int)\0getSmoothingMask(int)\0"
    "exitApplication()\0openImageDirectory()\0"
    "toggleAddGaussianNoise()\0toggleAddGammaNoise()\0"
    "toggleAddImpulseNoise()\0toggleBitPlaneSlicing()\0"
    "toggleContrastStretching()\0"
    "toggleFitToWindow()\0toggleHistogramEqualization()\0"
    "toggleLogarithm()\0toggleNegative()\0"
    "togglePowerLaw()\0toggleSharpeningAlgorithm()\0"
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
        case 2: getImpulseNoise((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: getLogarithmConstant((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: getPowerLawConstant((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: getPowerLawGamma((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: getR1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: getEdgeFilter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: getSharpeningAlgorithm((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: getSmoothingFilter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: getSmoothingMask((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: exitApplication(); break;
        case 12: openImageDirectory(); break;
        case 13: toggleAddGaussianNoise(); break;
        case 14: toggleAddGammaNoise(); break;
        case 15: toggleAddImpulseNoise(); break;
        case 16: toggleBitPlaneSlicing(); break;
        case 17: toggleContrastStretching(); break;
        case 18: toggleFitToWindow(); break;
        case 19: toggleHistogramEqualization(); break;
        case 20: toggleLogarithm(); break;
        case 21: toggleNegative(); break;
        case 22: togglePowerLaw(); break;
        case 23: toggleSharpeningAlgorithm(); break;
        case 24: toggleSmoothing(); break;
        case 25: toggleSwapRedBlue(); break;
        case 26: updateImageNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: timerEvent((*reinterpret_cast< QTimerEvent*(*)>(_a[1]))); break;
        case 28: on_pushButtonTrack_clicked(); break;
        default: ;
        }
        _id -= 29;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

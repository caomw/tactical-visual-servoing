/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed May 11 08:36:00 2011
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
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x09,
      29,   11,   11,   11, 0x09,
      57,   51,   11,   11, 0x09,
      86,   51,   11,   11, 0x09,
     114,   51,   11,   11, 0x09,
     139,   11,   11,   11, 0x09,
     150,   11,   11,   11, 0x09,
     169,   11,   11,   11, 0x09,
     197,   11,   11,   11, 0x09,
     221,   11,   11,   11, 0x09,
     243,   11,   11,   11, 0x09,
     261,   11,   11,   11, 0x09,
     282,   11,   11,   11, 0x09,
     306,   11,   11,   11, 0x09,
     333,   11,   11,   11, 0x09,
     353,   11,   11,   11, 0x09,
     383,   11,   11,   11, 0x09,
     401,   11,   11,   11, 0x09,
     418,   11,   11,   11, 0x09,
     435,   11,   11,   11, 0x09,
     463,   11,   11,   11, 0x09,
     481,   11,   11,   11, 0x09,
     501,   11,   11,   11, 0x09,
     524,   11,   11,   11, 0x08,
     549,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0getBitPlane(int)\0"
    "getDisplayOption(int)\0value\0"
    "getLogarithmConstant(double)\0"
    "getPowerLawConstant(double)\0"
    "getPowerLawGamma(double)\0getR1(int)\0"
    "getEdgeFilter(int)\0getSharpeningAlgorithm(int)\0"
    "getSmoothingFilter(int)\0getSmoothingMask(int)\0"
    "exitApplication()\0openImageDirectory()\0"
    "toggleBitPlaneSlicing()\0"
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
        case 2: getLogarithmConstant((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: getPowerLawConstant((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: getPowerLawGamma((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: getR1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: getEdgeFilter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: getSharpeningAlgorithm((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: getSmoothingFilter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: getSmoothingMask((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: exitApplication(); break;
        case 11: openImageDirectory(); break;
        case 12: toggleBitPlaneSlicing(); break;
        case 13: toggleContrastStretching(); break;
        case 14: toggleFitToWindow(); break;
        case 15: toggleHistogramEqualization(); break;
        case 16: toggleLogarithm(); break;
        case 17: toggleNegative(); break;
        case 18: togglePowerLaw(); break;
        case 19: toggleSharpeningAlgorithm(); break;
        case 20: toggleSmoothing(); break;
        case 21: toggleSwapRedBlue(); break;
        case 22: updateImageNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: timerEvent((*reinterpret_cast< QTimerEvent*(*)>(_a[1]))); break;
        case 24: on_pushButtonTrack_clicked(); break;
        default: ;
        }
        _id -= 25;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

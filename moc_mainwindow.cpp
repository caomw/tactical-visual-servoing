/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Fri May 6 13:05:23 2011
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
      19,   14, // methods
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
     187,   11,   11,   11, 0x09,
     208,   11,   11,   11, 0x09,
     232,   11,   11,   11, 0x09,
     259,   11,   11,   11, 0x09,
     279,   11,   11,   11, 0x09,
     309,   11,   11,   11, 0x09,
     327,   11,   11,   11, 0x09,
     344,   11,   11,   11, 0x09,
     361,   11,   11,   11, 0x09,
     384,   11,   11,   11, 0x08,
     409,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0getBitPlane(int)\0"
    "getDisplayOption(int)\0value\0"
    "getLogarithmConstant(double)\0"
    "getPowerLawConstant(double)\0"
    "getPowerLawGamma(double)\0getR1(int)\0"
    "getEdgeFilter(int)\0exitApplication()\0"
    "openImageDirectory()\0toggleBitPlaneSlicing()\0"
    "toggleContrastStretching()\0"
    "toggleFitToWindow()\0toggleHistogramEqualization()\0"
    "toggleLogarithm()\0toggleNegative()\0"
    "togglePowerLaw()\0updateImageNumber(int)\0"
    "timerEvent(QTimerEvent*)\0"
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
        case 7: exitApplication(); break;
        case 8: openImageDirectory(); break;
        case 9: toggleBitPlaneSlicing(); break;
        case 10: toggleContrastStretching(); break;
        case 11: toggleFitToWindow(); break;
        case 12: toggleHistogramEqualization(); break;
        case 13: toggleLogarithm(); break;
        case 14: toggleNegative(); break;
        case 15: togglePowerLaw(); break;
        case 16: updateImageNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: timerEvent((*reinterpret_cast< QTimerEvent*(*)>(_a[1]))); break;
        case 18: on_pushButtonTrack_clicked(); break;
        default: ;
        }
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

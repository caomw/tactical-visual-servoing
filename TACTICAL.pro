#-------------------------------------------------
#
# Project created by QtCreator 2009-07-20T18:55:21
#
#-------------------------------------------------

QT += network opengl

# OpenCV
win32 {
    INCLUDEPATH += C:\OpenCVTemp\cv\include
    INCLUDEPATH += C:\OpenCVTemp\otherlibs\highgui
    INCLUDEPATH += C:\OpenCVTemp\cxcore\include
    INCLUDEPATH += C:\OpenCVTemp\cvaux\include
}

linux {
    INCLUDEPATH += /usr/include/opencv
    INCLUDEPATH += /usr/include/opencv
    INCLUDEPATH += /home/lab/Development/libmv/src
    INCLUDEPATH += /home/lab/Development/libmv/src/third_party/eigen
}

# libmv
win32 {
    INCLUDEPATH += C:\libmv\src
    INCLUDEPATH += C:\libmv\src\third_party\eigen
}

# OpenCV
win32 {
    LIBS += C:\OpenCVTemp\lib\cv.lib
    LIBS += C:\OpenCVTemp\lib\highgui.lib
    LIBS += C:\OpenCVTemp\lib\cxcore.lib
    LIBS += C:\OpenCVTemp\lib\cvaux.lib
}

linux {
    LIBS += -lcv -lcxcore -lhighgui
}

#libmv
win32 {
    LIBS += C:\libmv\lib\image.lib
    LIBS += C:\libmv\lib\correspondence.lib
    LIBS += C:\libmv\lib\numeric.lib
}

linux {
    LIBS += -lcorrespondence -limage -lglog -lgflags
}

TARGET = TACTICAL
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp\
        utilities\utilities.cpp\
        image_functions\Image_Functions.cpp\
 #       tracking_algorithms\correlation\TuringTracking.cpp

HEADERS += mainwindow.h\
        utilities\utilities.h\
        image_functions\Image_Functions.h\
#        tracking_algorithms\correlation\TuringTracking.h

FORMS += mainwindow.ui

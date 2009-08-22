#-------------------------------------------------
#
# Project created by QtCreator 2009-07-20T18:55:21
#
#-------------------------------------------------

# this codebase is a mess right now.....
#  be sure to copy libturingtracking.a to /usr/local/lib


QT += network opengl

# OpenCV
win32 {
    INCLUDEPATH += C:\OpenCVTemp\cv\include
    INCLUDEPATH += C:\OpenCVTemp\otherlibs\highgui
    INCLUDEPATH += C:\OpenCVTemp\cxcore\include
    INCLUDEPATH += C:\OpenCVTemp\cvaux\include

}

unix {
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

# correlation tracking
unix {
    INCLUDEPATH += tracking_algorithms/Correlation/TuringTracking
}

# gsl
win32 {
    INCLUDEPATH += C:\gsl-1.8-lib\include
}

# OpenCV
win32 {
    LIBS += C:\OpenCVTemp\lib\cv.lib
    LIBS += C:\OpenCVTemp\lib\highgui.lib
    LIBS += C:\OpenCVTemp\lib\cxcore.lib
    LIBS += C:\OpenCVTemp\lib\cvaux.lib
}

unix {
    LIBS += -lcv -lcxcore -lhighgui
}

#libmv
win32 {
    LIBS += C:\libmv\lib\image.lib
    LIBS += C:\libmv\lib\correspondence.lib
    LIBS += C:\libmv\lib\numeric.lib
}

unix {
    LIBS += -lcorrespondence -limage -lglog -lgflags -lgsl -lgslcblas
}

# correlation tracking
unix {
    LIBS += -lturingtracking
}

# gsl
win32 {
    LIBS += C:\gsl-1.8-lib\lib\libgsl.a
    LIBS += C:\gsl-1.8-lib\lib\libgslcblas.a
}

unix {
    LIBS += -lgsl -lgslcblas
}

# sdl
unix {
    LIBS += -lSDL -lSDL_image
}

TARGET = TACTICAL
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp\
        utilities\utilities.cpp\
        image_functions\Image_Functions.cpp\
        tracking_algorithms/SIFT/imgfeatures.cpp \
        tracking_algorithms/SIFT/kdtree.cpp \
        tracking_algorithms/SIFT/minpq.cpp \
        tracking_algorithms/SIFT/sift.cpp \
        tracking_algorithms/SIFT/utils.cpp \
        tracking_algorithms/SIFT/xform.cpp
 #       tracking_algorithms\correlation\TuringTracking.cpp

HEADERS += mainwindow.h\
        utilities\utilities.h\
        image_functions\Image_Functions.h\
        tracking_algorithms/SIFT/imgfeatures.h \
        tracking_algorithms/SIFT/kdtree.h \
        tracking_algorithms/SIFT/minpq.h \
        tracking_algorithms/SIFT/sift.h \
        tracking_algorithms/SIFT/utils.h \
        tracking_algorithms/SIFT/xform.h
#        tracking_algorithms\correlation\TuringTracking.h

FORMS += mainwindow.ui

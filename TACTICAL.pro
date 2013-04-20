#-------------------------------------------------
#
# Project created by QtCreator 2009-07-20T18:55:21
#
#-------------------------------------------------

# this codebase is a mess right now.....
#  be sure to copy libturingtracking.a to /usr/local/lib


#QT += network opengl
QT += widgets

CONFIG += console

# OpenCV
#win32 {
#    INCLUDEPATH += C:\TACTICAL\OpenCV\cv\include
#    INCLUDEPATH += C:\TACTICAL\OpenCV\otherlibs\highgui
#    INCLUDEPATH += C:\TACTICAL\OpenCV\cxcore\include
#    INCLUDEPATH += C:\TACTICAL\OpenCV\cvaux\include
#}

#unix {
     INCLUDEPATH += /opt/local/include
#    INCLUDEPATH += /usr/local/include/opencv
#    INCLUDEPATH += /usr/local/include/opencv
    #INCLUDEPATH += /home/lab/Development/libmv/src
    #INCLUDEPATH += /home/lab/Development/libmv/src/third_party/eigen
#}

# graph-based segmentation
INCLUDEPATH += segmentation


# correlation tracking
#unix {
    INCLUDEPATH += tracking_algorithms/Correlation/TuringTracking
#}

# gsl
#win32 {
#    INCLUDEPATH += C:\TACTICAL\gsl-1.8-lib\include
#}

# sdl
#win32 {
#    INCLUDEPATH += C:\TACTICAL\SDL-1.2.13\include
#}

# OpenCV
#win32 {
#    LIBS += C:\TACTICAL\OpenCV\lib\cv.lib
#    LIBS += C:\TACTICAL\OpenCV\lib\highgui.lib
#    LIBS += C:\TACTICAL\OpenCV\lib\cxcore.lib
#    LIBS += C:\TACTICAL\OpenCV\lib\cvaux.lib
#}

#unix {
    #LIBS += -lcv -lcxcore -lhighgui
    #LIBS += -L /usr/local/lib -lopencv_calib3d -lopencv_contrib -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_objdetect -lopencv_video -lopencv_highgui -lopencv_core
    LIBS += -L /opt/local/lib -lopencv_calib3d -lopencv_contrib -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_objdetect -lopencv_video -lopencv_highgui -lopencv_core
#}

# correlation tracking
#unix {
#    LIBS += -lturingtracking
#}

# gsl
#win32 {
#    LIBS += C:\TACTICAL\gsl-1.8-lib\lib\libgsl.a
#    LIBS += C:\TACTICAL\gsl-1.8-lib\lib\libgslcblas.a
#}

#unix {
   # LIBS += -lgsl -lgslcblas
#}

# sdl
#unix {
  #  LIBS += -lSDL -lSDL_image
#}
#win32 {
#    LIBS += C:\TACTICAL\SDL-1.2.13\lib\SDL.lib
#    LIBS += C:\TACTICAL\SDL-1.2.13\lib\SDL_image.lib
#}

# math
#unix {
    LIBS += -lm
#}

# birchfield klt (I am not sure why I have to copy libklt.a to /usr/lib, it was hung up on finding KLTStoreFeatureList
#unix {
#    LIBS += -lklt
#}

# fft library
#unix {
#    LIBS += -lfftw3
#}
#win32 {
#    INCLUDEPATH += C:\TACTICAL\fftw3
#    LIBS += C:\TACTICAL\fftw3\fftw3.lib
#}


TARGET = TACTICAL
TEMPLATE = app

SOURCES += main.cpp \
        mainwindow.cpp \
        image_functions\Image_Functions.cpp \
        ImageProcessing.cpp \
        utilities\utilities.cpp \
        ConvertUTF.c \
        tracking_algorithms/Optical_Flow/KLT/KLT.cpp \
        avi/AVILibrary.cpp \
        segmentation\segment.cpp \
    #    FFTLibrary.cpp \
        VideoDisplay.cpp

HEADERS += mainwindow.h \
        image_functions\Image_Functions.h \
        ImageProcessing.h \
        utilities\utilities.h \
        image_functions/Image_Functions.h \
        SimpleIni.h \
        ConvertUTF.h \
        tracking_algorithms/Optical_Flow/KLT/KLT.h \
        avi/AVILibrary.h \
        segmentation.h \
     #   FFTLibrary.h \
        VideoDisplay.h

FORMS += mainwindow.ui

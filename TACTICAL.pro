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
    INCLUDEPATH += C:\TACTICAL\OpenCV\cv\include
    INCLUDEPATH += C:\TACTICAL\OpenCV\otherlibs\highgui
    INCLUDEPATH += C:\TACTICAL\OpenCV\cxcore\include
    INCLUDEPATH += C:\TACTICAL\OpenCV\cvaux\include

}

unix {
    INCLUDEPATH += /usr/local/include/opencv
    INCLUDEPATH += /usr/local/include/opencv
    #INCLUDEPATH += /home/lab/Development/libmv/src
    #INCLUDEPATH += /home/lab/Development/libmv/src/third_party/eigen
}

# libmv
win32 {
#    INCLUDEPATH += C:\libmv\src
#    INCLUDEPATH += C:\libmv\src\third_party\eigen
}

# correlation tracking
unix {
    INCLUDEPATH += tracking_algorithms/Correlation/TuringTracking
}

# gsl
win32 {
    INCLUDEPATH += C:\TACTICAL\gsl-1.8-lib\include
}

# sdl
win32 {
    INCLUDEPATH += C:\TACTICAL\SDL-1.2.13\include
}

# OpenCV
win32 {
    LIBS += C:\TACTICAL\OpenCV\lib\cv.lib
    LIBS += C:\TACTICAL\OpenCV\lib\highgui.lib
    LIBS += C:\TACTICAL\OpenCV\lib\cxcore.lib
    LIBS += C:\TACTICAL\OpenCV\lib\cvaux.lib
}

unix {
    #LIBS += -lcv -lcxcore -lhighgui
    LIBS += -L /usr/local/lib -lopencv_calib3d -lopencv_contrib -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_objdetect -lopencv_video -lopencv_highgui -lopencv_core
}

#libmv
win32 {
#    LIBS += C:\libmv\lib\image.lib
#    LIBS += C:\libmv\lib\correspondence.lib
#    LIBS += C:\libmv\lib\numeric.lib
}

unix {
#    LIBS += -lcorrespondence -limage -lglog -lgflags -lgsl -lgslcblas
}

# correlation tracking
unix {
#    LIBS += -lturingtracking
}

# gsl
win32 {
    LIBS += C:\TACTICAL\gsl-1.8-lib\lib\libgsl.a
    LIBS += C:\TACTICAL\gsl-1.8-lib\lib\libgslcblas.a
}

unix {
    LIBS += -lgsl -lgslcblas
}

# sdl
unix {
    LIBS += -lSDL -lSDL_image
}
win32 {
    LIBS += C:\TACTICAL\SDL-1.2.13\lib\SDL.lib
    LIBS += C:\TACTICAL\SDL-1.2.13\lib\SDL_image.lib
}

# math
unix {
    LIBS += -lm
}

# birchfield klt (I am not sure why I have to copy libklt.a to /usr/lib, it was hung up on finding KLTStoreFeatureList
unix {
#    LIBS += -lklt
}


TARGET = TACTICAL
TEMPLATE = app

SOURCES += main.cpp \
        mainwindow.cpp \
        image_functions\Image_Functions.cpp \
        ImageProcessing.cpp \
        utilities\utilities.cpp \
        ConvertUTF.c \
        tracking_algorithms/Optical_Flow/KLT/KLT.cpp

        # sift (hess)
 #       tracking_algorithms/Blob/SIFT/imgfeatures.cpp \
 #       tracking_algorithms/Blob/SIFT/kdtree.cpp \
 #       tracking_algorithms/Blob/SIFT/minpq.cpp \
 #       tracking_algorithms/Blob/SIFT/sift.cpp \
 #       tracking_algorithms/Blob/SIFT/utils.cpp \
 #       tracking_algorithms/Blob/SIFT/xform.cpp \
        # horn schunck optical flow
 #       tracking_algorithms/Optical_Flow/Horn_Schunck/Horn_Schunck.cpp \
       # stan birchfield's klt tracker (http://www.ces.clemson.edu/~stb/klt/index.html)
 #       tracking_algorithms/Optical_Flow/klt++/convolve.cpp \
 #       tracking_algorithms/Optical_Flow/klt++/error.cpp \
 #       tracking_algorithms/Optical_Flow/klt++/klt.cpp \
 #       tracking_algorithms/Optical_Flow/klt++/klt_util.cpp \
 #       tracking_algorithms/Optical_Flow/klt++/pnmio.cpp \
 #       tracking_algorithms/Optical_Flow/klt++/pyramid.cpp \
 #       tracking_algorithms/Optical_Flow/klt++/selectGoodFeatures.cpp \
 #       tracking_algorithms/Optical_Flow/klt++/trackFeatures.cpp \
 #       tracking_algorithms/Optical_Flow/klt++/writeFeatures.cpp \
        # farneback's polynomial expansion
        #tracking_algorithms/Optical_Flow/Farneback/Farneback.cpp \
        # opencv's lk implementation
        #tracking_algorithms/Optical_Flow/LK_OpenCV/LK_OpenCV.cpp \
        # OpenSURF
        #tracking_algorithms/Blob/OpenSURF/utils_surf.cpp \
        #tracking_algorithms/Blob/OpenSURF/integral.cpp \
        #tracking_algorithms/Blob/OpenSURF/fasthessian.cpp \
        #tracking_algorithms/Blob/OpenSURF/surf.cpp \
        #tracking_algorithms/Blob/OpenSURF/ipoint.cpp
        # correlation - only build in windows
        #tracking_algorithms/Correlation/TuringTracking/TuringTracking.cpp

HEADERS += mainwindow.h \
        image_functions\Image_Functions.h \
        ImageProcessing.h \
        utilities\utilities.h \
        image_functions/Image_Functions.h \
        SimpleIni.h \
        ConvertUTF.h \
        tracking_algorithms/Optical_Flow/KLT/KLT.h

        # sift (hess)
#        tracking_algorithms/Blob/SIFT/imgfeatures.h \
#        tracking_algorithms/Blob/SIFT/kdtree.h \
#        tracking_algorithms/Blob/SIFT/minpq.h \
#        tracking_algorithms/Blob/SIFT/sift.h \
#        tracking_algorithms/Blob/SIFT/utils.h \
#        tracking_algorithms/Blob/SIFT/xform.h \
        # horn schunck optical flow
#        tracking_algorithms/Optical_Flow/Horn_Schunck/Horn_Schunck.h \
        # stan birchfield's klt tracker (http://www.ces.clemson.edu/~stb/klt/index.html)
#        tracking_algorithms/Optical_Flow/klt++/klt.h \
#        tracking_algorithms/Optical_Flow/klt++/klt_util.h \
#        tracking_algorithms/Optical_Flow/klt++/base.h \
#        tracking_algorithms/Optical_Flow/klt++/convolve.h \
#        tracking_algorithms/Optical_Flow/klt++/error.h \
#        tracking_algorithms/Optical_Flow/klt++/pnmio.h \
#        tracking_algorithms/Optical_Flow/klt++/pyramid.h \
        # farneback's polynomial expansion
        #tracking_algorithms/Optical_Flow/Farneback/Farneback.h \
        # opencv's lk implementation
 #       tracking_algorithms/Optical_Flow/LK_OpenCV/LK_OpenCV.h \
        # OpenSURF
 #       tracking_algorithms/Blob/OpenSURF/surflib.h \
 #       tracking_algorithms/Blob/OpenSURF/utils_surf.h \
 #       tracking_algorithms/Blob/OpenSURF/integral.h \
 #       tracking_algorithms/Blob/OpenSURF/fasthessian.h \
 #       tracking_algorithms/Blob/OpenSURF/surf.h \
 #       tracking_algorithms/Blob/OpenSURF/ipoint.h \
 #       tracking_algorithms/Blob/OpenSURF/kmeans.h
        # turing tracking -- only build in windows
        #tracking_algorithms/Correlation/TuringTracking/TuringTracking.h

FORMS += mainwindow.ui

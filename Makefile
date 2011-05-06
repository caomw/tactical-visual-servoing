#############################################################################
# Makefile for building: TACTICAL
# Generated by qmake (2.01a) (Qt 4.7.0) on: Fri May 6 12:28:58 2011
# Project:  TACTICAL.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile TACTICAL.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_OPENGL_LIB -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtNetwork -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtOpenGL -I/usr/include/qt4 -I/usr/local/include/opencv -I/usr/local/include/opencv -Itracking_algorithms/Correlation/TuringTracking -I/usr/X11R6/include -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib -L/usr/X11R6/lib -L /usr/local/lib -lopencv_calib3d -lopencv_contrib -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_objdetect -lopencv_video -lopencv_highgui -lopencv_core -lgsl -lgslcblas -lSDL -lSDL_image -lm -lQtOpenGL -lQtGui -lQtNetwork -lQtCore -lGLU -lGL -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		image_functions/Image_Functions.cpp \
		ImageProcessing.cpp \
		utilities/utilities.cpp \
		ConvertUTF.c \
		tracking_algorithms/Optical_Flow/KLT/KLT.cpp \
		avi/AVILibrary.cpp moc_mainwindow.cpp
OBJECTS       = main.o \
		mainwindow.o \
		Image_Functions.o \
		ImageProcessing.o \
		utilities.o \
		ConvertUTF.o \
		KLT.o \
		AVILibrary.o \
		moc_mainwindow.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/opengl.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		TACTICAL.pro
QMAKE_TARGET  = TACTICAL
DESTDIR       = 
TARGET        = TACTICAL

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: TACTICAL.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/opengl.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtOpenGL.prl \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtNetwork.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile TACTICAL.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/opengl.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtOpenGL.prl:
/usr/lib/libQtGui.prl:
/usr/lib/libQtNetwork.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile TACTICAL.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/TACTICAL1.0.0 || $(MKDIR) .tmp/TACTICAL1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/TACTICAL1.0.0/ && $(COPY_FILE) --parents mainwindow.h image_functions/Image_Functions.h ImageProcessing.h utilities/utilities.h image_functions/Image_Functions.h SimpleIni.h ConvertUTF.h tracking_algorithms/Optical_Flow/KLT/KLT.h avi/AVILibrary.h .tmp/TACTICAL1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp image_functions/Image_Functions.cpp ImageProcessing.cpp utilities/utilities.cpp ConvertUTF.c tracking_algorithms/Optical_Flow/KLT/KLT.cpp avi/AVILibrary.cpp .tmp/TACTICAL1.0.0/ && $(COPY_FILE) --parents mainwindow.ui .tmp/TACTICAL1.0.0/ && (cd `dirname .tmp/TACTICAL1.0.0` && $(TAR) TACTICAL1.0.0.tar TACTICAL1.0.0 && $(COMPRESS) TACTICAL1.0.0.tar) && $(MOVE) `dirname .tmp/TACTICAL1.0.0`/TACTICAL1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/TACTICAL1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp
moc_mainwindow.cpp: image_functions/Image_Functions.h \
		utilities/utilities.h \
		tracking_algorithms/Optical_Flow/KLT/KLT.h \
		avi/AVILibrary.h \
		SimpleIni.h \
		ConvertUTF.h \
		ImageProcessing.h \
		third_party/tnt/tnt.h \
		third_party/tnt/tnt_version.h \
		third_party/tnt/tnt_math_utils.h \
		third_party/tnt/tnt_array1d.h \
		third_party/tnt/tnt_i_refvec.h \
		third_party/tnt/tnt_array2d.h \
		third_party/tnt/tnt_array3d.h \
		third_party/tnt/tnt_array1d_utils.h \
		third_party/tnt/tnt_array2d_utils.h \
		third_party/tnt/tnt_array3d_utils.h \
		third_party/tnt/tnt_fortran_array1d.h \
		third_party/tnt/tnt_fortran_array2d.h \
		third_party/tnt/tnt_fortran_array3d.h \
		third_party/tnt/tnt_fortran_array1d_utils.h \
		third_party/tnt/tnt_fortran_array2d_utils.h \
		third_party/tnt/tnt_fortran_array3d_utils.h \
		third_party/tnt/tnt_sparse_matrix_csr.h \
		third_party/tnt/tnt_stopwatch.h \
		third_party/tnt/tnt_subscript.h \
		third_party/tnt/tnt_vec.h \
		third_party/tnt/tnt_cmat.h \
		mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h
ui_mainwindow.h: mainwindow.ui
	/usr/bin/uic-qt4 mainwindow.ui -o ui_mainwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h \
		image_functions/Image_Functions.h \
		utilities/utilities.h \
		tracking_algorithms/Optical_Flow/KLT/KLT.h \
		avi/AVILibrary.h \
		SimpleIni.h \
		ConvertUTF.h \
		ImageProcessing.h \
		third_party/tnt/tnt.h \
		third_party/tnt/tnt_version.h \
		third_party/tnt/tnt_math_utils.h \
		third_party/tnt/tnt_array1d.h \
		third_party/tnt/tnt_i_refvec.h \
		third_party/tnt/tnt_array2d.h \
		third_party/tnt/tnt_array3d.h \
		third_party/tnt/tnt_array1d_utils.h \
		third_party/tnt/tnt_array2d_utils.h \
		third_party/tnt/tnt_array3d_utils.h \
		third_party/tnt/tnt_fortran_array1d.h \
		third_party/tnt/tnt_fortran_array2d.h \
		third_party/tnt/tnt_fortran_array3d.h \
		third_party/tnt/tnt_fortran_array1d_utils.h \
		third_party/tnt/tnt_fortran_array2d_utils.h \
		third_party/tnt/tnt_fortran_array3d_utils.h \
		third_party/tnt/tnt_sparse_matrix_csr.h \
		third_party/tnt/tnt_stopwatch.h \
		third_party/tnt/tnt_subscript.h \
		third_party/tnt/tnt_vec.h \
		third_party/tnt/tnt_cmat.h \
		tracking_algorithms/Correlation/TuringTracking/TuringTracking.h \
		tracking_algorithms/Correlation/TuringTracking/SimpleIni.h \
		tracking_algorithms/Correlation/TuringTracking/ConvertUTF.h \
		tracking_algorithms/Optical_Flow/Horn_Schunck/Horn_Schunck.h \
		tracking_algorithms/Optical_Flow/Farneback/Farneback.h \
		tracking_algorithms/Optical_Flow/klt++/klt.h \
		tracking_algorithms/Optical_Flow/klt++/klt_util.h \
		tracking_algorithms/Optical_Flow/klt++/pnmio.h \
		tracking_algorithms/Optical_Flow/LK_OpenCV/LK_OpenCV.h \
		tracking_algorithms/Blob/SIFT/sift.h \
		tracking_algorithms/Blob/SIFT/imgfeatures.h \
		tracking_algorithms/Blob/SIFT/kdtree.h \
		tracking_algorithms/Blob/SIFT/utils.h \
		tracking_algorithms/Blob/SIFT/xform.h \
		tracking_algorithms/Blob/OpenSURF/surflib.h \
		tracking_algorithms/Blob/OpenSURF/integral.h \
		tracking_algorithms/Blob/OpenSURF/fasthessian.h \
		tracking_algorithms/Blob/OpenSURF/ipoint.h \
		tracking_algorithms/Blob/OpenSURF/surf.h \
		tracking_algorithms/Blob/OpenSURF/utils_surf.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		image_functions/Image_Functions.h \
		utilities/utilities.h \
		tracking_algorithms/Optical_Flow/KLT/KLT.h \
		avi/AVILibrary.h \
		SimpleIni.h \
		ConvertUTF.h \
		ImageProcessing.h \
		third_party/tnt/tnt.h \
		third_party/tnt/tnt_version.h \
		third_party/tnt/tnt_math_utils.h \
		third_party/tnt/tnt_array1d.h \
		third_party/tnt/tnt_i_refvec.h \
		third_party/tnt/tnt_array2d.h \
		third_party/tnt/tnt_array3d.h \
		third_party/tnt/tnt_array1d_utils.h \
		third_party/tnt/tnt_array2d_utils.h \
		third_party/tnt/tnt_array3d_utils.h \
		third_party/tnt/tnt_fortran_array1d.h \
		third_party/tnt/tnt_fortran_array2d.h \
		third_party/tnt/tnt_fortran_array3d.h \
		third_party/tnt/tnt_fortran_array1d_utils.h \
		third_party/tnt/tnt_fortran_array2d_utils.h \
		third_party/tnt/tnt_fortran_array3d_utils.h \
		third_party/tnt/tnt_sparse_matrix_csr.h \
		third_party/tnt/tnt_stopwatch.h \
		third_party/tnt/tnt_subscript.h \
		third_party/tnt/tnt_vec.h \
		third_party/tnt/tnt_cmat.h \
		ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

Image_Functions.o: image_functions/Image_Functions.cpp image_functions/Image_Functions.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Image_Functions.o image_functions/Image_Functions.cpp

ImageProcessing.o: ImageProcessing.cpp ImageProcessing.h \
		third_party/tnt/tnt.h \
		third_party/tnt/tnt_version.h \
		third_party/tnt/tnt_math_utils.h \
		third_party/tnt/tnt_array1d.h \
		third_party/tnt/tnt_i_refvec.h \
		third_party/tnt/tnt_array2d.h \
		third_party/tnt/tnt_array3d.h \
		third_party/tnt/tnt_array1d_utils.h \
		third_party/tnt/tnt_array2d_utils.h \
		third_party/tnt/tnt_array3d_utils.h \
		third_party/tnt/tnt_fortran_array1d.h \
		third_party/tnt/tnt_fortran_array2d.h \
		third_party/tnt/tnt_fortran_array3d.h \
		third_party/tnt/tnt_fortran_array1d_utils.h \
		third_party/tnt/tnt_fortran_array2d_utils.h \
		third_party/tnt/tnt_fortran_array3d_utils.h \
		third_party/tnt/tnt_sparse_matrix_csr.h \
		third_party/tnt/tnt_stopwatch.h \
		third_party/tnt/tnt_subscript.h \
		third_party/tnt/tnt_vec.h \
		third_party/tnt/tnt_cmat.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ImageProcessing.o ImageProcessing.cpp

utilities.o: utilities/utilities.cpp utilities/utilities.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o utilities.o utilities/utilities.cpp

ConvertUTF.o: ConvertUTF.c tracking_algorithms/Correlation/TuringTracking/ConvertUTF.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o ConvertUTF.o ConvertUTF.c

KLT.o: tracking_algorithms/Optical_Flow/KLT/KLT.cpp tracking_algorithms/Optical_Flow/KLT/KLT.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o KLT.o tracking_algorithms/Optical_Flow/KLT/KLT.cpp

AVILibrary.o: avi/AVILibrary.cpp avi/AVILibrary.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AVILibrary.o avi/AVILibrary.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:


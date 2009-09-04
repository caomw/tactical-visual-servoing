
///////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2009 Shawn T. Hunt
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use,
// copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following
// conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.
//
//
// Source file: main.cpp
// Author: Shawn Hunt (shawn.t.hunt@gmail.com)
//
// This code has been developed to support my thesis on goal-based
//  visual servoing.  It is being made publicly available in the hopes
//  that it is of benefit to others.  If any errors have been found or
//  if you find it useful, please drop me a note.
//
// This is a total hack right now.  The end goal is to have this support
//  an image sequence or a movie file.  I am having issues with OpenCV
//  working under Linux that is limiting this right now.  I have it limited
//  to only look for bitmaps in the specified directory but that can be
//  easily changed.
//
// Due to the limited amount of storage available at Google code, the datasets
//  that I have been working with are published at:
//  http://tigrs.eng.wayne.edu/code.html
//
///////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#ifdef unix
    #include "SDL/SDL.h"
    #include "SDL/SDL_image.h"
    #include <dirent.h>
#endif

#ifdef win32
    #include "SDL.h"
    #include "SDL_image.h"
#endif

#include <QtGui/QApplication>
#include "mainwindow.h"

// OpenGL
#include <GL/gl.h>
#include <GL/glu.h>

// tracking
#include "tracking_algorithms/Correlation/TuringTracking/TuringTracking.h"

// optical flow :: horn schunck
#include "tracking_algorithms/Optical_Flow/Horn_Schunck/Horn_Schunck.h"

// optical flow :: farneback
#include "tracking_algorithms/Optical_Flow/Farneback/Farneback.h"

// optical flow :: klt++
#include "tracking_algorithms/Optical_Flow/klt++/klt.h"
#include "tracking_algorithms/Optical_Flow/klt++/pnmio.h"

// optical flow :: opencv's lk tracker
#include "tracking_algorithms/Optical_Flow/LK_OpenCV/LK_OpenCV.h"

// blob :: sift
#include "tracking_algorithms/Blob/SIFT/sift.h"
#include "tracking_algorithms/Blob/SIFT/imgfeatures.h"
#include "tracking_algorithms/Blob/SIFT/kdtree.h"
#include "tracking_algorithms/Blob/SIFT/utils.h"
#include "tracking_algorithms/Blob/SIFT/xform.h"

// blob :: surf
#include "tracking_algorithms/Blob/OpenSURF/surflib.h"
#include "tracking_algorithms/Blob/OpenSURF/integral.h"
#include "tracking_algorithms/Blob/OpenSURF/fasthessian.h"
#include "tracking_algorithms/Blob/OpenSURF/surf.h"
#include "tracking_algorithms/Blob/OpenSURF/ipoint.h"
#include "tracking_algorithms/Blob/OpenSURF/utils_surf.h"

#include "ImageProcessing.h"
#include "image_functions/Image_Functions.h"

// move these too, this is just a test for libmv
#include <algorithm>
#include <vector>

#include "libmv/image/image.h"
#include "libmv/image/image_io.h"
#include "libmv/image/image_pyramid.h"
#include "libmv/image/image_sequence_io.h"
#include "libmv/image/cached_image_sequence.h"
#include "libmv/image/pyramid_sequence.h"
#include "libmv/correspondence/correspondence.h"
#include "libmv/correspondence/feature.h"
#include "libmv/correspondence/klt.h"

// this is a hack until I can get sdl events recognized from within qt
#define USEQT_0_USESDL_1 1

// sift defines
#define KDTREE_BBF_MAX_NN_CHKS 200
#define NN_SQ_DIST_RATIO_THR 0.49
#define SIFT_MIN_RANSAC_FEATURES 4
#define COLOR_SWATCH_SZIE 16

#undef main

using namespace libmv;

///////////////////////////////////////////////////////////////////////////////
//
// forward declarations
//
///////////////////////////////////////////////////////////////////////////////

bool handleSDLEvents();

int initializeSDL();

string itos(int);

void listDirectoryContents(string);
void libmvRunKLT();
void runBlobSIFT();
void runBlobSURF();
void runCorrelationTuringMultiResolutionProgressiveAlignmentSearch();
void runOpticalFlowBirchfieldKLT();
void runOpticalFlowFarneback ();
void runOpticalFlowHornSchunck();
void runOpticalFlowLKOpenCV();
void WriteOutputImage(const FloatImage &image, CorrespondencesView<KLTPointFeature>::Iterator features, const char *output_filename);

///////////////////////////////////////////////////////////////////////////////
//
// global variables
//
///////////////////////////////////////////////////////////////////////////////

string commandsList;

string path = "/home/lab/Development/NavigationData/";

SDL_Rect rectangleCenter, rectangleLeft, rectangleRight, rectangleTop, rectangleBottom;
int xClick=0, yClick=0;

// SDL events
bool trackEvent = false;
bool trackingActivated = false;

// instantiate the image functions class
ImageFunctions *imageFunctions = new ImageFunctions();

// global vector to hold all file names
vector <string> sortedFiles;

// OpenGL texture
GLuint texture;

///////////////////////////////////////////////////////////////////////////////
//
// main
//
///////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    // OpenGL
    if (USEQT_0_USESDL_1 == 0) {
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        return a.exec();
    }

    int dirChoice=0;
    string dirIn;
    cout << "What is the dataset to run? (/home/lab/Development/NavigationData/...)? \n\n";
    cout << "1. Sign\n";
    cout << "2. Silver car\n";
    cout << "3. SUV\n";
    cout << "4. Wood pile\n";
    cout << "5. Other (manually specify)\n";
    cout << "\n===> ";
    cin >> dirChoice;

    if (dirChoice == 1) {
        path = path + "Sign";
    } else if (dirChoice == 2) {
        path = path + "SilverCar";
    } else if (dirChoice == 3) {
        path = path + "SUV";
    } else if (dirChoice == 4) {
        path = path + "WoodPile";
    } else if (dirChoice == 5) {
        cout << "\n===> ";
        cin  >> dirChoice;
        path = path + dirIn;
    }

    printf("Path is set to: %s\n", path.c_str());

    // get the contents of our directory
    listDirectoryContents(path);

    bool running = true;
    while (running) {

        int choice=0;

        cout << "\n\n\n";

        cout << "TACTICAL\n";
        cout << "--------\n\n";

        cout << "Algorithms:\n\n";

        cout << "Optical Flow:\n";
        cout << "1. Horn-Schnuck (Dense)\n";
        cout << "2. Farneback's Polynomial Expansion (Dense)\n";
        cout << "3. Birchfield's KLT Tracker (Sparse)\n";
        cout << "4. OpenCV's KLT Tracker (Sparse)\n\n";

        cout << "Blob Tracking:\n";
        cout << "5. SIFT (Hess's Implementation)\n";
        cout << "6. SURF\n\n";

        cout << "Correlation:\n";
        cout << "7. Turing's Multi-Resolution Progressive Alignment Tracker\n\n";

        cout << "9. End program\n";
        cout << "\n===> ";
        cin >> choice;

        if (choice == 1) {
            runOpticalFlowHornSchunck();
        } else if (choice == 2) {
            runOpticalFlowFarneback();
        } else if (choice == 3) {
            runOpticalFlowBirchfieldKLT();
        } else if (choice == 4) {
            runOpticalFlowLKOpenCV();
        } else if (choice == 5) {
            runBlobSIFT();
        } else if (choice == 6) {
            runBlobSURF();
        } else if (choice == 7) {
            runCorrelationTuringMultiResolutionProgressiveAlignmentSearch();
        } else if (choice == 9) {
            running = false;
        }

    }

    // exit nicely
    SDL_Quit();
    exit(0);

} // end main


///////////////////////////////////////////////////////////////////////////////
//
// handleSDLEvents
//
///////////////////////////////////////////////////////////////////////////////

bool handleSDLEvents()
{
    commandsList.clear();
    SDL_Event event;

    // keyboard events
    while (SDL_PollEvent(&event)) {

        switch (event.type) {

        case SDL_KEYDOWN:

            switch (event.key.keysym.sym) {

            case SDLK_ESCAPE:
                SDL_Quit();
                exit(0);
                return true;
                break;
            case SDLK_q:
                trackingActivated = false;
  //              foundClosestFeature = false;
                //tracking->trackingActivated = false;
                //tracking->reset();
                break;
            case SDLK_f:
                SDL_SetVideoMode(640, 480, 0, SDL_OPENGL | SDL_FULLSCREEN);
                break;
            case SDLK_r:
                SDL_SetVideoMode(640, 480, 0, SDL_OPENGL);
                break;
            default:
                break;
            }
            break;

        case SDL_QUIT:
            return true;
            break;

        case SDL_MOUSEBUTTONDOWN:

            printf("Mouse button pressed. ");
            printf("Button %i at (%i, %i)\n", event.button.button, event.button.x, event.button.y);

            trackEvent = true;

            // we received a new point to track
//            if (tracking->trackingActivated == true) {
//                tracking->reset();
//            }

            trackingActivated = true;

            xClick = event.button.x;
            yClick = event.button.y;

            break;
        }
    }

    return false;

} // end handleSDLEvents


///////////////////////////////////////////////////////////////////////////////
//
//  itos
//
///////////////////////////////////////////////////////////////////////////////

string itos (int i)
{
    stringstream s;
    s << i;
    return s.str();

} // end itos


///////////////////////////////////////////////////////////////////////////////
//
// listDirectoryContents
//
// This currently only looks for bitmaps...
//
///////////////////////////////////////////////////////////////////////////////

void listDirectoryContents (string directory)
{
    vector <string> files;
    size_t found;
    string searchArg = ".bmp";

    struct dirent *de=NULL;
    DIR *d=NULL;

    d=opendir(directory.c_str());
    if (d == NULL) {
        perror("Couldn't open directory");
    }

    // loop while there are files
    while (de = readdir(d)) {
        files.push_back(de->d_name);
        printf("%s\n",de->d_name);
    }

    // sort the vector
    sort(files.rbegin(), files.rend());

    for (int i=files.size()-1; i>=0; i--) {

        string tmp = files.at(i);
        // search for a valid bmp file
        found = tmp.find(searchArg);

        if (found != string::npos) {
            string temp = files.at(i);
            printf("%s\n", temp.c_str());
            sortedFiles.push_back(temp);
        }
    }

    closedir(d);

} // end listDirectoryContents


///////////////////////////////////////////////////////////////////////////////
//
// libmvRunKLT
//
///////////////////////////////////////////////////////////////////////////////

void libmvRunKLT ()
{
    // klt stuff
    vector<string> files;
    string path = "/home/lab/Development/NavigationData/WoodPile/pgm/";
    string base = "captured";
    for (int i=503; i<530; i++) {
        string fileName = path + base + itos(i) + ".pgm";
        files.push_back(fileName);
        printf("loading %s\n", fileName.c_str());
    }

    ImageCache cache;
    ImageSequence *source = ImageSequenceFromFiles(files, &cache);
    PyramidSequence *pyramid_sequence = MakePyramidSequence(source, 5, 1.5);

    KLTContext klt;
    Correspondences correspondences;

    // TODO(keir): Really have to get a scoped_ptr<> implementation!
    // Consider taking the one from boost but editing out the cruft.
    ImagePyramid *pyramid = pyramid_sequence->Pyramid(0);
    KLTContext::FeatureList features;
    klt.DetectGoodFeatures(pyramid->Level(0), &features);
    int i = 0;
    for (KLTContext::FeatureList::iterator it = features.begin(); it != features.end(); ++it, ++i) {
        correspondences.Insert(0, i, *it);
    }

    CorrespondencesView<KLTPointFeature> klt_correspondences(&correspondences);

    WriteOutputImage(pyramid_sequence->Pyramid(0)->Level(0), klt_correspondences.ScanFeaturesForImage(0), (files[0]+".out.ppm").c_str());

    // TODO(keir): Use correspondences here!
    for (size_t i = 1; i < files.size(); ++i) {

        printf("Tracking %2zd features in %s\n", features.size(), files[i].c_str());

        CorrespondencesView<KLTPointFeature>::Iterator it = klt_correspondences.ScanFeaturesForImage(i-1);
        for (; !it.Done(); it.Next()) {
            KLTPointFeature *next_position = new KLTPointFeature;
            if (klt.TrackFeature(pyramid_sequence->Pyramid(i-1), *it.feature(), pyramid_sequence->Pyramid(i), next_position)) {
                correspondences.Insert(i, it.track(), next_position);
            } else {
                delete next_position;
            }
        }

       WriteOutputImage(pyramid_sequence->Pyramid(i)->Level(0), klt_correspondences.ScanFeaturesForImage(i), (files[i]+".out.ppm").c_str());

    }

}  // end libmvRunKLT


///////////////////////////////////////////////////////////////////////////////
//
// WriteOutputImage :: code taken from libmv's track.cc
//
///////////////////////////////////////////////////////////////////////////////

void WriteOutputImage(const FloatImage &image, CorrespondencesView<KLTPointFeature>::Iterator features, const char *output_filename)
{
    FloatImage output_image(image.Height(), image.Width(), 3);

    for (int i = 0; i < image.Height(); ++i) {
        for (int j = 0; j < image.Width(); ++j) {
            output_image(i,j,0) = image(i,j);
            output_image(i,j,1) = image(i,j);
            output_image(i,j,2) = image(i,j);
        }
    }

    Vec3 green;
    green << 0, 1, 0;
    for (; !features.Done(); features.Next()) {
        DrawFeature(*features.feature(), green, &output_image);
    }

    WritePnm(output_image, output_filename);

} // end WriteOutputImage


///////////////////////////////////////////////////////////////////////////////
//
// runOpticalFlowHornSchunck
//
///////////////////////////////////////////////////////////////////////////////

void runOpticalFlowHornSchunck ()
{
    initHornSchunck();

    for (int i=0; i<sortedFiles.size()-1; i++) {
        string tempA = path + sortedFiles.at(i);
        string tempB = path + sortedFiles.at(i+1);

        printf("trying to load %s and %s\n", tempA.c_str(), tempB.c_str());

        IplImage *imgA = cvLoadImage(tempA.c_str());
        IplImage *imgB = cvLoadImage(tempB.c_str());

        IplImage *imgA_1 = cvCreateImage(cvGetSize(imgA), 8, 1);
        IplImage *imgB_1 = cvCreateImage(cvGetSize(imgA), 8, 1);

        cvCvtColor(imgA, imgA_1, CV_BGR2GRAY);
        cvCvtColor(imgB, imgB_1, CV_BGR2GRAY);

        cvReleaseImage(&imgA);
        cvReleaseImage(&imgB);

        runHornSchunck(imgA_1, imgB_1);
    }

    endHornSchunck();
}



///////////////////////////////////////////////////////////////////////////////
//
// runOpticalFlowFarneback
//
///////////////////////////////////////////////////////////////////////////////

void runOpticalFlowFarneback ()
{
    initFarneback();

    for (int i=0; i<sortedFiles.size()-1; i++) {
        string tempA = path + sortedFiles.at(i);
        string tempB = path + sortedFiles.at(i+1);

        printf("trying to load %s and %s\n", tempA.c_str(), tempB.c_str());

        IplImage *imgA = cvLoadImage(tempA.c_str());
        IplImage *imgB = cvLoadImage(tempB.c_str());

//        IplImage *imgA_1 = cvCreateImage(cvGetSize(imgA), 8, 1);
//        IplImage *imgB_1 = cvCreateImage(cvGetSize(imgA), 8, 1);

//        cvCvtColor(imgA, imgA_1, CV_BGR2GRAY);
//        cvCvtColor(imgB, imgB_1, CV_BGR2GRAY);

//        cvReleaseImage(&imgA);
//        cvReleaseImage(&imgB);

        runHornSchunck(imgA, imgB);
    }

    endFarneback();

} // end runOpticalFlowFarneback


///////////////////////////////////////////////////////////////////////////////
//
// runOpticalFlowLKOpenCV
//
///////////////////////////////////////////////////////////////////////////////

void runOpticalFlowLKOpenCV ()
{
    initLKOpenCV();

    for (int i=0; i<sortedFiles.size()-1; i++) {

        string tempA = path + '/' + sortedFiles.at(i);

        printf("trying to load %s\n", tempA.c_str());

        IplImage *imgA = cvLoadImage(tempA.c_str());

        runLKOpenCV(imgA);

        //cvReleaseImage(&imgA);
    }

    endLKOpenCV();

} // runOpticalFlowLKOpenCV


///////////////////////////////////////////////////////////////////////////////
//
// runOpticalFlowBirchfieldKLT
//
///////////////////////////////////////////////////////////////////////////////

void runOpticalFlowBirchfieldKLT ()
{
    #define REPLACE

    string path = "/home/lab/Development/NavigationData/WoodPile/pgm/";
    string base = "captured";
    string imgFileName;
    string flFileName;
    string ftFileName;

    unsigned char *img1, *img2;
    char fnamein[100], fnameout[100];

    KLT_TrackingContext tc;
    KLT_FeatureList fl;
    KLT_FeatureTable ft;

    int nFeatures = 150, nFrames = 50;
    int ncols, nrows;
    int i=0;
    int frameCounter = 1;
    int start=503, stop=552;

    tc = KLTCreateTrackingContext();
    fl = KLTCreateFeatureList(nFeatures);
    ft = KLTCreateFeatureTable(nFrames, nFeatures);
    tc->sequentialMode = TRUE;
    tc->writeInternalImages = FALSE;
    tc->affineConsistencyCheck = 2;  // set this to 2 to turn on affine consistency check, -1 turns it off

    // load in the first image of our set
    imgFileName = path + base + itos(start) + ".pgm";
    img1 = pgmReadFile((char *)imgFileName.c_str(), NULL, &ncols, &nrows);
    img2 = (unsigned char *) malloc(ncols*nrows*sizeof(unsigned char));

    KLTSelectGoodFeatures(tc, img1, ncols, nrows, fl);
    KLTStoreFeatureList(fl, ft, 0);

    flFileName = path + "/features/feat" + itos(frameCounter) + ".ppm";
    KLTWriteFeatureListToPPM(fl, img1, ncols, nrows, (char *)flFileName.c_str());

    frameCounter++;
    start++;

    for (i=start; i<stop; i++)  {

        imgFileName = path + base + itos(i) + ".pgm";
        cout << "Reading :: " << imgFileName << "\n";
        pgmReadFile((char *)imgFileName.c_str(), img2, &ncols, &nrows);
        KLTTrackFeatures(tc, img1, img2, ncols, nrows, fl);

        #ifdef REPLACE
        KLTReplaceLostFeatures(tc, img2, ncols, nrows, fl);
        #endif

        KLTStoreFeatureList(fl, ft, frameCounter);
        flFileName = path + "/features/feat" + itos(frameCounter) + ".ppm";
        KLTWriteFeatureListToPPM(fl, img2, ncols, nrows, (char *)flFileName.c_str());

        frameCounter++;
    }

    ftFileName = path + "/features/feat.ft";
    KLTWriteFeatureTable(ft, (char *)ftFileName.c_str(), NULL);

    ftFileName = path + "/features/feat.txt";
    KLTWriteFeatureTable(ft, (char *)ftFileName.c_str(), "%5.1f");

    KLTFreeFeatureTable(ft);
    KLTFreeFeatureList(fl);
    KLTFreeTrackingContext(tc);
    free(img1);
    free(img2);

} // end runOpticalFlowBirchfieldKLT


///////////////////////////////////////////////////////////////////////////////
//
// runCorrelationTuringMultiResolutionProgressiveAlignmentSearch
//
///////////////////////////////////////////////////////////////////////////////

void runCorrelationTuringMultiResolutionProgressiveAlignmentSearch ()
{
    // declare the tracking library
    turingTracking *tracking;

    bool trackingInstantiated = false;
    bool continueTest = true;
    int frameNumber = 0;

    // loop over the first image and wait for the mouse click
    bool pointSelected = false;
    bool loaded = false;
    IplImage *temp;
    IplImage *temp2;
    while (pointSelected == false) {

        if (loaded == false) {
            // grab the first image and display it
            string t = path + '/' + sortedFiles.at(frameNumber);
            temp = cvLoadImage(t.c_str());

            // swap the red and blue channels
            temp2 = cvCreateImage(cvSize(temp->width, temp->height), 8, 3);
            cvConvertImage(temp, temp2, CV_CVTIMG_SWAP_RB);

            loaded = true;

            printf("\n\n\nTRACKING INIIIALIZED...\n\n\n");
        }

        SDL_Surface *image = SDL_CreateRGBSurfaceFrom(temp2->imageData, temp2->width, temp->height, 24, temp2->widthStep, 0x0000ff, 0x00ff00, 0xff0000, 0);

        // generate a texture object handle
        glGenTextures(1, &texture);

        glBindTexture(GL_TEXTURE_2D, texture);

        // set the stretching properties
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        // edit the texture object's image data
        glTexImage2D(GL_TEXTURE_2D, 0, 3, image->w, image->h, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

        // now, draw it
        glBindTexture(GL_TEXTURE_2D, texture);

        glBegin(GL_QUADS);

            // top left
            glTexCoord2i(0, 0);
            glVertex3f(1, 1, 0.0f);

            // bottom left
            glTexCoord2i(1, 0);
            glVertex3f(640, 1, 0.0f);

            // bottom right
            glTexCoord2i(1, 1);
            glVertex3f(640, 480, 0);

            // top right
            glTexCoord2i(0, 1);
            glVertex3f(1, 480, 0);

        glEnd();

        // flip the OpenGL to SDL
        SDL_GL_SwapBuffers();

        // delete the texture
        glDeleteTextures(1, &texture);

        // handle any SDL events
        handleSDLEvents();
        if (trackEvent == true) {
            pointSelected = true;
            cvReleaseImage(&temp);
            cvReleaseImage(&temp2);
        }
    }

    // main loop
    while (continueTest == true) {

        trackingActivated = true;

        string t = path + '/' + sortedFiles.at(frameNumber);

        IplImage *temp = cvLoadImage(t.c_str());

        if (trackingInstantiated == false) {
            string h = itos(temp->height);
            string w = itos(temp->width);
            tracking = new turingTracking(h.c_str(), w.c_str());
            trackingInstantiated = true;
         }

        // swap the red and blue channels
        IplImage *temp2 = cvCreateImage(cvSize(temp->width, temp->height), 8, 3);
        cvConvertImage(temp, temp2, CV_CVTIMG_SWAP_RB);

        SDL_Surface *image = SDL_CreateRGBSurfaceFrom(temp2->imageData, temp2->width, temp->height, 24, temp2->widthStep, 0x0000ff, 0x00ff00, 0xff0000, 0);

        Uint32 colorRed    = SDL_MapRGB(image->format, 255, 0, 0);
        Uint32 colorGreen  = SDL_MapRGB(image->format, 0, 255, 0);
        Uint32 colorWhite  = SDL_MapRGB(image->format, 255, 255, 255);
        Uint32 colorOrange = SDL_MapRGB(image->format, 255, 91, 0);

        SDL_LockSurface(image);

        ///////////////////////////////////////////////////////////////////////
        //
        // tracking algorithm
        //
        ///////////////////////////////////////////////////////////////////////

        if (trackingActivated == true) {

            // get the size of the image
            int rows = image->h;
            int cols = image->w;

            // convert the image to a 2D matrix
            int **image2D = SDLImageTo2DArrayOnePlane2(image, rows, cols, 2);

            tracking->constellationTrackWrapper(image2D, xClick, yClick);

            // center point is red
            rectangleCenter.w = 4;
            rectangleCenter.h = 4;
            rectangleCenter.x = tracking->cLast[0] - 2;
            rectangleCenter.y = tracking->rLast[0] - 2;
            SDL_FillRect(image, &rectangleCenter, colorRed);

            // the other constellation points are green
            rectangleLeft.w = 4;
            rectangleLeft.h = 4;
            rectangleLeft.x = tracking->cLast[1] - 2;
            rectangleLeft.y = tracking->rLast[1] - 2;
            SDL_FillRect(image, &rectangleLeft, colorGreen);

            rectangleRight.w = 4;
            rectangleRight.h = 4;
            rectangleRight.x = tracking->cLast[2] - 2;
            rectangleRight.y = tracking->rLast[2] - 2;
            SDL_FillRect(image, &rectangleRight, colorGreen);

            rectangleTop.w = 4;
            rectangleTop.h = 4;
            rectangleTop.x = tracking->cLast[3] - 2;
            rectangleTop.y = tracking->rLast[3] - 2;
            SDL_FillRect(image, &rectangleTop, colorGreen);

            rectangleBottom.w = 4;
            rectangleBottom.h = 4;
            rectangleBottom.x = tracking->cLast[4] - 2;
            rectangleBottom.y = tracking->rLast[4] - 2;
            SDL_FillRect(image, &rectangleBottom, colorGreen);

            SDL_UnlockSurface(image);

            printf("The tracked point is at (%d, %d)\n", tracking->rLast[0], tracking->cLast[0]);
            printf("correlationError = %f, degeneracy = %f, shapeChange = %f\n", tracking->correlationError, tracking->degeneracy, tracking->shapeChange);

            // generate a texture object handle
            glGenTextures(1, &texture);

            glBindTexture(GL_TEXTURE_2D, texture);

            // set the stretching properties
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

            // edit the texture object's image data
            glTexImage2D(GL_TEXTURE_2D, 0, 3, image->w, image->h, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

            // now, draw it
            glBindTexture(GL_TEXTURE_2D, texture);

            glBegin(GL_QUADS);

                // top left
                glTexCoord2i(0, 0);
                glVertex3f(1, 1, 0.0f);

                // bottom left
                glTexCoord2i(1, 0);
                glVertex3f(640, 1, 0.0f);

                // bottom right
                glTexCoord2i(1, 1);
                glVertex3f(640, 480, 0);

                // top right
                glTexCoord2i(0, 1);
                glVertex3f(1, 480, 0);

            glEnd();

            // flip the OpenGL to SDL
            SDL_GL_SwapBuffers();

            // delete the texture
            glDeleteTextures(1, &texture);

            // free the OpenCV images we created
            cvReleaseImage(&temp);
            cvReleaseImage(&temp2);

            bool status = handleSDLEvents();
            if (status == true) {
                continueTest = false;
            }

            // increment our frame number if we get a mouse event
            if (trackEvent == true) {
                frameNumber++;
                printf("incrementing the frame number :: %d...\n", frameNumber);
            }

            // look for termination conditions
            if (frameNumber > sortedFiles.size()-1) {
                continueTest = false;
            }

        }

        // if the tracking algorithm has been terminated, let the local variable know
        if (tracking->trackingActivated == false) {
            trackingActivated = false;
        }

    } // end while

    // clear up memory
    delete tracking;

} // end runCorrelationTuringMultiResolutionProgressiveAlignmentSearch


///////////////////////////////////////////////////////////////////////////////
//
// runBlobSIFT
//
///////////////////////////////////////////////////////////////////////////////

void runBlobSIFT ()
{
    cvNamedWindow("Matches", 1);
    cvNamedWindow("Transformed", 1);

    struct feature *feat1, *feat2, *feat;
    struct feature **nbrs;
    struct kd_node *kdRoot;
    CvPoint pt1, pt2;
    double d0, d1;
    int n1, n2, k, m=0;
    int siftCount = 0;
    int frameNumberSIFT = 0;

    // loop through all of the image
    for (int i=0; i<sortedFiles.size()-1; i++) {

        IplImage *stacked;

        string tempA = path + '/' + sortedFiles.at(i);
        string tempB = path + '/' + sortedFiles.at(i+1);

        printf("Trying to load :: %s & %s\n", tempA.c_str(), tempB.c_str());

        IplImage *imgA  = cvLoadImage(tempA.c_str());
        IplImage *imgB  = cvLoadImage(tempB.c_str());

        printf("Loaded images\n");

        stacked = stack_imgs(imgA, imgB);

        n1 = sift_features(imgA, &feat1);
        n2 = sift_features(imgB, &feat2);
        kdRoot = kdtree_build(feat2, n2);

        int j=0;
        for (j=0; j<n1; j++) {
            feat = feat1 + j;
            k = kdtree_bbf_knn(kdRoot, feat, 2, &nbrs, KDTREE_BBF_MAX_NN_CHKS);

            if (k == 2) {
                d0 = descr_dist_sq(feat, nbrs[0]);
                d1 = descr_dist_sq(feat, nbrs[1]);

                if (d0 < d1 * NN_SQ_DIST_RATIO_THR) {

                    pt1 = cvPoint(cvRound(feat->x), cvRound(feat->y));
                    pt2 = cvPoint(cvRound(nbrs[0]->x), cvRound(nbrs[0]->y));
                    pt2.y += imgA->height;
                    cvLine(stacked, pt1, pt2, CV_RGB(255, 0, 255), 1, 8, 0);
                    m++;
                    feat1[j].fwd_match = nbrs[0];
                }
            }

            free(nbrs);
        }

        cout << "Found " << m << " total matches\n";

        cvShowImage("Matches", stacked);
        cvWaitKey(10);

        // save the image
//        if (archive == true) {
//            string fileName = path + "_matches" + itos(frameNumberSIFT) + ".bmp";
//            cvSaveImage(fileName.c_str(), stacked);
//        }

        printf("Now, doing RANSAC...j=%d\n", j);

        // now, do RANSAC
        feat1[j].fwd_match = nbrs[0];
        {
            CvMat *H;
            printf("n1 = %d\n", n1);
            H = ransac_xform(feat1, n1, FEATURE_FWD_MATCH, lsq_homog, 4, 0.01, homog_xfer_err, 3.0, NULL, NULL);
            printf("Transformation found...\n");

            if (H) {

                for (int ti=0; ti<3; ti++) {
                    for (int tj=0; tj<3; tj++) {
                        cout << cvmGet(H, ti, tj) << " ";
                    }
                    cout << "\n";
                }

                IplImage *transformed;
                transformed = cvCreateImage(cvGetSize(imgA), 8, 3);
                cvWarpPerspective(imgA, transformed, H, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS, cvScalarAll(0));

                cvShowImage("Transformed", transformed);
                cvWaitKey(10);

                // save the image
//                if (archive == true) {
                    string fileName = path + "/transformed/transformed_" + itos(frameNumberSIFT) + ".bmp";
                    cvSaveImage(fileName.c_str(), transformed);
//                }

                cvReleaseImage(&transformed);
                cvReleaseMat(&H);

            }

        } // end RANSAC

        // free allocated memory
        cvReleaseImage(&stacked);
        cvReleaseImage(&imgA);
        cvReleaseImage(&imgB);
        kdtree_release(kdRoot);
        free(feat1);
        free(feat2);
        siftCount = 0;
        frameNumberSIFT++;
    }

 } // end runBlobSIFT


///////////////////////////////////////////////////////////////////////////////
//
// runBlobSURF
//
///////////////////////////////////////////////////////////////////////////////

void runBlobSURF ()
{
    // declare Ipoints and other stuff
    IpVec ipts, old_ipts, motion;
    IpPairVec matches;

    cvNamedWindow("OpenSURF");

    // loop through all of the image
    for (int i=0; i<sortedFiles.size()-1; i++) {

        string tempA = path + '/' + sortedFiles.at(i);

        printf("Trying to load :: %s\n", tempA.c_str());

        IplImage *imgA  = cvLoadImage(tempA.c_str());

        // Detect and describe interest points in the image
        old_ipts = ipts;
        surfDetDes(imgA, ipts, true, 3, 4, 2, 0.0004f);

        // Fill match vector
        getMatches(ipts,old_ipts,matches);
        for (unsigned int i = 0; i < matches.size(); ++i) {
            const float & dx = matches[i].first.dx;
            const float & dy = matches[i].first.dy;
            float speed = sqrt(dx*dx+dy*dy);
            if (speed > 5 && speed < 30) {
                drawIpoint(imgA, matches[i].first, 3);
            }
        }

        // Display the result
        cvShowImage("OpenSURF", imgA);

        // If ESC key pressed exit loop
        if( (cvWaitKey(10) & 255) == 27 ) break;

    }

    cvDestroyWindow("OpenSURF");

} // end runBlobSURF


///////////////////////////////////////////////////////////////////////////////
//
// initializeSDL
//
///////////////////////////////////////////////////////////////////////////////

int initializeSDL()
{
    if ((SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_TIMER) == -1)) {
        cout << "Could not initialize SDL: " << SDL_GetError() << endl;
        return 1;
    }

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    // create a 640x480 OpenGL screen
    if (SDL_SetVideoMode(640, 480, 0, SDL_OPENGL) == NULL) {
        cout << "Unable to create OpenGL screen: " << SDL_GetError() << "\n";
        SDL_Quit();
        exit(2);
    }

    // set the title bar
    SDL_WM_SetCaption("TACTICAL", NULL);

    // init OpenGL
    glEnable(GL_TEXTURE_2D);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glViewport(0, 0, 640, 480);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, 640, 480, 0.0f, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

} // end initializeSDL

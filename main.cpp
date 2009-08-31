
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include <QtGui/QApplication>
#include "mainwindow.h"

// OpenGL
#include <GL/gl.h>
#include <GL/glu.h>

// tracking
#include "tracking_algorithms/Correlation/TuringTracking/TuringTracking.h"

#include "ImageProcessing.h"
#include "image_functions/Image_Functions.h"

// this is a hack until I can get sdl events recognized from within qt
#define USEQT_0_USESDL_1 1

///////////////////////////////////////////////////////////////////////////////
//
// forward declarations
//
///////////////////////////////////////////////////////////////////////////////

bool handleSDLEvents();
string itos (int i);

///////////////////////////////////////////////////////////////////////////////
//
// global variables
//
///////////////////////////////////////////////////////////////////////////////

string commandsList;

string path = "/home/lab/Development/NavigationData/WoodPile/";
string baseFileName = "captured";
int start = 0;
int stop = 730;

string aviFileName = "/home/lab/Development/NavigationData/WoodPile/out_WoodPile.avi";

SDL_Rect rectangleCenter, rectangleLeft, rectangleRight, rectangleTop, rectangleBottom;
int xClick=0, yClick=0;

// SDL events
bool trackEvent = false;
bool trackingActivated = false;

// instantiate the tracking library
turingTracking *tracking = new turingTracking("480", "640");

// instantiate the image functions class
ImageFunctions *imageFunctions = new ImageFunctions();

///////////////////////////////////////////////////////////////////////////////
//
// main
//
///////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    GLuint texture;

    // OpenGL
    if (USEQT_0_USESDL_1 == 0) {
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        return a.exec();

    // SDL
    } else {

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

        bool continueTest = true;
        int frameNumber = start;

        imageFunctions->aviInitialize(aviFileName);

        // main loop
        while (continueTest == true) {

            IplImage *temp = imageFunctions->aviGrabFrame(frameNumber);

            cout << "Current frame number = " << frameNumber << "\n";

           // string fileName = path + baseFileName + itos(frameNumber) + ".bmp";

            // just test loading a frame
       //     IplImage *temp;
       //     temp = cvLoadImage(fileName.c_str());
       //     cout << "Loaded image..." << fileName << "(" << temp->height << "," << temp->width << ")\n";

            //IplImage *temp2;
      //      CvSize size;
      //      size.height = temp->height;
      //      size.width  = temp->width;
      //      IplImage *temp2 = cvCreateImage(size, 8, 3);
      //      cvConvertImage(temp, temp2, CV_CVTIMG_SWAP_RB);

            SDL_Surface *image = SDL_CreateRGBSurfaceFrom(temp->imageData, temp->width, temp->height, 24, temp->widthStep, 0x0000ff, 0x00ff00, 0xff0000, 0);

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
/**
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

            // find good features
            } else {

                int numberGoodFeatures = tracking->findGoodFeatures(temp);

                // draw the good features
                int k=0;
                for (int i=0; i<numberGoodFeatures; i++) {
                    tracking->points[1][k++] = tracking->points[1][i];
                    rectangleCenter.w = 4;
                    rectangleCenter.h = 4;
                    CvPoint pt = cvPointFrom32f(tracking->points[1][i]);
                    rectangleCenter.x = pt.x;
                    rectangleCenter.y = pt.y;
                    SDL_FillRect(image, &rectangleCenter, colorWhite);
                }
**/
            }

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

            // free the OpenCV image we created
            cvReleaseImage(&temp);
        //    cvReleaseImage(&temp2);

            bool status = handleSDLEvents();
            if (status == true) {
                continueTest = false;
            }

            // increment our frame number if we get a mouse event
            if (trackEvent == true) {
                frameNumber++;
                printf("incrementing the frame number :: %d...\n", frameNumber);
            }

            printf("There are %d frames in the current AVI\n", imageFunctions->captureAVIFrames);

            // look for termination conditions
            if (frameNumber > imageFunctions->captureAVIFrames) {
                continueTest = false;
            }

        }

        // if the tracking algorithm has been terminated, let the local variable know
        if (tracking->trackingActivated == false) {
                trackingActivated = false;
        }

    } // end if Qt or SDL

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
                tracking->trackingActivated = false;
                tracking->reset();
                break;
            case SDLK_f:
                SDL_SetVideoMode(640, 480, 0, SDL_OPENGL | SDL_FULLSCREEN);
                break;
            case SDLK_p:
 //               if (enableFiltering == true) {
 //                   enableFiltering = false;
 //               } else if (enableFiltering == false) {
 //                   // make sure to reset the lk
 //                   tracking->lkResetOpticalFlow();
 //                   enableFiltering = true;
 //               }
                break;
            case SDLK_r:
                SDL_SetVideoMode(640, 480, 0, SDL_OPENGL);
                break;
            case SDLK_s:
 //               if (enableSIFT == true) {
 //                   enableSIFT = false;
 //               } else if (enableSIFT == false) {
 //                   enableSIFT = true;
 //               }
                break;
            case SDLK_d:
 //               if (coordinatesActivated == false) {
 //                   coordinatesActivated = true;
   //             } else if (coordinatesActivated == true) {
   //                 coordinatesActivated = false;
   //             }
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


#include "ImageProcessing.h"

///////////////////////////////////////////////////////////////////////////////
//
// free2DArray
//
///////////////////////////////////////////////////////////////////////////////

void free2DArray(int **p, int rows)
{
    for (int i=0; i<rows; i++) {
        free(p[i]);
    }

    free(p);

} // end free2DArray


///////////////////////////////////////////////////////////////////////////////
//
// make2DArray
//
///////////////////////////////////////////////////////////////////////////////

int **make2DArray(int rows, int cols)
{
    int **p;

    p = (int **)malloc(rows * sizeof(int *));

    if (p == NULL)
		return NULL;

    for (int i=0; i<rows; i++) {
        p[i] = (int *)malloc(cols * sizeof(int));
        if (p[i] == NULL)
			return NULL;
    }

    return p;

} // end make2DArray


///////////////////////////////////////////////////////////////////////////////
//
// mean2
//
///////////////////////////////////////////////////////////////////////////////

double mean2 (int **imageIn, int rows, int cols, int numberPlanes)
{
	printf("In mean2, rows = %d, cols=%d\n", rows, cols);

	float sum = 0;
	
	for (int i=0; i<rows; i++) {
		for (int j=0; j<cols; j++) { 
			sum = sum + (double)imageIn[i][j];
		}
	}

	return sum / (rows * cols * numberPlanes);

} // end mean2


///////////////////////////////////////////////////////////////////////////////
//
// SDLImageTo2DArrayOnePlane
//
///////////////////////////////////////////////////////////////////////////////

int **SDLImageTo2DArrayOnePlane (SDL_Surface *image, int rows, int cols, int plane) 
{
	SDL_PixelFormat *fmt;
	fmt = image->format;

	Uint32 temp, pixel;
	Uint8 red, green, blue, alpha;

	int bpp = image->format->BytesPerPixel;

	int **onePlane2D = make2DArray(rows, cols);
  
	// create the 2D array
	for (int y=0; y<rows; y++) {
		for (int x=0; x<cols; x++) {
	
		//	pixel = *((Uint32*)image->pixels + y * image->pitch /4 + x * bpp);		
			
			pixel = *((Uint32*)image->pixels + y * image->pitch /4 + x);	
	
			// r=1, g=2, 3=b

			if (plane == 1) {

				// get the red component 
				temp = pixel & fmt->Rmask;  // isolate red component
				temp = temp >> fmt->Rshift; // shift it down to 8-bit
				temp = temp << fmt->Rloss;  // expand to a full 8-bit number
				red = (Uint8)temp;
				onePlane2D[y][x] = (int)red;
			}

			if (plane == 2) {
			
				// get the green component
				temp = pixel & fmt->Gmask;  // isolate green component 
				temp = temp >> fmt->Gshift; // shift it down to 8-bit
				temp = temp << fmt->Gloss;  // expand to a full 8-bit number
				green = (Uint8)temp;
				onePlane2D[y][x] = (int)green;
			}

			if (plane == 3) {

				// get the blue component 
				temp = pixel & fmt->Bmask;  // isolate blue component 
				temp = temp >> fmt->Bshift; // shift it down to 8-bit 
				temp = temp << fmt->Bloss;  // expand to a full 8-bit number 
				blue = (Uint8)temp;			
				onePlane2D[y][x] = (int)blue;
			}
	
			// i don't care about the alpha channel but i'll leave it here anyway
			if (plane == 4) {

				// get alpha component 
				temp = pixel & fmt->Amask;  // isolate alpha component 
				temp = temp >> fmt->Ashift; // shift it down to 8-bit 
				temp = temp << fmt->Aloss;  // expand to a full 8-bit number 
				alpha = (Uint8)temp;
			}

 		}

	}

	return onePlane2D; 

} // end SDLImageTo2DArrayOnePlane


///////////////////////////////////////////////////////////////////////////////
//
// SDLImageTo1DArrayOnePlane
//
///////////////////////////////////////////////////////////////////////////////

int *SDLImageTo1DArrayOnePlane (SDL_Surface *image, int rows, int cols, int plane) 
{
	SDL_PixelFormat *fmt;
	fmt = image->format;

	Uint32 temp, pixel;
	Uint8 red, green, blue, alpha;

	int bpp = image->format->BytesPerPixel;

	int *onePlane1D = new int[rows * cols];
	
	int count=0;
  
	// create the 1D array
	for (int y=0; y<rows; y++) {
		for (int x=0; x<cols; x++) {

		//	pixel = *((Uint32*)image->pixels + y * image->pitch /4 + x * bpp);

			pixel = *((Uint32*)image->pixels + y * image->pitch /4  + x);

			// r=1, g=2, 3=b

			if (plane == 1) {

				// get the red component 
				temp = pixel & fmt->Rmask;  // isolate red component
				temp = temp >> fmt->Rshift; // shift it down to 8-bit
				temp = temp << fmt->Rloss;  // expand to a full 8-bit number
				red = (Uint8)temp;
				onePlane1D[count] = (int)red;
			}

			if (plane == 2) {
			
				// get the green component
				temp = pixel & fmt->Gmask;  // isolate green component 
				temp = temp >> fmt->Gshift; // shift it down to 8-bit
				temp = temp << fmt->Gloss;  // expand to a full 8-bit number
				green = (Uint8)temp;
				onePlane1D[count] = (int)green;
			}

			if (plane == 3) {

				// get the blue component 
				temp = pixel & fmt->Bmask;  // isolate blue component 
				temp = temp >> fmt->Bshift; // shift it down to 8-bit 
				temp = temp << fmt->Bloss;  // expand to a full 8-bit number 
				blue = (Uint8)temp;			
				onePlane1D[count] = (int)blue;
			}
	
			// i don't care about the alpha channel but i'll leave it here anyway
			if (plane == 4) {

				// get alpha component 
				temp = pixel & fmt->Amask;  // isolate alpha component 
				temp = temp >> fmt->Ashift; // shift it down to 8-bit 
				temp = temp << fmt->Aloss;  // expand to a full 8-bit number 
				alpha = (Uint8)temp;
			}

			count++;

 		}

	}

	return onePlane1D; 

} // end SDLImageTo1DArrayOnePlane


///////////////////////////////////////////////////////////////////////////////
//
// ImageArray1DToIplImageOnePlane
//
///////////////////////////////////////////////////////////////////////////////

IplImage *ImageArray1DToIplImageOnePlane (int *imageIn, int rows, int cols)
{

    CvSize frameSize;
    frameSize.width = cols;
	frameSize.height = rows;

	// allocate space for the IplImage
	IplImage *imageWork = cvCreateImage(frameSize, 8, 1);

	// load the IplImage up
	for (int i=0; i<rows*cols; i++) {
		((uchar *)imageWork->imageData)[i] = (uchar)imageIn[i];	
	}		

	return imageWork;

} // end ImageArrayToIplImageOnePlane


///////////////////////////////////////////////////////////////////////////////
//
// ImageArray2DToIplImageOnePlane
//
///////////////////////////////////////////////////////////////////////////////

IplImage *ImageArray2DToIplImageOnePlane (int **imageIn, int rows, int cols)
{

    CvSize frameSize;
    frameSize.width = cols;
	frameSize.height = rows;

	// allocate space for the IplImage
	IplImage *imageWork = cvCreateImage(frameSize, 8, 1);

	// convert the 2D array to 1D
	int count = 0;
	int *tempArray = new int[rows*cols];
 
	for (int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			tempArray[count] = imageIn[i][j];		
//			count++;	
		
			((uchar *)imageWork->imageData)[count] = (uchar)imageIn[i][j];	

			count++;

		}
	}

	// load the IplImage up
//	for (int i=0; i<rows*cols; i++) {
//		((uchar *)imageWork->imageData)[i] = (uchar)tempArray[i];	
//	}		

	// free memory
	delete [] tempArray;

	return imageWork;

} // end ImageArrayToIplImageOnePlane


///////////////////////////////////////////////////////////////////////////////
//
// ImageArray1DToIplImageThreePlanes
//
///////////////////////////////////////////////////////////////////////////////

IplImage *ImageArray1DToIplImageThreePlanes (int *imageIn, int rows, int cols)
{
    CvSize frameSize;
    frameSize.width = cols;
	frameSize.height = rows;

	// allocate space for the IplImage
	IplImage *imageWork = cvCreateImage(frameSize, 8, 3);
 
	// load the IplImage up
	int count = 0;
	for (int i=0; i<rows*cols*3; i+=3) {
		((uchar *)imageWork->imageData)[i]   = (uchar)imageIn[count];
		((uchar *)imageWork->imageData)[i+1] = (uchar)imageIn[count];
		((uchar *)imageWork->imageData)[i+2] = (uchar)imageIn[count];
		count++;	
	}		

	return imageWork;

} // end ImageArray2DToIplImageThreePlanes


///////////////////////////////////////////////////////////////////////////////
//
// ImageArray2DToIplImageThreePlanes
//
///////////////////////////////////////////////////////////////////////////////

IplImage *ImageArray2DToIplImageThreePlanes (int **imageIn, int rows, int cols)
{

    CvSize frameSize;
    frameSize.width = cols;
	frameSize.height = rows;

	// allocate space for the IplImage
	IplImage *imageWork = cvCreateImage(frameSize, 8, 3);

	// convert the 2D array to 1D
	int count = 0;
	int *tempArray = new int[rows*cols];
 
	for (int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			tempArray[count] = imageIn[i][j];	
			count++;		
		}
	}

	// load the IplImage up
	count = 0;
	for (int i=0; i<rows*cols*3; i+=3) {
		((uchar *)imageWork->imageData)[i]   = (uchar)tempArray[count];
		((uchar *)imageWork->imageData)[i+1] = (uchar)tempArray[count];
		((uchar *)imageWork->imageData)[i+2] = (uchar)tempArray[count];
		count++;	
	}		

	// free memory
	delete [] tempArray;

	return imageWork;

} // end ImageArray2DToIplImageThreePlanes



///////////////////////////////////////////////////////////////////////////////
//
// SDLImageTo2DArrayOnePlane2
//
///////////////////////////////////////////////////////////////////////////////

int **SDLImageTo2DArrayOnePlane2 (SDL_Surface *image, int rows, int cols, int plane) 
{
	SDL_PixelFormat *fmt;
	fmt = image->format;

	Uint32 temp, pixel;
	Uint8 red, green, blue, alpha;

	int **onePlane2D = make2DArray(rows, cols);
  
	// create the 2D array
	for (int y=0; y<rows; y++) {
		for (int x=0; x<cols; x++) {

			pixel = getpixel(image, x, y);	
			
			SDL_GetRGB(pixel, fmt, &red, &green, &blue);
			onePlane2D[y][x] = green;

 		}

	}

	return onePlane2D; 

} // end SDLImageTo2DArrayOnePlane



Uint32 getpixel(SDL_Surface *surface, int x, int y)
{
 	int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        return *p;

    case 2:
        return *(Uint16 *)p;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;

    case 4:
        return *(Uint32 *)p;

    default:
        return 0;       /* shouldn't happen, but avoids warnings */
    }
}


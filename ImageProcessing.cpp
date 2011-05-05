
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

                //  pixel = *((Uint32*)image->pixels + y * image->pitch /4 + x * bpp);
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
            ((uchar *)imageWork->imageData)[count] = (uchar)imageIn[i][j];
            count++;
        }
    }

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


///////////////////////////////////////////////////////////////////////////////
//
// getpixel
//
///////////////////////////////////////////////////////////////////////////////

Uint32 getpixel(SDL_Surface *surface, int x, int y)
{

    int bpp = surface->format->BytesPerPixel;

    // Here p is the address to the pixel we want to retrieve
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {

        case 1:
            return *p;

        case 2:
            return *(Uint16 *)p;

        case 3:

            if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
                return p[0] << 16 | p[1] << 8 | p[2];
            } else {
                return p[0] | p[1] << 8 | p[2] << 16;
            }

        case 4:
            return *(Uint32 *)p;

        default:
            return 0;
    }

} // end getpixel


/////////////////////////////////////////////////////////////////////
//
// runHistogramEqualization
//
/////////////////////////////////////////////////////////////////////

TNT::Array2D <double> runHistogramEqualization(TNT::Array2D <double> array)
{
    int height = array.dim1(), width = array.dim2();
    int	max = 255, range = 255;

    TNT::Array2D <double> a(height, width, 0.0);

    TNT::Array1D <long int> histogram;
    histogram = getHistogram(array);

    double sum=0;

    sum = histogram[0];

    // get the weighted sum of the histogram
    for (int i=1; i<max; i++) {
        sum += 2 * histogram[i];
    }

    sum += histogram[max];

    double scale = range/sum;

    TNT::Array1D <int> lut(range+1, 0);

    lut[0] = 0;

    sum = histogram[0];

    for (int i=1; i<max; i++) {

        double delta = histogram[i];
        sum += delta;
        lut[i] = (sum*scale)+0.5;
        sum += delta;
    }

    lut[max] = max;

    // finally, apply the table
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            a[i][j] = lut[(int)(array[i][j])&0xff];
        }
    }

    return a;

} // end runHistogramEqualization


/////////////////////////////////////////////////////////////////////
//
// getHistogram
//
/////////////////////////////////////////////////////////////////////

TNT::Array1D <long int> getHistogram (TNT::Array2D <double> array)
{
    int height = array.dim1(), width = array.dim2();

    TNT::Array1D <long int> a(256, static_cast< long int>(0));

    for (int m=0; m<height; m++) {
        for (int n=0; n<width; n++) {
            a[static_cast<int>(array[m][n])] += 1;
        }
    }

    return a;

} // end getHistogram


/////////////////////////////////////////////////////////////////////
//
// getArrayFromIplImage
//
/////////////////////////////////////////////////////////////////////

TNT::Array2D<double> getArrayFromIplImage(IplImage *frame)
{
    int width = frame->width, height = frame->height;
    TNT::Array2D <double> array(height, width, 0.0);

    printf("getArrayFromIplImage :: height = %d, width = %d\n", height, width);

    int plane = 2;

    for (int y=0; y<height; y++) {
        for (int x=0; x<width; x++) {

            // plane (1=R, 2=G, 3=B)
             if (plane == 1) {
                array[y][x] = ((uchar*)(frame->imageData + frame->widthStep*y))[x*3];
             } else if (plane == 2) {
                array[y][x] = ((uchar*)(frame->imageData + frame->widthStep*y))[x*3+1];
             } else if (plane == 3) {
                array[y][x] = ((uchar*)(frame->imageData + frame->widthStep*y))[x*3+2];
             }

        }
    }

    return array;

} // end getArrayFromIplImage


/////////////////////////////////////////////////////////////////////
//
// getIplImageFromArray
//
/////////////////////////////////////////////////////////////////////

IplImage  *getIplImageFromArray(const TNT::Array2D<double> &array)
{
    int height = array.dim1(), width = array.dim2();
    unsigned char intensity;

    printf("getIplImageFromArray :: height = %d, width = %d\n", height, width);

    IplImage *imageWork = cvCreateImage(cvSize(width, height), 8, 1);

    int count = 0;

    for (int y=0; y<height; y++) {
        for (int x=0; x<width; x++) {

            if (array[y][x] > 255) {
                intensity = 255;
            } else if (array[y][x] < 0) {
                intensity = 0;
            } else {
                intensity = static_cast<unsigned char>(array[y][x]);
            }

            ((uchar *)imageWork->imageData)[count] = intensity;
            count++;

        }

    }

    return imageWork;

} // end getIplImageFromArray


/////////////////////////////////////////////////////////////////////
//
// getIplImageFromArray2
//
/////////////////////////////////////////////////////////////////////

IplImage  *getIplImageFromArray2(const TNT::Array2D<double> &array)
{
    int height = array.dim1(), width = array.dim2();
    unsigned char intensity;

    printf("getIplImageFromArray :: height = %d, width = %d\n", height, width);

    IplImage *imageWork = cvCreateImage(cvSize(width, height), 8, 3);

    int count = 0;

    for (int y=0; y<height; y++) {
        for (int x=0; x<width; x++) {

            if (array[y][x] > 255) {
                intensity = 255;
            } else if (array[y][x] < 0) {
                intensity = 0;
            } else {
                intensity = static_cast<unsigned char>(array[y][x]);
            }

            ((uchar *)imageWork->imageData)[count] = intensity;
            ((uchar *)imageWork->imageData)[count+1] = intensity;
            ((uchar *)imageWork->imageData)[count+2] = intensity;
            count+=3;

        }

    }

    return imageWork;

} // end getIplImageFromArray


/////////////////////////////////////////////////////////////////////
//
// getIplImageFromArray2
//
/////////////////////////////////////////////////////////////////////

void getIplImageFromArray2(const TNT::Array2D<double> &array, IplImage *imageWork)
{
    int height = array.dim1(), width = array.dim2();
    unsigned char intensity;

    printf("getIplImageFromArray :: height = %d, width = %d\n", height, width);

    int count = 0;

    for (int y=0; y<height; y++) {
        for (int x=0; x<width; x++) {

            if (array[y][x] > 255) {
                intensity = 255;
            } else if (array[y][x] < 0) {
                intensity = 0;
            } else {
                intensity = static_cast<unsigned char>(array[y][x]);
            }

            ((uchar *)&imageWork->imageData)[count] = intensity;
            ((uchar *)&imageWork->imageData)[count+1] = intensity;
            ((uchar *)&imageWork->imageData)[count+2] = intensity;
            count+=3;

        }

    }

} // end getIplImageFromArray


/////////////////////////////////////////////////////////////////////
//
// findLUT
//
/////////////////////////////////////////////////////////////////////

TNT::Array1D <int> findLUT(TNT::Array2D <double> array, int r1, int s1, int r2, int s2)
{
    int height = array.dim1(), width = array.dim2();

    TNT::Array1D <int> yAxis(256, 0);

    if ((r1==s1) && (r2==s2)) {

        for (int i=0; i<256; i++) {
            yAxis[i] = i;
        }

    } else {

        for (int i=0; i<=r1; i++) {
            yAxis[i] = findYCoordRect(i, 0, 0, r1, s1);
        }

        if (r1==r2) {
            yAxis[r1]=s2;
        } else {
            for (int i=r1+1; i<=r2; i++) {
                yAxis[i] = findYCoordRect(i, r1, s1, r2, s2);
            }
        }

        for (int i=r2; i<=255; i++) {
            yAxis[i]=findYCoordRect(i,r2,s2,255,255);
        }

    }

    return yAxis;

} // end findLUT


///////////////////////////////////////////////////////////////////////////////
//
// laplacian
//
///////////////////////////////////////////////////////////////////////////////

TNT::Array2D <double> laplacian(TNT::Array2D <double> array)
{
    int height = array.dim1(), width = array.dim2();

    TNT::Array2D <double> a(height, width, 0.0);

    // create horizontal and vertical arrays
    TNT::Array2D <double> hh;
    TNT::Array2D <double> vv;

    hh = getHorizontalHessian(array, FLT_EPSILON);
    vv = getVerticalHessian(array, FLT_EPSILON);

    for (int i=0;i<height;i++) {
        for (int j=0;j<width;j++) {
            a[i][j] = hh[i][j] + vv[i][j];
        }
    }

    return a;

} // end laplacian


///////////////////////////////////////////////////////////////////////////////
//
// logarithm
//
///////////////////////////////////////////////////////////////////////////////

TNT::Array2D <double> logarithm(TNT::Array2D <double> array, float constant)
{
    int height = array.dim1(), width = array.dim2();

    int s=0, temp=0;

    TNT::Array2D <double> a(height, width, 0.0);

    for (int i=0; i<height;i++) {
        for (int j=0;j<width;j++) {
            temp = array[i][j];
            s = log((float)temp) * (float)255/log((float)255) * constant;
            a[i][j] = s;
        }
    }

    return a;

} // end logarithm


///////////////////////////////////////////////////////////////////////////////
//
// max
//
// This function calculates the maximum of a kxk pixel
//	neighborhood (including center pixel)
//
///////////////////////////////////////////////////////////////////////////////

int max (TNT::Array2D <double> array, int k, int width, int height, int x, int y)
{
    int t=0, number=0;
    int *supp = new int [k*k];

    for (int i=0;i<k;i++) {
        for (int j=0;j<k;j++) {
            if(((x-1+j)>=0) && ((y-1+i)>=0) && ((x-1+j)<width) && ((y-1+i)<height)) {
                supp[t] = array[y-1+i][x-1+j];
                t++;
                number++;
            }
        }
    }

    if (number == 0) {
        delete [] supp;
        return 0;
    }

    sortArray(supp, k*k);
    int temp = supp[k*k-1];

    delete [] supp;
    return temp;

} // end max


///////////////////////////////////////////////////////////////////////////////
//
// meanArithmetic
//
///////////////////////////////////////////////////////////////////////////////

int meanArithmetic(TNT::Array2D <double> array, int k, int width, int height, int x, int y)
{
    int sum=0, number=0;

    for(int i=0;i<k;i++) {
        for(int j=0;j<k;j++) {
            if(((x-1+j)>=0) && ((y-1+i)>=0) && ((x-1+j)<width) && ((y-1+i)<height)) {
                sum = sum + array[y-1+i][x-1+j];
                number++;
            }
        }
    }

    if (number==0) {
        return 0;
    }

    return (sum/number);

} // end meanArithmetic


///////////////////////////////////////////////////////////////////////////////
//
// meanContraharmonic
//
// Calculates the contraharmonic mean of a kxk pixel neighborhood
//	(including center pixel)
//
// array	- input image (2d array)
// k		- dimension of the kernel
// width	- width of the image
// height	- height of the image
// x		- x coordinate of the center pixel of the array
// y		- y coordinate of the center pixel of the array
// q		- order of the filter
//
///////////////////////////////////////////////////////////////////////////////

int meanContraharmonic (TNT::Array2D <double> array, int k, int width, int height, int x, int y, float q)
{
    double sum1=0, sum2=0, number=0, supp=0;

    for (int i=0;i<k;i++) {
        for (int j=0;j<k;j++) {
            if(((x-1+j)>=0) && ((y-1+i)>=0) && ((x-1+j)<width) && ((y-1+i)<height)) {
                supp=(double)array[y-1+i][x-1+j];
                sum1 = sum1 + pow(supp,(double)q+1);
                sum2 = sum2 + pow(supp,(double)q);
                number++;
            }
        }
    }

    if (number==0) {
        return 0;
    }

    double result=sum1/sum2;

    if (result<0) {
        result=0;
    }

    if (result>255) {
        result=255;
    }

    return (int)result;

} // end meanContraharmonic


///////////////////////////////////////////////////////////////////////////////
//
// meanGeometric
//
// Calculates the geometric mean of a kxk pixel neighborhood
//	(including center pixel)
//
// array	- input image (2d array)
// k		- dimension of the kernel
// width	- width of the image
// height	- height of the image
// x		- x coordinate of the center pixel of the array
// y		- y coordinate of the center pixel of the array
//
///////////////////////////////////////////////////////////////////////////////

int meanGeometric(TNT::Array2D <double> array, int k, int width, int height, int x, int y)
{
    double product=1, number=0;

    for (int i=0;i<k;i++) {
        for (int j=0;j<k;j++) {
            if(((x-1+j)>=0) && ((y-1+i)>=0) && ((x-1+j)<width) && ((y-1+i)<height)) {
                product = product * array[y-1+i][x-1+j];
                number++;
            }
        }
    }

    if (number==0) {
        return 0;
    }

    double eps=1/number;
    double result=pow(product,eps);

    if (result<0) {
        result=0;
    }

    if(result>255) {
        result=255;
    }

    return (int)result;

} // end meanGeometric


///////////////////////////////////////////////////////////////////////////////
//
// meanHarmonic
//
// Calculates the harmonic mean of a kxk pixel neighborhood
//	(including center pixel)
//
// array	- input image (2d array)
// k		- dimension of the kernel
// width	- width of the image
// height	- height of the image
// x		- x coordinate of the center pixel of the array
// y		- y coordinate of the center pixel of the array
//
///////////////////////////////////////////////////////////////////////////////

int meanHarmonic (TNT::Array2D <double> array, int k, int width, int height, int x, int y)
{
    double sum=0, number=0, supp=0;

    for(int i=0;i<k;i++) {
        for(int j=0;j<k;j++) {
            if(((x-1+j)>=0) && ((y-1+i)>=0) && ((x-1+j)<width) && ((y-1+i)<height)) {
                supp = array[y-1+i][x-1+j];
                sum = sum + 1/supp;
                number++;
            }
        }
    }

    if (number==0) {
        return 0;
    }

    double result=number/sum;

    if (result<0) {
        result=0;
    }

    if (result>255) {
        result=255;
    }

    return (int)result;

} // end meanHarmonic


/////////////////////////////////////////////////////////////////////
//
// meanLocal
//
// This function calculates the mean of a kxk pixel
//	neighborhood (including center pixel)
//
/////////////////////////////////////////////////////////////////////

int meanLocal (TNT::Array2D <double> array, int k, int width, int height, int x, int y)
{
    double sum=0, number=0;

    for (int i=0;i<k;i++) {
        for (int j=0;j<k;j++) {
            if(((x-1+j)>=0) && ((y-1+i)>=0) && ((x-1+j)<width) && ((y-1+i)<height)) {
                sum = sum+array[y-1+1][x-1+j];
                number++;
            }
        }
    }

    if (number == 0) {
        return 0;
    }

    return sum/number;

} // end meanLocal


/////////////////////////////////////////////////////////////////////
//
// median
//
/////////////////////////////////////////////////////////////////////

int median (TNT::Array2D <double> array, int k, int width, int height, int x, int y)
{
    int t=0, number=0;
    int *supp = new int [k*k];

    for (int i=0;i<k;i++) {
        for (int j=0;j<k;j++) {
            if(((x-1+j)>=0) && ((y-1+i)>=0) && ((x-1+j)<width) && ((y-1+i)<height)) {
                supp[t] = array[y-1+i][x-1+j];
                t++;
                number++;
            }
        }
    }

    if (number == 0) {
        delete [] supp;
        return 0;
    }

    sortArray(supp, k*k);
    int temp = supp[k*k-1];

    delete [] supp;
    return temp/2;

} // end median


///////////////////////////////////////////////////////////////////////////////
//
// min
//
// This function calculates the minimum of a kxk pixel
//	neighborhood (including center pixel)
//
///////////////////////////////////////////////////////////////////////////////

int min (TNT::Array2D <double> array, int k, int width, int height, int x, int y)
{
    int t=0, number=0;
    int *supp = new int [k*k];

    for (int i=0;i<k;i++) {
        for (int j=0;j<k;j++) {
            if(((x-1+j)>=0) && ((y-1+i)>=0) && ((x-1+j)<width) && ((y-1+i)<height)) {
                supp[t] = array[y-1+i][x-1+j];
                t++;
                number++;
            }
        }
    }

    if (number == 0) {
        delete [] supp;
        return 0;
    }

    sortArray(supp, k*k);
    int temp = supp[0];

    delete [] supp;
    return temp;

} // end min


///////////////////////////////////////////////////////////////////////////////
//
// negative
//
///////////////////////////////////////////////////////////////////////////////

TNT::Array2D <double> negative(TNT::Array2D <double> array)
{
    int height = array.dim1(), width = array.dim2();

    int l=256, s=0, temp=0;

    TNT::Array2D <double> a(height, width, 0.0);

    for (int i=0; i<height; i++) {
        for (int j=0;j<width;j++) {
            temp = array[i][j];
            s = l-1-temp;
            a[i][j] = s;
        }
    }

    return a;

} // end negative


///////////////////////////////////////////////////////////////////////////////
//
// findYCoordRect
//
///////////////////////////////////////////////////////////////////////////////

int findYCoordRect (int x, int x0, int y0, int x1, int y1)
{
    int y;

    if (y0==y1) {
        y = y1;
    } else if (x0==x1) {
        y = y1;
    } else {
        y=(int)((((float)(x-x0)/(x1-x0))*(y1-y0))+y0);
    }

    return y;

} // end find YCoordRect


///////////////////////////////////////////////////////////////////////////////
//
// getHessian
//
///////////////////////////////////////////////////////////////////////////////

TNT::Array1D <double> getHessian (TNT::Array1D <double> c)
{
    TNT::Array1D <double> h(2, 0.0);

    h[0] = -2.0;
    h[1] =  1.0;

    TNT::Array1D <double> a;

    a = symmetricFirMirrorOnBounds(h, c);

    return a;

} // end getHessian


///////////////////////////////////////////////////////////////////////////////
//
// getHorizontalGradient
//
///////////////////////////////////////////////////////////////////////////////

TNT::Array2D <double> getHorizontalGradient(TNT::Array2D <double> array, double tolerance)
{
    int height = array.dim1(), width = array.dim2();

    TNT::Array2D <double> a(height, width, 0.0);

    TNT::Array1D <double> line;
    TNT::Array1D <double> spline;
    TNT::Array1D <double> gradient;

    for (int i=0; i<height; i++) {

        line = getRow2(array, i);
        spline = getSplineInterpolationCoefficients(line, tolerance);
        gradient = getGradient(spline);
//	putRow(&a, width, height, hessian, i);
        putRow2(&a, width, height, gradient, i);
        line = spline = gradient = 0.0;

    }

    return a;

} // end getHorizontalGradient


///////////////////////////////////////////////////////////////////////////////
//
// getHorizontalHessian
//
///////////////////////////////////////////////////////////////////////////////

TNT::Array2D <double> getHorizontalHessian(TNT::Array2D <double> array, double tolerance)
{
    int height = array.dim1(), width = array.dim2();

    TNT::Array2D <double> a(height, width, 0.0);

    TNT::Array1D <double> line;
    TNT::Array1D <double> spline;
    TNT::Array1D <double> hessian;

    for (int i=0; i<height; i++) {

        line = getRow2(array, i);
        spline = getSplineInterpolationCoefficients(line, tolerance);
        hessian = getHessian(spline);
//	putRow(&a, width, height, hessian, i);
        putRow2(&a, width, height, hessian, i);
        line = spline = hessian = 0.0;

        int tmp = line.dim1();
        int noop=0;
    }

    return a;

} // end getHorizontalHessian


/////////////////////////////////////////////////////////////////////
//
// getInitialAntiCausalCoefficientMirrorOnBounds
//
/////////////////////////////////////////////////////////////////////

double getInitialAntiCausalCoefficientMirrorOnBounds(TNT::Array1D <double> line, double z, double tolerance)
{
    return ((z * line[line.dim1()-2]  + line[line.dim1()-1]) * z / (z * z - 1.0));

} // end  getInitialAntiCausalCoefficientMirrorOnBounds


/////////////////////////////////////////////////////////////////////
//
// getInitialCausalCoefficientMirrorOnBounds
//
/////////////////////////////////////////////////////////////////////

double getInitialCausalCoefficientMirrorOnBounds(TNT::Array1D <double> line, double z, double tolerance)
{
    int size = line.dim1();

    double z1 = z;
    double zn = pow(z, size-1);
    double sum = line[0] + zn * line[size - 1];

    int horizon = line.dim1();

    if (0.0 < tolerance) {
        horizon = 2 + (int) log(tolerance) / log(abs(z));
        horizon = (horizon < line.dim1()) ? (horizon) : (line.dim1());
    }

    zn = zn * zn;

    for (int n=1; n<horizon-1; n++) {
        zn = zn/z;
        sum = sum + (z1+zn) * line[n];
        z1 = z1 * z;
    }

    return (sum/(1.0-pow(z, 2 * line.dim1() - 2)));

} // end getInitialCausalCoefficientMirrorOnBounds


/////////////////////////////////////////////////////////////////////
//
// getRow
//
/////////////////////////////////////////////////////////////////////

TNT::Array1D <double> getRow(TNT::Array2D <double> array, int row)
{
    int height = array.dim1(), width = array.dim2();

    TNT::Array1D <double> a(width, 0.0);
    TNT::Array1D <double> temp(width*height, 0.0);

    int rowLength = height;

    int y = row;
    y *= rowLength;

    temp = convert2DTo1D(array);

    for (int i=0; i<width; i++) {
        a[i] = temp[y++];
    }

    return a;

} // end getRow


/////////////////////////////////////////////////////////////////////
//
// getRow2
//
/////////////////////////////////////////////////////////////////////

TNT::Array1D <double> getRow2(TNT::Array2D <double> array, int row)
{
    int height = array.dim1(), width = array.dim2();

    TNT::Array1D <double> a(width, 0.0);
    TNT::Array1D <double> temp(width*height, 0.0);

    int rowLength = width;

    int y = row;
    y *= rowLength;

    temp = convert2DTo1D(array);

    for (int i=0; i<width; i++) {
        a[i] = temp[y++];
    }

    return a;

} // end getRow2


/////////////////////////////////////////////////////////////////////
//
// getSplineInterpolationCoefficients
//
/////////////////////////////////////////////////////////////////////

TNT::Array1D <double> getSplineInterpolationCoefficients(TNT::Array1D <double> line, double tolerance)
{
    int size = line.dim1();

    double zSize = 1;
    double lambda=1.0;

    TNT::Array1D <double> z (zSize, 0.0);
    TNT::Array1D <double> a (size, 0.0);

    // copy line to a
    for (int i=0; i<size; i++) {
        a[i] = line[i];
    }

    z[0] = sqrt(3.0) - 2.0;


    for (int k=0; k<zSize; k++) {
        lambda = lambda * (1.0 - z[k]) * (1.0 - 1.0 / z[k]);
    }

    for (int n=0; n<size; n++) {
        a[n] = a[n] * lambda;
    }

    for (int k=0; k<zSize; k++) {
        a[0] = getInitialCausalCoefficientMirrorOnBounds(a, z[k], tolerance);

        for (int n=1; n<size; n++) {
            a[n] = a[n] + z[k] * a[n-1];
        }

        a[size-1] = getInitialAntiCausalCoefficientMirrorOnBounds(a, z[k], tolerance);

        for (int n=size-2; 0 <= n; n--) {
            a[n] = z[k] * (a[n+1] - a[n]);
        }
    }

    return a;

} // end getSplineInterpolationCoefficients


/////////////////////////////////////////////////////////////////////
//
// getVerticalGradient
//
/////////////////////////////////////////////////////////////////////

TNT::Array2D <double> getVerticalGradient(TNT::Array2D <double> array, double tolerance)
{
    int height = array.dim1(), width = array.dim2();

    TNT::Array2D <double> a(height, width, 0.0);

    TNT::Array1D <double> line;
    TNT::Array1D <double> spline;
    TNT::Array1D <double> gradient;

    for (int i=0; i<width; i++) {

        line = getCol2(array, i);
        spline = getSplineInterpolationCoefficients(line, tolerance);
        gradient = getGradient(spline);
//	putRow(&a, width, height, hessian, i);
        putCol2(&a, width, height, gradient, i);
        line = spline = gradient = 0.0;

    }

    return a;

} // end getVerticalGradient


/////////////////////////////////////////////////////////////////////
//
// getVerticalHessian
//
/////////////////////////////////////////////////////////////////////

TNT::Array2D <double> getVerticalHessian(TNT::Array2D <double> array, double tolerance)
{
    int height = array.dim1(), width = array.dim2();

    TNT::Array2D <double> a(height, width, 0.0);

    TNT::Array1D <double> line;
    TNT::Array1D <double> spline;
    TNT::Array1D <double> hessian;

    for (int i=0; i<width; i++) {

        line = getCol(array, i);
        spline	= getSplineInterpolationCoefficients(line, tolerance);
        hessian = getHessian(spline);
//	putCol(&a, width, height, hessian, i);
        putCol2(&a, width, height, hessian, i);
    }

    return a;

} // end getVerticalHessian



/////////////////////////////////////////////////////////////////////
//
// gradient
//
/////////////////////////////////////////////////////////////////////

TNT::Array2D <double> gradient(TNT::Array2D <double> array)
{
    int height = array.dim1(), width = array.dim2();

    TNT::Array2D <double> a(height, width, 0.0);
    TNT::Array1D <double> temp(height*width, 0.0);

    // create horizontal and vertical arrays
    TNT::Array2D <double> hh;
    TNT::Array2D <double> vv;

    TNT::Array1D <double> hhTemp, vvTemp, aTemp;

    for (int i=0;i<height;i++) {
        for (int j=0;j<width;j++) {
            a[i][j] = array[i][j];
        }
    }

    hh = getHorizontalGradient(array, FLT_EPSILON);
    vv = getVerticalGradient(array, FLT_EPSILON);

    for (int i=0;i<height;i++) {
        for (int j=0;j<width;j++) {
            a[i][j] = sqrt(hh[i][j] * hh[i][j] + vv[i][j] * vv[i][j]);
        }
    }

    return a;

} // end gradient


/////////////////////////////////////////////////////////////////////
//
// sortArray
//
/////////////////////////////////////////////////////////////////////

void sortArray(int *arrayIn, int size)
{
    // throw this to a vector and sort
    vector <int> v;
    for (int i=0; i<size; i++) {
        v.push_back(arrayIn[i]);
    }

    sort(v.begin(), v.end());

    // put sorted values back to array
    for (int i=0; i<size; i++) {
        arrayIn[i] = v[i];
    }

} // end sortArray


/////////////////////////////////////////////////////////////////////
//
// symmetricFirMirrorOnBounds
//
/////////////////////////////////////////////////////////////////////

TNT::Array1D <double> symmetricFirMirrorOnBounds(TNT::Array1D <double> h, TNT::Array1D <double> c)
{
    TNT::Array1D <double> a (c.dim1(), 0.0);

    int temp = c.dim1();
    int fun=0;

    a[0] = h[0] * c[0] + 2.0 * h[1] * c[1];
    for (int i=1; (i<(c.dim1()-1)); i++) {
        a[i] = h[0] * c[i] + h[1] * (c[i - 1] + c[i + 1]);
    }
    a[c.dim1()-1] = h[0] * c[c.dim1()-1] + 2.0 * h[1] * c[c.dim1()-2];

    return a;

} // end symmetricFirMirrorOnBounds


/////////////////////////////////////////////////////////////////////
//
// getGradient
//
/////////////////////////////////////////////////////////////////////

TNT::Array1D <double> getGradient (TNT::Array1D <double> c)
{
    TNT::Array1D <double> h(2, 0.0);

    h[0] = 0.0;
    h[1] = -1.0/2.0;

    TNT::Array1D <double> a;

    a = antiSymmetricFirMirrorOnBounds(h, c);

    return a;

} // end getGradient


/////////////////////////////////////////////////////////////////////
//
// putRow2
//
/////////////////////////////////////////////////////////////////////

void putRow2(TNT::Array2D <double> *array, int width, int height, TNT::Array1D <double> rowIn, int row)
{
    TNT::Array1D <double> temp(width * height, 0.0);

    int rowLength = width;

    int y = row;
    y *= rowLength;

    temp = convert2DTo1D(*array);

    for (int i=0; i<width; i++) {
        temp[y++] = rowIn[i];
    }

    *array = convert1DTo2D(temp, width, height);

} // end putRow2


/////////////////////////////////////////////////////////////////////
//
// convert2DTo1D
//
/////////////////////////////////////////////////////////////////////

TNT::Array1D <double> convert2DTo1D(TNT::Array2D <double> arrayIn)
{
    int height = arrayIn.dim1(), width = arrayIn.dim2(), size=0;

    size = height * width;

    TNT::Array1D <double> a(size, 0.0);

    int index=0;

    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            a[index] = arrayIn[i][j];
            index++;
        }
    }

    return a;

} // end  convert2DTo1D


/////////////////////////////////////////////////////////////////////
//
// getCol
//
/////////////////////////////////////////////////////////////////////

TNT::Array1D <double> getCol(TNT::Array2D <double> array, int col)
{
    int height = array.dim1(), width = array.dim2();

    TNT::Array1D <double> a(height, 0.0);
    TNT::Array1D <double> temp(height*width, 0.0);

    int x = col;

    temp = convert2DTo1D(array);

    for (int i=0; i<height; i++) {
        a[i] = temp[x];
        x += width;
    }

    return a;

} // end getCol


/////////////////////////////////////////////////////////////////////
//
// getCol2
//
/////////////////////////////////////////////////////////////////////

TNT::Array1D <double> getCol2(TNT::Array2D <double> array, int col)
{
    int height = array.dim1(), width = array.dim2();

    TNT::Array1D <double> a(height, 0.0);
    TNT::Array1D <double> temp(height*width, 0.0);

    int x = col;

    temp = convert2DTo1D(array);

    for (int i=0; i<height; i++) {
        a[i] = temp[x];
        x += width;
    }

    return a;

} // end getCol2


/////////////////////////////////////////////////////////////////////
//
// putCol2
//
/////////////////////////////////////////////////////////////////////

void putCol2(TNT::Array2D <double> *array, int width, int height, TNT::Array1D <double> colIn, int col)
{
    TNT::Array1D <double> temp(width*height, 0.0);

    int x = col;

    temp = convert2DTo1D(*array);

    for (int i=0; i<height; i++) {
        temp[x] = colIn[i];
        x += width;
    }

    *array = convert1DTo2D(temp, width, height);

} // end putCol2


/////////////////////////////////////////////////////////////////////
//
// antiSymmetricFirMirrorOnBounds
//
/////////////////////////////////////////////////////////////////////

TNT::Array1D <double> antiSymmetricFirMirrorOnBounds(TNT::Array1D <double> h, TNT::Array1D <double> c)
{
    TNT::Array1D <double> a (c.dim1(), 0.0);

    int temp = c.dim1();
    int fun=0;

    a[0] = 0.0;
    for (int i=1; (i<(c.dim1()-1)); i++) {
        a[i] = h[1] * ((c[i + 1] - c[i - 1]));
    }

    a[c.dim1()-1] = 0.0;

    return a;

} // end antiSymmetricFirMirrorOnBounds


/////////////////////////////////////////////////////////////////////
//
// convert1DTo2D
//
/////////////////////////////////////////////////////////////////////

TNT::Array2D <double> convert1DTo2D(TNT::Array1D <double> arrayIn, int width, int height)
{
    TNT::Array2D <double> a(height, width, 0.0);

    int index=0;

    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            a[i][j] = arrayIn[index];
            index++;
        }
    }

    return a;

} // end convert1DTo2D


#include "FFTLibrary.h"

///////////////////////////////////////////////////////////////////////////////
//
// constructor
//
///////////////////////////////////////////////////////////////////////////////

FFTLibrary::FFTLibrary ()
{
} // end constructor


///////////////////////////////////////////////////////////////////////////////
//
// destructor
//
///////////////////////////////////////////////////////////////////////////////

FFTLibrary::~FFTLibrary ()
{
} // end destructor


///////////////////////////////////////////////////////////////////////////////
//
// lowpass
//
// This takes the IplImage (RGB) as input, cutX, cutY, and returns
//  the processed image
//
// Do I want to add a parm for FFTW_ESTIMATE vs. FFTW_MEASURE?
//  FFTW_MEASURE takes longer because it runs and measures the time of
//  several FFTs in order to find the best way to compute te transform of
//  size n.  FFTW_ESTIMATE just builds a reasonable plan and runs it.
//
///////////////////////////////////////////////////////////////////////////////

IplImage *FFTLibrary::lowpass (IplImage *img, int spacing)
{
	//  parameters
	float fx, fy, dx, dy, sharp; 
	float fx2, fy2, dx2, dy2, sharp2;
	float fx3, fy3, dx3, dy3, sharp3;
    float fx4, fy4, dx4, dy4, sharp4;
	int plane;
	int show;
	bool info;
	bool measure;

    int height = img->height;
    int width = img->width;

	//////////////////////////////////////////////////////////////////////////////
	//
	// fftw init stuff
	//
	//////////////////////////////////////////////////////////////////////////////

	float *in;
	fftwf_complex *out;
	fftwf_plan plan, plani;
	int nx = width, ny = height;
	int outwidth;

	in = (float *)fftwf_malloc(sizeof(float) * nx * ny);

	// width (pitch) of complex fft
	outwidth = nx/2+1; 

	out = (fftwf_complex *)fftwf_malloc(sizeof(fftwf_complex) * ny * outwidth);

	int planMeasure = FFTW_ESTIMATE;
	//int planMeasure = FFTW_MEASURE;

	// direct fft 
	plan = fftwf_plan_dft_r2c_2d(ny, nx, in, out, planMeasure); 

	// inverse fft  
	plani = fftwf_plan_dft_c2r_2d(ny, nx, out, in, planMeasure); 

    // convert to grayscale
    IplImage *gray = cvCreateImage(cvGetSize(img), 8, 1);
    cvCvtColor(img, gray, CV_RGB2GRAY);

    // convert the scale
    IplImage *scaledToFloat = cvCreateImage(cvGetSize(img), IPL_DEPTH_32F, 1);
    IplImage *scaledToUChar = cvCreateImage(cvGetSize(img), 8, 1);
    cvConvertScale(gray, scaledToFloat, 1.0 ,0);

    ///////////////////////////////////////////////////////////////////////
    //
    // fft operations
    //
    ///////////////////////////////////////////////////////////////////////

    float *inp;
    inp = (float *)fftwf_malloc(sizeof(float) * nx * ny);
    memcpy(inp, scaledToFloat->imageData, sizeof(float) * width * height);

    // do FFT and get out
    fftwf_execute_dft_r2c(plan, inp, out);

    // clean the high frequencies
    //cleanHigh(out, outwidth, height, cutX, cutY);
    cleanHigh2(out, outwidth, height, 3);

    // do the IFFT
    fftwf_execute_dft_c2r(plani, out, inp);

    // copy the image data back
    memcpy(scaledToFloat->imageData, inp, sizeof(float) * width * height);

    // scale the image back to grayscale
    double minVal=0, maxVal=0;
    cvMinMaxLoc(scaledToFloat, &minVal, &maxVal);
    double min=0.0, max=255.0;
    double scale = (max - min)/(maxVal - minVal);
    double shift = -minVal * scale + min;
    cvConvertScale(scaledToFloat, scaledToUChar, scale, shift);

	// free the fftw stuff
	fftwf_destroy_plan(plan);
	fftwf_destroy_plan(plani);
	fftwf_free(in);
	fftwf_free(out);	
    fftwf_free(inp);

    // free the temporary IplImages
    cvReleaseImage(&gray);
    cvReleaseImage(&scaledToFloat);

    // return the converted image
    return scaledToUChar;

} // end main


///////////////////////////////////////////////////////////////////////////////
//
// highpass
//
// This takes the IplImage (RGB) as input and does a bandpass filter
//
// Do I want to add a parm for FFTW_ESTIMATE vs. FFTW_MEASURE?
//  FFTW_MEASURE takes longer because it runs and measures the time of
//  several FFTs in order to find the best way to compute te transform of
//  size n.  FFTW_ESTIMATE just builds a reasonable plan and runs it.
//
///////////////////////////////////////////////////////////////////////////////

IplImage *FFTLibrary::highpass (IplImage *img)
{
    //  parameters
    float fx, fy, dx, dy, sharp;
    float fx2, fy2, dx2, dy2, sharp2;
    float fx3, fy3, dx3, dy3, sharp3;
    float fx4, fy4, dx4, dy4, sharp4;
    int plane;
    int show;
    bool info;
    bool measure;

    int height = img->height;
    int width = img->width;

    //////////////////////////////////////////////////////////////////////////////
    //
    // fftw init stuff
    //
    //////////////////////////////////////////////////////////////////////////////

    float *in;
    fftwf_complex *out;
    fftwf_plan plan, plani;
    int nx = width, ny = height;
    int outwidth;

    in = (float *)fftwf_malloc(sizeof(float) * nx * ny);

    // width (pitch) of complex fft
    outwidth = nx/2+1;

    out = (fftwf_complex *)fftwf_malloc(sizeof(fftwf_complex) * ny * outwidth);

    int planMeasure = FFTW_ESTIMATE;
    //int planMeasure = FFTW_MEASURE;

    // direct fft
    plan = fftwf_plan_dft_r2c_2d(ny, nx, in, out, planMeasure);

    // inverse fft
    plani = fftwf_plan_dft_c2r_2d(ny, nx, out, in, planMeasure);

    // convert to grayscale
    IplImage *gray = cvCreateImage(cvGetSize(img), 8, 1);
    cvCvtColor(img, gray, CV_RGB2GRAY);

    // convert the scale
    IplImage *scaledToFloat = cvCreateImage(cvGetSize(img), IPL_DEPTH_32F, 1);
    IplImage *scaledToUChar = cvCreateImage(cvGetSize(img), 8, 1);
    cvConvertScale(gray, scaledToFloat, 1.0 ,0);

    ///////////////////////////////////////////////////////////////////////
    //
    // fft operations
    //
    ///////////////////////////////////////////////////////////////////////

    float *inp;
    inp = (float *)fftwf_malloc(sizeof(float) * nx * ny);
    memcpy(inp, scaledToFloat->imageData, sizeof(float) * width * height);

    // do FFT and get out
    fftwf_execute_dft_r2c(plan, inp, out);

    // do the highpass filter
    highpassFilter(out, outwidth, height);

    // do the IFFT
    fftwf_execute_dft_c2r(plani, out, inp);

    // copy the image data back
    memcpy(scaledToFloat->imageData, inp, sizeof(float) * width * height);

    // scale the image back to grayscale
    double minVal=0, maxVal=0;
    cvMinMaxLoc(scaledToFloat, &minVal, &maxVal);
    double min=0.0, max=255.0;
    double scale = (max - min)/(maxVal - minVal);
    double shift = -minVal * scale + min;
    cvConvertScale(scaledToFloat, scaledToUChar, scale, shift);

    // free the fftw stuff
    fftwf_destroy_plan(plan);
    fftwf_destroy_plan(plani);
    fftwf_free(in);
    fftwf_free(out);
    fftwf_free(inp);

    // free the temporary IplImages
    cvReleaseImage(&gray);
    cvReleaseImage(&scaledToFloat);

    // return the converted image
    return scaledToUChar;

} // end main


///////////////////////////////////////////////////////////////////////////////
//
// bandpass
//
// This takes the IplImage (RGB) as input and does a bandpass filter
//
// Do I want to add a parm for FFTW_ESTIMATE vs. FFTW_MEASURE?
//  FFTW_MEASURE takes longer because it runs and measures the time of
//  several FFTs in order to find the best way to compute te transform of
//  size n.  FFTW_ESTIMATE just builds a reasonable plan and runs it.
//
///////////////////////////////////////////////////////////////////////////////

IplImage *FFTLibrary::bandpass (IplImage *img)
{
    //  parameters
    float fx, fy, dx, dy, sharp;
    float fx2, fy2, dx2, dy2, sharp2;
    float fx3, fy3, dx3, dy3, sharp3;
    float fx4, fy4, dx4, dy4, sharp4;
    int plane;
    int show;
    bool info;
    bool measure;

    int height = img->height;
    int width = img->width;

    //////////////////////////////////////////////////////////////////////////////
    //
    // fftw init stuff
    //
    //////////////////////////////////////////////////////////////////////////////

    float *in;
    fftwf_complex *out;
    fftwf_plan plan, plani;
    int nx = width, ny = height;
    int outwidth;

    in = (float *)fftwf_malloc(sizeof(float) * nx * ny);

    // width (pitch) of complex fft
    outwidth = nx/2+1;

    out = (fftwf_complex *)fftwf_malloc(sizeof(fftwf_complex) * ny * outwidth);

    int planMeasure = FFTW_ESTIMATE;
    //int planMeasure = FFTW_MEASURE;

    // direct fft
    plan = fftwf_plan_dft_r2c_2d(ny, nx, in, out, planMeasure);

    // inverse fft
    plani = fftwf_plan_dft_c2r_2d(ny, nx, out, in, planMeasure);

    // convert to grayscale
    IplImage *gray = cvCreateImage(cvGetSize(img), 8, 1);
    cvCvtColor(img, gray, CV_RGB2GRAY);

    // convert the scale
    IplImage *scaledToFloat = cvCreateImage(cvGetSize(img), IPL_DEPTH_32F, 1);
    IplImage *scaledToUChar = cvCreateImage(cvGetSize(img), 8, 1);
    cvConvertScale(gray, scaledToFloat, 1.0 ,0);

    ///////////////////////////////////////////////////////////////////////
    //
    // fft operations
    //
    ///////////////////////////////////////////////////////////////////////

    float *inp;
    inp = (float *)fftwf_malloc(sizeof(float) * nx * ny);
    memcpy(inp, scaledToFloat->imageData, sizeof(float) * width * height);

    // do FFT and get out
    fftwf_execute_dft_r2c(plan, inp, out);

    // do the bandpass filter
    bandpassFilter(out, outwidth, height);

    // do the IFFT
    fftwf_execute_dft_c2r(plani, out, inp);

    // copy the image data back
    memcpy(scaledToFloat->imageData, inp, sizeof(float) * width * height);

    // scale the image back to grayscale
    double minVal=0, maxVal=0;
    cvMinMaxLoc(scaledToFloat, &minVal, &maxVal);
    double min=0.0, max=255.0;
    double scale = (max - min)/(maxVal - minVal);
    double shift = -minVal * scale + min;
    cvConvertScale(scaledToFloat, scaledToUChar, scale, shift);

    // free the fftw stuff
    fftwf_destroy_plan(plan);
    fftwf_destroy_plan(plani);
    fftwf_free(in);
    fftwf_free(out);
    fftwf_free(inp);

    // free the temporary IplImages
    cvReleaseImage(&gray);
    cvReleaseImage(&scaledToFloat);

    // return the converted image
    return scaledToUChar;

} // end main


///////////////////////////////////////////////////////////////////////////////
//
// cleanPeak
//
///////////////////////////////////////////////////////////////////////////////

void FFTLibrary::cleanPeak(fftwf_complex *outp, int outwidth, int height, float fxPeak, float fyPeak)
{
	// old mode used in Defreq v.0.2, replaced by CleanWindow in v.0.3
	// blind set 12 points to 0
	int w_Peak = int(fxPeak*outwidth)/100;
	int h_Peak = ( fyPeak >=0 ) ? int(fyPeak*height)/200 : int(fyPeak*height)/200 + height-1;// changed to >= in v.0.5

	// must be some array access check here...(later)
			outp += outwidth*h_Peak; // curr line
			outp[w_Peak][0] = 0;
			outp[w_Peak][1] = 0;
			outp[w_Peak+1][0] = 0;
			outp[w_Peak+1][1] = 0;
			if (w_Peak>0)
			{
				outp[w_Peak-1][0] = 0;
				outp[w_Peak-1][1] = 0;
			}
	if (h_Peak-2>=0)// changed to >= in v.0.5
	{
			outp -= outwidth<<1; // prev prev line
			outp[w_Peak][0] = 0;
			outp[w_Peak][1] = 0;
			outp += outwidth<<1; // restore cur line
	}
	if (h_Peak-1>=0)// changed to >= in v.0.5
	{
			outp -= outwidth; // prev line
			outp[w_Peak][0] = 0;
			outp[w_Peak][1] = 0;
			outp[w_Peak+1][0] = 0;
			outp[w_Peak+1][1] = 0;
			if (w_Peak>0)
			{
				outp[w_Peak-1][0] = 0;
				outp[w_Peak-1][1] = 0;
			}
			outp += outwidth; // restore cur line
	}
	if (h_Peak+1<height)
	{
			outp += outwidth; // next line
			outp[w_Peak][0] = 0;
			outp[w_Peak][1] = 0;
			outp[w_Peak+1][0] = 0;
			outp[w_Peak+1][1] = 0;
			if (w_Peak>0)
			{
				outp[w_Peak-1][0] = 0;
				outp[w_Peak-1][1] = 0;
			}
			outp -= outwidth; // restore cur line
	}
	if (h_Peak+2<height)
	{
			outp += outwidth<<1; // next next line
			outp[w_Peak][0] = 0;
			outp[w_Peak][1] = 0;
			outp -= outwidth<<1; // restore cur line
	}

} // end cleanPeak


///////////////////////////////////////////////////////////////////////////////
//
// cleanWindow
//
///////////////////////////////////////////////////////////////////////////////

void FFTLibrary::cleanWindow(fftwf_complex *out, int outwidth, int height,
						 float fx, float fy, float dx, float dy, float fxPeak, float fyPeak, float sharpPeak)
{
	// more adaptive cleaning method, added in v.0.3
	fftwf_complex * outp = out;

//	float decreasingFactor = sqrtf(sharpPeak); //  factor to clean Peak with neighbors. 
	//I decide to use this empirical value for partial cleaning

	// get Peak value
	int w_Peak = int(fxPeak*outwidth)/100;
	int h_Peak = ( fyPeak >0 ) ? int(fyPeak*height)/200 : int(fyPeak*height)/200 + height-1;
	outp += outwidth*h_Peak; // curr line
	float fftmax = (outp[w_Peak][0])*(outp[w_Peak][0])+(outp[w_Peak][1])*(outp[w_Peak][1]);

	float fftbackground = fftmax/sharpPeak; //v0.7

	outp = out; // pointer

	// search Peak limits
    float fxmin = fmax(0.0, fx - dx);
    float fxmax = fmin(100.0, fx + dx);
    float fymin = fmax(-100.0, fy - dy);
    float fymax = fmin(100.0, fy + dy);
	
	// from float percent to integer
	int ixmin = int(fxmin * outwidth)/100;
	int ixmax = int(fxmax * outwidth)/100;
	int iymin = int(fymin * height)/200;
	int iymax = int(fymax * height)/200;

	int hmax = 0;
	int wmax = 0;
	float fftsum = 0;
	int fftcount = 0;
	int h,w;
	for (h=0; h < height/2; h++) 
	{       // Loop from top line to middle line 
			
			if (h>=iymin && h<=iymax)
			{
				for (w = ixmin; w <= ixmax; w++)       
				{
					float fftcur =	(outp[w][0])*(outp[w][0])+(outp[w][1])*(outp[w][1]); // modul*2
//					if (fftcur*decreasingFactor) > fftmax)
//					{
//						outp[w][0] /= decreasingFactor;
//						outp[w][1] /= decreasingFactor;
//					}
					if (fftcur > fftbackground) //new method (more pixels) in v.0.7
					{
						float f = sqrt(fftbackground/fftcur); //to background
						outp[w][0] *= f; // decrease
						outp[w][1] *= f; // decrease

					}
				}
			}
			outp += outwidth;
		}

		for (h=height/2; h < height; h++) 
		{       // Loop from middle line to bottom line 
			
			if (h >= height+iymin-1 && h <= height+iymax-1)
			{
				for (w = ixmin; w <= ixmax; w++)       
				{
					float fftcur =	(outp[w][0])*(outp[w][0])+(outp[w][1])*(outp[w][1]); // modul*2
					if (fftcur > fftbackground) //v0.7
					{
						float f = sqrt(fftbackground/fftcur);
						outp[w][0] *= f; // decrease
						outp[w][1] *= f; // decrease
					}
				}
			}
			outp += outwidth;
	}

} // end cleanWindow


///////////////////////////////////////////////////////////////////////////////
//
// cleanHigh
//
///////////////////////////////////////////////////////////////////////////////

void FFTLibrary::cleanHigh(fftwf_complex *outp, int outwidth, int height, float cutx, float cuty)
{
	// Butterworth low pass filter, 
	// factor = 1/( (freqx/cutx)*(freqx/cutx) + (freqy/cuty)*(freqy/cuty)

	int w,h;
	float fh,fw,f;
    //float invcutx = 100.0f/(cutx*outwidth);
    //float invcuty = 200.0f/(cuty*height);


    //printf("invcutx = %lf, invcuty = %lf\n", invcutx, invcuty);

    float invcutx = 0.0625;
    float invcuty = 0.0625;

    for (h=0; h < height/2; h++) {

        {
            fh = float(h)*invcuty;
            fh *= fh;
            for (w = 0; w < outwidth; w++) {
                fw = float(w)*invcutx;
                fw *= fw;
                f = 1/(1 + fh + fw);
                outp[w][0] *= f;
                outp[w][1] *= f;
            }
        }

        outp += outwidth;
    }

    for (h=height/2; h < height; h++) {

        {
            fh = float(height-h-1)*invcuty;
            fh *= fh;
            for (w = 0; w < outwidth; w++) {
                fw = float(w)*invcutx;
                fw *= fw;
                f = 1/(1 + fh + fw);
                outp[w][0] *= f;
                outp[w][1] *= f;
            }
        }

        outp += outwidth;
    }

} // end cleanHigh


///////////////////////////////////////////////////////////////////////////////
//
// getFFT2MinMax
//
///////////////////////////////////////////////////////////////////////////////

void FFTLibrary::getFFT2MinMax(float *psd, int outwidth, int height, float *fft2min, float *fft2max) // changed in v0.6
{
		// found fftmin and fftmax
		float fft2cur;
		float psdmin = 1.0e14f; // bug fixed in v.0.4a
		float psdmax = 0;
		for (int h=0; h < height; h++) 
		{   
			for (int w = 0; w < outwidth; w++) 
			{
				fft2cur = psd[w]; 
//				if (fft2cur < psdmin) 
//				{
//					psdmin = fft2cur;
//				}
				if (fft2cur > psdmax) 
				{
					psdmax = fft2cur;
				}
			}
			psd += outwidth;
		}
		if (psdmax == 0)
		{
			psdmax = 1.0f;
		}
		psdmin = (psdmax)*1.0e-13f; // some empirical number - v0.6
		*fft2min = psdmin;
		*fft2max = psdmax;

} // end getFFT2MinMax

/**

//-------------------------------------------------------------------------------------------
void DeFreq::DrawSearchBox(float * psd, int outwidth, int height, float fx, float fy, float dx, float dy, float fftvalue)
{
	float fxmin = max(0, fx - dx);
	float fxmax = min(100, fx + dx);
	float fymin = max(-100, fy - dy);
	float fymax = min(100, fy + dy);

	// from float percent to integer
	int ixmin = int(fxmin * outwidth)/100;
	int ixmax = int(fxmax * outwidth)/100;
	int iymin = int(fymin * height)/200;
	int iymax = int(fymax * height)/200;

	int hmin = ( iymin >=0 ) ? iymin : iymin + height-1; // changed to >= in v.0.5
	int hmax = ( iymax >=0 ) ? iymax : iymax + height-1; // changed to >= in v.0.5
	int w,h;
	if (hmin <= hmax) // one region
	{
		psd += outwidth*hmin;
		for (w=ixmin; w<=ixmax; w++)
		{
			psd[w] = fftvalue;
		}
		for (h=hmin; h<hmax; h++)
		{
			psd[ixmin] = fftvalue;
			psd[ixmax] = fftvalue;
			psd += outwidth;
		}
		for (w=ixmin; w<=ixmax; w++)
		{
			psd[w] = fftvalue;
		}
	}
	else // two regions (fymin<0, fymax>0    i.e.      hmin>height/2, hmax<height/2)
	{
//		for (w=ixmin; w<ixmax; w++) // disabled in v0.6
		{
//			psd[w] = fftvalue;
		}
		for (h=0; h<hmax; h++)
		{
			psd[ixmin] = fftvalue;
			psd[ixmax] = fftvalue;
			psd += outwidth;
		}
		for (w=ixmin; w<ixmax; w++)
		{
			psd[w] = fftvalue;
		}
		psd += outwidth*(hmin-hmax);
		for (w=ixmin; w<ixmax; w++)
		{
			psd[w] = fftvalue;
		}
		for (h=hmin; h<height; h++)
		{
			psd[ixmin] = fftvalue;
			psd[ixmax] = fftvalue;
			psd += outwidth;
		}
//		for (w=ixmin; w<ixmax; w++) // disabled in v0.6
		{
//			psd[w] = fftvalue;
		}
	}

// must be added case fymax<fymin

}
**/



///////////////////////////////////////////////////////////////////////////////
//
// cleanHigh2
//
///////////////////////////////////////////////////////////////////////////////

void FFTLibrary::cleanHigh2(fftwf_complex *outp, int outwidth, int height, int spacing)
{
    // Butterworth low pass filter,
    // factor = 1/(2*spacing)

    int w,h;
    float fh,fw,f;

    float invcutx = 1.0 / (2.0*(float)(spacing)*outwidth);
    float invcuty = 1.0 / (2.0*(float)(spacing)*height);

    for (h=0; h < height/2; h++) {

        {
            fh = float(h)*invcuty;
            fh *= fh;
            for (w = 0; w < outwidth; w++) {
                fw = float(w)*invcutx;
                fw *= fw;
                f = 1/(1 + fh + fw);
                outp[w][0] *= f;
                outp[w][1] *= f;
            }
        }

        outp += outwidth;
    }

    for (h=height/2; h < height; h++) {

        {
            fh = float(height-h-1)*invcuty;
            fh *= fh;
            for (w = 0; w < outwidth; w++) {
                fw = float(w)*invcutx;
                fw *= fw;
                f = 1/(1 + fh + fw);
                outp[w][0] *= f;
                outp[w][1] *= f;
            }
        }

        outp += outwidth;
    }

} // end cleanHigh2



///////////////////////////////////////////////////////////////////////////////
//
// highpassFilter
//
///////////////////////////////////////////////////////////////////////////////

void FFTLibrary::highpassFilter(fftwf_complex *outp, int outwidth, int height)
{
    float radius = 30.0;

    for (int i=0; i<height; i++) {
        for (int j=0; j<outwidth; j++) {

            float d = sqrt( ((height/2.0)-j) * ((height/2.0)-j) +
                ((outwidth/2.0)-i) * ((outwidth/2.0)-i) );

            outp[i][j] = 1.0 - exp(-(d*d)/(2*radius*radius));

        }
    }

} // end highpassFilter


///////////////////////////////////////////////////////////////////////////////
//
// bandpassFilter
//
///////////////////////////////////////////////////////////////////////////////

void FFTLibrary::bandpassFilter(fftwf_complex *outp, int outwidth, int height)
{    
    // Butterworth low pass filter,
    // factor = 1/(2*spacing)

    int w,h;
    float fh,fw,f;

    float invcutx = 1.0;
    float invcuty = 1.0;

    for (h=0; h < height/2; h++) {

        {
            fh = float(h)*invcuty;
            fh *= fh;
            for (w = 0; w < outwidth; w++) {
                fw = float(w)*invcutx;
                fw *= fw;
                f = 1/(1 + fh + fw);
                outp[w][0] *= f;
                outp[w][1] *= f;
            }
        }

        outp += outwidth;
    }

    for (h=height/2; h < height; h++) {

        {
            fh = float(height-h-1)*invcuty;
            fh *= fh;
            for (w = 0; w < outwidth; w++) {
                fw = float(w)*invcutx;
                fw *= fw;
                f = 1/(1 + fh + fw);
                outp[w][0] *= f;
                outp[w][1] *= f;
            }
        }

        outp += outwidth;
    }

} // end bandpassFilter

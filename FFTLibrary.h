#ifndef _FFT_LIBRARY
#define _FFT_LIBRARY

#include <stdio.h>
#include <math.h>

#include "cv.h"
#include "highgui.h"
#include "fftw3.h"

class FFTLibrary
{
    public:

        FFTLibrary();
        ~FFTLibrary();

        IplImage *lowpass (IplImage *img, int spacing);
        IplImage *highpass (IplImage *img);
        IplImage *bandpass (IplImage *img);

   private:

        void cleanPeak(fftwf_complex *out, int outwidth, int height, float fxPeak, float fyPeak);
        void cleanWindow(fftwf_complex *out, int outwidth, int height, float fx, float fy, float dx, float dy,
            float fxPeak, float fyPeak, float sharpPeak);
        void cleanHigh(fftwf_complex *outp, int outwidth, int height, float cutx, float cuty);
        void cleanHigh2(fftwf_complex *outp, int outwidth, int height, int spacing);
        void getFFT2MinMax(float *psd, int outwidth, int height, float *fft2min, float *fft2max);
        void bandpassFilter(fftwf_complex *outp, int outwidth, int height);
        void highpassFilter(fftwf_complex *outp, int outwidth, int height);
};

#endif

/*
Copyright (C) 2006 Pedro Felzenszwalb

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
*/

#include <cstdio>
#include <cstdlib>
#include "image.h"
#include "misc.h"
#include "pnmfile.h"
#include "segment-image.h"

IplImage *segmentation (IplImage *imageIn, float sigma, float k, float min_size)
{
    image<rgb> *input = loadIplImageFromMemory(imageIn);

    printf("processing\n");
    int num_ccs;
    image<rgb> *seg = segment_image(input, sigma, k, min_size, &num_ccs);

    IplImage *out = cvCreateImage(cvGetSize(imageIn), 8, 3);

    int counter = 0;
    for (int y = 0; y < out->height; y++) {
        for (int x = 0; x < out->width; x++) {
            ((uchar*)(out->imageData + out->widthStep*y))[x*3]   = imRef(seg, x, y).r;
            ((uchar*)(out->imageData + out->widthStep*y))[x*3+1] = imRef(seg, x, y).g;
            ((uchar*)(out->imageData + out->widthStep*y))[x*3+2] = imRef(seg, x, y).b;

        }
    }

    return out;

} // end segmentation


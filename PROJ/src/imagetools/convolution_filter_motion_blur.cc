// Copyright 2018 <Jonathan Lee>

#include "imagetools/convolution_filter_motion_blur.h"

#include <iostream>
#include <string>

#include "imagetools/image_tools_math.h"

namespace image_tools {

  // constructor
  ConvolutionFilterMotionBlur::ConvolutionFilterMotionBlur() {
    radius = 5.0; dir = "North/South";}

    // destructor
    ConvolutionFilterMotionBlur::~ConvolutionFilterMotionBlur() {}

    // set values from imagetools.cc
    // string matches instead of using MBlurDir
    void ConvolutionFilterMotionBlur::SetValues(float r,
      std::string direction) {
     radius = r;
     dir = direction;
    }

    // string matches to 4 cases
    FloatMatrix* ConvolutionFilterMotionBlur::CreateKernel() {
    // printf("creating blur kernel\n");
    int rad = static_cast<int>(radius);
    FloatMatrix* blur_kernel = new FloatMatrix(radius);

    // sets vertical center to 1 and everything else to 0
    /*
        0  1  0
        0  1  0
        0  1  0
    */
    if (dir == "North/South") {
      for (int i = 0; i < blur_kernel->height(); i++) {
        for (int j = 0; j < blur_kernel->width(); j++) {
          if (j == rad)
            blur_kernel->set_value(i, j, 1);
          else
            blur_kernel->set_value(i, j, 0);
        }
      }
    // sets horizontal center to 1 and everything else to 0
    /*
        0  0  0
        1  1  1
        0  0  0
    */
    } else if (dir == "East/West") {
      for (int i = 0; i < blur_kernel->height(); i++) {
        for (int j = 0; j < blur_kernel->width(); j++) {
          if (i == rad)
            blur_kernel->set_value(i, j, 1);
          else
            blur_kernel->set_value(i, j, 0);
        }
      }
    // sets diagonal to 1 and everything else to 0
    /*
        0  0  1
        0  1  0
        1  0  0
    */
    } else if (dir == "Northeast/Southwest") {
      int counter = blur_kernel->width()-1;
      for (int i = 0; i < blur_kernel->height(); i++) {
        for (int j = 0; j < blur_kernel->width(); j++) {
          if (j == counter)
            blur_kernel->set_value(i, j, 1);
          else
            blur_kernel->set_value(i, j, 0);
        }
        counter--;
      }
    // sets diagonal to 1 and everything else to 0
    /*
        1  0  0
        0  1  0
        0  0  1
    */
    } else if (dir == "Northwest/Southeast") {
      int counter = 0;
      for (int i = 0; i < blur_kernel->height(); i++) {
        for (int j = 0; j < blur_kernel->width(); j++) {
          if (j == counter)
            blur_kernel->set_value(i, j, 1);
          else
            blur_kernel->set_value(i, j, 0);
        }
        counter++;
      }
    }

    blur_kernel->Normalize();
    return blur_kernel;
  }
}  // namespace image_tools

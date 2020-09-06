// Copyright 2018 <Jonathan Lee>

#include "imagetools/convolution_filter_blur.h"

#include <iostream>

#include "imagetools/image_tools_math.h"

namespace image_tools {

  // constructor
  ConvolutionFilterBlur::ConvolutionFilterBlur() {radius = 5.0;}

  // destructor
  ConvolutionFilterBlur::~ConvolutionFilterBlur() {}

  // sets radius of the kernel from imagetools.cc
  void ConvolutionFilterBlur::SetRad(float r) { radius = r; }

  /* Steps to creating CreateKernel():
      1. create matrix
      2. for each item in matrix:
        -get position relative to center using dist. form.
        -find gaussian value for each pos: gaussian(dist, radius)
        -set val in kernel to that gaussian val
      3. normalize
  */
  FloatMatrix* ConvolutionFilterBlur::CreateKernel() {
    // printf("creating blur kernel\n");
    FloatMatrix* blur_kernel = new FloatMatrix(radius);
    for (int i = 0; i < blur_kernel->height(); i++) {
      for (int j = 0; j < blur_kernel->width(); j++) {
        float dist_to_center = sqrt(
          pow((i - radius), 2)+pow((j - radius), 2));
        float g_val = ImageToolsMath::Gaussian(dist_to_center, radius);
        blur_kernel->set_value(i, j, g_val);
      }
    }
    blur_kernel->Normalize();
    return blur_kernel;
  }
}  // namespace image_tools

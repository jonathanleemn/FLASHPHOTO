// Copyright 2018 <Jonathan Lee>

#include "imagetools/convolution_filter_edge_detect.h"

#include "imagetools/image_tools_math.h"

namespace image_tools {

  // constructor
  ConvolutionFilterEdgeDetect::ConvolutionFilterEdgeDetect() {}

  // destructor
  ConvolutionFilterEdgeDetect::~ConvolutionFilterEdgeDetect() {}

  // hardcode 3x3 kernel and set all values to -1
  // set center value to 8
  FloatMatrix* ConvolutionFilterEdgeDetect::CreateKernel() {
    FloatMatrix* edge_kernel = new FloatMatrix(3, 3);
    for (int j = 0; j < edge_kernel->height(); j++) {
      for (int i = 0; i < edge_kernel->width(); i++) {
        edge_kernel->set_value(i, j, -1);
      }
    }
    edge_kernel->set_value(1, 1, 8);
    return edge_kernel;
  }
}  // namespace image_tools

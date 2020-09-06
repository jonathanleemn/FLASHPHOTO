// Copyright 2018 <Jonathan Lee>

#ifndef IMAGETOOLS_CONVOLUTION_FILTER_EDGE_DETECT_H_
#define IMAGETOOLS_CONVOLUTION_FILTER_EDGE_DETECT_H_

#include "imagetools/convolution_filter.h"

namespace image_tools {

/** @brief Implements a edge detecting filter using a corresponding edge
detecting kernel */
class ConvolutionFilterEdgeDetect : public ConvolutionFilter{
 public:
    ConvolutionFilterEdgeDetect();
    virtual ~ConvolutionFilterEdgeDetect();
    FloatMatrix* CreateKernel() override;
};
}  // namespace image_tools

#endif  // IMAGETOOLS_CONVOLUTION_FILTER_EDGE_DETECT_H_

// Copyright 2018 <Jonathan Lee>

#ifndef IMAGETOOLS_CONVOLUTION_FILTER_BLUR_H_
#define IMAGETOOLS_CONVOLUTION_FILTER_BLUR_H_

#include "imagetools/convolution_filter.h"

namespace image_tools {

/** @brief Implements a blur filter using a corresponding blur kernel*/
class ConvolutionFilterBlur : public ConvolutionFilter{
 public:
    /// Defaults to radius=5.0
    ConvolutionFilterBlur();
    virtual ~ConvolutionFilterBlur();
    void SetRad(float radius);
    FloatMatrix* CreateKernel() override;
 private:
    float radius;
};
}  // namespace image_tools

#endif  // IMAGETOOLS_CONVOLUTION_FILTER_BLUR_H_

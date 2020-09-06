// Copyright 2018 <Jonathan Lee>

#ifndef IMAGETOOLS_CONVOLUTION_FILTER_MOTION_BLUR_H_
#define IMAGETOOLS_CONVOLUTION_FILTER_MOTION_BLUR_H_

#include "imagetools/convolution_filter.h"
#include <string>

namespace image_tools {

  /** @brief Implements a motion blur filter using a corresponding motion blur
  kernel*/
class ConvolutionFilterMotionBlur : public ConvolutionFilter{
 public:
    /// Defaults to radius=5.0 and dir="North/South"
    ConvolutionFilterMotionBlur();
    virtual ~ConvolutionFilterMotionBlur();
    /** The direction of the blur is determined by the string passed to
    this method. There are four possible blur directions: "North/South",
    "East/West", "Northeast/Southwest" and "Northwest/Southeast". */
    void SetValues(float radius, std::string dir);
    FloatMatrix* CreateKernel() override;
 private:
    float radius;
    std::string dir;
};
}  // namespace image_tools

#endif  // IMAGETOOLS_CONVOLUTION_FILTER_MOTION_BLUR_H_

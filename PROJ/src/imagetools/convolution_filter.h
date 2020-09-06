// Copyright 2018 <Jonathan Lee>

#ifndef IMAGETOOLS_CONVOLUTION_FILTER_H_
#define IMAGETOOLS_CONVOLUTION_FILTER_H_

#include "imagetools/filter.h"
#include "imagetools/color_data.h"
#include "imagetools/float_matrix.h"
#include "imagetools/pixel_buffer.h"
#include "imagetools/image_tools_math.h"

namespace image_tools {

/** @brief Inherits from the Filter class to implement the following convolution
filters: Blur, Edge Detect, Motion Blur, and Sharpen. */
class ConvolutionFilter : public Filter {
 public:
    ConvolutionFilter();
    virtual ~ConvolutionFilter();
    /// Will be overriden by the convolution filters.
    virtual FloatMatrix* CreateKernel();
    /// Creates a default kernel.
    void SetupFilter() override;
    /// Repurposed code to calculate each filtered pixel.
    /// Source: https://lodev.org/cgtutor/filtering.html.
    ColorData CalculateFilteredPixel(PixelBuffer *buffer,
      int x, int y) override;
    /// Deletes pointer value.
    void CleanupFilter() override;
    /// Convolution Filters require a copy buffer since they cannot
    /// be copied in place.
    bool can_copy_in_place() override;
 protected:
    FloatMatrix* kernel_;
};
}  // namespace image_tools

#endif  // IMAGETOOLS_CONVOLUTION_FILTER_H_

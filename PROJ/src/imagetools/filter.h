// Copyright 2018 <Jonathan Lee>

#ifndef IMAGETOOLS_FILTER_H_
#define IMAGETOOLS_FILTER_H_

#include "imagetools/color_data.h"
#include "imagetools/float_matrix.h"
#include "imagetools/pixel_buffer.h"

namespace image_tools {

/** @brief Serves as the parent class to implement all filters. Modifies an
image by changing each pixel value within the image. */
class Filter {
 public:
    Filter();
    virtual ~Filter();
    virtual void SetupFilter();
    /// Deletes pointer.
    virtual void CleanupFilter();
    /** Simple filters (FilterChannels, FilterQuantize, FilterSaturate, and
    FilterThreshold) can be copied in place, whereas convolution filters 
    (ConvolutionFilterBlur, ConvolutionFilterEdgeDetect,
    ConvolutionFilterMotionBlur, and ConvolutionFilterSharpen ) cannot. */
    virtual bool can_copy_in_place();
    /// Applies a filter by looping through each pixel in an image and
    /// modifying that pixel.
    virtual ColorData CalculateFilteredPixel(PixelBuffer *buffer, int x, int y);
    void ApplyToBuffer(PixelBuffer *buffer);
};
}  // namespace image_tools

#endif  // IMAGETOOLS_FILTER_H_

// Copyright 2018 <Jonathan Lee>

#ifndef IMAGETOOLS_FILTER_THRESHOLD_H_
#define IMAGETOOLS_FILTER_THRESHOLD_H_

#include "imagetools/filter.h"

namespace image_tools {

/** @brief Implements a filter by rounding an image's RGB value up to 1.0
(white) if it's pixel value is greater than the threshold input or down to 0.0
(black) if it's pixel value is lower than the threshold input. */
class FilterThreshold : public Filter{
 public:
    /// Defaults to threshold_val=0.5
    FilterThreshold();
    virtual ~FilterThreshold();
    ColorData CalculateFilteredPixel(PixelBuffer *buffer,
        int x, int y) override;
    void SetValue(float threshold_val);

 private:
    float threshold_val;
};
}  // namespace image_tools

#endif  // IMAGETOOLS_FILTER_THRESHOLD_H_

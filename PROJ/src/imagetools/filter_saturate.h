// Copyright 2018 <Jonathan Lee>

#ifndef IMAGETOOLS_FILTER_SATURATE_H_
#define IMAGETOOLS_FILTER_SATURATE_H_

#include "imagetools/filter.h"
#include "imagetools/image_tools_math.h"

namespace image_tools {

/** @brief Implements a filter by increasing or decreasing the intensity of an
image's colors*/
class FilterSaturate: public Filter{
 public:
    /// Defaults to sat_value=0.5
    FilterSaturate();
    virtual ~FilterSaturate();
    ColorData CalculateFilteredPixel(PixelBuffer *buffer,
        int x, int y) override;
    void SetValue(float sat_val);

 private:
    float sat_val;
};
}  // namespace image_tools

#endif  // IMAGETOOLS_FILTER_SATURATE_H_

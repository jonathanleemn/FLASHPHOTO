// Copyright 2018 <Jonathan Lee>

#ifndef IMAGETOOLS_FILTER_QUANTIZE_H_
#define IMAGETOOLS_FILTER_QUANTIZE_H_

#include "imagetools/filter.h"

namespace image_tools {

/** @brief Implements a filter by reducing the number of colors in the image
via a binning method. Each color channel is modified by placing it into the 
closest bin.*/
class FilterQuantize: public Filter{
 public:
    /// Defaults to bin_val=1
    FilterQuantize();
    virtual ~FilterQuantize();
    ColorData CalculateFilteredPixel(PixelBuffer *buffer,
        int x, int y) override;
    void SetValue(int bin_val);

 private:
    int bin_val;
};
}  // namespace image_tools

#endif  // IMAGETOOLS_FILTER_QUANTIZE_H_

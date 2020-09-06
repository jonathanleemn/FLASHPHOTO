// Copyright 2018 <Jonathan Lee>

#ifndef IMAGETOOLS_FILTER_CHANNELS_H_
#define IMAGETOOLS_FILTER_CHANNELS_H_

#include "imagetools/filter.h"

namespace image_tools {

/** @brief Implements a filter by adjusting the red, green, blue values of each
pixel.*/
class FilterChannels : public Filter{
 public:
    /// Defaults to r=0.5, g=0.5, and b=0.5
    FilterChannels();
    virtual ~FilterChannels();
    ColorData CalculateFilteredPixel(PixelBuffer *buffer,
        int x, int y) override;
    void SetValues(float r, float g, float b);

 private:
    float r;
    float g;
    float b;
};
}  // namespace image_tools

#endif  // IMAGETOOLS_FILTER_CHANNELS_H_

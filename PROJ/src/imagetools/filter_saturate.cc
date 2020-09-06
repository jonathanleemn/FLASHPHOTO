// Copyright 2018 <Jonathan Lee>

#include "imagetools/filter_saturate.h"

namespace image_tools {

  // constructor
  FilterSaturate::FilterSaturate() {sat_val = 0.5;}

  // destructor
  FilterSaturate::~FilterSaturate() {}

  // grabs saturate value from imagetools.cc
  void FilterSaturate::SetValue(float val) { sat_val = val; }

  // linearly interpolates between greyscale pixel and the original pixel
  ColorData FilterSaturate::CalculateFilteredPixel(
    PixelBuffer *buffer, int x, int y) {
    ColorData pixel_color = buffer->pixel(x, y);
    ColorData greyscale = ColorData(pixel_color.Luminance(),
      pixel_color.Luminance(), pixel_color.Luminance());
    return ImageToolsMath::Lerp(greyscale, pixel_color, sat_val);
  }
}  // namespace image_tools

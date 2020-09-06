// Copyright 2018 <Jonathan Lee>

#include "imagetools/filter_threshold.h"

namespace image_tools {

  // constructor
  FilterThreshold::FilterThreshold() {threshold_val = 0.5;}

  // destructor
  FilterThreshold::~FilterThreshold() {}

  // sets threshold value from imagetools.cc
  void FilterThreshold::SetValue(float val) {
    threshold_val = val;
  }

  // sets pixel to black if average intensity is less than threshold_val
  // otherwise pixel set to white
  ColorData FilterThreshold::CalculateFilteredPixel(
    PixelBuffer *buffer, int x, int y) {
    ColorData pixel_color = buffer->pixel(x, y);
    // finds average intensity of the pixel by averaging its rgb values
    float avg = (pixel_color.red() + pixel_color.green() +
      pixel_color.blue()) / 3.0f;
    if (avg < threshold_val)
      return ColorData(0.0f, 0.0f, 0.0f);
    else
      return ColorData(1.0f, 1.0f, 1.0f);
  }
}  // namespace image_tools

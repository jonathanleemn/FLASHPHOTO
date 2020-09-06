// Copyright 2018 <Jonathan Lee>

#include "imagetools/filter_quantize.h"

#include <cmath>

namespace image_tools {
  // constructor
  FilterQuantize::FilterQuantize() { bin_val = 1; }

  // destructor
  FilterQuantize::~FilterQuantize() {}

  // grabs bin number from imagetools.cc
  void FilterQuantize::SetValue(int val) { bin_val = val; }

  /*  source: DanK_IntroToFlashPhoto.pdf
      reduces # of bins of unique colors in image by binning similar colors
  */
  ColorData FilterQuantize::CalculateFilteredPixel(
    PixelBuffer *buffer, int x, int y) {
    ColorData pixel_color = buffer->pixel(x, y);
    int num_steps = bin_val - 1;
    float red = round(pixel_color.red() * num_steps) / num_steps;
    float green = round(pixel_color.green() * num_steps) / num_steps;
    float blue = round(pixel_color.blue() * num_steps) / num_steps;

    return ColorData(red, green, blue);
  }
}  // namespace image_tools

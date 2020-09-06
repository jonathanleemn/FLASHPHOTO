// Copyright 2018 <Jonathan Lee>

#include "imagetools/filter_channels.h"

#include <iostream>

namespace image_tools {
  // constructor
  FilterChannels::FilterChannels() { r = 0.5; g = 0.5; b = 0.5; }

  // destructor
  FilterChannels::~FilterChannels() {}

  // grabs rgb values from imagetools.cc
  void FilterChannels::SetValues(float r_val, float g_val, float b_val) {
    r = r_val;
    g = g_val;
    b = b_val;
  }

  // scales rgb channels to the values from the setter
  ColorData FilterChannels::CalculateFilteredPixel(
    PixelBuffer *buffer, int x, int y) {
    ColorData pixel_color = buffer->pixel(x, y);
    pixel_color.set_red(pixel_color.red() * r);
    pixel_color.set_green(pixel_color.green() * g);
    pixel_color.set_blue(pixel_color.blue() * b);
    pixel_color.Clamp();
    return pixel_color;
  }
}  // namespace image_tools

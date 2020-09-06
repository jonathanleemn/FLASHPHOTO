// Copyright 2018 <Jonathan Lee>

#include "imagetools/filter.h"

#include <iostream>

namespace image_tools {
  // constructor
  Filter::Filter() {}

  // destructor
  Filter::~Filter() {}

  // will be overridden by convolution filters
  void Filter::SetupFilter() {}

  // will be overridden by convolution filters
  void Filter::CleanupFilter() {}

  // will be set to false in convolution filters
  bool Filter::can_copy_in_place() { return true; }

  // will be overridden by filters
  ColorData Filter::CalculateFilteredPixel(PixelBuffer *buffer, int x, int y) {
    return buffer->pixel(x, y);
  }

  void Filter::ApplyToBuffer(PixelBuffer *buffer) {
    SetupFilter();
    // loops through every pixel in a copy buffer
    // used for convolution filters
    if (!can_copy_in_place()) {
      PixelBuffer *copy = new PixelBuffer(*buffer);
      for (int j = 0; j < copy->height(); j++) {
        for (int i = 0; i < copy->width(); i++) {
          ColorData pixel_color = CalculateFilteredPixel(copy, i, j);
          buffer->set_pixel(i, j, pixel_color);
        }
      }
      delete copy;
    } else {  // loops through every pixel in the buffer for the simple filters
      for (int j = 0; j < buffer->height(); j++) {
        for (int i = 0; i < buffer->width(); i++) {
          ColorData pixel_color = CalculateFilteredPixel(buffer, i, j);
          buffer->set_pixel(i, j, pixel_color);
        }
      }
    }

    CleanupFilter();
  }

} /* namespace image_tools */

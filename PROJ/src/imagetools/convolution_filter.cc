// Copyright 2018 <Jonathan Lee>

#include "imagetools/convolution_filter.h"

namespace image_tools {

  // constructor
  ConvolutionFilter::ConvolutionFilter() {}

  // destructor
  ConvolutionFilter::~ConvolutionFilter() {}

  // will be overriden by convolution filters
  FloatMatrix* ConvolutionFilter::CreateKernel() { return kernel_; }

  // creates default kernel
  void ConvolutionFilter::SetupFilter() { kernel_ = CreateKernel(); }

  // source: https://lodev.org/cgtutor/filtering.html
  ColorData ConvolutionFilter::CalculateFilteredPixel(PixelBuffer *buffer,
    int x, int y) {
    double red = 0.0;
    double green = 0.0;
    double blue = 0.0;

    for (int filterY = 0; filterY < kernel_->height(); filterY++) {
      for (int filterX = 0; filterX < kernel_->width(); filterX++) {
        int imageX = x - (kernel_->width() / 2) + filterX;
        int imageY = y - (kernel_->height() / 2) + filterY;

        // make sure we're within the bounds of the canvas
        imageX = ImageToolsMath::Clamp(imageX, 0, buffer->width()-1);
        imageY = ImageToolsMath::Clamp(imageY, 0, buffer->height()-1);

        ColorData pixel_color = buffer->pixel(imageX, imageY);

        red += pixel_color.red() * kernel_->value(filterX, filterY);
        green += pixel_color.green() * kernel_->value(filterX, filterY);
        blue += pixel_color.blue() * kernel_->value(filterX, filterY);
      }
    }
    ColorData new_color = ColorData(red, green, blue);

    new_color.Clamp();
    return new_color;
  }

  // deletes pointer value
  void ConvolutionFilter::CleanupFilter() { delete kernel_; }

  // convolution filters req a copy buffer
  bool ConvolutionFilter::can_copy_in_place() { return false; }

} /* namespace image_tools */

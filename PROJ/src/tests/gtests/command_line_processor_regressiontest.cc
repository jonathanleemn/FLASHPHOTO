// Copyright Jonathan Lee <2018>

#include <iostream>
#include "gtest/gtest.h"
#include "mia/command_line_processor.h"
#include "imagetools/image_editor.h"
#include "imagetools/color_data.h"

using image_tools::PixelBuffer;
using image_tools::ImageEditor;
using image_tools::ColorData;
using image_tools::ToolChalk;

class RegressionTest : public ::testing::Test {
  void SetUp() override {
    buf_test = new PixelBuffer("resources/test.png");
    buf_blur = new PixelBuffer("resources/blur.png");
    buf_edge = new PixelBuffer("resources/edge.png");
    buf_sharpen = new PixelBuffer("resources/sharpen.png");
    buf_red = new PixelBuffer("resources/red.png");
    buf_green = new PixelBuffer("resources/green.png");
    buf_blue = new PixelBuffer("resources/blue.png");
    buf_quantize = new PixelBuffer("resources/quantize.png");
    buf_saturate = new PixelBuffer("resources/saturate.png");
    buf_threshold = new PixelBuffer("resources/threshold.png");
    buf_mblur_n_s = new PixelBuffer("resources/mblurns.png");
    buf_mblur_e_w = new PixelBuffer("resources/mblurew.png");
    buf_mblur_ne_sw = new PixelBuffer("resources/mblurnesw.png");
    buf_mblur_nw_se = new PixelBuffer("resources/mblurnwse.png");
    image_editor_ = new ImageEditor();
  }

  void TearDown() override {
    delete buf_test;
    delete buf_blur;
    delete buf_edge;
    delete buf_sharpen;
    delete buf_red;
    delete buf_green;
    delete buf_blue;
    delete buf_quantize;
    delete buf_saturate;
    delete buf_threshold;
    delete buf_mblur_n_s;
    delete buf_mblur_e_w;
    delete buf_mblur_ne_sw;
    delete buf_mblur_nw_se;
    delete image_editor_;
    delete buf_tool;
  }

 protected:
  PixelBuffer* buf_test;
  PixelBuffer* buf_blur;
  PixelBuffer* buf_edge;
  PixelBuffer* buf_sharpen;
  PixelBuffer* buf_red;
  PixelBuffer* buf_green;
  PixelBuffer* buf_blue;
  PixelBuffer* buf_quantize;
  PixelBuffer* buf_saturate;
  PixelBuffer* buf_threshold;
  PixelBuffer* buf_mblur_n_s;
  PixelBuffer* buf_mblur_e_w;
  PixelBuffer* buf_mblur_ne_sw;
  PixelBuffer* buf_mblur_nw_se;
  ImageEditor* image_editor_;
  PixelBuffer* buf_tool;
};

TEST_F(RegressionTest, BlurTest) {
  image_editor_->set_pixel_buffer(buf_test);
  image_editor_->ApplyBlurFilter(5.0);
  buf_test = image_editor_->pixel_buffer();

  EXPECT_EQ(*buf_blur, *buf_test);
  buf_test = new PixelBuffer("resources/test.png");
}

TEST_F(RegressionTest, EdgeDetectTest) {
  image_editor_->set_pixel_buffer(buf_test);
  image_editor_->ApplyEdgeDetectFilter();
  buf_test = image_editor_->pixel_buffer();

  EXPECT_EQ(*buf_edge, *buf_test);
  buf_test = new PixelBuffer("resources/test.png");
}

TEST_F(RegressionTest, SharpenTest) {
  image_editor_->set_pixel_buffer(buf_test);
  image_editor_->ApplySharpenFilter(5.0);
  buf_test = image_editor_->pixel_buffer();

  EXPECT_EQ(*buf_sharpen, *buf_test);
  buf_test = new PixelBuffer("resources/test.png");
}

TEST_F(RegressionTest, ChannelsTest) {
  image_editor_->set_pixel_buffer(buf_test);
  image_editor_->ApplyChannelsFilter(5.0, 1.0, 1.0);
  buf_test = image_editor_->pixel_buffer();

  EXPECT_EQ(*buf_red, *buf_test);
  buf_test = new PixelBuffer("resources/test.png");

  image_editor_->set_pixel_buffer(buf_test);
  image_editor_->ApplyChannelsFilter(1.0, 5.0, 1.0);
  buf_test = image_editor_->pixel_buffer();

  EXPECT_EQ(*buf_green, *buf_test);
  buf_test = new PixelBuffer("resources/test.png");

  image_editor_->set_pixel_buffer(buf_test);
  image_editor_->ApplyChannelsFilter(1.0, 1.0, 5.0);
  buf_test = image_editor_->pixel_buffer();

  EXPECT_EQ(*buf_blue, *buf_test);
  buf_test = new PixelBuffer("resources/test.png");
}

TEST_F(RegressionTest, QuantizeTest) {
  image_editor_->set_pixel_buffer(buf_test);
  image_editor_->ApplyQuantizeFilter(5);
  buf_test = image_editor_->pixel_buffer();

  EXPECT_EQ(*buf_quantize, *buf_test);
  buf_test = new PixelBuffer("resources/test.png");
}

TEST_F(RegressionTest, SaturateTest) {
  image_editor_->set_pixel_buffer(buf_test);
  image_editor_->ApplySaturateFilter(0.5);
  buf_test = image_editor_->pixel_buffer();

  EXPECT_EQ(*buf_saturate, *buf_test);
  buf_test = new PixelBuffer("resources/test.png");
}

TEST_F(RegressionTest, ThresholdTest) {
  image_editor_->set_pixel_buffer(buf_test);
  image_editor_->ApplyThresholdFilter(5.0);
  buf_test = image_editor_->pixel_buffer();

  EXPECT_EQ(*buf_threshold, *buf_test);
  buf_test = new PixelBuffer("resources/test.png");
}

TEST_F(RegressionTest, MblurTest) {
  image_editor_->set_pixel_buffer(buf_test);
  image_editor_->ApplyMotionBlurFilter(5.0, ImageEditor::MBLUR_DIR_N_S);
  buf_test = image_editor_->pixel_buffer();

  EXPECT_EQ(*buf_mblur_n_s, *buf_test);
  buf_test = new PixelBuffer("resources/test.png");

  image_editor_->set_pixel_buffer(buf_test);
  image_editor_->ApplyMotionBlurFilter(5.0, ImageEditor::MBLUR_DIR_E_W);
  buf_test = image_editor_->pixel_buffer();

  EXPECT_EQ(*buf_mblur_e_w, *buf_test);
  buf_test = new PixelBuffer("resources/test.png");

  image_editor_->set_pixel_buffer(buf_test);
  image_editor_->ApplyMotionBlurFilter(5.0, ImageEditor::MBLUR_DIR_NE_SW);
  buf_test = image_editor_->pixel_buffer();

  EXPECT_EQ(*buf_mblur_ne_sw, *buf_test);
  buf_test = new PixelBuffer("resources/test.png");

  image_editor_->set_pixel_buffer(buf_test);
  image_editor_->ApplyMotionBlurFilter(5.0, ImageEditor::MBLUR_DIR_NW_SE);
  buf_test = image_editor_->pixel_buffer();

  EXPECT_EQ(*buf_mblur_nw_se, *buf_test);
  buf_test = new PixelBuffer("resources/test.png");
}

TEST_F(RegressionTest, ToolBlurTest) {
  image_editor_->set_pixel_buffer(buf_test);
  image_editor_->StartStroke("Blur", ColorData(0, 0, 0, 0), 5.0, 5, 5);
  image_editor_->AddToStroke(5, 6);
  image_editor_->AddToStroke(5, 7);
  image_editor_->AddToStroke(5, 8);
  image_editor_->AddToStroke(5, 9);
  image_editor_->EndStroke(5, 10);
  image_editor_->SaveToFile("resources/tblur.png");
  buf_tool = new PixelBuffer("resources/tblur.png");
  EXPECT_EQ(*buf_test, *buf_tool);
}

TEST_F(RegressionTest, ToolCalligraphyTest) {
  image_editor_->set_pixel_buffer(buf_test);
  image_editor_->StartStroke("Caligraphy Pen",
    ColorData(0, 0, 0, 0), 5.0, 5, 5);
  image_editor_->AddToStroke(5, 6);
  image_editor_->AddToStroke(5, 7);
  image_editor_->AddToStroke(5, 8);
  image_editor_->AddToStroke(5, 9);
  image_editor_->EndStroke(5, 10);
  image_editor_->SaveToFile("resources/tcaligraphy.png");
  buf_tool = new PixelBuffer("resources/tcaligraphy.png");
  EXPECT_EQ(*buf_test, *buf_tool);
}

TEST_F(RegressionTest, ToolEraserTest) {
  image_editor_->set_pixel_buffer(buf_test);
  image_editor_->StartStroke("Eraser", ColorData(0, 0, 0, 0), 5.0, 5, 5);
  image_editor_->AddToStroke(5, 6);
  image_editor_->AddToStroke(5, 7);
  image_editor_->AddToStroke(5, 8);
  image_editor_->AddToStroke(5, 9);
  image_editor_->EndStroke(5, 10);
  image_editor_->SaveToFile("resources/teraser.png");
  buf_tool = new PixelBuffer("resources/teraser.png");
  EXPECT_EQ(*buf_test, *buf_tool);
}

TEST_F(RegressionTest, ToolHighlighterTest) {
  image_editor_->set_pixel_buffer(buf_test);
  image_editor_->StartStroke("Highlighter", ColorData(0, 0, 0, 0), 5.0, 5, 5);
  image_editor_->AddToStroke(5, 6);
  image_editor_->AddToStroke(5, 7);
  image_editor_->AddToStroke(5, 8);
  image_editor_->AddToStroke(5, 9);
  image_editor_->EndStroke(5, 10);
  image_editor_->SaveToFile("resources/thighlighter.png");
  buf_tool = new PixelBuffer("resources/thighlighter.png");
  EXPECT_EQ(*buf_test, *buf_tool);
}

TEST_F(RegressionTest, ToolPenTest) {
  image_editor_->set_pixel_buffer(buf_test);
  image_editor_->StartStroke("Pen", ColorData(0, 0, 0, 0), 5.0, 5, 5);
  image_editor_->AddToStroke(5, 6);
  image_editor_->AddToStroke(5, 7);
  image_editor_->AddToStroke(5, 8);
  image_editor_->AddToStroke(5, 9);
  image_editor_->EndStroke(5, 10);
  image_editor_->SaveToFile("resources/tpen.png");
  buf_tool = new PixelBuffer("resources/tpen.png");
  EXPECT_EQ(*buf_test, *buf_tool);
}

TEST_F(RegressionTest, ToolSprayCanTest) {
  image_editor_->set_pixel_buffer(buf_test);
  image_editor_->StartStroke("Spray Can", ColorData(0, 0, 0, 0), 5.0, 5, 5);
  image_editor_->AddToStroke(5, 6);
  image_editor_->AddToStroke(5, 7);
  image_editor_->AddToStroke(5, 8);
  image_editor_->AddToStroke(5, 9);
  image_editor_->EndStroke(5, 10);
  image_editor_->SaveToFile("resources/tspray.png");
  buf_tool = new PixelBuffer("resources/tspray.png");
  EXPECT_EQ(*buf_test, *buf_tool);
}

TEST_F(RegressionTest, ToolChalkTest) {
  image_editor_->set_pixel_buffer(buf_test);
  image_editor_->StartStroke("Chalk", ColorData(0, 0, 0, 0), 5.0, 5, 5);
  image_editor_->AddToStroke(5, 6);
  image_editor_->AddToStroke(5, 7);
  image_editor_->AddToStroke(5, 8);
  image_editor_->AddToStroke(5, 9);
  image_editor_->EndStroke(5, 10);
  image_editor_->SaveToFile("resources/tchalk.png");
  buf_tool = new PixelBuffer("resources/tchalk.png");
  EXPECT_EQ(*buf_test, *buf_tool);
}

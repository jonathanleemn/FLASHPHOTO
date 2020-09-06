// Copyright Jonathan Lee <2018>

#include <iostream>
#include "gtest/gtest.h"
#include "mia/command_line_processor.h"

using image_tools::CommandLineProcessor;

class CommandLineProcessorTest : public ::testing::Test {
  void SetUp() override {
    cmd_processor = new CommandLineProcessor();
  }

  void TearDown() override {
    delete cmd_processor;
  }

 protected:
  CommandLineProcessor *cmd_processor;
};

TEST_F(CommandLineProcessorTest, BlurFilter) {
  char* testargv[] = {strdup("./build/bin/mia"), strdup("input.png"),
    strdup("-blur"), strdup("5.0"), strdup("output.png")};
  testing::internal::CaptureStdout();
  cmd_processor->ProcessCommandLine(5, testargv);
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "");
}

TEST_F(CommandLineProcessorTest, EdgeDetect) {
  char* testargv[] = {strdup("./build/bin/mia"), strdup("input.png"),
    strdup("-edgedetect"), strdup("output.png")};
  testing::internal::CaptureStdout();
  cmd_processor->ProcessCommandLine(4, testargv);
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "");
}

TEST_F(CommandLineProcessorTest, Sharpen) {
  char* testargv[] = {strdup("./build/bin/mia"), strdup("input.png"),
    strdup("-sharpen"), strdup("output.png")};
  testing::internal::CaptureStdout();
  cmd_processor->ProcessCommandLine(4, testargv);
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "");
}

TEST_F(CommandLineProcessorTest, Red) {
  char* testargv[] = {strdup("./build/bin/mia"), strdup("input.png"),
    strdup("-red"), strdup("5.0"), strdup("output.png")};
  testing::internal::CaptureStdout();
  cmd_processor->ProcessCommandLine(5, testargv);
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "");
}

TEST_F(CommandLineProcessorTest, Green) {
  char* testargv[] = {strdup("./build/bin/mia"), strdup("input.png"),
    strdup("-green"), strdup("5.0"), strdup("output.png")};
  testing::internal::CaptureStdout();
  cmd_processor->ProcessCommandLine(5, testargv);
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "");
}

TEST_F(CommandLineProcessorTest, Blue) {
  char* testargv[] = {strdup("./build/bin/mia"), strdup("input.png"),
    strdup("-blue"), strdup("5.0"), strdup("output.png")};
  testing::internal::CaptureStdout();
  cmd_processor->ProcessCommandLine(5, testargv);
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "");
}

TEST_F(CommandLineProcessorTest, Quantize) {
  char* testargv[] = {strdup("./build/bin/mia"), strdup("input.png"),
    strdup("-quantize"), strdup("5"), strdup("output.png")};
  testing::internal::CaptureStdout();
  cmd_processor->ProcessCommandLine(5, testargv);
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "");
}

TEST_F(CommandLineProcessorTest, Saturate) {
  char* testargv[] = {strdup("./build/bin/mia"), strdup("input.png"),
    strdup("-saturate"), strdup("5.0"), strdup("output.png")};
  testing::internal::CaptureStdout();
  cmd_processor->ProcessCommandLine(5, testargv);
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "");
}

TEST_F(CommandLineProcessorTest, Threshold) {
  char* testargv[] = {strdup("./build/bin/mia"), strdup("input.png"),
    strdup("-threshold"), strdup("5.0"), strdup("output.png")};
  testing::internal::CaptureStdout();
  cmd_processor->ProcessCommandLine(5, testargv);
  std::string output = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output, "");
}

TEST_F(CommandLineProcessorTest, MBlur) {
  char* testargv1[] = {strdup("./build/bin/mia"), strdup("input.png"),
    strdup("-motionblur-n-s"), strdup("5.0"), strdup("output.png")};
  testing::internal::CaptureStdout();
  cmd_processor->ProcessCommandLine(5, testargv1);
  std::string output1 = testing::internal::GetCapturedStdout();

  char* testargv2[] = {strdup("./build/bin/mia"), strdup("input.png"),
    strdup("-motionblur-e-w"), strdup("5.0"), strdup("output.png")};
  testing::internal::CaptureStdout();
  cmd_processor->ProcessCommandLine(5, testargv2);
  std::string output2 = testing::internal::GetCapturedStdout();

  char* testargv3[] = {strdup("./build/bin/mia"), strdup("input.png"),
    strdup("-motionblur-n-s"), strdup("5.0"), strdup("output.png")};
  testing::internal::CaptureStdout();
  cmd_processor->ProcessCommandLine(5, testargv3);
  std::string output3 = testing::internal::GetCapturedStdout();

  char* testargv4[] = {strdup("./build/bin/mia"), strdup("input.png"),
    strdup("-motionblur-n-s"), strdup("5.0"), strdup("output.png")};
  testing::internal::CaptureStdout();
  cmd_processor->ProcessCommandLine(5, testargv4);
  std::string output4 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, "");
  EXPECT_EQ(output2, "");
  EXPECT_EQ(output3, "");
  EXPECT_EQ(output4, "");
}

TEST_F(CommandLineProcessorTest, ErrorMessage) {
  char* testargv1[] = {strdup("./build/bin/mia"), strdup("input.png"),
    strdup("-threshold"), strdup("AHHHH"), strdup("output.png")};
  testing::internal::CaptureStdout();
  cmd_processor->ProcessCommandLine(5, testargv1);
  std::string output1 = testing::internal::GetCapturedStdout();

  char* testargv2[] = {strdup("./build/bin/mia"), strdup("-h")};
  testing::internal::CaptureStdout();
  cmd_processor->ProcessCommandLine(2, testargv2);
  std::string output2 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, output2);
}

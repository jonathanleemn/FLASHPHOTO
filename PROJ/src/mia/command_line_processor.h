// Copyright Jonathan Lee <2018>

#ifndef MIA_COMMAND_LINE_PROCESSOR_H_
#define MIA_COMMAND_LINE_PROCESSOR_H_

#include <string>
#include <cstring>
#include <iostream>

#include "imagetools/color_data.h"
#include "imagetools/image_editor.h"
#include "mia/image_editor_commands.h"

namespace image_tools {

  /** @brief Processes a series of input(s) from the user and applies the
   change(s) to an image without a GUI.*/
class CommandLineProcessor {
 public:
  CommandLineProcessor();
  virtual ~CommandLineProcessor();
  /// @brief Checks to see if the input(s) are valid.
  void ProcessCommandLine(int argc, char* argv[]);
  /// @brief Prints out a help message to the terminal if a user inputs an
  /// invalid command or if the user inputs "-h".
  void PrintErrorMessage();

 private:
  ImageEditor* image_editor_;
  std::string infile;
  std::string outfile;
  PixelBuffer* buf;
};
}  // namespace image_tools

#endif  // MIA_COMMAND_LINE_PROCESSOR_H_

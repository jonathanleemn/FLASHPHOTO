// Copyright Jonathan Lee <2018>

#include "mia/command_line_processor.h"

#include <vector>

namespace image_tools {

CommandLineProcessor::CommandLineProcessor() {
  image_editor_ = new ImageEditor();
  buf = new PixelBuffer(1280, 720, image_tools::ColorData(1, 1, 1));
}

CommandLineProcessor::~CommandLineProcessor() {}

void CommandLineProcessor::ProcessCommandLine(int argc, char* argv[]) {
  image_editor_->set_pixel_buffer(buf);

  // create a vector to store valid commands
  std::vector<ImageEditorCommand*> commands;
  infile = argv[1];

  // loops through each command and checks if it is valid
  // if valid, push the command onto the vector
  // else, print the errror message
  for (int i = 1; i < argc; i++) {
    std::string current_arg = argv[i];

    if ((current_arg == infile) && (current_arg != "-h") && argc >= 3) {
      try {
      outfile = argv[argc-1];
      ImageEditorCommand* load_command = new LoadCommand(image_editor_, infile);
      commands.push_back(load_command);
    }
    catch (const std::exception) {
      PrintErrorMessage();
    }
  } else if ((current_arg == "-blur") && (argv[i+1] != NULL) && argc >= 5) {
      try {
      std::string next_arg = argv[i+1];
      ImageEditorCommand* command = new BlurFilterCommand(image_editor_,
         stof(next_arg));
      commands.push_back(command);
      i++;
      }
      catch(const std::exception) {
        PrintErrorMessage();
      }
    } else if ((current_arg == "-edgedetect") && argc >= 4) {
      try {
      ImageEditorCommand* command = new EdgeFilterCommand(image_editor_);
      commands.push_back(command);
      }
      catch(const std::exception) {
        PrintErrorMessage();
      }
    } else if ((current_arg == "-sharpen") && (argv[i+1] != NULL) &&
        argc >= 5) {
      try {
      std::string next_arg = argv[i+1];
      ImageEditorCommand* command = new SharpenFilterCommand(image_editor_,
         stof(next_arg));
      commands.push_back(command);
      i++;
      }
      catch(const std::exception) {
        PrintErrorMessage();
      }
    } else if ((current_arg == "-red") && (argv[i+1] != NULL) && argc >= 5) {
      try {
      std::string next_arg = argv[i+1];
      ImageEditorCommand* command = new ChannelsFilterCommand(image_editor_,
        stof(next_arg), 1.0, 1.0);
      commands.push_back(command);
      i++;
    }
    catch(const std::exception) {
      PrintErrorMessage();
    }
    } else if ((current_arg == "-green") && (argv[i+1] != NULL) && argc >= 5) {
      try {
      std::string next_arg = argv[i+1];

      ImageEditorCommand* command = new ChannelsFilterCommand(image_editor_,
        1.0, stof(next_arg), 1.0);
      commands.push_back(command);
      i++;
    }
    catch(const std::exception) {
      PrintErrorMessage();
    }
    } else if ((current_arg == "-blue") && (argv[i+1] != NULL) && argc >= 5) {
      try {
      std::string next_arg = argv[i+1];

      ImageEditorCommand* command = new ChannelsFilterCommand(image_editor_,
        1.0, 1.0, stof(next_arg));
      commands.push_back(command);
      i++;
    }
    catch(const std::exception) {
      PrintErrorMessage();
    }
    } else if ((current_arg == "-quantize") && (argv[i+1] != NULL) &&
        argc >= 5) {
      try {
      std::string next_arg = argv[i+1];

      ImageEditorCommand* command = new QuantizeFilterCommand(image_editor_,
        stoi(next_arg));
      commands.push_back(command);
      i++;
    }
    catch(const std::exception) {
      PrintErrorMessage();
    }
    } else if ((current_arg == "-saturate") && (argv[i+1] != NULL) &&
        argc >= 5) {
      try {
      std::string next_arg = argv[i+1];

      ImageEditorCommand* command = new SaturateFilterCommand(image_editor_,
        stof(next_arg));
      commands.push_back(command);
      i++;
    }
    catch(const std::exception) {
      PrintErrorMessage();
    }
    } else if ((current_arg == "-threshold") && (argv[i+1] != NULL) &&
        argc >= 5) {
      try {
      std::string next_arg = argv[i+1];

      ImageEditorCommand* command = new ThresholdFilterCommand(image_editor_,
        stof(next_arg));
      commands.push_back(command);
      i++;
    }
    catch(const std::exception) {
      PrintErrorMessage();
    }
    } else if ((current_arg == "-motionblur-n-s") && (argv[i+1] != NULL) &&
        argc >= 5) {
      try {
      std::string next_arg = argv[i+1];

      ImageEditorCommand* command = new MotionBlurFilterCommand(image_editor_,
        stof(next_arg), ImageEditor::MBLUR_DIR_N_S);
      commands.push_back(command);
      i++;
    }
    catch(const std::exception) {
      PrintErrorMessage();
    }
    } else if ((current_arg == "-motionblur-e-w") && (argv[i+1] != NULL) &&
        argc >= 5) {
      try {
      std::string next_arg = argv[i+1];

      ImageEditorCommand* command = new MotionBlurFilterCommand(image_editor_,
        stof(next_arg), ImageEditor::MBLUR_DIR_E_W);
      commands.push_back(command);
      i++;
    }
    catch(const std::exception) {
      PrintErrorMessage();
    }
    } else if ((current_arg == "-motionblur-ne-sw") && (argv[i+1] != NULL) &&
        argc >= 5) {
      try {
      std::string next_arg = argv[i+1];

      ImageEditorCommand* command = new MotionBlurFilterCommand(image_editor_,
        stof(next_arg), ImageEditor::MBLUR_DIR_NE_SW);
      commands.push_back(command);
      i++;
    }
      catch(const std::exception) {
        PrintErrorMessage();
      }
    } else if ((current_arg == "-motionblur-nw-se") && (argv[i+1] != NULL) &&
        argc >= 5) {
      try {
      std::string next_arg = argv[i+1];

      ImageEditorCommand* command = new MotionBlurFilterCommand(image_editor_,
        stof(next_arg), ImageEditor::MBLUR_DIR_NW_SE);
      commands.push_back(command);
      i++;
    }
    catch(const std::exception) {
      PrintErrorMessage();
    }
  } else if ((current_arg == outfile) && argc >= 3) {
      try {
      ImageEditorCommand* save_command = new SaveCommand(
        image_editor_, outfile);
      commands.push_back(save_command);
    }
    catch(const std::exception) {
      PrintErrorMessage();
    }
    } else {
      PrintErrorMessage();
    }
  }

  // executes the commands if the vector isn't empty
  // after all commands are executed, they are deleted
  if (!commands.empty()) {
    for (unsigned i = 0; i < commands.size(); i++) {
      commands[i]->Execute();
    }
  }

for (ImageEditorCommand* ptr : commands)
  delete ptr;

commands.clear();
delete image_editor_;
delete buf;
}

void CommandLineProcessor::PrintErrorMessage() {
  std::cout << "\nusage: mia infile.png [image processing commands ...]" <<
  " outfile.png\n" <<
  "\ninfile.png: input image file iout.pngn png format\n" <<
  "outfile.png: filename to use for saving the result\n\n" <<
  "image processing commands:\n" <<
  "-blur r: apply a gaussian blur of radius r\n" <<
  "-edgedetect: apply an edge detection filter\n" <<
  "-sharpen r: apply a sharpening filter of radius r\n" <<
  "-red s: scale the red channel by factor s\n" <<
  "-green s: scale the green channel by factor s\n" <<
  "-blue s: scale the blue channel by factor s\n" <<
  "-quantize n: quantize each color channel into n bins\n" <<
  "-saturate s: saturate colors by scale factor s\n" <<
  "-threshold c: threshold using cutoff value c\n" <<
  "-motionblur-n-s r: north-south motion blur with kernel radius r\n" <<
  "-motionblur-e-w r: east-west motion blur with kernel radius r\n" <<
  "-motionblur-ne-sw r: ne-sw motion blur with kernel radius r\n" <<
  "-motionblur-nw-se r: nw-se motion blur with kernel radius r\n";
}
}  // namespace image_tools

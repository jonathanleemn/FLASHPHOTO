Main Page  {#mainpage}
===========



For Users  {#userpage}
===========
Getting Started with FlashPhoto: image_tools::FlashPhotoApp <br />
FlashPhoto is an image editing software that uses a number of brushes and
filters. Brushes allow users to simulate directly drawing on an image using
various tools. Filters alter an image by changing its pixel value. Filters are
broken up into two types: simple filters and convolution filters. Convolution
filters are different from the simple filters because their pixel value cannot
be copied in place and thus require a kernel. Executing FlashPhoto launches a
GUI with options to select different brushes and filters. <br />

Getting Started with Mia: image_tools::MiaApp <br />
Mia allows users to load an image, apply filters onto that image, and then save
the modified image. This is all done in the command line. <br />
Instructions on how to use Mia:
<br />
        1. Open terminal
        2. `cd [your project directory]`
        3. `make`
        4. `./build/bin/mia input.png [insert commands here] output.png`

Alternatively, users can type `./build/bin/mia -h` for more information on the
list of valid commands.



For Developers  {#devpage}
===========
Programming Reference: image_tools




High-Level Design  {#designpage}
===========
FlashPhoto and Mia are some of the more important classes within this project.
FlashPhoto uses a GUI where users can load an image, apply changes to the image
using various tools or filters implemented in the project and then save the
image on their machine. Mia allows users to perform the same tasks except 
through the command line instead of the GUI. These two classes make use of
various tools and filters (inherited from the Tool and Filter class,
respectively). Filter serves as the parent class for all filters, including
the Convolution Filters.

![picture alt](/home/leex6659/3081_F18/repo-leex6659/PROJ/resources/filters_uml.png)
![picture alt](/home/leex6659/3081_F18/repo-leex6659/PROJ/resources/tools_uml.png)



Coding Style  {#stylepage}
===========
This project adheres to the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
<br /> A few important details of how Google Style is used in this project:
<br />
        * Lines of code are no more than 80 characters. 
        * Header guards are included for .h files.
        * Variable and class names should be descriptive and self documenting
        * File names follow snake casing.

We wanted our code to follow a certain standard in order to ensure consistency
without our code. We ensured that it follows this guide by running 'cpplint.py'
or 'make check-style' on our machines. 





Common Tasks  {#taskpage}
===========
Thinking of adding a new filter to the project? <br />

If the pixels can be copied in place, then you can implement similarly to the
simple filters (Quantize, Channels, Saturate, and Threshold). Simply create a 
new filter class that inherits from the Filter parent class and overrides the 
CalculateFilteredPixel method from the parent class. It is also important to
implement setters to adjust the pixel value in this class and in the
ImageEditor class. <br />

If the pixels cannot be copied in place, you would implement it similarly to
the convolution filters (Blur, MotionBlur, EdgeDetect, Sharpen). For
convolution filters, you would need to override the CreateKernel method in
the ConvolutionFilter class. 


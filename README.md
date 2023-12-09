# pervasive_display_E2370PS0C1_demo

<section align="center"><img src="/readme_assets/pervasive_displays_370_1.png" width="600"/></section>

## components

- Display: [E2370PS0C1](https://www.pervasivedisplays.com/product/3-70-e-ink-displays/)
- Development board: [EXT3-1](https://www.pervasivedisplays.com/product/epd-extension-kit-gen-3-ext3/)
- Raspberry Pi Pico
- Jumper wires
- USB cable
- Development computer ( Windows, MacOS, or Linux )

## links

- Internal ticket: https://jira.clearpathrobotics.com/browse/CPE87-520
- Wiring guide: https://docs.pervasivedisplays.com/epd-usage/development-kits/ext3-1/wiring-to-raspberry-pico
- Wiring guide: https://github.com/PervasiveDisplays/EPD_Driver_GF_small
- https://embeddedcomputing.weebly.com/connecting-the-ext3-to-the-raspberry-pi-pico.html
- https://www.pervasivedisplays.com/rapidly-explore-the-capability-of-e-paper-with-ext2/


## notes

1.  I downloaded the repository <https://github.com/PervasiveDisplays/EPD_Driver_GF_small> as a .zip
2.  Next, I imported this .zip as a library in Arduino IDE
3.  I attempted to compile this, but was getting File Not Found errors from the import statements. 
    I then removed the file paths, and just included the library name to be imported, without the relative file path.
    Arduino IDE was then able to locate the file, and compile.
4.  The application manual mentions that bits are interpreted as:
    - 1 = Black
    - 0 = White
    This is opposite of how the PDi Apps tool outputs data.
    Per this tool:
    - 8 black pixels as (0x00)
    - 8 white pixels as (0xff)
5.  We need to use  1-bit grayscale color / monochrome images.

## files of interest, for making updates

- `examples/Demo/Demo.ino` is the main file that Arduino IDE will use to build the project.
- `examples/Demo/fastupdate_src/fp_data/370/images370.c` is a file where I have stored custom bitmaps.
  These could be separated into individual `.c` files per image.
  I combined all the Clearpath custom images into a single `.c` file for simplicity of showing how Pervasive Displays' Arduino library functions.
- `examples/Demo/fastupdate_src/fp_data/370/FuPu_Data.h` is used for importing the bitmap data from `.c` files, and defining constants with this data.

## creating a new bitmap image

Note that this all assumes that the physical display is in a horizontal orientation.

1.  Create a black and white `.png` image that is 416 pixels wide by 240 tall.
2.  Open Pervasive Displays PDI Apps V1.30.
    The `Pervasive Displays PDI Apps V1.30` installer was [available here](https://www.pervasivedisplays.com/private-doc/pdi-apps-v1-30-installer/) in December 2023. 
    I tested this on Windows 10.
    I do not know if it is available for other operating systems.

    <center><img src="/readme_assets/pervasive_displays_pdi_apps.png" width="600"/></center>

3.  Once the application is open, switch to the `Bitmap` tab.
4.  Select `File`, and navigate to the `png` created in Step 1.
5.  Select `Custom` image size, and set the fields to 240 Width, and 416 Height.
    This seems backwards, but it is deliberate due to the display's indexing direction being designed for a vertical orientation.

    <center><a href='https://www.pervasivedisplays.com/wp-content/uploads/2022/09/ApplicationNote_smallSize_fast-update_v02_20220907.pdf'><img src="/readme_assets/pervasive_displays_370_2.png" width="200"/></a></center>

6.  Select `Rotate - 180`.
7.  Select `Convert`.
8.  Copy all the text from the `Output Image Raw Data` field.
9.  Paste that text into a new object in the file `examples/Demo/fastupdate_src/fp_data/370/images370.c`.
    You will also need to define a new constant in `examples/Demo/fastupdate_src/fp_data/370/FuPu_Data.h`.
    After that, you can use the new constant / image in `examples/Demo/Demo.ino`.

## setup

1.  Get the components listed in this README, and connect them per the [Wiring Guide](https://docs.pervasivedisplays.com/epd-usage/development-kits/ext3-1/wiring-to-raspberry-pico).
2.  Install Arduino IDE on your development computer.
3.  Download this repository as a `.zip`.
4.  In the Arduino IDE application, install a ZIP library, selecting the `.zip` of this repository.
5.  In the Arduino IDE, open the example project `File → Examples → EPD_Driver → Demo`.
6.  Once loaded in the Arduino IDE, select the Board as a `Raspberry Pi Pico`, and select the Port that the microcontroller is connected to.
7.  Select the Upload button.
    Arduino IDE should build the broject, and flash the Raspberry Pi Pico.

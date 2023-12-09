# pervasive_display_E2370PS0C1_demo

<img src="/readme_assets/pervasive_displays_370_1.png" width="800"/>

## components

- Display: [E2370PS0C1](https://www.pervasivedisplays.com/product/3-70-e-ink-displays/)
- Development board: [EXT3-1](https://www.pervasivedisplays.com/product/epd-extension-kit-gen-3-ext3/)
- Raspberry Pi Pico

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

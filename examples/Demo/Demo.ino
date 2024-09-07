/*
  EPD_Driver_demo
  This is a demo sketch for the small PS-type EPDs from Pervasive Displays, Inc.
  The aim of this demo and the library used is to introduce CoG usage, global and fast update functionality.
  
  Hardware Suggested:
  * Launchpad MSP432P401R or (Tiva-C) with TM4C123/Arduino M0 Pro/Raspberry Pi Pico
  * EPD Extension Kit (EXT3 or EXT3-1)
  * Small-sized (<5") EPD (PS-type)
  * 10/20-pin rainbow cable
*/

#include <EPD_Driver.h>

// DEMO Image Set <Comment out when in User Mode>
// Screen Size: 154, 206, 213, 266, 271, 287, 292, 370, 417, 437
#define SCREEN 370
#include "./globalupdate_src/globalDemoImageData.h"
#include "./fastupdate_src/fastDemoImageData.h"
//------------------------------------------------------------

#define EPD_SIZE eScreen_EPD_370
#define BOARD_TYPE boardRaspberryPiPico_RP2040_EXT3

EPD_Driver epdtest(EPD_SIZE, BOARD_TYPE);

void setup()
{
	// Initialize CoG for GU
	epdtest.COG_initial_GU();
  
	// Global Update Call
	epdtest.globalUpdate(BW_monoBuffer, BW_0x00Buffer);

	// Turn off CoG
	epdtest.COG_powerOff();

	delay(2000);

	// Initialize CoG for FU
	epdtest.COG_initial_FU();
	
	delay(2000);
	epdtest.fastUpdate(FastPic_1, FastPic_b);
	epdtest.fastUpdate(FastPic_b, FastPic_w);

	// Turn off CoG
	// epdtest.COG_powerOff();
}

void loop()
{
	delay(2000);
	epdtest.fastUpdate(FastPic_w, img_hmi_5_flipped);
  delay(10000);
  epdtest.fastUpdate(img_hmi_5_flipped, img_hmi_3_flipped);
  delay(2000);
  epdtest.fastUpdate(img_hmi_3_flipped, img_hmi_2_flipped);
  delay(2000);
  epdtest.fastUpdate(img_hmi_2_flipped, img_hmi_1_flipped);
  delay(2000);
  epdtest.fastUpdate(img_hmi_1_flipped, img_hmi_4_flipped);
  delay(10000);
  epdtest.fastUpdate(img_hmi_4_flipped, FastPic_b);
  delay(2000);
	epdtest.fastUpdate(FastPic_b, FastPic_w);
}

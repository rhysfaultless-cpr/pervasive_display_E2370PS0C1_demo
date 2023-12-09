/*
	demoImageData.h
  DEMO set of Image Data
*/

// Load Global Update Images
#include "image_370_416x240_BW.c"
#include "image_370_416x240_BWR.c"
#define BW_monoBuffer        (uint8_t *) & image_370_416x240_BW_mono
#define BW_0x00Buffer        (uint8_t *) & image_370_416x240_BW_0x00
#define BWR_blackBuffer      (uint8_t *) & image_370_416x240_BWR_blackBuffer
#define BWR_redBuffer        (uint8_t *) & image_370_416x240_BWR_redBuffer

/*
	FuPu_Data.h
  User set of Image Data
*/

// 3.70"
#include "370_1.c"
#include "370_2.c"
#include "370_3.c"
#include "370_4.c"
#include "370_black.c"
#include "images370.c"


#define FastPic_1        (uint8_t *) & image_370_416x240_BW_mono
#define FastPic_2        (uint8_t *) & Img_370_1
#define FastPic_3        (uint8_t *) & Img_370_3
#define FastPic_4        (uint8_t *) & Img_370_1
#define FastPic_b        (uint8_t *) & Img_black
#define FastPic_w        (uint8_t *) & image_370_416x240_BW_0x00

#define img_cpr_240x416_1            (uint8_t *) & global_img_cpr_240x416_1
#define img_cpr_240x416_1_inverted   (uint8_t *) & global_img_cpr_240x416_1_inverted
#define img_cpr_240x416_2            (uint8_t *) & global_img_cpr_240x416_2
#define img_cpr_240x416_2_inverted   (uint8_t *) & global_img_cpr_240x416_2_inverted
#define img_cpr_240x416_3            (uint8_t *) & global_img_cpr_240x416_3
#define img_cpr_240x416_3_inverted   (uint8_t *) & global_img_cpr_240x416_3_inverted

#define img_hmi_1                    (uint8_t *) & global_img_hmi_1
#define img_hmi_2                    (uint8_t *) & global_img_hmi_2
#define img_hmi_3                    (uint8_t *) & global_img_hmi_3
#define img_hmi_4                    (uint8_t *) & global_img_hmi_4
#define img_hmi_5                    (uint8_t *) & global_img_hmi_5

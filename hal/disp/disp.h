/**
 * @file disp.h
 * 
 */

#ifndef DISP_H
#define DISP_H

/*********************
 *      INCLUDES
 *********************/
#include <stdint.h>
#include "misc/others/color.h"

/*********************
 *      DEFINES
 *********************/
#define DISP_ID_ALL 0xFF

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

void disp_area(uint8_t disp_id, int32_t x1, int32_t y1, int32_t x2, int32_t y2);
void disp_fill(uint8_t disp_id, color_t color);
void disp_map(uint8_t disp_id, color_t * color_p);

/**********************
 *      MACROS
 **********************/

#endif

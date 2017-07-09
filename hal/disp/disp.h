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
#include "misc/gfx/color.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Fill the an area with a color
 * @param x1 left coordinate of an area
 * @param y1 top coordinate of an area
 * @param x2 right coordinate of an area
 * @param y2 bottom coordinate of an area
 * @param color fill color
 */
void disp_fill(int32_t x1, int32_t y1, int32_t x2, int32_t y2, color_t color);

/**
 * Put a color map to an area
 * @param x1 left coordinate of an area
 * @param y1 top coordinate of an area
 * @param x2 right coordinate of an area
 * @param y2 bottom coordinate of an area
 * @param color_p pointer to an array of colors
 */
void disp_map(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const color_t * color_p);

/**********************
 *      MACROS
 **********************/

#endif

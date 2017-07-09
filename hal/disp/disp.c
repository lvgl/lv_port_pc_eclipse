/**
 * @file disp.c
 * 
 */

/*********************
 *      INCLUDES
 *********************/
#include "hw_conf.h"
#include "hal/disp/disp.h"
#include "hw/dev/dispc/SSD1963.h"
#include "hw/dev/dispc/R61581.h"
#include "hw/dev/dispc/ST7565.h"
#include "hw/per/tft.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * Fill the an area with a color
 * @param x1 left coordinate of an area
 * @param y1 top coordinate of an area
 * @param x2 right coordinate of an area
 * @param y2 bottom coordinate of an area
 * @param color fill color
 */
void disp_fill(int32_t x1, int32_t y1, int32_t x2, int32_t y2, color_t color)
{
    tft_fill(x1, y1, x2, y2, color);
}

/**
 * Put a color map to an area
 * @param x1 left coordinate of an area
 * @param y1 top coordinate of an area
 * @param x2 right coordinate of an area
 * @param y2 bottom coordinate of an area
 * @param color_p pointer to an array of colors
 */
void disp_map(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const color_t * color_p)
{
    tft_map(x1, y1, x2, y2, color_p);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

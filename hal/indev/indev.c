/**
 * @file indev.c
 * 
 */

/*********************
 *      INCLUDES
 *********************/
#include "indev.h"
#include "hw_conf.h"
#include "hw/dev/tp/XPT2046.h"
#include "hw/dev/tp/FT5406EE8.h"
#include "hw/dev/tp/mouse.h"

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
 * Read an input device
 * @param indev_id id of the input device to read
 * @param x put the x coordinate here
 * @param y put the y coordinate here
 * @return true: the device is pressed, false: released
 */
bool indev_get(uint8_t indev_id, int16_t * x, int16_t * y)
{
#if USE_XPT2046 != 0
    return xpt2046_get(x, y);
#endif

#if USE_FT5406EE8 != 0
    return ft5406ee8_get(x, y);
#endif

#if USE_MOUSE != 0
    return mouse_get(x, y);
#endif
    
    *x = 0;
    *y = 0;
    return false;

}
/**********************
 *   STATIC FUNCTIONS
 **********************/

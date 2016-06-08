/**
 * @file indev.h
 * 
 */

#ifndef INDEV_H
#define INDEV_H

/*********************
 *      INCLUDES
 *********************/
#include <stdbool.h>
#include <stdint.h>

/*********************
 *      DEFINES
 *********************/
#define INDEV_NUM 1

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
bool indev_get(uint8_t indev_id, int16_t * x, int16_t * y);

/**********************
 *      MACROS
 **********************/

#endif

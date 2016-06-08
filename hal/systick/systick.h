/**
 * @file systick.h
 * Provide access to the system tick with 1 millisecond resolution
 */

#ifndef SYSTICK_H
#define SYSTICK_H

/*********************
 *      INCLUDES
 *********************/
#include <stdint.h>
#include <stdbool.h>

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
uint32_t systick_get(void);
uint32_t systick_elaps(uint32_t prev_tick);
bool systick_add_cb(void (*cb) (void));
void systick_rem_cb(void (*cb) (void));


/**********************
 *      MACROS
 **********************/

#endif

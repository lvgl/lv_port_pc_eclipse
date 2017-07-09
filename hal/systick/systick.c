/**
 * @file systick.c
 * Provide access to the system tick with 1 millisecond resolution
 */

/*********************
 *      INCLUDES
 *********************/
#include "hw_conf.h"
#include "hw/per/tick.h"
#include "systick.h"

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
 * Get the elapsed milliseconds since start up
 * @return the elapsed milliseconds
 */
uint32_t systick_get(void)
{
	return tick_get();
}

/**
 * Get the elapsed milliseconds science a previous time stamp
 * @param prev_tick a previous time stamp from 'systick_get'
 * @return the elapsed milliseconds since 'prev_tick'
 */
uint32_t systick_elaps(uint32_t prev_tick)
{
	return tick_elaps(prev_tick);
}

/**
 * Add a callback function to the systick interrupt
 * @param cb a function pointer
 * @return true: 'cb' added to the systick callbacks, false: 'cb' not added
 */
bool systick_add_cb(void (*cb) (void))
{
	return tick_add_func(cb);
}

/**
 * Remove a callback function from the systick callbacks
 * @param cb a function pointer (added with 'systick_add_cb')
 */
void systick_rem_cb(void (*cb) (void))
{
	 tick_rem_func(cb);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

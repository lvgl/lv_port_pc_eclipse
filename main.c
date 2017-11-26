
/**
 * @file main
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdlib.h>
#include <unistd.h>
#include <SDL2/SDL.h>
#include "lv_drivers/display/monitor.h"
#include "lv_drivers/indev/mouse.h"
#include "lvgl/lvgl.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void hal_init(void);
static int tick_thread(void *data);
static bool mouse_input_read(lv_indev_data_t *data);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
int main (void)
{
    /*Initialize LittlevGL*/
    lv_init();

    /*Initialize the HAL for LittlevGL*/
    hal_init();

    /*Load a demo*/
    demo_init();


    while(1) {
        /* Periodically call the lv_task handler.
         * It could be done in a timer interrupt or an OS task too.*/
        lv_task_handler();
        usleep(5000);       /*Just to let the system breath*/
    }

    return 0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/**
 * Initialize the Hardware Abstraction Layer (HAL) for the Littlev graphics library
 */
static void hal_init(void)
{

    /* Add a display
     * Use the 'monitor' driver which creates window on PC's monitor to simulate a display*/
    monitor_init();
    lv_disp_drv_t disp_drv;
    memset(&disp_drv, 0, sizeof(disp_drv));     /*Basic initialization*/
    disp_drv.fill = monitor_fill;
    disp_drv.map = monitor_map;
    disp_drv.copy = NULL;
    lv_disp_register(&disp_drv);

    /* Add the mouse (or touchpad) as input device
     * Use the 'mouse' driver which reads the PC's mouse*/
    mouse_init();
    lv_indev_drv_t indev_drv;
    memset(&indev_drv, 0, sizeof(indev_drv));      /*Basic initialization*/
    indev_drv.type = LV_INDEV_TYPE_MOUSE;
    indev_drv.get_data = mouse_input_read;  /*This function will be called periodically (by the library) to get the mouse position and events*/
    lv_indev_register(&indev_drv);

    /* Tick init.
     * You have to call 'lv_tick_handler()' in every milliseconds
     * Create an SDL thread to do this*/
    SDL_CreateThread(tick_thread, "tick", NULL);

}

static int tick_thread(void *data)
{
    while(1) {
        lv_tick_handler();
        SDL_Delay(1);
    }

    return 0;
}


/**
 * Interface function to read the mouse position and events
 * @param data store the mouse info here
 * @return 'false' because no buffering in operation (it would return 'true' if there would be more data be read)
 */
static bool mouse_input_read(lv_indev_data_t * data)
{
    /*Get the mouse data*/
    lv_point_t p;
    bool state;
    state = mouse_get(&p.x, &p.y);

    /*Store the collected data*/
    data->point.x = p.x;
    data->point.y = p.y;
    data->state = state ? LV_INDEV_EVENT_PR : LV_INDEV_EVENT_REL;

    return false;
}

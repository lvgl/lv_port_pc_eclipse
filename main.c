
/**
 * @file main
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdlib.h>
#include <unistd.h>
#include "hw/hw.h"
#include "hw/per/tft.h"
#include "hw/per/tick.h"
#include "hw/dev/indev/mouse.h"
#include "misc/misc.h"
#include "misc/os/ptask.h"
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
    /*Initialize the the misc. library and the drivers */
    misc_init();
    per_init();
    dev_init();

    /*Initialize the HAL for LittlevGL*/
    hal_init();

    /*Initialize LittlevGL*/
    lv_init();

    /*Create a Hello world Label*/
    static lv_style_t new_style;                                /*Create a new style*/
    lv_style_copy(&new_style, &lv_style_plain);                 /*Copy a built-in style as starting point*/
    new_style.text.color = COLOR_BLUE;                          /*Modify the text color*/
    new_style.text.letter_space = 20;                           /*Modify the letter space*/

    lv_obj_t * label1 =  lv_label_create(lv_scr_act(), NULL);   /*Create a Label on the current screen*/
    lv_label_set_text(label1, "Hello world!");                  /*Modify the Label's text*/
    lv_obj_set_style(label1, &new_style);                       /*Set the new style*/
    lv_obj_align(label1, NULL, LV_ALIGN_CENTER, 0, 0);       /*Align the Label to the center*/

    while(1) {
        /* Periodically call the ptask handler.
         * It could be done in a timer interrupt or an OS task too.*/
        ptask_handler();
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
    /* Sys. tick init.
     * You have to call 'lv_tick_handler()' in every milliseconds
     * Use the 'tick' module of the 'hw' repository*/
    tick_add_func(lv_tick_handler);

    /* Add a display
     * Use the 'TFT' module of the 'hw' repository which
     * uses a window on PC's monitor to simulate a display*/
    lv_disp_drv_t disp_drv;
    disp_drv.fill = tft_fill;
    disp_drv.map = tft_map;
    disp_drv.copy = NULL;
    lv_disp_register(&disp_drv);

    /* Add the mouse (or touchpad) as input device
     * Use the 'mouse' module of the 'hw' repository which reads the PC-s mouse*/
    lv_indev_drv_t indev_drv;
    indev_drv.name = "Mouse";
    indev_drv.type = LV_INDEV_TYPE_MOUSE;
    indev_drv.get_data = mouse_input_read;  /*This function will be called periodically (by the library) to get the mouse position and events*/
    lv_indev_register(&indev_drv);
}

/**
 * Interface function to read the mouse position and events
 * @param data store the mouse info here
 * @return 'false' because no buffering in operation (it would return 'true' if there would be more data be read)
 */
static bool mouse_input_read(lv_indev_data_t * data)
{
    /*Get the mouse data*/
    point_t p;
    bool state;
    state = mouse_get(&p.x, &p.y);

    /*Store the collected data*/
    data->point.x = p.x;
    data->point.y = p.y;
    data->state = state ? LV_INDEV_EVENT_PR : LV_INDEV_EVENT_REL;

    return false;
}

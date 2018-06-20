
/**
 * @file main
 *
 */

/*********************
 *      INCLUDES
 *********************/
/* INCLUDE THIS FILE FIRST! IT SETS UP DEFINES AND SYSTEM SETTINGS */
#include "lv_drv_conf.h"

#include <assert.h>
#include <features.h>
#include <stdio.h>
#include <stdlib.h>

#if defined _POSIX_SOURCE
#include <unistd.h>
#endif      /*_POSIX_SOURCE*/

#include <SDL2/SDL.h>

#include "lvgl/lvgl.h"
#include "lv_drivers/display/monitor.h"
#include "lv_drivers/indev/mouse.h"
#if USE_KEYBOARD
#include "lv_drivers/indev/keyboard.h"
#endif

#if BUILD_DEMO
#include "lv_examples/lv_apps/demo/demo.h"
#elif BUILD_TUTORIAL
#include "lv_examples/lv_tutorial/10_keyboard/lv_tutorial_keyboard.h"
#else
/* TODO: Provide other switches to control these demo builds
#include "lv_examples/lv_apps/benchmark/benchmark.h"
#include "lv_examples/lv_tests/lv_test_theme/lv_test_theme.h"
*/
#endif

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

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL VARIABLES
 **********************/
#if USE_KEYBOARD
lv_indev_t * g_kbd_dev = NULL;
#endif

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

int main(int argc, char** argv)
{
    /*Initialize LittlevGL*/
    lv_init();

    /*Initialize the HAL for LittlevGL*/
    hal_init();

#if BUILD_DEMO
    /*Load a demo*/
    demo_create(g_kbd_dev);
#elif BUILD_TUTORIAL
    /*Load keyboard tutorial code*/
    lv_tutorial_keyboard(g_kbd_dev);
#endif
    /*Or try the benchmark too to see the speed of your MCU*/
    //benchmark_create();

    /*Or try a theme (Enable the theme in lv_conf.h with USE_LV_THEME_...  1 )*/
    //lv_theme_t * th = lv_theme_night_init(210, NULL);      /*Hue: 210; Font: NULL (default)*/
    //lv_test_theme_1(th);

    while(1) {
        /* Periodically call the lv_task handler.
         * It could be done in a timer interrupt or an OS task too.*/
        lv_task_handler();
        usleep(1000);       /*Just to let the system breath*/
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
    lv_disp_drv_init(&disp_drv);            /*Basic initialization*/
    disp_drv.disp_flush = monitor_flush;
    disp_drv.disp_fill = monitor_fill;
    disp_drv.disp_map = monitor_map;
    lv_disp_drv_register(&disp_drv);

#if USE_KEYBOARD
    /* Use the 'keyboard' driver which reads the PC's keyboard*/
    keyboard_init();
    lv_indev_drv_t kbd_drv;
    lv_indev_drv_init(&kbd_drv);          /*Basic initialization*/
    kbd_drv.type = LV_INDEV_TYPE_KEYPAD;
    kbd_drv.read = keyboard_read;         /*This function will be called periodically (by the library) to read the keyboard*/
    g_kbd_dev = lv_indev_drv_register(&kbd_drv);
#endif

    /* Add the mouse (or touchpad) as input device
     * Use the 'mouse' driver which reads the PC's mouse*/
    mouse_init();
    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);          /*Basic initialization*/
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read = mouse_read;         /*This function will be called periodically (by the library) to get the mouse position and state*/
    lv_indev_drv_register(&indev_drv);

    /* Tick init.
     * You have to call 'lv_tick_handler()' in every milliseconds
     * Create an SDL thread to do this*/
    SDL_CreateThread(tick_thread, "tick", NULL);
}

/**
 * A task to measure the elapsed time for LittlevGL
 * @param data unused
 * @return never return
 */
static int tick_thread(void *data)
{
    while(1) {
        lv_tick_inc(1);
        SDL_Delay(1);   /*Sleep for 1 millisecond*/
    }

    return 0;
}

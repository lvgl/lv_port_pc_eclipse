
/**
 * @file main
 *
 */

/*********************
 *      INCLUDES
 *********************/
/* INCLUDE THE CONF FILES FIRST! THEY SET UP DEFINES AND SYSTEM SETTINGS! */
#include "lv_conf.h"
#include "lv_ex_conf.h"

#include <unistd.h>
#include "lvgl/lvgl.h"
#include "lvgl/lv_sys/lv_sys.h"
#include "lvgl/lv_hal/lv_hal_indev.h"
#include "lv_examples/lv_apps/demo/demo.h"
/*
If trying the benchmark, tutorials or tests - use one of these headers instead of demo.h!
#include "lv_examples/lv_apps/benchmark/benchmark.h"
#include "lv_examples/lv_tests/lv_test_theme/lv_test_theme.h"
#include "lv_examples/lv_tutorial/10_keyboard/lv_tutorial_keyboard.h"
*/

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
 *   GLOBAL VARIABLES
 **********************/
lv_indev_t   *  g_kbd_dev = NULL;       /*The keyboard handler*/
bool            g_app_quit_qry = false; /*set to notify app it needs to exit*/

/**********************
 * ADD YOUR HAL IMPL
 **********************/
/* You should select a display and indev implementation. This can be done:
 *  - in 'lv_drv_conf.h, for example, by selecting 'USE_FBDEV'.
 *  - via a env var during make (look at LVGL_USE_SDL2 in Makefile).
 *
 * This will provide a proper implementation of hal_init and hal_deinit
 * for your platform. Look at the two default hal_init_... files provided
 * below for an example.
 */
#if USE_FBDEV
#include "hal_init_fbdev.cc"
#elif USE_SDL2
#include "hal_init_SDL2.cc"
#else
#warning "NO HARDWARE IMPLEMENTATION SELECTED in lv_drv_conf! (e.g. USE_FBDEV)"
#endif

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

int main(int argc, char ** argv)
{
    /*Init OS-dependent settings, provide 'atexit' user cleanup func (ignored if NULL)*/
    lv_sys_init(hal_deinit);

    /*Initialize LittlevGL*/
    lv_init();

    /*Initialize the HAL for LittlevGL*/
    hal_init();

    /*Load a demo*/
    demo_create(g_kbd_dev);

    /*Or try the benchmark too to see the speed of your MCU*/
    //benchmark_create();

    /*Or try a theme (Enable the theme in lv_conf.h with USE_LV_THEME_...  1 )*/
    //lv_theme_t * th = lv_theme_night_init(210, NULL);      /*Hue: 210; Font: NULL (default)*/
    //lv_test_theme_1(th);

    /*Or try a tutorial (Enable USE_LV_TUTORIALS in lv_ex_conf.h)*/
    //lv_tutorial_keyboard(g_kbd_dev);

    while(!g_app_quit_qry) {
        /* Periodically call the lv_task handler.
         * It could be done in a timer interrupt or an OS task too.*/
        lv_task_handler();
        usleep(10000);      /*Just to let the system breathe*/
    }

    /*  hal_deinit(); --> Since hal_deinit was already registered to be called
                          at exit by the lv_sys_init function it should NOT be
                          called again here! */

    return 0;
}

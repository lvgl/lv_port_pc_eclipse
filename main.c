
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
#include <SDL2/SDL.h>
#include "lvgl/lvgl.h"
#if USE_MONITOR
#include "lv_drivers/display/monitor.h"
#endif
#if USE_MOUSE
#include "lv_drivers/indev/mouse.h"
#endif
#if USE_KEYBOARD || USE_LV_DEMO
#include "lv_drivers/indev/keyboard.h"
#endif
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
static void hal_init(void);
static void hal_deinit(void);
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
lv_indev_t * g_kbd_dev = NULL;  /*The keyboard handler*/
bool g_sdl_quit_qry = false;

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

int main(int argc, char** argv)
{
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

    while(!g_sdl_quit_qry) {
        /* Periodically call the lv_task handler.
         * It could be done in a timer interrupt or an OS task too.*/
        lv_task_handler();
        usleep(1000);       /*Just to let the system breath*/
    }

    hal_deinit();

    return 0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static int sdl_quit_filter(void * userdata, SDL_Event * event)
{
    (void)userdata;

    if(event->type == SDL_QUIT) {
        g_sdl_quit_qry = true;
    }

    return 1;
}

/**
 * Initialize the Hardware Abstraction Layer (HAL) for the Littlev graphics library.
 * In our case - since we use SDL2 code in monitor.c, keyboard.c and mouse.c - this
 * means initialize our SDL2-based simulation.
 * When writing an implementation for your board you should use hal_init to
 * initialize your hardware properly (set pins, registers, frequiencies, etc).
 */
static void hal_init(void)
{
    /*Initialize the SDL*/
    SDL_Init(SDL_INIT_VIDEO);

    SDL_SetEventFilter(sdl_quit_filter, NULL);

#if USE_MONITOR
    /* Add a display
     * Use the 'monitor' driver which creates window on PC's monitor to simulate a display*/
    monitor_init();
    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);            /*Basic initialization*/
    disp_drv.disp_flush = monitor_flush;
    disp_drv.disp_fill = monitor_fill;
    disp_drv.disp_map = monitor_map;
    lv_disp_drv_register(&disp_drv);
#endif

#if USE_KEYBOARD
    /* Use the 'keyboard' driver which reads the PC's keyboard*/
    keyboard_init();
    lv_indev_drv_t kbd_drv;
    lv_indev_drv_init(&kbd_drv);          /*Basic initialization*/
    kbd_drv.type = LV_INDEV_TYPE_KEYPAD;
    kbd_drv.read = keyboard_read;         /*This function will be called periodically (by the library) to read the keyboard*/
    g_kbd_dev = lv_indev_drv_register(&kbd_drv);
#endif

#if USE_MOUSE
    /* Add the mouse (or touchpad) as input device
     * Use the 'mouse' driver which reads the PC's mouse*/
    mouse_init();
    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);          /*Basic initialization*/
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read = mouse_read;         /*This function will be called periodically (by the library) to get the mouse position and state*/
    lv_indev_drv_register(&indev_drv);
#endif

    /* Tick init.
     * You have to call 'lv_tick_inc()' every millisecond.
     * Create an SDL thread to do this. This really belongs in one of
     * the impl files, e.g. in monitor.c but is left here to bring
     * the user's attention to the importance of calling lv_tick_inc!*/
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

/**
 * Deinitialize LvGL's HAL layer.
 * In our case - since we use SDL2 in 'monitor.c' to simulate some
 * imaginary hardware - this means deinit the SDL2 lib.
 * When writing an implementation for your board you should use hal_deinit
 * to properly deinit your hardware (if necessary). In reality, embedded systems
 * often run only one application and there may be no need for deinit.
 */
static void hal_deinit(void)
{
}

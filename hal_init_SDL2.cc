#include <SDL2/SDL.h>

#include "lv_drivers/display/monitor.h"

#if  USE_EVDEV
#include "lv_drivers/indev/evdev.h"
#endif

#if USE_MOUSE
#include "lv_drivers/indev/mouse.h"
#endif

#if USE_KEYBOARD
#include "lv_drivers/indev/keyboard.h"
#endif

extern bool         g_sdl_quit_qry;

/**********************
 *  STATIC PROTOTYPES
 **********************/

static int hal_tick_thread(void *data);

/**********************
 *  STATIC FUNCTIONS
 **********************/

static int sdl_quit_filter(void * userdata, SDL_Event * event)
{
    (void)userdata;

    if(event->type == SDL_QUIT) {
        /*Notify app that it needs to quit*/
        g_app_quit_qry = g_sdl_quit_qry = true;
    }

    return 1;
}

/**
 * Initialize the Hardware Abstraction Layer (HAL) for the Littlev graphics library
 */
static void hal_init(void)
{
    /*Initialize the SDL*/
    SDL_Init(SDL_INIT_VIDEO);

    SDL_SetEventFilter(sdl_quit_filter, NULL);

    /* Add the 'monitor' driver which creates window on PC's monitor to simulate a display*/
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

    /* Add the mouse or touchpad as input device */
#if USE_MOUSE
    /* Use the 'mouse' driver which reads the PC's mouse*/
    mouse_init();
    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);          /*Basic initialization*/
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read = mouse_read;         /*This function will be called periodically (by the library) to get the mouse position and state*/
    lv_indev_drv_register(&indev_drv);
#elif USE_EVDEV
    /* Use the 'evdev' driver which reads the PC's USB mouse/tpad*/
    evdev_init();
    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);          /*Basic initialization*/
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read = evdev_read;         /*This function will be called periodically (by the library) to get the mouse position and state*/
    lv_indev_drv_register(&indev_drv);
#endif

    /* Tick init.
     * You have to call 'lv_tick_handler()' in every milliseconds
     * Create an SDL thread to do this*/
    SDL_CreateThread(hal_tick_thread, "tick", NULL);
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
    monitor_deinit();    
}

/**
 * A task to measure the elapsed time for LittlevGL
 * @param data unused
 * @return never return
 */
static int hal_tick_thread(void *data)
{
    while(1) {
        lv_tick_inc(1);
        SDL_Delay(1);   /*Sleep for 1 millisecond*/
    }

    return 0;
}

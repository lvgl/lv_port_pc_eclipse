#include <pthread.h>

#if USE_MOUSE
#include "lv_drivers/indev/mouse.h"
#endif

#include "lv_drivers/display/fbdev.h"

typedef pthread_t           lv_thread_t;
typedef pthread_attr_t      lv_thread_attr_t;

static void * hal_tick_thread(void *data);

int lv_thread_create( lv_thread_t * new_thrd, void * (*start_routine) (void *), void *arg )
{
    pthread_attr_t  attr;
    int             err_code;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    err_code = pthread_create(new_thrd, &attr, start_routine, (void *)arg);
    pthread_attr_destroy(&attr);

    return err_code;
}


/**
 * A task to measure the elapsed time for LittlevGL
 * @param data unused
 * @return never return
 */
static void * hal_tick_thread(void *data)
{
    while(1) {
        lv_tick_inc(1);
        usleep(1000); /*Sleep for 1 millisecond*/
    }

    return 0;
}


/**
 * Initialize the Hardware Abstraction Layer (HAL) for the Littlev graphics library
 */
static void hal_init(void)
{
    /* Add a display
     * Use the 'monitor' driver which creates window on PC's monitor to simulate a display*/
    fbdev_init();
    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);            /*Basic initialization*/
    disp_drv.disp_flush = fbdev_flush;
    disp_drv.disp_fill = fbdev_fill;
    disp_drv.disp_map = fbdev_map;
    lv_disp_drv_register(&disp_drv);

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
     * Create a thread to do this*/
    lv_thread_t tick_thread;
    lv_thread_create(&tick_thread, hal_tick_thread, NULL);
}

/**
 * Deinitialize the Hardware Abstraction Layer (HAL). Need to provide
 * an impl for this func even if an empty such.
 */
static void hal_deinit(void)
{
}

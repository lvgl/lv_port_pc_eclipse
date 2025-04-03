/**
 * @file main
 *
 */

/*********************
 *      INCLUDES
 *********************/
#define _DEFAULT_SOURCE /* needed for usleep() */
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
#include "lvgl/lvgl.h"
#include "lvgl/examples/lv_examples.h"
#include "lvgl/demos/lv_demos.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static lv_display_t * hal_init(int32_t w, int32_t h);
static void timer_handler_resume_cb(void * data);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *      VARIABLES
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

int main(int argc, char **argv)
{
  /*Initialize LVGL*/
  lv_init();

  /*Initialize the display, and the input devices*/
  hal_init(480, 320);

  /*Open a demo or an example*/
  if (argc <= 1) {
    lv_demo_widgets();
    //  lv_example_chart_1();
  } else {
    if (!lv_demos_create(&argv[1], argc - 1)) {
      lv_demos_show_help();
      goto demo_end;
    }
  }

  static sem_t sem;
  if (sem_init(&sem, 0, 0) != 0) {
    LV_LOG_ERROR("Failed to initialize semaphore: %d", errno);
    goto demo_end;
  }

  lv_timer_handler_set_resume_cb(timer_handler_resume_cb, &sem);

  /*To hide the memory and performance indicators in the corners
   *disable `LV_USE_MEM_MONITOR` and `LV_USE_PERF_MONITOR` in `lv_conf.h`*/

  while(1) {
    /* Periodically call the lv_timer_handler. */
    const uint32_t time_until_next = lv_timer_handler();

    if (time_until_next == LV_NO_TIMER_READY) {
      /* No more timers ready, wait for the timer resume. */
      sem_wait(&sem);
      continue;
    }

    usleep(time_until_next * 1000);
  }

demo_end:
  lv_deinit();
  return 0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/**
 * Initialize the Hardware Abstraction Layer (HAL) for the LVGL graphics
 * library
 */
static lv_display_t * hal_init(int32_t w, int32_t h)
{
  lv_group_set_default(lv_group_create());

  lv_display_t * disp = lv_sdl_window_create(w, h);

  lv_indev_t * mouse = lv_sdl_mouse_create();
  lv_indev_set_group(mouse, lv_group_get_default());
  lv_indev_set_display(mouse, disp);
  lv_display_set_default(disp);

  LV_IMAGE_DECLARE(mouse_cursor_icon); /*Declare the image file.*/
  lv_obj_t * cursor_obj;
  cursor_obj = lv_image_create(lv_screen_active()); /*Create an image object for the cursor */
  lv_image_set_src(cursor_obj, &mouse_cursor_icon);           /*Set the image source*/
  lv_indev_set_cursor(mouse, cursor_obj);             /*Connect the image  object to the driver*/

  lv_indev_t * mousewheel = lv_sdl_mousewheel_create();
  lv_indev_set_display(mousewheel, disp);

  lv_indev_t * keyboard = lv_sdl_keyboard_create();
  lv_indev_set_display(keyboard, disp);
  lv_indev_set_group(keyboard, lv_group_get_default());

  return disp;
}

/**
 * Callback function to resume the timer handler when the timer is ready.
 */
static void timer_handler_resume_cb(void * data)
{
  sem_post((sem_t *)data);
}

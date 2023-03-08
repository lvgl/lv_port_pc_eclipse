
/**
 * @file main
 *
 */

/*********************
 *      INCLUDES
 *********************/
#define _DEFAULT_SOURCE /* needed for usleep() */
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
static lv_disp_t * hal_init(lv_coord_t w, lv_coord_t h);

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
  (void)argc; /*Unused*/
  (void)argv; /*Unused*/

  /*Initialize LVGL*/
  lv_init();

  /*Create a default group for keyboard navigation*/
  lv_group_set_default(lv_group_create());

  /*Initialize the HAL (display, input devices, tick) for LVGL*/
  hal_init(800, 480);

//  lv_example_switch_1();
//  lv_example_calendar_1();
//  lv_example_btnmatrix_2();
//  lv_example_checkbox_1();
//  lv_example_colorwheel_1();
//  lv_example_chart_6();
//  lv_example_table_2();
//  lv_example_scroll_2();
//  lv_example_textarea_1();
//  lv_example_msgbox_1();
//  lv_example_dropdown_2();
//  lv_example_btn_1();
//  lv_example_scroll_1();
//  lv_example_tabview_1();
//  lv_example_tabview_1();
//  lv_example_flex_3();
//  lv_example_label_1();

  lv_demo_widgets();

  while(1) {
      /* Periodically call the lv_task handler.
       * It could be done in a timer interrupt or an OS task too.*/
      lv_timer_handler();
      usleep(5 * 1000);
  }

  return 0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/


/**
 * Initialize the Hardware Abstraction Layer (HAL) forLVGL
 */
static lv_disp_t * hal_init(lv_coord_t w, lv_coord_t h)
{
  lv_disp_t * disp = lv_sdl_window_create(w, h);
  lv_indev_t * mouse = lv_sdl_mouse_create();
  lv_indev_set_group(mouse, lv_group_get_default());
  lv_indev_set_disp(mouse, disp);

  LV_IMG_DECLARE(mouse_cursor_icon); /*Declare the image file.*/
  lv_obj_t * cursor_obj;
  cursor_obj = lv_img_create(lv_scr_act());         /*Create an image object for the cursor */
  lv_img_set_src(cursor_obj, &mouse_cursor_icon);   /*Set the image source*/
  lv_indev_set_cursor(mouse, cursor_obj);           /*Connect the image  object to the driver*/

  lv_indev_t * mousewheel = lv_sdl_mousewheel_create();
  lv_indev_set_disp(mousewheel, disp);
  lv_indev_set_group(mousewheel, lv_group_get_default());

  lv_indev_t * keyboard = lv_sdl_keyboard_create();
  lv_indev_set_disp(keyboard, disp);
  lv_indev_set_group(keyboard, lv_group_get_default());

  return disp;
}

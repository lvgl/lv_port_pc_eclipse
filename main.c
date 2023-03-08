
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
#define SDL_MAIN_HANDLED /*To fix SDL's "undefined reference to WinMain" issue*/
#include <SDL2/SDL.h>
#include "lvgl/lvgl.h"
#include "lvgl/examples/lv_examples.h"
#include "lvgl/demos/lv_demos.h"
#include "lvgl/src/dev/sdl/lv_sdl_window.h"
#include "lvgl/src/dev/sdl/lv_sdl_mouse.h"
#include "lvgl/src/dev/sdl/lv_sdl_mousewheel.h"
#include "lvgl/src/dev/sdl/lv_sdl_keyboard.h"
#include "lvgl/src/dev/disp/fb/lv_linux_fbdev.h"
#include <pthread.h>

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
  /*Initialize the HAL (display, input devices, tick) for LVGL*/
  lv_group_t * g = lv_group_create();
  lv_group_set_default(g);

  hal_init(800, 480);

  lv_obj_set_flex_flow(lv_scr_act(), LV_FLEX_FLOW_ROW_WRAP);

  for(int i = 0; i < 100; i++) {
      lv_obj_t * panel = lv_obj_create(lv_scr_act());
      lv_obj_set_size(panel, 140, 40);
      lv_obj_set_style_bg_color(panel, lv_color_hex3(0xf00 + i%16), 0);
      lv_obj_set_style_border_color(panel, lv_color_hex3(0x0f0), 0);
      lv_obj_set_style_pad_all(panel, 8, 0);

      lv_obj_t * label = lv_label_create(panel);
      lv_label_set_text_fmt(label, "Panel %d\nOne more line", i);

      lv_obj_set_style_transform_angle(panel, 50 * i, 0);
  }


  while(1) {
      /* Periodically call the lv_task handler.
       * It could be done in a timer interrupt or an OS task too.*/
      lv_timer_handler();
      usleep(10 * 1000);
//      lv_obj_invalidate(lv_scr_act());
  }

  return 0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/


/**
 * Initialize the Hardware Abstraction Layer (HAL) for the LVGL graphics
 * library
 */
static lv_disp_t * hal_init(lv_coord_t w, lv_coord_t h)
{

  lv_disp_t * disp = lv_sdl_window_create(w, h);
  lv_draw_unit_sw_create(disp, 13);

  lv_indev_t * mouse = lv_sdl_mouse_create();
  lv_indev_set_group(mouse, lv_group_get_default());
  lv_indev_set_disp(mouse, disp);

//  LV_IMG_DECLARE(mouse_cursor_icon); /*Declare the image file.*/
//  lv_obj_t * cursor_obj;
//  cursor_obj = lv_img_create(lv_scr_act()); /*Create an image object for the cursor */
//  lv_img_set_src(cursor_obj, &mouse_cursor_icon);           /*Set the image source*/
//  lv_indev_set_cursor(mouse, cursor_obj);             /*Connect the image  object to the driver*/

  lv_indev_t * mousewheel = lv_sdl_mousewheel_create();
  lv_indev_set_disp(mousewheel, disp);
  lv_indev_set_group(mousewheel, lv_group_get_default());

  lv_indev_t * keyboard = lv_sdl_keyboard_create();
  lv_indev_set_disp(keyboard, disp);
  lv_indev_set_group(keyboard, lv_group_get_default());

  return disp;
}

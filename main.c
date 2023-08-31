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
  hal_init(800, 480);

//  lv_example_img_1();

  lv_demo_widgets();
//  lv_disp_get_scr_act(NULL);

//  hal_init(800, 480);
//  lv_demo_multilang();

//  lv_obj_t * main_cont = lv_obj_create(lv_scr_act());
//  lv_obj_center(main_cont);
//  lv_obj_set_size(main_cont, 740, 400);
//  lv_obj_set_flex_flow(main_cont, LV_FLEX_FLOW_ROW_WRAP);
////  lv_obj_set_scrollbar_mode(main_cont, LV_SCROLLBAR_MODE_OFF);
//  uint32_t i;
//  for(i = 0; i < 20; i++) {
//      lv_obj_t * cont = lv_obj_create(main_cont);
////      lv_obj_set_scrollbar_mode(cont, LV_SCROLLBAR_MODE_OFF);
//      lv_obj_set_size(cont, 130, 100);
//      lv_obj_set_style_pad_all(cont, 5, 0);
//      lv_obj_set_flex_flow(cont, LV_FLEX_FLOW_ROW_WRAP);
//
//      uint32_t j;
//      for(j = 0; j < 5; j++) {
//          lv_obj_t * btn = lv_btn_create(cont);
//          lv_obj_t * label = lv_label_create(btn);
//          lv_label_set_text(label, "A");
//      }
//  }


//  lv_refr_now(NULL);


//  extern uint32_t stat[];
//  extern uint32_t total;
//  total = 0;
//  lv_memzero(stat, 256 * 4);
//  lv_obj_invalidate(lv_scr_act());
//  lv_refr_now(NULL);
//  lv_refr_now(NULL);
//uint32_t i;
//for(i = 0; i < 1000; i++) {
//      lv_refr_now(NULL);
//      lv_obj_invalidate(lv_scr_act());
//}
//exit(0);

  while(1) {
      /* Periodically call the lv_task handler.
       * It could be done in a timer interrupt or an OS task too.*/
      lv_timer_handler();
//      lv_refr_now(NULL);
//      lv_obj_invalidate(lv_scr_act());
//      usleep(1 * 1000);
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
  lv_indev_t * mouse = lv_sdl_mouse_create();
  lv_indev_set_group(mouse, lv_group_get_default());
  lv_indev_set_disp(mouse, disp);
  lv_disp_set_default(disp);

  LV_IMG_DECLARE(mouse_cursor_icon); /*Declare the image file.*/
  lv_obj_t * cursor_obj;
  cursor_obj = lv_img_create(lv_scr_act()); /*Create an image object for the cursor */
  lv_img_set_src(cursor_obj, &mouse_cursor_icon);           /*Set the image source*/
  lv_indev_set_cursor(mouse, cursor_obj);             /*Connect the image  object to the driver*/

  lv_indev_t * mousewheel = lv_sdl_mousewheel_create();
  lv_indev_set_disp(mousewheel, disp);

  lv_indev_t * keyboard = lv_sdl_keyboard_create();
  lv_indev_set_disp(keyboard, disp);
  return disp;
}

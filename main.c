
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
#define SDL_MAIN_HANDLED /*To fix SDL's "undefined reference to WinMain" \
                            issue*/
#include <SDL2/SDL.h>
#include "lvgl/lvgl.h"
#include "lv_drivers/display/monitor.h"
#include "lv_drivers/gtkdrv/gtkdrv.h"
#include "lv_drivers/indev/mouse.h"
#include "lv_drivers/indev/keyboard.h"

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
static void memory_monitor(lv_timer_t *param);

/**********************
 *  STATIC VARIABLES
 **********************/
lv_indev_t *kb_indev;

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
  hal_init();

//  lv_example_table_2();
//  lv_example_calendar_1();
//  lv_example_btnmatrix_2();
//  lv_example_tabview_1();
//  lv_example_chart_3();
//  lv_example_colorwheel_1();
//  lv_example_meter_4();
//  lv_example_tabview_1();
//  lv_example_scroll_3();
//  lv_example_list_1();


//  lv_example_btn_1();
  lv_example_dropdown_3();

//  lv_demo_keypad_encoder();
//  lv_demo_widgets();


  while(1) {
      /* Periodically call the lv_task handler.
       * It could be done in a timer interrupt or an OS task too.*/
      lv_timer_handler();
      usleep(5 * 1000);
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
static void hal_init(void)
{

  /* Use the 'monitor' driver which creates window on PC's monitor to simulate a display*/
  monitor_init();

  /* Tick init.
   * You have to call 'lv_tick_inc()' in periodically to inform LittelvGL about
   * how much time were elapsed Create an SDL thread to do this*/
  SDL_CreateThread(tick_thread, "tick", NULL);


  /*Create a display buffer*/
  static lv_disp_buf_t disp_buf1;
  static lv_color_t buf1_1[MONITOR_HOR_RES * MONITOR_VER_RES];
  static lv_color_t buf1_2[MONITOR_HOR_RES * MONITOR_VER_RES];
  lv_disp_buf_init(&disp_buf1, buf1_1, buf1_2, MONITOR_HOR_RES * MONITOR_VER_RES / 2);

  /*Create a display*/
  lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv); /*Basic initialization*/
  disp_drv.buffer = &disp_buf1;
  disp_drv.flush_cb = monitor_flush;
  disp_drv.hor_res = MONITOR_HOR_RES;
  disp_drv.ver_res = MONITOR_VER_RES;
  disp_drv.antialiasing = 1;

  lv_disp_t * disp = lv_disp_drv_register(&disp_drv);

//  lv_theme_t * th = lv_theme_default_init(disp, LV_COLOR_PALETTE_LIGHT_BLUE, LV_COLOR_PALETTE_LIGHT_BLUE, &lv_font_montserrat_10, LV_FONT_DEFAULT, &lv_font_montserrat_18);
//  lv_disp_set_theme(disp, th);

  /* Add the mouse as input device
   * Use the 'mouse' driver which reads the PC's mouse*/
  mouse_init();
  lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv); /*Basic initialization*/
  indev_drv.type = LV_INDEV_TYPE_POINTER;

  /*This function will be called periodically (by the library) to get the mouse position and state*/
  indev_drv.read_cb = mouse_read;
  lv_indev_t *mouse_indev = lv_indev_drv_register(&indev_drv);

  keyboard_init();
  lv_indev_drv_init(&indev_drv); /*Basic initialization*/
  indev_drv.type = LV_INDEV_TYPE_KEYPAD;
  indev_drv.read_cb = keyboard_read;
  kb_indev = lv_indev_drv_register(&indev_drv);

  /*Set a cursor for the mouse*/
  LV_IMG_DECLARE(mouse_cursor_icon); /*Declare the image file.*/
  lv_obj_t * cursor_obj = lv_img_create(lv_scr_act(), NULL); /*Create an image object for the cursor */
  lv_img_set_src(cursor_obj, &mouse_cursor_icon);           /*Set the image source*/
  lv_indev_set_cursor(mouse_indev, cursor_obj);             /*Connect the image  object to the driver*/

  /* Optional:
   * Create a memory monitor task which prints the memory usage in
   * periodically.*/
  lv_timer_create(memory_monitor, 10000, NULL);
}

/**
 * A task to measure the elapsed time for LVGL
 * @param data unused
 * @return never return
 */
static int tick_thread(void *data) {
    (void)data;

    while(1) {
        SDL_Delay(5);   /*Sleep for 5 millisecond*/
        lv_tick_inc(5); /*Tell LittelvGL that 5 milliseconds were elapsed*/
    }

    return 0;
}

/**
 * Print the memory usage periodically
 * @param param
 */
static void memory_monitor(lv_timer_t *param) {
  (void)param; /*Unused*/
//  lv_event_queue_refresh_recursive(NULL);
  lv_mem_monitor_t mon;
  lv_mem_monitor(&mon);
  printf("used: %6d (%3d %%), frag: %3d %%, biggest free: %6d\n",
         (int)mon.total_size - mon.free_size, mon.used_pct, mon.frag_pct,
         (int)mon.free_biggest_size);
}

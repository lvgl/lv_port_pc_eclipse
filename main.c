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
#include "lv_drivers/indev/mouse.h"
#include "lv_examples/lv_examples.h"
#include "lv_components/lv_components.h"

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
static void memory_monitor(lv_task_t *param);

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

int main(int argc, char **argv)
{
  (void)argc; /*Unused*/
  (void)argv; /*Unused*/

  /*Initialize LVGL*/
  lv_init();

  /*Initialize the HAL (display, input devices, tick) for LVGL*/
  hal_init();

//  lv_obj_t * list = lv_list_create(lv_scr_act());
//  for(int i = 0; i < 20; i++) {
//      lv_list_add_btn_with_icon(list, LV_SYMBOL_OK, "hello list button");
//  }
//
//  /* Change the size.
//   * All percentage based and flex item should be updated
//   * With > 240 px height the screen will overflow so scroll chaining can be tested as well*/
//  lv_obj_set_size(list, 180, 300);


  /*Some other things to try*/
//  lv_tabview_create(lv_scr_act(), LV_DIR_TOP, 50);


//  lv_obj_t * calendar_cont = lv_obj_create(lv_scr_act(), NULL);
//  lv_obj_set_size(calendar_cont, 220, 220);
//  lv_obj_set_flex_cont(calendar_cont, LV_FLEX_DIR_COLUMN);
//
//  lv_obj_t * calendar_header = lv_calendar_header_arrow_create(calendar_cont, NULL, 25);
//  lv_obj_set_flex_item(calendar_header, LV_FLEX_CENTER);
//  lv_obj_set_width(calendar_header, LV_COORD_PCT(100));
//
//  lv_obj_t * calendar = lv_calendar_create(calendar_cont, NULL);
//  lv_obj_set_size(calendar, LV_COORD_PCT(100), LV_FLEX_GROW(1));
//  lv_obj_set_flex_item(calendar, LV_FLEX_CENTER);
//
//  lv_calendar_header_arrow_set_calendar(calendar_header, calendar);


//  lv_ex_dropdown_2();



//
//  lv_obj_t * tv = lv_tileview_create(lv_scr_act());
//  lv_obj_t * t;
//  lv_obj_t * l;
//  t = lv_tileview_add_tile(tv, 0, 0, LV_DIR_VER);
//  l = lv_label_create(t, NULL);
//  lv_label_set_text(l, "c0, r0");
//
//  t = lv_tileview_add_tile(tv, 1, 0, LV_DIR_HOR);
//  l = lv_label_create(t, NULL);
//  lv_label_set_text(l, "c1, r0");
//
//  t = lv_tileview_add_tile(tv, 2, 0, LV_DIR_ALL);
//  l = lv_label_create(t, NULL);
//  lv_label_set_text(l, "c2, r0");
//
//  t = lv_tileview_add_tile(tv, 0, 1, LV_DIR_ALL);
//  l = lv_label_create(t, NULL);
//  lv_label_set_text(l, "c0, r1");
//
//  t = lv_tileview_add_tile(tv, 2, 1, LV_DIR_ALL);
//  l = lv_label_create(t, NULL);
//  lv_label_set_text(l, "c2, r1");


//  const char * btns[] = {"Ok", "Cancel", ""};
//  lv_msgbox_create("Hello,", "Some text\nvery very long text it should be wrapped do you see it heeee?", btns, true);

//  lv_spinbox_create(lv_scr_act());

//  lv_ex_colorwheel_1();
  lv_ex_calendar_1();

  while (1) {
    /* Periodically call the lv_task handler.
     * It could be done in a timer interrupt or an OS task too.*/
    lv_task_handler();
    LV_ASSERT_MEM_INTEGRITY();
    usleep(5 * 1000);
  }

  return 0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/**
 * Initialize the Hardware Abstraction Layer (HAL) for the Littlev graphics
 * library
 */
static void hal_init(void) {
  /* Use the 'monitor' driver which creates window on PC's monitor to simulate a display*/
  monitor_init();

  /*Create a display buffer*/
  static lv_disp_buf_t disp_buf1;
  static lv_color_t buf1_1[LV_HOR_RES_MAX * 120];
  lv_disp_buf_init(&disp_buf1, buf1_1, NULL, LV_HOR_RES_MAX * 120);

  /*Create a display*/
  lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv); /*Basic initialization*/
  disp_drv.buffer = &disp_buf1;
  disp_drv.flush_cb = monitor_flush;
  lv_disp_drv_register(&disp_drv);

  /* Add the mouse as input device
   * Use the 'mouse' driver which reads the PC's mouse*/
  mouse_init();
  lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv); /*Basic initialization*/
  indev_drv.type = LV_INDEV_TYPE_POINTER;

  /*This function will be called periodically (by the library) to get the mouse position and state*/
  indev_drv.read_cb = mouse_read;
  lv_indev_t *mouse_indev = lv_indev_drv_register(&indev_drv);

  /*Set a cursor for the mouse*/
  LV_IMG_DECLARE(mouse_cursor_icon); /*Declare the image file.*/
  lv_obj_t * cursor_obj = lv_img_create(lv_scr_act(), NULL); /*Create an image object for the cursor */
  lv_img_set_src(cursor_obj, &mouse_cursor_icon);           /*Set the image source*/
  lv_indev_set_cursor(mouse_indev, cursor_obj);             /*Connect the image  object to the driver*/

  /* Tick init.
   * You have to call 'lv_tick_inc()' in periodically to inform LittelvGL about
   * how much time were elapsed Create an SDL thread to do this*/
  SDL_CreateThread(tick_thread, "tick", NULL);

  /* Optional:
   * Create a memory monitor task which prints the memory usage in
   * periodically.*/
  lv_task_create(memory_monitor, 5000, LV_TASK_PRIO_MID, NULL);
}

/**
 * A task to measure the elapsed time for LVGL
 * @param data unused
 * @return never return
 */
static int tick_thread(void *data) {
  (void)data;

  while (1) {
    SDL_Delay(5);   /*Sleep for 5 millisecond*/
    lv_tick_inc(5); /*Tell LittelvGL that 5 milliseconds were elapsed*/
  }

  return 0;
}

/**
 * Print the memory usage periodically
 * @param param
 */
static void memory_monitor(lv_task_t *param) {
  (void)param; /*Unused*/

  lv_mem_monitor_t mon;
  lv_mem_monitor(&mon);
  printf("used: %6d (%3d %%), frag: %3d %%, biggest free: %6d\n",
         (int)mon.total_size - mon.free_size, mon.used_pct, mon.frag_pct,
         (int)mon.free_biggest_size);
}

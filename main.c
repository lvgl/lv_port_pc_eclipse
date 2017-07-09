/*
 * main.c
 */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "hw/hw.h"
#include "misc/misc.h"
#include "misc/os/ptask.h"
#include "lvgl/lvgl.h"
#include "lvgl/lv_app/lv_app_util/lv_app_notice.h"


int main (void)
{
	/*Initialization*/
	per_init();
	misc_init();
	dev_init();
	lv_init();


#if LV_APP_ENABLE == 0 /*The applications are not enabled*/

	/*Create a Hello world Label*/
    static lv_style_t new_style;                                /*Create a new style*/
    lv_style_get(LV_STYLE_SCR, &new_style);                     /*Copy the screen style*/
    new_style.ccolor = COLOR_BLUE;                              /*Modify the Content Color (text color)*/
    new_style.letter_space = 20;                                /*Modify the letter space*/

    lv_obj_t * label1 =  lv_label_create(lv_scr_act(), NULL);   /*Create a Label on the current screen*/
    lv_label_set_text(label1, "Hello world!");                  /*Modify the Label's text*/
    lv_obj_set_style(label1, &new_style);                       /*Set the new style*/
    lv_obj_align_us(label1, NULL, LV_ALIGN_CENTER, 0, 0);       /*Align the Label to the center*/

#else /*The applications are enabled*/

	/*Run some applications*/
	lv_app_inst_t * app;

	app = lv_app_run(lv_app_dsc_get("Benchmark"), NULL);
	lv_app_sc_open(app); /*Open the shortcut*/

    app = lv_app_run(lv_app_dsc_get("Sys. monitor"), NULL);
    lv_app_sc_open(app); /*Open the shortcut*/

    app = lv_app_run(lv_app_dsc_get("Terminal"), NULL);
    lv_app_sc_open(app); /*Open the shortcut*/

    lv_app_notice_add("Click on a shortcut to open\n"
                      "the application in a window");
#endif

	while(1) {
		ptask_handler();
		usleep(1000);
	}

	return 0;
}

/*
 * main.c
 *
 *  Created on: 2016. jan. 24.
 *      Author: kisvegabor
 */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "hw/hw.h"
#include "misc/misc.h"
#include "misc/os/ptask.h"
#include "lvgl/lvgl.h"
#include "lvgl/lv_misc/anim.h"
#include "lvgl/lv_app/lv_app_util/lv_app_notice.h"

int main (void)
{
	/*Initialization*/
	per_init();
	misc_init();
	dev_init();
	lv_init();

#if LV_APP_ENABLE == 0 /*The applications are not enabled*/

	/*Create a label style*/
	static lv_labels_t label_style;
	lv_labels_get(LV_LABELS_DEF, &label_style); /*Initialize from the default labels style*/
	label_style.objs.color = COLOR_RED;
	label_style.font = FONT_DEJAVU_80;
	label_style.letter_space = 10 * LV_DOWNSCALE;

	/*Create a label*/
	lv_obj_t * label;
	label = lv_label_create(lv_scr_act(), NULL);
	lv_label_set_text(label, "Hello world!");
    lv_obj_set_style(label, &label_style);
	lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);

#else /*The applications are enabled*/

	/*Run some applications*/
	lv_app_inst_t * app;

	app = lv_app_run(lv_app_dsc_get("Example"), NULL);
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

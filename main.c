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


int main (void)
{
	/*Initialization*/
	per_init();
	misc_init();
	dev_init();
	lv_init();

	/*Create a title*/
	lv_obj_t * title = lv_label_create(lv_scr_act(), NULL);
	lv_label_set_text(title, "LittleV graphical library");
	lv_obj_align_us(title, NULL, LV_ALIGN_CENTER, 0, 0);

	/*Create a button*/
	lv_obj_t * btn1 = lv_btn_create(lv_scr_act(), NULL);
	lv_obj_set_size_us(btn1, 120, 60); /*Set the size*/
	lv_obj_set_pos_us(btn1, 10, 10);   /*Set the pos*/
	lv_obj_set_drag(btn1, true);       /*Enable dragging*/
	lv_btn_set_tgl(btn1, true);        /*Enable  toggling*/

	/*Create a label on the button*/
	lv_obj_t * btnl = lv_label_create(btn1, NULL);
	lv_obj_set_style(btnl, lv_labels_get(LV_LABELS_BTN, NULL));
	lv_label_set_text(btnl, "Button1");
	lv_obj_align_us(btnl, NULL, LV_ALIGN_CENTER, 0, 0);

	ptask_en(true);

	while(1) {
		usleep(1000);
		ptask_handler();
	}

	return 0;
}

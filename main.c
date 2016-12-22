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


int main (void)
{
	/*Initialization*/
	per_init();
	misc_init();
	dev_init();
	lv_init();

#if LV_APP_ENABLE == 0 /*The applications are not enabled*/

	lv_obj_t * label = lv_label_create(lv_scr_act(), NULL);
	lv_obj_set_style(label, lv_labels_get(LV_LABELS_BTN, NULL));
	lv_label_set_text(label, "Hello world!");
	lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);

#else /*The applications are enabled*/

	/*Run the "Example" application*/
	lv_app_inst_t * app_sender = lv_app_run(lv_app_dsc_get("Example"),"Sender");
	lv_app_sc_open(app_sender); /*Open the shortcut*/

    /*Run the "Example" application again*/
    lv_app_inst_t * app_receiver = lv_app_run(lv_app_dsc_get("Example"),"Receiver");
    lv_app_sc_open(app_receiver); /*Open the shortcut*/

    /*Make a connection between the applications */
    lv_app_con_set(app_sender, app_receiver);

    /* What to do?
     * 1. Run the project.
     * 2. Click on the "Sender" application
     * 3. In the opened window click on the text area
     * 4. Write something and Click the "Ok" button
     * 5. Click the "Down" arrow on the right top corner
     * 6. Check the "Receiver" application got the text */

    /*What else?
     * - Click on the "Apps" button.
     * - Open new instances of this application
     * - Press longly a shortcut on the desktop (it will turn redish)
     * - Click on other shortcuts to connect them to the long pressed
     * - Click on the background
     * - Test tit by sending text
     */

    /*Try to write new applications based on "Example"*/

#endif

	while(1) {
		ptask_handler();
		usleep(1000);
	}

	return 0;
}

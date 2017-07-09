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

#if LV_APP_ENABLE != 0
/*Called when the phantom app. receives data*/
static void phantom_listen (lv_app_inst_t * app_send, lv_app_inst_t * app_rec,
                            lv_app_com_type_t type , const void * data, uint32_t size)
{
    const char * data_char = data;

    uint32_t i;
    for(i = 0; i < size; i++) {
        printf("%c", data_char[i]);
    }
    printf("\n");
}

#endif

int main (void)
{
	/*Initialization*/
    misc_init();
	per_init();
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

	/*Run a terminal and open its shortcut*/
    lv_app_inst_t * app_term = lv_app_run(lv_app_dsc_get("Terminal"), NULL);
    lv_app_sc_open(app_term);

	app = lv_app_run(lv_app_dsc_get("Benchmark"), NULL);
	lv_app_sc_open(app); /*Open the shortcut*/

    /* Make the terminal to listen the phantom and send data with the phantom
     * The data will appear in the terminal*/
    lv_app_con_set(app_phantom, app_term);
    lv_app_com_send(app_phantom, LV_APP_COM_TYPE_CHAR, "Hello", 5);

    /* Make the phantom to listen the terminal and send data with the terminal
     * The data will be printf-ed by the phantom_listen() function*/
    lv_app_con_set(app_term, app_phantom);
    lv_app_com_send(app_term, LV_APP_COM_TYPE_CHAR, "Hello from the terminal", 23);

#endif

	while(1) {
	    /* Periodically call the ptask handler.
	     * It could be done in a timer interrupt or an OS task too.*/
		ptask_handler();
        usleep(5000);

	}

	return 0;
}




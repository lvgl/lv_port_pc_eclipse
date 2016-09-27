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

static const char * btn_str = "123+456-789*0C=/";
static lv_obj_t * ans_label;
static lv_labels_t ans_labels;
static bool calc_btn_rel_action(lv_obj_t * obj_dp, lv_dispi_t * dispi_p);

int main (void)
{
	/*Initialization*/
	per_init();
	misc_init();
	dev_init();
	lv_init();

	calc_create();

	ptask_en(true);

	while(1) {
		ptask_handler();
		usleep(1000);
	}

	return 0;
}

/**
 * Create a calculator
 */
static void calc_create(void)
{
	/*Create a holder object for the calculator*/
	lv_obj_t * calch = lv_rect_create(lv_scr_act(), NULL);
	lv_rect_set_fit(calch, true, true);		/*Enable auto fit (its size will fit to the objects on it)*/
	lv_rect_set_layout(calch, LV_RECT_LAYOUT_COL_R); /*Everything to the right*/

	/*Create a style for the label which shows the written numbers*/
	lv_labels_get(LV_LABELS_TITLE, &ans_labels); /* Copy the title style */
	ans_labels.font = FONT_DEJAVU_60;

	/*Create a label to show the written numbers*/
	ans_label = lv_label_create(calch, NULL);
	lv_obj_set_style(ans_label, &ans_labels);

	/*Create a holder for the number and operation buttons */
	lv_obj_t * btnh = lv_rect_create(calch, NULL);
	lv_obj_set_size_us(btnh, 280, 250);
	lv_obj_set_style(btnh, lv_rects_get(LV_RECTS_TRANSP, NULL));
	lv_rect_set_layout(btnh, LV_RECT_LAYOUT_GRID); /*Order the children to grid*/

	/*Create a button and a label for the numbers and operations*/
	uint8_t i;
	for(i = 0; btn_str[i] != '\0'; i++ ){
		/*Create a button*/
		lv_obj_t * btn = lv_btn_create(btnh, NULL);
		lv_obj_set_size_us(btn, 50, 50);
		lv_obj_set_free_num(btn,  btn_str[i]);
		lv_btn_set_rel_action(btn, calc_btn_rel_action);

		/*Add a label to the button*/
		lv_obj_t * label = lv_label_create(btn, NULL);
		lv_obj_set_style(label, lv_labels_get(LV_LABELS_BTN, NULL));
		char txt[2];
		txt[0] = btn_str[i];
		txt[1] = '\0';
		lv_label_set_text(label, txt);
	}

	/*Align the main calculator holder to the center*/
	lv_obj_align(calch, NULL, LV_ALIGN_CENTER, 0, 0);
}

/**
 * Called when button of the calculator is released
 * @param obj_dp pointer to the released object
 * @param dispi_p pointer to the caller display input
 * @return always true (because obj_dp will not be deleted)
 */
static bool calc_btn_rel_action(lv_obj_t * obj_dp, lv_dispi_t * dispi_p)
{
	static int32_t act = 0; /*Number is written now*/
	static int32_t ans = 0; /*The previous answer*/
	static char op = '\0';	/*Initially no operation*/
	static bool last_op = false; /*The previous button was on operation? */

	/*Get the id of the button (e.g. '7' or '+')*/
	char id = lv_obj_get_free_num(obj_dp);

	/*Do the corresponding action*/
	switch(id) {
		/*A number is released, so write it to 'ans_label'*/
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			/* If the previous button was an operation (e.g. '+')
			 * then begin a new number*/
			if(last_op != false) {
				last_op = false;
				act = 0;
			}

			/*Write the released number to the ones digit*/
			act *= 10;
			act += id - 0x30;
			break;
		/*Clear lastly written number (only one digit)*/
		case 'C':
			if(last_op != false) {
				last_op = false;
				act = 0;
			}
			act /= 10;
			break;

		/*Make the corresponding operation*/
		case '+':
		case '-':
		case '*':
		case '/':
		case '=':
			/*Do no make an operation twice but repeat it on '=' sign*/
			if(last_op == false || id == '=') {
				if(op == '\0') ans = act;	/*If there is no operation yet just copy the number */
				if(op == '+') ans = ans + act;
				if(op == '-') ans = ans - act;
				if(op == '*') ans = ans * act;
				if(op == '/') ans = ans / act;
				last_op = true;
			}
			/*Save the operation*/
			if(id != '=') op = id;
			break;

	}

	/* If an operation button released then show the answer
	 * else show the number being written*/
	char buf[32];
	if(last_op == false) sprintf(buf, "%d", act);
	else sprintf(buf, "%d", ans);
	lv_label_set_text(ans_label, buf);

	/*The object is still valid (not deleted), so return 'true'*/
	return true;
}


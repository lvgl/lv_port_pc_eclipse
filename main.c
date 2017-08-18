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
#include "fsnav/fsnav.h"

static lv_action_res_t rel_action(lv_obj_t * btn, lv_dispi_t * dispi);


int main (void)
{
    /*Initialization*/
    misc_init();
    per_init();
    dev_init();
    lv_init();

    fsnav_init();

   // fsnav_shuffle_set(true);

//    lv_obj_t * page = lv_page_create(NULL, NULL);
//    lv_cont_set_layout(lv_page_get_scrl(page), LV_CONT_LAYOUT_PRETTY);
//
//    lv_scr_load(page);
//
//    lv_obj_t * btn = lv_btn_create(page, NULL);
//    lv_obj_set_free_num(btn, 'r');
//    lv_obj_clr_protect(btn, LV_PROTECT_FOLLOW);
//    lv_btn_set_rel_action(btn, rel_action);
//    lv_obj_t * l = lv_label_create(btn, NULL);
//    lv_label_set_text(l, "Artist <");
//
//    btn = lv_btn_create(page, btn);
//    lv_obj_set_free_num(btn, 'R');
//    lv_obj_set_protect(btn, LV_PROTECT_FOLLOW);
//    l = lv_label_create(btn, l);
//    lv_label_set_text(l, "Artist >");
//
//
//    btn = lv_btn_create(page, btn);
//    lv_obj_set_free_num(btn, 'l');
//    lv_obj_clr_protect(btn, LV_PROTECT_FOLLOW);
//    l = lv_label_create(btn, l);
//    lv_label_set_text(l, "Album <");
//
//    btn = lv_btn_create(page, btn);
//    lv_obj_set_free_num(btn, 'L');
//    lv_obj_set_protect(btn, LV_PROTECT_FOLLOW);
//    l = lv_label_create(btn, l);
//    lv_label_set_text(l, "Album >");
//
//
//    btn = lv_btn_create(page, btn);
//    lv_obj_set_free_num(btn, 't');
//    lv_obj_clr_protect(btn, LV_PROTECT_FOLLOW);
//    l = lv_label_create(btn, l);
//    lv_label_set_text(l, "Track <");
//
//    btn = lv_btn_create(page, btn);
//    lv_obj_set_free_num(btn, 'T');
//    lv_obj_set_protect(btn, LV_PROTECT_FOLLOW);
//    l = lv_label_create(btn, l);
//    lv_label_set_text(l, "Track >");


    static lv_style_t s;
    lv_style_get(LV_STYLE_PRETTY, &s);
    //s.radius = LV_RADIUS_CIRCLE;
    s.vpad = 0;
    s.hpad = 0;

    static lv_style_t sk;
    lv_style_get(LV_STYLE_PRETTY, &sk);
   // sk.opa = OPA_COVER;
  //  sk.radius = LV_RADIUS_CIRCLE;

    static lv_style_t si;
    lv_style_get(LV_STYLE_PRETTY_COLOR, &si);
   // si.radius = LV_RADIUS_CIRCLE;
   // si.vpad = 18;
   // si.hpad = 18;

//    lv_obj_t * sw = lv_sw_create(lv_scr_act(), NULL);
//    lv_obj_set_pos(sw, 50, 50);
//    lv_obj_set_style(sw, &s);
//    lv_bar_set_style_indic(sw, &si);
//    lv_slider_set_style_knob(sw, &sk);
//    lv_slider_set_action(sw, rel_action);

    while(1) {
        /* Periodically call the ptask handler.
         * It could be done in a timer interrupt or an OS task too.*/
        ptask_handler();
        usleep(5000);

    }

    return 0;
}

static lv_action_res_t rel_action(lv_obj_t * sw, lv_dispi_t * dispi)
{
    int16_t v = lv_bar_get_value(sw);

    printf("Switch: %d\n", v);

    return LV_ACTION_RES_OK;
}

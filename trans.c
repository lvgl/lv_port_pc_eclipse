///**
// * @file trans.c
// *
// */
//
//#include "lvgl/lvgl.h"
//
///***********************
// *      en_GB
// ***********************/
//
//static const lv_i18n_trans_t en_gb_simple[] = {
//        {"scr1_title", "Title of screen 1"},
//        {"scr1_dsc",   "This is a text on the first screen..."},
//        {NULL, NULL},       /*Mark that there is no more translations*/
//};
//
//static const lv_i18n_trans_t en_gb_zero[] = {
//        {"dog", "I have no dogs yet."},
//        {"cat", "My friend has no cats yet."},
//        {NULL, NULL},       /*Mark that there is no more translations*/
//};
//
//static const lv_i18n_trans_t en_gb_one[] = {
//        {"dog", "I have only one dog."},
//        {"cat", "My friend has only one cat."},
//        {NULL, NULL},       /*Mark that there is no more translations*/
//};
//
//static const lv_i18n_trans_t en_gb_many[] = {
//        {"dog", "I already have %d dogs."},
//        {"cat", "My friend already has %d cats."},
//        {NULL, NULL},       /*Mark that there is no more translations*/
//};
//
//static uint8_t en_gb_plural_rule(int32_t num)
//{
//    if(num == 0) return LV_I18N_PLURAL_TYPE_ZERO;
//    else if(num == 1) return LV_I18N_PLURAL_TYPE_ONE;
//    else return LV_I18N_PLURAL_TYPE_MANY;
//}
//
//static const lv_i18n_lang_t en_gb_lang = {
//    .name = "en_GB",
//    .simple = en_gb_simple,
//    .plurals[LV_I18N_PLURAL_TYPE_ZERO] = en_gb_zero,
//    .plurals[LV_I18N_PLURAL_TYPE_ONE] = en_gb_one,
//    .plurals[LV_I18N_PLURAL_TYPE_MANY] = en_gb_many,
//    .plural_rule = en_gb_plural_rule,
//};
//
//
///***********************
// * LANGUAGE COLLECTION
// ***********************/
//
//const lv_i18n_lang_pack_t languages[] = {
//        &en_gb_lang,    /*The first language will be the default*/
//        NULL,           /*Mark that there is no more languages*/
//};
//
//

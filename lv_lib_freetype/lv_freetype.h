/**
 * @file lv_freetype.h
 *
 */

#ifndef LV_FREETYPE_H
#define LV_FREETYPE_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include <stdint.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include "lvgl/lvgl.h"



/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    FT_Face     face;      /* handle to face object */

}lv_font_fmt_freetype_dsc_t;



/**********************
 * GLOBAL PROTOTYPES
 **********************/
int lv_freetype_init(void);
int lv_freetype_font_init(lv_font_t * font, const char * font_path, uint16_t size);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_FREETYPE_H*/

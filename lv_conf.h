/**
 * @file lv_conf.h
 * 
 */

#ifndef LV_CONF_H
#define LV_CONF_H

/*=====================
   Graphical settings
 *=====================*/

/* Horizontal and vertical resolution of the library.
 * Screen resolution multiplied by LV_DOWN_SCALE*/
#define LV_HOR_RES          (480 * LV_DOWNSCALE)
#define LV_VER_RES          (320 * LV_DOWNSCALE)

/* Buffered rendering: >= LV_DOWNSCALE * LV_HOR_RES or 0 to disable buffering*/

#define LV_VDB_SIZE         (LV_HOR_RES * (LV_VER_RES / 20))

/* Anti-aliasing with downscaling everything
 * 1: disabled
 * 2: 2x anti-alias -> half size
 * 4: 4x anti-alias -> quarter size */
#define LV_DOWNSCALE		2

#define LV_UPSCALE_FONT	 0 /*Scale up fonts to compensate LV_DOWNSCALE*/
#define LV_UPSCALE_MAP	 0 /*Scale up maps (e.g. images) elements to compensate LV_DOWNSCALE*/
#define LV_UPSCALE_SYTLE 1 /*Scale up default styles to compensate LV_DOWNSCALE*/

#define LV_REFR_PERIOD      40 	  /*Screen refresh period in milliseconds*/
#define LV_INV_FIFO_SIZE    32    /*The average number of objects on a screen */

/*=================
   Misc. setting
 *=================*/
/*Display Input settings*/
#define LV_DISPI_READ_PERIOD   	50 /*Input device read period milliseconds*/
#define LV_DISPI_TP_MARKER		0  /*Mark the pressed points*/
#define LV_DISPI_DRAG_LIMIT       10    /*Drag threshold in pixels */
#define LV_DISPI_DRAG_THROW       20    /*Drag throw slow-down in [%]. Greater value means faster slow-down */
#define LV_DISPI_LONG_PRESS_TIME  400   /*Long press time in milliseconds*/
#define LV_DISPI_LONG_PRESS_REP_TIME 100 /*Repeated trigger period in long press [ms] */

/*Coordinates*/
#define LV_CORD_TYPE    int16_t	/*Coordinate type*/
#define LV_CORD_MAX     (32000)
#define LV_CORD_MIN     (-32000)

/*Fonts and texts*/
#define USE_FONT_DEJAVU_8    1
#define USE_FONT_DEJAVU_10   1
#define USE_FONT_DEJAVU_14   1
#define USE_FONT_DEJAVU_20   1
#define USE_FONT_DEJAVU_30   1
#define USE_FONT_DEJAVU_40   1
#define USE_FONT_DEJAVU_60   1
#define USE_FONT_DEJAVU_80   1
#define LV_FONT_DEFAULT  FONT_DEJAVU_30  /*Always set a default font*/
#define LV_TXT_BREAK_CHARS	" ,.;-" /*Can break texts on these chars*/

/*lv_obj (base object) settings*/
#define LV_OBJ_FREE_P        	 1 			 /*Enable the free pointer attribute*/
#define LV_OBJ_DEF_SCR_COLOR     COLOR_SILVER /*Default screen color*/

/*==================
 *  LV OBJ X USAGE 
 * ================*/

#define USE_LV_RECT     1

#define USE_LV_LABEL    1
#if USE_LV_LABEL != 0
#define LV_LABEL_SCROLL_SPEED 		(25 * LV_DOWNSCALE) /*Hor, or ver. scroll speed (px/sec) in 'LV_LABEL_LONG_SCROLL' mode*/
#define LV_LABEL_SCROLL_SPEED_VER   (10 * LV_DOWNSCALE) /*Ver. scroll speed if hor. scroll is applied too*/
#define LV_LABEL_SCROLL_PLAYBACK_PAUSE	500 /*Wait before the scroll turns back in ms*/
#define LV_LABEL_SCROLL_REPEAT_PAUSE	500 /*Wait before the scroll begins again in ms*/
#endif

#define USE_LV_BTN      1

#define USE_LV_LINE     1

#define USE_LV_IMG      1
#if USE_LV_IMG != 0
#define LV_IMG_COLOR_TRANSP     COLOR_LIME
#define LV_IMG_DEF_WALLPAPER	img_square_x2
#endif /*USE_LV_IMG*/

#define USE_LV_PAGE     1
#if USE_LV_PAGE != 0
#define LV_PAGE_ANIM_FOCUS_TIME 300 /*List focus animation time [ms] (0: turn off the animation)*/
#endif

#define USE_LV_LIST     1

#define USE_LV_CB 		1

#define USE_LV_PB		1

#define USE_LV_CHARTBG	1

#define USE_LV_CHART	1

#define USE_LV_TA      1
#if USE_LV_TA != 0
#define LV_TA_MAX_LENGTH	512
#define LV_TA_DEF_WIDTH		120
#define LV_TA_DEF_HEIGHT	80
#define LV_TA_CUR_BLINK_TIME 400	/*ms*/
#endif

#define USE_LV_BTNM     1

#define USE_LV_WIN      1

#define USE_LV_MBOX		1

/*==================
 *  LV APP SETTINGS 
 * =================*/
#define LV_APP_ENABLE       1
#define LV_APP_SC_WIDTH		(LV_HOR_RES / 4)
#define LV_APP_SC_HEIGHT	(LV_VER_RES / 3)
#define LV_APP_FONT_SMALL   FONT_DEJAVU_20
#define LV_APP_FONT_MEDIUM  FONT_DEJAVU_30
#define LV_APP_FONT_LARGE   FONT_DEJAVU_40

#define LV_APP_USE_INTERNAL_ICONS 	2 /*if 0: img_close, img_add etc icons have to be available"*/

#define LV_APP_EFFECT_OPA      1 /*Enable the opacity in the application style (can be modified)*/
#define LV_APP_EFFECT_ANIM     1 /*Enable the animation of the applications*/
#define LV_APP_EFFECT_OPA_ANIM 1 /*Enable the using opacity in the application animations*/
#define LV_APP_ANIM_WIN 200	/*Animation time in milliseconds (0: turn off animation)*/
#define LV_APP_ANIM_SC 	200 /*Animation time in milliseconds (0: turn off animation)*/

/*==================
 *  LV APP X USAGE 
 * ================*/
#define USE_LV_APP_EXAMPLE 1

#endif

/**
 * @file lv_freetype.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "lv_freetype.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static const uint8_t * lv_font_get_bitmap_fmt_freetype(const lv_font_t * font, uint32_t unicode_letter);
static bool lv_font_get_glyph_dsc_fmt_freetype(const lv_font_t * font, lv_font_glyph_dsc_t * dsc_out, uint32_t unicode_letter, uint32_t unicode_letter_next);

/**********************
 *  STATIC VARIABLES
 **********************/
static FT_Library  library;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

int lv_freetype_init(void)
{

    int error;

    error = FT_Init_FreeType( &library );
    if ( error )
    {
        printf("Error in FT_Init_FreeType: %d\n", error);
        return error;
    }

    return FT_Err_Ok;
}

int lv_freetype_font_init(lv_font_t * font, const char * font_path, uint16_t size)
{
    lv_font_fmt_freetype_dsc_t * dsc = lv_mem_alloc(sizeof(lv_font_fmt_freetype_dsc_t));
    LV_ASSERT_MEM(dsc);
    if(dsc == NULL) return FT_Err_Out_Of_Memory;

    int error;

    error = FT_New_Face( library,
            font_path,    /* first byte in memory */
            0,         /* face_index           */
            &dsc->face );
    if ( error ) {
        printf("Error in FT_New_Face: %d\n", error);
        return error;
    }

    error = FT_Set_Char_Size(
            dsc->face,    /* handle to face object           */
            0,       /* char_width in 1/64th of points  */
            size*64,   /* char_height in 1/64th of points */
            300,     /* horizontal device resolution    */
            300 );   /* vertical device resolution      */

    if ( error ) {
        printf("Error in FT_Set_Char_Size: %d\n", error);
        return error;
    }

    error = FT_Set_Pixel_Sizes(
            dsc->face,   /* handle to face object */
            0,      /* pixel_width           */
            size );   /* pixel_height          */

    if ( error ) {
        printf("Error in FT_Set_Char_Size: %d\n", error);
        return error;
    }

    font->get_glyph_dsc = lv_font_get_glyph_dsc_fmt_freetype;    /*Function pointer to get glyph's data*/
    font->get_glyph_bitmap = lv_font_get_bitmap_fmt_freetype;    /*Function pointer to get glyph's bitmap*/
    font->line_height = dsc->face->size->metrics.height/64;          /*The maximum line height required by the font*/
    font->base_line = -dsc->face->size->metrics.descender / 64;             /*Baseline measured from the bottom of the line*/
    font->dsc = dsc;           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
    font->subpx = 0;

    return FT_Err_Ok;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/


/**
 * Used as `get_glyph_bitmap` callback in LittelvGL's native font format if the font is uncompressed.
 * @param font pointer to font
 * @param unicode_letter an unicode letter which bitmap should be get
 * @return pointer to the bitmap or NULL if not found
 */
static const uint8_t * lv_font_get_bitmap_fmt_freetype(const lv_font_t * font, uint32_t unicode_letter)
{
    lv_font_fmt_freetype_dsc_t * fdsc = (lv_font_fmt_freetype_dsc_t *) font->dsc;

    int error;

    FT_UInt glyph_index = FT_Get_Char_Index(fdsc->face, unicode_letter );

    error = FT_Load_Glyph(
            fdsc->face,          /* handle to face object */
            glyph_index,   /* glyph index           */
            FT_LOAD_DEFAULT );  /* load flags, see below */

    if ( error ) {
        printf("Error in FT_Load_Glyph: %d\n", error);
        return NULL;
    }

    error = FT_Render_Glyph(fdsc->face->glyph,   /* glyph slot  */
            FT_RENDER_MODE_NORMAL ); /* render mode */

    if ( error ) {
        printf("Error in FT_Render_Glyph: %d\n", error);
        return NULL;
    }

    /*If not returned earlier then the letter is not found in this font*/
    return fdsc->face->glyph->bitmap.buffer;
}

/**
 * Used as `get_glyph_dsc` callback in LittelvGL's native font format if the font is uncompressed.
 * @param font_p pointer to font
 * @param dsc_out store the result descriptor here
 * @param letter an UNICODE letter code
 * @return true: descriptor is successfully loaded into `dsc_out`.
 *         false: the letter was not found, no data is loaded to `dsc_out`
 */
static bool lv_font_get_glyph_dsc_fmt_freetype(const lv_font_t * font, lv_font_glyph_dsc_t * dsc_out, uint32_t unicode_letter, uint32_t unicode_letter_next)
{

    if(unicode_letter < 0x20) return false;

    lv_font_fmt_freetype_dsc_t * fdsc = (lv_font_fmt_freetype_dsc_t *) font->dsc;

    int error = 0;
//    error = render_glyph(unicode_letter, fdsc);

    FT_UInt glyph_index = FT_Get_Char_Index(fdsc->face, unicode_letter );

    error = FT_Load_Glyph(
            fdsc->face,          /* handle to face object */
            glyph_index,   /* glyph index           */
            FT_LOAD_DEFAULT );  /* load flags, see below */
    if ( error )
    {
        printf("Error in FT_Load_Glyph: %d\n", error);
        return error;
    }


    if(error) return false;

    FT_Vector akern;
    error = FT_Get_Kerning(fdsc->face, unicode_letter, unicode_letter_next,
            FT_KERNING_DEFAULT, &akern);

    if(error) return false;

    int32_t adv_w = (fdsc->face->glyph->advance.x + akern.x + 32) / 64;


    dsc_out->adv_w = adv_w;
    dsc_out->box_w = fdsc->face->glyph->metrics.width / 64;
    dsc_out->box_h = fdsc->face->glyph->metrics.height / 64;
    dsc_out->ofs_x = fdsc->face->glyph->metrics.horiBearingX / 64;
    dsc_out->ofs_y = fdsc->face->glyph->metrics.horiBearingY / 64 - dsc_out->box_h;
    dsc_out->bpp   = 8;

    return true;
}

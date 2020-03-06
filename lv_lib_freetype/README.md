# lv_freetype
Interface to FreeType to generate font bitmaps run time

## Install FreeType
- Download Freetype from [here](https://sourceforge.net/projects/freetype/files/)
- `make`
- `sudo make install`

## Add FreeType to your project
- Add include path: `/usr/include/freetype2` (for GCC: `-I/usr/include/freetype2 -L/usr/local/lib`)
- Add library: `freetype` (for GCC: `-L/usr/local/lib -lfreetype`)

## Usage in LittlevGL
```c
    lv_freetype_init();

    static lv_font_t font1;
    lv_freetype_font_init(&font1, "./lv_freetype/arial.ttf", 32);

    lv_obj_t * label = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text(label, "Hello world");
```

## Learn more
- FreeType [tutorial](https://www.freetype.org/freetype2/docs/tutorial/step1.html) 
- LittlevGL's [font interface](https://docs.littlevgl.com/en/html/overview/font.html#add-a-new-font-engine)

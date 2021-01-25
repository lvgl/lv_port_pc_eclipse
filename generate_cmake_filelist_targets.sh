mkdir lvgl_lib_cmake
cd lv_drivers
find . -name "*.c" > ../lvgl_lib_cmake/lv_drivers_c.txt
find . -name "*.h" > ../lvgl_lib_cmake/lv_drivers_h.txt
cd ../lv_examples
find . -name "*.c" > ../lvgl_lib_cmake/lv_examples_c.txt
find . -name "*.h" > ../lvgl_lib_cmake/lv_examples_h.txt
cd ../lvgl
find . -name "*.c" > ../lvgl_lib_cmake/lvgl_c.txt
find . -name "*.h" > ../lvgl_lib_cmake/lvgl_h.txt

cmake_minimum_required(VERSION 3.10)
project(lvgl)
set(CMAKE_C_STANDARD 11)#C11
set(CMAKE_CXX_STANDARD 17)#C17
set(CMAKE_CXX_STANDARD_REQUIRED ON)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})

file(GLOB_RECURSE INCLUDES "lv_drivers/*.h" "lv_examples/*.h"  "lvgl/*.h"  "./*.h" "lv_lib_freetype/*.h")
file(GLOB_RECURSE SOURCES  "lv_drivers/*.c" "lv_examples/*.c"  "lvgl/*.c" "lv_lib_freetype/*.c")

add_compile_options(-fdiagnostics-color=always)
add_compile_options(-I/usr/include/freetype2 -L/usr/local/lib -lfreetype)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) 

find_package(SDL2 REQUIRED SDL2)
include_directories(${SDL2_INCLUDE_DIRS})
add_executable(main main.c mouse_cursor_icon.c ${SOURCES} ${INCLUDES})
target_link_libraries(main PRIVATE SDL2 freetype)
add_custom_target (run COMMAND ${EXECUTABLE_OUTPUT_PATH}/main)
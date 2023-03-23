cmake_minimum_required(VERSION 3.10)
project(lvgl)
set(CMAKE_C_STANDARD 11)#C11
set(CMAKE_CXX_STANDARD 17)#C17
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS " -Wno-int-conversion")

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})

file(GLOB_RECURSE INCLUDES "./*.h" )

# Here is only an example to use static lib. If you use shared lib,
# simply change SDL2-static to SDL2. Set SDL2 to where SDL2Config.cmake
# exists in the SDL2 package.
set(SDL2_DIR "C:/Users/Administrator/Desktop/SDL/lib/lib/cmake/SDL2")
find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2-static)
include_directories(${SDL2_INCLUDE_DIRS})

add_subdirectory(lvgl)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) 

add_executable(main main.c mouse_cursor_icon.c ${SOURCES} ${INCLUDES})
add_compile_definitions(LV_CONF_INCLUDE_SIMPLE)
# If you use shared lib, change SDL2-static to SDL2.
target_link_libraries(main PRIVATE lvgl lvgl::examples lvgl::demos SDL2-static)
add_custom_target (run COMMAND ${EXECUTABLE_OUTPUT_PATH}/main)

cmake_minimum_required(VERSION 3.10)

project(lvgl)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

find_package(SDL2 REQUIRED SDL2)
include_directories(
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_INCLUDE_DIRS}/../
        ${PROJECT_SOURCE_DIR}
)

add_subdirectory(lvgl)
add_subdirectory(lv_drivers)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_executable(main main.c mouse_cursor_icon.c ${SOURCES} ${INCLUDES})
target_link_libraries(main PRIVATE lvgl lvgl::examples lvgl::demos lvgl::drivers ${SDL2_LIBRARIES})
add_custom_target(run COMMAND ${EXECUTABLE_OUTPUT_PATH}/main)

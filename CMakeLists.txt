cmake_minimum_required(VERSION 3.14)

project(lvgl_simulator C CXX ASM)

option(USE_CONAN_PACKAGE_MANAGER OFF)

if( USE_CONAN_PACKAGE_MANAGER )
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup(TARGETS)
else()
    find_package(SDL2 REQUIRED SDL2)
endif()

include(cmake/declare_lvgl_target_library.cmake)

add_library(lvgl_conf INTERFACE)
target_include_directories(lvgl_conf INTERFACE )

set (GENERATED_LVGL_PATHS_DIR ${CMAKE_CURRENT_LIST_DIR}/lvgl_lib_cmake)

lvgl_create_static_library_target(lvgl ${GENERATED_LVGL_PATHS_DIR} lvgl_conf)
lvgl_create_static_library_target(lv_examples ${GENERATED_LVGL_PATHS_DIR} lvgl lvgl_conf)
lvgl_create_static_library_target(lv_drivers ${GENERATED_LVGL_PATHS_DIR} lvgl lvgl_conf)

add_executable(lvgl_sim_eclipse main.c mouse_cursor_icon.c)

#add_subdirectory (lv_lib_rlottie)

target_include_directories(
    lvgl_sim_eclipse
    PRIVATE
    ${CMAKE_CURRRENT_LIST_DIR}
)

target_compile_features(
    lvgl_sim_eclipse
    PRIVATE
    cxx_std_17
)

target_link_libraries(lvgl_sim_eclipse PRIVATE lvgl lv_lib_rlottie SDL2 )

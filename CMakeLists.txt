cmake_minimum_required(VERSION 3.14)

project(lvgl_simulator C CXX ASM)

option(USE_CONAN OFF)
option(USE_TARGET_BASED_BUILD OFF)

set (SDL_TARGET_NAME "")
if( USE_CONAN )
    set( CONAN_DISABLE_CHECK_COMPILER TRUE )
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup(TARGETS)
    set(SDL_TARGET_NAME CONAN_PKG::sdl2)
else()
    find_package(SDL2 REQUIRED SDL2)
    set(SDL_TARGET_NAME SDL2)
endif()

message("[Pacakges] SDL target name is: ${SDL_TARGET_NAME}")
message("[Build]    Target based build is ${USE_TARGET_BASED_BUILD}")

add_subdirectory (lv_lib_rlottie)

if ( USE_TARGET_BASED_BUILD )

include(cmake/declare_lvgl_target_library.cmake)

add_library(lvgl_conf INTERFACE)
target_include_directories(lvgl_conf INTERFACE )

set (GENERATED_LVGL_PATHS_DIR ${CMAKE_CURRENT_LIST_DIR}/lvgl_lib_cmake)

lvgl_create_static_library_target(lvgl ${GENERATED_LVGL_PATHS_DIR} lvgl_conf)
lvgl_create_static_library_target(lv_drivers ${GENERATED_LVGL_PATHS_DIR})
lvgl_create_static_library_target(lv_examples ${GENERATED_LVGL_PATHS_DIR})

target_link_libraries(lvgl PUBLIC lvgl_conf)
target_link_libraries(lv_drivers PUBLIC lvgl_conf lvgl ${SDL_TARGET_NAME})
target_link_libraries(lv_examples PUBLIC lvgl_conf lvgl lv_drivers)

add_executable(lvgl_sim_eclipse main.c mouse_cursor_icon.c)

target_include_directories(
    lvgl_sim_eclipse
    PRIVATE
    ${CMAKE_CURRRENT_LIST_DIR}
)

target_link_libraries(lvgl_sim_eclipse PRIVATE lvgl lv_examples lv_lib_rlottie)

else()

set(LOTTIE_MODULE OFF)
set(LOTTIE_THREAD OFF)
set(BUILD_SHARED_LIBS OFF)

include_directories(
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/lvgl
    ${CMAKE_CURRENT_LIST_DIR}/lv_examples
    ${CMAKE_CURRENT_LIST_DIR}/lv_drivers
    ${CMAKE_CURRENT_LIST_DIR}/lv_lib_rlottie
    ${CMAKE_CURRENT_LIST_DIR}/lv_lib_rlottie/rlottie_lib/rlottie/inc
)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS lvgl/src/*.c lv_drivers/*.c lv_examples/*.c lv_lib_rlottie/*.c )

add_executable(lvgl_sim_eclipse main.c mouse_cursor_icon.c ${SOURCES})
target_link_libraries(lvgl_sim_eclipse PRIVATE ${SDL_TARGET_NAME} rlottie)

endif()

target_compile_features(
    lvgl_sim_eclipse
    PRIVATE
    cxx_std_14
)
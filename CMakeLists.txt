cmake_minimum_required(VERSION 3.14)

project(lvgl_simulator C CXX ASM)

option(USE_CONAN_PACKAGE_MANAGER OFF)

if( USE_CONAN_PACKAGE_MANAGER )
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup(TARGETS)
else()
    find_package(SDL2 REQUIRED SDL2)
endif()

set (APP_TARGET lvgl_simulator)

# file(GLOB_RECURSE INCLUDES " lvgl/*.h lv_drivers/*.h" "lv_examples/*.h"    "lv_lib_rlottie/*.h" "./*.h" )
# file(GLOB_RECURSE SOURCES  " lvgl/*.c lv_drivers/*.c" "lv_examples/*.c"   "lv_lib_rlottie/.*c")

add_executable(${APP_TARGET} ${SOURCES} ${INCLUDES})

#add_subdirectory (lv_lib_rlottie)

target_include_directories(
    ${APP_TARGET}
    PRIVATE
    ${CMAKE_CURRRENT_LIST_DIR}
)

target_compile_features(
    ${APP_TARGET}
    PRIVATE
    cxx_std_17
)

target_link_libraries(${APP_TARGET} PRIVATE lv_lib_rlottie SDL2 )

function (lvgl_create_static_library_target TARGET_NAME GENERATED_FILES_DIR TARGET_LINK_EXT_LIBRARIES )

    set(LV_TARGET_SOURCES_PATH "${GENERATED_FILES_DIR}/${TARGET_NAME}_c.txt")
    set (LV_TARGET_HEADERS_PATH "${GENERATED_FILES_DIR}/${TARGET_NAME}_h.txt")

    file(STRINGS ${LV_TARGET_SOURCES_PATH} C_LVGL_SOURCES )
    file(STRINGS ${LV_TARGET_HEADERS_PATH} C_LVGL_HEADERS )

    message("Current target is ${TARGET_NAME}")
    message("${TARGET_NAME} source path is ${LV_TARGET_SOURCES_PATH}")
    message("${TARGET_NAME} includes path is ${LV_TARGET_HEADERS_PATH}")

    set (MODIFIED_SOURCE_LIST "")
    foreach(SOURCE_PATH ${C_LVGL_SOURCES} )
        string(REPLACE "./" "${TARGET_NAME}/" SOURCE_OUT ${SOURCE_PATH})
        list(APPEND MODIFIED_SOURCE_LIST ${SOURCE_OUT})
    endforeach()
    
    set (MODIFIED_INCLUDES_LIST "")
    foreach(INCLUDE_PATH ${C_LVGL_HEADERS} )
        string(REPLACE "./" "${TARGET_NAME}/" INCLUDE_OUT ${INCLUDE_PATH})
        list(APPEND MODIFIED_INCLUDES_LIST ${INCLUDE_OUT})
    endforeach()

    set_source_files_properties(${MODIFIED_SOURCE_LIST} PROPERTIES LANGUAGE C)
    add_library( ${TARGET_NAME} STATIC ${MODIFIED_SOURCE_LIST})

    target_sources(${TARGET_NAME} PUBLIC ${MODIFIED_INCLUDES_LIST} ${MODIFIED_SOURCE_LIST})
    if(WIN32)
        target_compile_definitions(${TARGET_NAME} PRIVATE _CRT_SECURE_NO_WARNINGS)
    endif(WIN32)

    
    target_link_libraries( ${TARGET_NAME} PUBLIC ${TARGET_LINK_EXT_LIBRARIES})
endfunction()
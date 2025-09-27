function(add_gtk_resources _target _xmlfile)
    get_filename_component(XML_ABS ${_xmlfile} ABSOLUTE)
    get_filename_component(XML_DIR ${_xmlfile} DIRECTORY)
    get_filename_component(XML_NAME_WE ${_xmlfile} NAME_WE)
    
    set(XML_NAME_WE ${XML_NAME_WE}Resource)

    set(RES_C ${CMAKE_CURRENT_BINARY_DIR}/${XML_NAME_WE}.c)
    set(RES_H ${CMAKE_CURRENT_BINARY_DIR}/${XML_NAME_WE}.h)
   
    add_custom_command(
        OUTPUT ${RES_C} ${RES_H}
        COMMAND rm -vf ${RES_C} ${RES_H}
        COMMAND glib-compile-resources ${XML_ABS} --generate-source --target=${RES_C}
        COMMAND glib-compile-resources ${XML_ABS} --generate-header --target=${RES_H}
        DEPENDS ${XML_ABS} ${XML_DIR}/ui/*.ui
        WORKING_DIRECTORY ${XML_DIR}
    )

    target_sources(${_target} PUBLIC ${RES_C})
    target_include_directories(${_target} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

endfunction()
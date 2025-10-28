cmake_minimum_required(VERSION 3.28.0)

include(${CMAKE_CURRENT_SOURCE_DIR}/../global.cmake)

set(PROJECTNAME "wtc")
set(INC_DIR ".")
set(SRC_DIR ".")
set(SRC_COMMON_DIR "../common")

set(SRCS)

project(${PROJECTNAME})

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)

aux_source_directory(${SRC_DIR} SRCS)
aux_source_directory(${SRC_DIR}/wtc SRCS)

add_executable(${PROJECTNAME})

target_include_directories( 
    ${PROJECTNAME} 
    PUBLIC ${INC_DIR} 
    PUBLIC "${SRC_COMMON_DIR}"
    PUBLIC "${SRC_COMMON_DIR}/autilitys/autils" 
    PUBLIC ${GTK4_INCLUDE_DIRS}
    PUBLIC "${SRC_DIR}/wtc"
    # PUBLIC "${SRC_COMMON_DIR}/gtkaa" 
)

target_sources( 
    ${PROJECTNAME} 
    PUBLIC ${SRCS}
)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    include(${SOLUTION_DIR}/addGtkResource.cmake)
    add_gtk_resources(${PROJECTNAME} "${CMAKE_CURRENT_SOURCE_DIR}/resources/wtc.gresource.xml")
endif()

target_compile_definitions( ${PROJECTNAME}  PUBLIC
    # "_CRT_SECURE_NO_WARNINGS"
    PUBLIC
    $<$<CONFIG:Debug>:DEBUG>
    $<$<CONFIG:Release>:RELEASE>
    $<$<CONFIG:RelWithDebInfo>:DEBUG>
    $<$<CONFIG:MinSizeRel>:RELEASE>
)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_directories(${PROJECTNAME} PUBLIC ${GTK4_LIBRARY_DIRS})
    target_link_libraries(${PROJECTNAME} PUBLIC stdc++fs ${GTK4_LIBRARIES})
endif()

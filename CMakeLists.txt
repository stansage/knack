cmake_minimum_required( VERSION 2.8 )
project( knack )

set( CMAKE_CXX_FLAGS "-std=c++11" )

set( GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Build GLFW examples" )
set( GLFW_BUILD_TESTS OFF CACHE BOOL "Build GLFW tests" )
set( GLFW_BUILD_DOCS OFF CACHE BOOL "Build GLFW documentation" )
set( GLFW_INSTALL OFF CACHE BOOL "Generate GLFW installation" )

add_subdirectory( glfw )
include_directories( glfw/include )

aux_source_directory( src SOURCES )
add_executable( ${PROJECT_NAME} ${SOURCES} )
target_link_libraries( ${PROJECT_NAME} glfw ${GLFW_LIBRARIES} )

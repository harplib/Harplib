cmake_minimum_required(VERSION 3.29)
project(harplib C)

set(CMAKE_C_STANDARD 99)

find_package(OpenGL REQUIRED)

include_directories(
        ${OPENGL_INCLUDE_DIR}
        ${GLFW_INCLUDE_DIRS}
        "glfw/include/"
)

set( GLFW_SOURCE_DIR "glfw" )

set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )
set( GLAD_GL "" )

option( GLFW-CMAKE-STARTER-USE-GLFW-GLAD "Use GLAD from GLFW" ON )

if( GLFW-CMAKE-STARTER-USE-GLFW-GLAD )
    include_directories("${GLFW_SOURCE_DIR}/deps")
    set( GLAD_GL "${GLFW_SOURCE_DIR}/deps/glad/gl.h" )
endif()

if( MSVC )
    SET( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup" )
endif()

add_library(harplib STATIC harplib_desktop.c)

set( TESTER-SRC
        tester.c
        harplib_desktop.c
        harplib.h
)
add_executable( tester ${TESTER-SRC} ${GLAD_GL} )
target_link_libraries( tester ${OPENGL_LIBRARIES})

if(WIN32)
    target_link_libraries(tester ${CMAKE_CURRENT_SOURCE_DIR}/glfw-bin/lib-vc2022/glfw3.lib)
else()
    target_link_libraries(tester glfw)
endif()

set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT GLFW-CMake-starter )
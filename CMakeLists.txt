cmake_minimum_required(VERSION 3.10)

project(renderer)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)

set(RENDERER_SRC ${CMAKE_SOURCE_DIR}/src)
set(RENDERER_RESOURCES ${CMAKE_SOURCE_DIR}/res)
set(RENDERER_LIB ${CMAKE_SOURCE_DIR}/lib)
set(RENDERER_BIN ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${RENDERER_BIN})

include(${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake)
include_directories(${CMAKE_SOURCE_DIR}/vcpkg/installed/x64-windows/include)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    link_directories(${CMAKE_SOURCE_DIR}/vcpkg/installed/x64-windows/debug/lib)
    message("Debug mode: ${CMAKE_C_FLAGS_DEBUG}")
else()
    link_directories(${CMAKE_SOURCE_DIR}/vcpkg/installed/x64-windows/lib)
    message("Release mode: ${CMAKE_C_FLAGS_RELEASE}")
endif()

include_directories(${RENDERER_SRC})

add_subdirectory(src)

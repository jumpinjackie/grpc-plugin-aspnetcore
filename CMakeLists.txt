cmake_minimum_required(VERSION 3.0)

# Set configuration if not defined
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif (NOT CMAKE_BUILD_TYPE)

message(STATUS "Build type is: ${CMAKE_BUILD_TYPE}")

find_package(protobuf CONFIG REQUIRED)

#################### Windows specifics ################

if(WIN32)
    add_definitions(-D_WIN32_WINNT=0x600)
    add_definitions(-DUNICODE -D_UNICODE)
    add_definitions(/MP)
    if(MSVC)
        if(NOT (MSVC14))
            message(FATAL_ERROR, "Only MSVC14 (Visual Studio 2015) is supported compiler on Windows")
        endif(NOT (MSVC14))
    else(MSVC)
        message(FATAL_ERROR, "Only MSVC is the supported compiler on Windows")
    endif(MSVC)
endif(WIN32)

add_subdirectory(src)
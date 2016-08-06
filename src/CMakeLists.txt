cmake_minimum_required(VERSION 3.0)

project(GcovFileParser CXX)

set(CXX_STANDARD "c++14")

if(${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -fno-exceptions -pedantic -pedantic-errors -Wall -Wextra -Werror")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL Clang)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -fno-exceptions -pedantic -pedantic-errors -Wall -Wextra -Werror")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W3 /EHsc")
else()
    message(WARNING "Unsupported compiler!")
endif()

set(LIB_FILES
	    ./gcovfileparser_global.h
	    ./gcovfileparser.h
		./gcovfileparser.cpp
		./gcovbuffer.h
		./gcovbuffer.cpp
		)

file( GLOB SRCS *.cpp )
add_library(GcovFileParser STATIC ${SRCS})
target_include_directories (GcovFileParser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
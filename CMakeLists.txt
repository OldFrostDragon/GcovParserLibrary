cmake_minimum_required(VERSION 3.0)
project(GcovFileParserProject CXX)
set(CXX_STANDARD "c++14")

SET(CMAKE_INCLUDE_CURRENT_DIR ON)

enable_testing()

if(${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -fno-exceptions -pedantic -pedantic-errors -Wall -Wextra -Werror")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL Clang)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -fno-exceptions -pedantic -pedantic-errors -Wall -Wextra -Werror")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W3 /EHsc")
else()
    message(WARNING "Unsupported compiler!")
endif()


include_directories(src)

add_subdirectory(src)
add_subdirectory(tests)


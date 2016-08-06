if (${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -fno-exceptions -pedantic -pedantic-errors -Wall -Wextra -Werror" )
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL Clang)
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -fno-exceptions -pedantic -pedantic-errors -Wall -Wextra -Werror" )
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W3 /EHsc" )
else ()
    message( WARNING "Unsupported compiler!" )
endif ()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable( gtest_auto
        main.cpp
        gcovfileparsertests.cpp )
target_link_libraries(gtest_auto gtest gtest_main  GcovFileParser)
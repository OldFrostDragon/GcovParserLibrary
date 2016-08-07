if (${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -pedantic -Wall -Wextra" )
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL Clang)
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -pedantic -Wall -Wextra" )
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W3 /EHsc" )
else ()
    message( WARNING "Unsupported compiler!" )
endif ()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable( gtest_auto
        main.cpp
        gcovfileparsertests.cpp gcovbuffertests.cpp slicereftest.cpp )
target_link_libraries(gtest_auto gtest gtest_main  GcovFileParser)

add_test(gtest_auto gtest_auto)
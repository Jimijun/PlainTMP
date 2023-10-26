cmake_minimum_required(VERSION 3.5)
project(PlainTMP VERSION 0.1.0 LANGUAGES C CXX)

add_definitions(-DUNICODE -D UNICODE)
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

add_library(PlainTMP SHARED
    custom_tmp.hpp
    plain_tmp.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

cmake_minimum_required(VERSION 2.6.0)
project(base_test)

# config executable_name
set(run_exe_name test)

include_directories(${PROJECT_SOURCE_DIR}/)
include_directories(${PROJECT_SOURCE_DIR}/base)
include_directories(${PROJECT_SOURCE_DIR}/compile_patch)
include_directories(${PROJECT_SOURCE_DIR}/deps/gtest/include)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/unit SRC_LIST)

# add main gtest
add_executable(${run_exe_name}   ${PROJECT_SOURCE_DIR}/src/main/main_test.cpp ${SRC_LIST})

set(gtest_lib ${PROJECT_SOURCE_DIR}/deps/gtest/lib/libgtest.a)
set(base_lib ${PROJECT_SOURCE_DIR}/base_lib/libbase.dylib)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

target_link_libraries(${run_exe_name} ${gtest_lib} ${base_lib})
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(project)
add_executable(project.bin src/main.cpp)
# set(CMAKE_BUILD_TYPE Debug)
target_include_directories(project.bin PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

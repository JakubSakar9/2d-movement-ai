cmake_minimum_required(VERSION 3.18.4)

project(2d_movement_ai LANGUAGES CXX)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++17")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB source_files "${source_dir}/*.cpp")

add_executable(${PROJECT_NAME} "${source_files}")
target_link_libraries(${PROJECT_NAME} SDL2 SDL2_image SDL2_ttf)

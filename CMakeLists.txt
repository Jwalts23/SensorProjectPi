cmake_minimum_required(VERSION 3.8)
project(sensor_lib)

find_library(wiringPi_LIB wiringPi)

add_executable(${PROJECT_NAME} main.cpp)
add_subdirectory(libs)

target_include_directories(${PROJECT_NAME} PUBLIC libs)
target_link_directories(${PROJECT_NAME} PRIVATE libs)

target_link_libraries(${PROJECT_NAME} sensors ${wiringPi_LIB})
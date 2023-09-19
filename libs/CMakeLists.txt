#adding the header <.h> files into the project

include_directories(include)
file(GLOB SOURCES "*.cpp")
add_library(sensors ${SOURCES})


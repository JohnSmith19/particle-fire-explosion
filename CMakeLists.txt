cmake_minimum_required(VERSION 3.10)
project(Particle)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)

set(CMAKE_CXX_STANDARD 11)

include_directories(${SDL2_INCLUDE_DIR})
add_executable(Particle main.cpp Screen.cpp Screen.h)

if(WIN32)
    target_link_libraries(Particle ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -mwindows)
else()
    target_link_libraries(Particle ${SDL2_LIBRARY} -lSDL2main -lSDL2)
endif(WIN32)

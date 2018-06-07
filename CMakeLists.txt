cmake_minimum_required(VERSION 3.10)
project(ParticleFireExplosion)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_CXX_STANDARD 11)

add_executable(ParticleFireExplosion main.cpp)

target_link_libraries(ParticleFireExplosion SDL2main SDL2)
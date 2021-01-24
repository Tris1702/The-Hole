cmake_minimum_required(VERSION 3.17)
project(Game1_0)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5 COMPONENTS system window graphics)

add_executable(Game1_0 main.cpp Player.cpp Player.h Map.cpp Map.h Menu.cpp Menu.h Ttexture.cpp Ttexture.h)
#add_executable(Game1_0 main.cpp Ttexture.cpp Ttexture.h Menu.cpp)

target_link_libraries(Game1_0 sfml-system sfml-window sfml-graphics sfml-audio)

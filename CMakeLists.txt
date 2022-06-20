cmake_minimum_required(VERSION 3.21)
project(GameProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SFML_ROOT /usr/local/lib)
set(SOURCE_FILES main.cpp Game.cpp Game.h Player.cpp Player.h Bullet.cpp Bullet.h Libraries.h Monster.cpp Monster.h Alien.cpp Alien.h BugAlien.cpp BugAlien.h)
add_executable(GameProject ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(GameProject sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
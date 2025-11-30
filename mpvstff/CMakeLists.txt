cmake_minimum_required(VERSION 3.22)
project(kolplayer_v2 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(MPV REQUIRED mpv)


add_executable(kolplayer_v2 main.cpp)

target_include_directories(kolplayer_v2 PRIVATE ${MPV_INCLUDE_DIRS})
target_link_directories(kolplayer_v2 PRIVATE ${MPV_LIBRARY_DIRS})

target_link_libraries(kolplayer_v2 PRIVATE ${MPV_LIBRARIES})






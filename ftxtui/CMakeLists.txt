cmake_minimum_required(VERSION 3.22)
project(ftxui_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(ftxui_test src/main.cpp)

target_include_directories(ftxui_test PRIVATE
${CMAKE_CURRENT_SOURCE_DIR}/ftxui_headers/include
)

target_link_libraries(ftxui_test PRIVATE
${CMAKE_CURRENT_SOURCE_DIR}/ftxui_headers/ftxui_static_libs/libftxui_component.a
${CMAKE_CURRENT_SOURCE_DIR}/ftxui_headers/ftxui_static_libs/libftxui_dom.a
${CMAKE_CURRENT_SOURCE_DIR}/ftxui_headers/ftxui_static_libs/libftxui_screen.a

)

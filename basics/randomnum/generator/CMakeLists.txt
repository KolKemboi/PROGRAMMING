add_library(generator STATIC generator.cpp)

#to expose the headers
target_include_directories(generator PUBLIC $(CMAKE_CURRENT_SOURCE_DIR))

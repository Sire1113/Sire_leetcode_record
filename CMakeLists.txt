cmake_minimum_required(VERSION 3.31)
set(CMAKE_CXX_STANDARD 20)
project(leetcode)

#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
#message(STATUS  "Found Python3: ${Python3_EXECUTABLE} \n found version ${Python3_VERSION}")
#message(STATUS "Lib dirs: ${Python3_LIBRARY_DIRS}")
#add_library(list_utils STATIC "utils/list_utils.cpp")

#add_library(leetcode SHARED src/test.cpp)
# 可执行文件
add_subdirectory(utils)
add_executable(leetcode main.cpp)
# 正确链接 - 使用目标名
target_link_libraries(leetcode PRIVATE utils)
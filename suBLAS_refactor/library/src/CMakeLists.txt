INCLUDE_DIRECTORIES("${CMAKE_SOURCE_DIR}/library/src"
"${CMAKE_SOURCE_DIR}/library/src/core")

set(CMAKE_CXX_FLAGS "-std=c++14 -g")

file(GLOB_RECURSE SRC ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)
add_executable(hello ${SRC})


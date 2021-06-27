cmake_minimum_required(VERSION 3.5)
project(mn2)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

#create executables
add_executable(a a.c)
add_executable(b b.c)
add_executable(c c.c)

#add libm library for math functions
target_link_libraries(a m)
target_link_libraries(b m)
target_link_libraries(c m)

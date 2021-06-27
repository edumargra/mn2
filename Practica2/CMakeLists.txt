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
add_executable(a.exe a.c)
add_executable(b.exe b.c)
add_executable(c.exe c.c)
add_executable(d.exe d.c)
add_executable(e.exe e.c)
add_executable(g.exe g.c)
add_executable(tan.exe tan.c)

#add libm library for math functions
target_link_libraries(a.exe m)
target_link_libraries(b.exe m)
target_link_libraries(c.exe m)
target_link_libraries(d.exe m)
target_link_libraries(e.exe m)
target_link_libraries(g.exe m)
target_link_libraries(tan.exe m)
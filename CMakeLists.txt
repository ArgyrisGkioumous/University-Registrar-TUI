cmake_minimum_required(VERSION 4.2)
project(University_Registrar_TUI)

set(CMAKE_CXX_STANDARD 20)

find_package(Curses REQUIRED)

add_executable(University_Registrar_TUI main.cpp
        Member.cpp
        Member.h
        Professor.cpp
        Professor.h
        Course.cpp
        Course.h
        Registrar.cpp
        Registrar.h)

target_include_directories(University_Registrar_TUI PRIVATE ${CURSES_INCLUDE_DIRS})
target_link_libraries(University_Registrar_TUI PRIVATE ncurses ${CURSES_LIBRARIES})
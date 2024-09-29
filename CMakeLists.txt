cmake_minimum_required(VERSION 3.27)
project(CC1 C)

set(CMAKE_C_STANDARD 11)

add_executable(CC1 src/main.c
        src/select.c
        src/insert.c
        src/main.h
        src/structure.h
        src/binary_tree.h
        src/binary_tree.c
        src/insert.h
        src/delete.c
        src/delete.h
        src/update.c
        src/update.h
        src/structure.c
        src/structure.c
)

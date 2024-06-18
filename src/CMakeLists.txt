cmake_minimum_required(VERSION 3.10)

project(max-number-neighborhood LANGUAGES C)

set(SOURCES 
    main.c 
    common/alloc.h
)

add_executable(max-number-neighborhood ${SOURCES})
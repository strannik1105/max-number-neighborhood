cmake_minimum_required(VERSION 3.10)

project(max-number-neighborhood LANGUAGES C)

set(SOURCES 
    main.c 
    common/list.c
)


add_executable(max-number-neighborhood ${SOURCES})

target_include_directories(max-number-neighborhood
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)
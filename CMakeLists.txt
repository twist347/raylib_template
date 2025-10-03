cmake_minimum_required(VERSION 3.20)

set(T raylib_template)

project(${T})

set(RAYLIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/raylib-5.5_linux_amd64)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${T} main.c)
target_include_directories(${T} PRIVATE ${RAYLIB_DIR}/include)
target_link_directories(${T} PRIVATE ${RAYLIB_DIR}/lib)
target_link_libraries(${T} PRIVATE raylib m)
target_compile_options(${T} PRIVATE -Wall -Wextra -pedantic)

add_custom_command(
        TARGET ${T}
        POST_BUILD

        COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:${T}>/textures"
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/textures"
        "$<TARGET_FILE_DIR:${T}>/textures"

        COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:${T}>/shaders"
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/shaders"
        "$<TARGET_FILE_DIR:${T}>/shaders"
)

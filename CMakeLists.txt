cmake_minimum_required(VERSION 3.31)
project(ICCore)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glfw3 CONFIG REQUIRED)

add_library(${PROJECT_NAME} STATIC
        src/image.cpp
        src/Window.cpp
        include/Window.h
)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        PRIVATE
        ${Stb_INCLUDE_DIR}
)

target_compile_definitions(${PROJECT_NAME} PRIVATE STB_IMAGE_IMPLEMENTATION)

target_link_libraries(${PROJECT_NAME}
        PRIVATE glfw
)
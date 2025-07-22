cmake_minimum_required(VERSION 3.31)
project(ICCore)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

add_library(${PROJECT_NAME} STATIC
        src/image.cpp
        src/Window.cpp
        include/Window.h
        include/Camera.h
        src/Camera.cpp
        include/Logger.h
        src/Logger.cpp
        include/Data.h
        include/Mesh.h
        src/Mesh.cpp
        include/Primitives.h
        include/Material.h
        include/IShader.h
)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE
        ${Stb_INCLUDE_DIR}
)

target_compile_definitions(${PROJECT_NAME} PRIVATE STB_IMAGE_IMPLEMENTATION)

target_link_libraries(${PROJECT_NAME}
        PUBLIC glfw
        spdlog::spdlog_header_only
)

# Export library
install(TARGETS ICCore EXPORT ICCoreTargets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
)

install(DIRECTORY include/ DESTINATION include)

install(EXPORT ICCoreTargets
        FILE ICCoreConfig.cmake
        NAMESPACE ICCore::
        DESTINATION lib/cmake/ICCore
)
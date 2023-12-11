cmake_minimum_required(VERSION 3.0)
set(PROJECT_NAME Snake)
project(${PROJECT_NAME})
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)
# Copy image files to the build directory
set(SOURCE_FILES
    ${CMAKE_SOURCE_DIR}/src/main.cpp
    ${CMAKE_SOURCE_DIR}/src/Grid.cpp
    ${CMAKE_SOURCE_DIR}/src/Apple.cpp
    # ${CMAKE_SOURCE_DIR}/src/Snake.cpp
    # ${CMAKE_SOURCE_DIR}/src/SnakeSegment.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-graphics)



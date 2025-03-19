cmake_minimum_required(VERSION 3.27)

project(
    labwork1
    VERSION 1.0
    DESCRIPTION "Comp-Arch Year 2024 labwork1.1"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
add_executable(${PROJECT_NAME} src/main.cpp src/min_dist.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})


configure_file(
    ${CMAKE_SOURCE_DIR}/src/graph.txt
    ${CMAKE_BINARY_DIR}/graph.txt
    COPYONLY
)

enable_testing()
add_subdirectory(tests)

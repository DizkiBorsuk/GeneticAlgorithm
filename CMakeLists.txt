cmake_minimum_required(VERSION 3.15)
project(GeneticAlgorithm VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(${PROJECT_SOURCE_DIR})
add_executable(${PROJECT_NAME} main.cpp tools.cpp GeneticAlgorithm.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
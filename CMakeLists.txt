cmake_minimum_required(VERSION 3.7.0)

set(CMAKE_CXX_STANDARD 20)

project(Origin VERSION 0.1.0 LANGUAGES C CXX)
add_executable(Origin src/main.cpp)

add_subdirectory(SDL)
add_library(vendor INTERFACE)
target_link_libraries(vendor INTERFACE SDL3::SDL3)
target_link_libraries(Origin INTERFACE vendor)
# add_subdirectory(SDL)
# target_link_libraries(Origin PRIVATE SDL3)

# NOTE: DID NOT STATICALLY LINK, SO NEED DLLs for now. lmao

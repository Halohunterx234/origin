# cmake_minimum_required(VERSION 3.7.0)

# set(CMAKE_CXX_STANDARD 20)

# project(Origin VERSION 0.1.0 LANGUAGES C CXX)
# add_executable(Origin src/main.cpp)

# add_subdirectory(SDL)
# add_library(vendor INTERFACE)
# target_link_libraries(vendor INTERFACE SDL3::SDL3)
# target_link_libraries(Origin INTERFACE vendor)
# add_subdirectory(SDL)
# target_link_libraries(Origin PRIVATE SDL3)

# NOTE: DID NOT STATICALLY LINK, SO NEED DLLs for now. lmao

cmake_minimum_required(VERSION 3.5)
project(Origin VERSION 0.1.0 LANGUAGES C CXX)

# Create an option to switch between a system sdl library and a vendored SDL library
option(MYGAME_VENDORED "Use vendored libraries" ON)

if(MYGAME_VENDORED)
    # This assumes you have added SDL as a submodule in vendored/SDL
    add_subdirectory(SDL/ EXCLUDE_FROM_ALL)
else()
    # 1. Look for a SDL3 package,
    # 2. look for the SDL3-shared component, and
    # 3. fail if the shared component cannot be found.
    find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
endif()

# Create your game executable target as usual
add_executable(Origin WIN32 src/main.cpp)

# Link to the actual SDL3 library.
target_link_libraries(Origin PRIVATE SDL3::SDL3)
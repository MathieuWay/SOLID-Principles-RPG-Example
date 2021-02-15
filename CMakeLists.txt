cmake_minimum_required(VERSION 3.10)

project(
    SOLID_Exemple_Project
    VERSION 0.1.0
    DESCRIPTION "SOLID Exemple"
    LANGUAGES CXX C
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS FALSE)

# add main library code
add_subdirectory(SOLID_Exemple)

# add examples code
add_subdirectory(example)
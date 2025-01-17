# Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.15)

# Set the project name and specify C++ as the language
project(cpp-exercices LANGUAGES CXX)

# Set the C++ standard (e.g., C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify the compiler (Clang in this case)
set(CMAKE_CXX_COMPILER "clang++")

###################################################################
######################## Main ################################
###################################################################

add_executable(main
  "${CMAKE_CURRENT_SOURCE_DIR}/src/class/dijkstra.cc"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
)

target_include_directories(main
  PRIVATE
  # src/class
  src
)

target_compile_options(main PRIVATE -Wall -Wextra -Wpedantic)

# Add a custom target to run
add_custom_target(run_main
    COMMAND main
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

# TO USE it
# Step 1: run mkdir build && cd build
# Step 2: run cmake .. -DCMAKE_CXX_COMPILER=clang++
# Step 3: run cmake --build . --target [runner-name]
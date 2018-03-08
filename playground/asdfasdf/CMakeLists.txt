
cmake_minimum_required(VERSION 3.7.2 FATAL_ERROR)

project(asfdasdf CXX C)

# Set the language standard be 11 for C and 14 for C++
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)
enable_language(C CXX)

find_package(Threads REQUIRED)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/third_party/spdlog)

add_executable(${PROJECT_NAME}
  src/main.cpp
)
target_link_libraries(${PROJECT_NAME}
  PRIVATE
  Threads::Threads
  spdlog
)


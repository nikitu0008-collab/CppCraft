cmake_minimum_required(VERSION 3.20)
project(CppCraft LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# FLTK -- графическая библиотека интерфейса (GuiGenerator.cpp)
find_package(FLTK REQUIRED)

include_directories(include)

add_executable(cpp_craft
    src/main.cpp
    src/CodeGenerator.cpp
    src/GuiGenerator.cpp
)

# Связываем с FLTK, найденным find_package()
target_link_libraries(cpp_craft PRIVATE ${FLTK_LIBRARIES})

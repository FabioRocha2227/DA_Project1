cmake_minimum_required(VERSION 3.20)
project(DA_project)

set(CMAKE_CXX_STANDARD 14)

add_executable(DA_project main.cpp src/carrinhas.cpp src/carrinhas.h src/encomendas.cpp src/encomendas.h src/company.cpp src/company.h menus/mainMenu.cpp menus/mainMenu.h)

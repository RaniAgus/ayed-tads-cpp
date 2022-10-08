cmake_minimum_required(VERSION 3.22)
project(ayed-tads-cpp CXX)

add_library(ayed STATIC
        src/archivos.cpp
        src/arrays.cpp
        src/cola.cpp
        src/criteriosDeBusqueda.cpp
        src/listaDoblementeEnlazada.cpp
        src/listaEnlazada.cpp
        src/pila.cpp
        src/tree.cpp)

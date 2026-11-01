cmake_minimum_required(VERSION 3.16)
project(ReseauIp)

# Définir le standard C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ajouter le sous-répertoire contenant la librairie
add_subdirectory(src)

# Créer l'exécutable
add_executable(ReseauIp Principal.cpp)

# Lier la librairie statique à l'exécutable
target_link_libraries(ReseauIp PRIVATE Res_lib)

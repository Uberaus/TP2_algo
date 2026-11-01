# Créer une librairie statique à partir des fichiers sources
add_library(Res_lib
    Graphe.h
    Reseau.cpp
    Reseau.h
    Routeur.cpp
    Routeur.h
)
target_include_directories(Res_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
#include <iostream>
#include <string>
#include <vector>
#include "../include/Mazmorra.h"
#include "../include/SalaJefe.h"
#include "../include/Enemigo.h"
#include "../include/Jugador.h"
#include "../include/Otros.h"
#include "../include/Boss.h"
#include "../include/Juego.h"

long unsigned int Juego::getSeleccionMazmorra() {
    return seleccionMazmorra;
}

void Juego::setDungeonsPath(std::string dungeonsPath) {
    this->dungeonsPath = dungeonsPath;
}
void Juego::setEnemiesPath(std::string enemiesPath) {
    this->enemiesPath = enemiesPath;
}
std::string Juego::getDungeonsPath() {
    return dungeonsPath;
}
std::string Juego::getEnemiesPath() {
    return enemiesPath;
}

Mazmorra Juego::elegirMazmorra() {

    Otros otros;
    bool opcionValida = false;
    std::vector<Mazmorra> mazmorras = otros.cargarMazmorrasCSV("/home/pbn/tarea3pbn/mazmorras.csv").first;
    std::cout << "=== Selección de Mazmorras ===" << std::endl;
    for (size_t i = 0; i < mazmorras.size(); ++i) {
        std::cout << "Mazmorras #" << i + 1 << ": " << mazmorras[i].getFilas() << "x" << mazmorras[i].getColumnas() << std::endl;
    }
    while (!opcionValida) {
    try{
        std::cout << "Selecciona una mazmorras (1-" << mazmorras.size() << "): ";
        std::cin >> seleccionMazmorra;
        if (seleccionMazmorra < 1 || seleccionMazmorra > mazmorras.size()) {
            throw std::invalid_argument("Número de mazmorras fuera de rango.");
        }
        opcionValida = true;
    }
    catch (std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    }

    std::cout << "Mazmorras #" << seleccionMazmorra << " seleccionada." << std::endl;
    
    return mazmorras[seleccionMazmorra - 1];

}




int Juego::iniciarJuego() {
    Jugador jugador(0, 0);
    Otros otros;

    std::cout << "Bienvenido al juego!" << std::endl;
    std::cout << "Jugador creado en la posición inicial (0, 0)." << std::endl;

    std::string mazmorraPath;
    //std::cout << "Introduce la ruta del archivo de mazmorras: " << std::endl;
    //std::cin >> mazmorraPath;
    mazmorraPath = "/home/pbn/tarea3pbn/mazmorras.csv";

    std::string enemigosPath;
    //std::cout << "Introduce la ruta del archivo de enemigos: " << std::endl;
    //std::cin >> enemigosPath;
    enemigosPath = "/home/pbn/tarea3pbn/enemigos.csv";

    otros.mostrarMazmorras(otros.cargarMazmorrasCSV(mazmorraPath).first);

    Mazmorra mazmorraElegida = elegirMazmorra();
    std::vector<Mazmorra> vectorMazmorras = otros.cargarMazmorrasCSV("/home/pbn/tarea3pbn/mazmorras.csv").first;
    
    // int idxMazmorraElegida = 0;
    // for (size_t i = 0; i < vectorMazmorras.size(); ++i) {
    //     if (vectorMazmorras[i].getFilas() == mazmorraElegida.getFilas() && 
    //         vectorMazmorras[i].getColumnas() == mazmorraElegida.getColumnas()) {
    //         idxMazmorraElegida = i;
    //         break;
    //     }
    // }

    SalaJefe salaJefeElegida = otros.cargarMazmorrasCSV("/home/pbn/tarea3pbn/mazmorras.csv").second[this -> getSeleccionMazmorra() - 1];

    mazmorraElegida.mostrarMapa();

    return 0;
}
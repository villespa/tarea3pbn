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

void Juego::setDungeonsPath() {

    std::string dungeonsPath;
    std::cout << "ingrese el camino del csv de mazmorras:" << std::endl;
    // std::cin >> dungeonsPath;
    dungeonsPath = "/home/pbn/tarea3pbn/mazmorras.csv";

    this->dungeonsPath = dungeonsPath;
}
void Juego::setEnemiesPath() {
    std::string enemiesPath;
    std::cout << "ingrese el camino del csv de enemigos:" << std::endl;
    // std::cin >> enemiesPath;
    enemiesPath = "/home/pbn/tarea3pbn/enemigos.csv";

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


std::pair<Jugador, Mazmorra> Juego::iniciarJuego() {
    Jugador jugador(0, 0);
    Otros otros;

    std::cout << "Bienvenido al juego!" << std::endl;
    std::cout << "Jugador creado en la posición inicial (0, 0)." << std::endl;

    otros.mostrarMazmorras(otros.cargarMazmorrasCSV(this -> getDungeonsPath()).first);

    Mazmorra mazmorraElegida = elegirMazmorra();
    std::vector<Mazmorra> vectorMazmorras = otros.cargarMazmorrasCSV("/home/pbn/tarea3pbn/mazmorras.csv").first;

    SalaJefe salaJefeElegida = otros.cargarMazmorrasCSV("/home/pbn/tarea3pbn/mazmorras.csv").second[this -> getSeleccionMazmorra() - 1];

    mazmorraElegida.mostrarMapa();

    return std::make_pair(jugador, mazmorraElegida);
}

void mostrarInstrucciones() {
    std::cout << "\n=== CONTROLES ===" << std::endl;
    std::cout << "m = mover" << std::endl;
    std::cout << "d = cambiar direccion" << std::endl;
    std::cout << "z = usar habilidad" << std::endl;
    std::cout << "c = interactuar" << std::endl;
    std::cout << "p = salir del juego" << std::endl;
    std::cout << "=================" << std::endl;
}

void mostrarEstado(Jugador& jugador) {
    std::cout << "\n=== ESTADO ===" << std::endl;
    std::cout << "Posición: (" << jugador.getX() << ", " << jugador.getY() << ")" << std::endl;
    std::cout << "Vida: " << jugador.getVida() << std::endl;
    std::cout << "Dirección: " << jugador.getDireccion() << std::endl;
    std::cout << "==============" << std::endl;
}

int Juego::mainLoop(Jugador& jugador, Mazmorra& mazmorraElegida) {
    int contador = 0;  

    std::pair<int, int> posicionDeL = mazmorraElegida.posicionInicialJugador();
    jugador.setX(posicionDeL.second);
    jugador.setY(posicionDeL.first);

    while (jugador.getVida() > 0) {
        mostrarInstrucciones();
        char instruccion;
        mostrarEstado(jugador);
        mazmorraElegida.mostrarMapa();
        std::cout << "Ingrese una instrucción: ";
        std::cout << "Contador: " << contador << std::endl;
        std::cin >> instruccion;
        switch (instruccion) 
        {
        case 'm': {
            std::cout << "se va a mover en la dirección: " << "\033[1;33m" << jugador.getDireccion() << "\033[0m " << std::endl;
            std::pair<int, int> futuraPos = mazmorraElegida.dondeSeMueveJugador(jugador);
            std::cout << "Futura posición: (" << futuraPos.first << ", " << futuraPos.second << ")" << std::endl;
            
            // 
            // // la relacion entre direccion y cambio de posicion esta mal, rara  
            // // la relacion entre direccion y cambio de posicion esta mal, rara  
            // 
            if (jugador.puedeMoverse(mazmorraElegida, futuraPos.first, futuraPos.second)) {
                jugador.mover();
                std::cout << "Jugador se ha movido a la posición: (" << jugador.getX() << ", " << jugador.getY() << ")" << std::endl;
            } else {
                std::cout << "Movimiento no permitido." << std::endl;
                break;
        
            }
            break;
        }
        default:
            std::cout << "Instrucción no válida. Intente de nuevo." << std::endl;
            break;
        }
        
    }


    return 0;
}
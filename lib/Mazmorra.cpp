#include "../include/Mazmorra.h"

Mazmorra::Mazmorra(int filas, int columnas, const std::vector<std::vector<char>>& mapa,
                   const std::vector<Enemigo>& enemigos)
    : filas(filas), columnas(columnas), mapa(mapa), enemigos(enemigos) {}

void Mazmorra::mostrarMapa() const {
    for (const auto& fila : mapa) {
        for (char c : fila) {
            if (c == 'L' || c == 'Z') {
                std::cout << "\033[1;4;92m" << c << "\033[0m "; // Color verde
            } 
            else if (c == 'X') {
                std::cout << "\033[0;90m" << c << "\033[0m "; // Color rojo
            }
            else {
                std::cout << c << ' ';
            }
        }
        std::cout << std::endl;
    }
}

char Mazmorra::obtenerElemento(int x, int y) const {
    if (x >= 0 && x < filas && y >= 0 && y < columnas)
        return mapa[x][y];
    return '?'; // fuera de límites
}

void Mazmorra::modificarElemento(int x, int y, char nuevoValor) {
    if (x >= 0 && x < filas && y >= 0 && y < columnas)
        mapa[x][y] = nuevoValor;
}

int Mazmorra::getFilas() const {
    return filas;
}

int Mazmorra::getColumnas() const {
    return columnas;
}

std::vector<Enemigo>& Mazmorra::getEnemigos() {
    return enemigos;
}

void Mazmorra::agregarEnemigo(const Enemigo& enemigo) {
    enemigos.push_back(enemigo);
}

void Mazmorra::eliminarEnemigoEn(int x, int y) {
    for (auto it = enemigos.begin(); it != enemigos.end(); ++it) {
        if (it->getX() == x && it->getY() == y) {
            enemigos.erase(it);
            break;
        }
    }
}


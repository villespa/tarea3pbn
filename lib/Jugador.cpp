#include <iostream>
#include <string>
#include "../include/Jugador.h"
#include "../include/Mazmorra.h"

void Jugador::setX(int x) {
    this->x = x;
}
void Jugador::setY(int y) {
    this->y = y;
}
void Jugador::cambiarVida(int vida) {
    this->vida = vida;
}
int Jugador::getX() {
    return x;
}
int Jugador::getY() {
    return y;
}
int Jugador::getVida() {
    return vida;
}
std::string Jugador::getDireccion() {
    return direccion;
}

Jugador::Jugador() : x(0), y(0), vida(100), dano(20), direccion("arriba") {
    llaves = 0;
    llavesJefe = 0;
    pasos = 0;
    cofresAbiertos = 0;
    puertasAbiertas = 0;
    EnemigosDerrotados = 0;
    recibiendoDano = false;
    usandoHabilidad = false;
    atacando = false;
    enSalaJefe = false;
    haGanado = false;
}

Jugador::Jugador(int x, int y) : x(x), y(y), vida(100), dano(20), direccion("arriba") {
    llaves = 0;
    llavesJefe = 0;
    pasos = 0;
    cofresAbiertos = 0;
    puertasAbiertas = 0;
    EnemigosDerrotados = 0;
    recibiendoDano = false;
    usandoHabilidad = false;
    atacando = false;
    enSalaJefe = false;
    haGanado = false;
}

void Jugador::setDireccion(std::string direccion) {
    this->direccion = direccion;
}

void Jugador::mover() {
    if (direccion == "arriba") {
        y--;
    } else if (direccion == "abajo") {
        y++;
    } else if (direccion == "izquierda") {
        x--;
    } else if (direccion == "derecha") {
        x++;
    }

}


bool Jugador::puedeMoverse(Mazmorra& mazmorra, int nuevoX, int nuevoY) {
    if (nuevoX < 0 || nuevoX >= mazmorra.getFilas() || nuevoY < 0 || nuevoY >= mazmorra.getColumnas()) {
        return false; // Fuera de límites
    }
    char elemento = mazmorra.obtenerElemento(nuevoX, nuevoY);
    if (elemento == '-') {
        return true; // Espacio vacío
    }
    else if ((elemento == 'p' || elemento == 'P') && llaves > 0) {
        return true; // Puerta
    }
    else if ((elemento == 'y' || elemento == 'Y') && llavesJefe > 0) {
        return true; // Puerta Jefe
    }
    return false; // No se puede mover
}

void Jugador::atacar() {
    atacando = true;
    std::cout << "Link ataca con su espada!" << std::endl;
}

void Jugador::usarHabilidad() {
    usandoHabilidad = true;
    std::cout << "Link usa su habilidad: " << habilidad << std::endl;
}
#include <iostream>
#include <string>
#include "../include/Jugador.h"

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

Jugador::Jugador() : x(0), y(0), vida(100), dano(20){}

Jugador::Jugador(int x, int y) {
    this->x = x;
    this->y = y;
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


bool Jugador::puedeMoverse(char elemento) {
    if (elemento == 'X') {
        return false;
    }
    
    if (elemento == 'P' && llaves <= 0) {
        return false;
    }
    
    if (elemento == 'Y' && llavesJefe <= 0) {
        return false;
    }
    
    return true;
}

void Jugador::atacar() {
    atacando = true;
    std::cout << "Link ataca con su espada!" << std::endl;
}

void Jugador::usarHabilidad() {
    usandoHabilidad = true;
    std::cout << "Link usa su habilidad: " << habilidad << std::endl;
}
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


Jugador::Jugador() : x(0), y(0), vida(100), dano(20){}

Jugador::Jugador(int x, int y) {
    this->x = x;
    this->y = y;
}
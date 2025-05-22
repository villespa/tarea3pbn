#ifndef JUGADOR_H
#define JUGADOR_H

#include<iostream>
#include<string>

class Jugador
{
    int x;
    int y;
    int vida = 100;
    int dano = 20;
    int rango = 1;
    std::string habilidad;
    std::string direccion;
    bool recibiendoDano;
    int llaves;
    int llavesJefe;
    int pasos;
    int cofresAbiertos;
    int puertasAbiertas;
    int EnemigosDerrotados;
    int numBombas = 3;
    bool usandoHabilidad;
    bool atacando;
    bool enSalaJefe;
    bool haGanado;

public:
    //constructores
    Jugador();
    Jugador(int x, int y);


    //setters
    void setX(int x);
    void setY(int y);
    void cambiarVida(int vida);

    //getters
    int getX();
    int getY();
    int getVida();

};

#endif
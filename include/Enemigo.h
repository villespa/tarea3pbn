#ifndef ENEMIGO_H
#define ENEMIGO_H

#include<iostream>
#include<string>
#include<vector>

class Enemigo{
    int x;
    int y;
    int vida = 100;
    int dano = 20;
    int rango = 1;
    int frecuenciaAtaque;
    std::vector<std::pair<int, int>> patronMovimiento;
    int pasoActual;
    bool atacando;
    int xOriginal;
    int yOriginal;
    bool recibiendoDano;
    int turnosDesdeUltimoAtaque;

public:
    int getX();
    int getY();
    int getVida();
    int getDano();
    int getRango();
    int getFrecuenciaAtaque();
    Enemigo(int x, int y, std::vector<std::pair<int,int>> patronMoviemiento, int vida, int dano, int rango, int frecuenciaAtaque);
};

#endif
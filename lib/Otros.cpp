#include "../include/Otros.h"
#include "../include/SalaJefe.h"
#include "../include/Enemigo.h"
#include "../include/Mazmorra.h"
#include "../include/Boss.h"
#include "../include/Jugador.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Otros.h"

std::pair<std::vector<Mazmorra>, std::vector<SalaJefe>> Otros::cargarMazmorrasCSV(const std::string& path) {
    // Cargar mazmorras desde un archivo CSV
    std::vector<Mazmorra> mazmorras;
    std::ifstream archivo(path);
    std::vector<SalaJefe> salasJefes;
    
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo: " << path << std::endl;
        return std::make_pair(mazmorras, salasJefes);
    }
    
    std::string linea;
    int numLinea = 0;

    
    while (std::getline(archivo, linea)) {
        numLinea++;
        //std::cout << "\n=== MAZMORRA #" << numLinea << " ===\n" << std::endl;
        
        std::stringstream ss(linea);
        std::string valor;
        
        // Añadir una nueva instancia de SalaJefe al vector
        salasJefes.push_back(SalaJefe());
        
        // Leer filas y columnas de la mazmorra principal
        int filas, columnas;
        std::getline(ss, valor, ',');
        //std::cout << "Filas de la mazmorra: " << valor << std::endl;
        filas = std::stoi(valor);
        
        std::getline(ss, valor, ',');
        //std::cout << "Columnas de la mazmorra: " << valor << std::endl;
        columnas = std::stoi(valor);
        
        // Crear una matriz para el mapa
        std::vector<std::vector<char>> mapa(filas, std::vector<char>(columnas));
        
        //std::cout << "\nMapa de la mazmorra principal:" << std::endl;
        
        // // Imprimir cabecera de columnas
        // //std::cout << "    ";
        // for (int j = 0; j < columnas; j++) {
        //     //std::cout << std::setw(2) << j << " ";
        // }
        // //std::cout << std::endl;
        
        // // Imprimir línea separadora
        // //std::cout << "   ";
        // for (int j = 0; j < columnas; j++) {
        //     //std::cout << "---";
        // }
        // //std::cout << std::endl;
        
        // Leer e imprimir el mapa
        for (int i = 0; i < filas; i++) {
            // Imprimir número de fila
            //std::cout << std::setw(2) << i << " |";
            
            for (int j = 0; j < columnas; j++) {
                std::getline(ss, valor, ',');
                mapa[i][j] = valor[0];
                //std::cout << " " << mapa[i][j] << " ";
            

                // Si encontramos una entrada al jefe
                if (valor[0] == 'E') {
                    salasJefes[numLinea-1].setPosicionEntradaJefe(i, j);
                }
            }

            // Salto de línea al final de cada fila
            //std::cout << std::endl;
        }


        // // Mostrar entradas encontradas
        // for (int i = 0; i < filas; i++) {
        //     for (int j = 0; j < columnas; j++) {
        //         if (mapa[i][j] == 'E') {
        //             //std::cout << "Entrada al jefe en [" << i << ", " << j << "]" << std::endl;
        //         }
        //     }
        // }
        
        // Leer dimensiones de la sala del jefe
        std::getline(ss, valor, ',');
        //std::cout << "\nFilas de la sala del jefe: " << valor << std::endl;
        salasJefes[numLinea-1].setFilas(std::stoi(valor));
        
        std::getline(ss, valor, ',');
        //std::cout << "Columnas de la sala del jefe: " << valor << std::endl;
        salasJefes[numLinea-1].setColumnas(std::stoi(valor));
        
        // Redimensionar el mapa de la sala del jefe
        salasJefes[numLinea-1].mapa.resize(salasJefes[numLinea-1].getFilas(), 
                                         std::vector<char>(salasJefes[numLinea-1].getColumnas()));
        
        //std::cout << "\nMapa de la sala del jefe:" << std::endl;
        
        // Imprimir cabecera de columnas para la sala del jefe
        //std::cout << "    ";
        // for (int j = 0; j < salasJefes[numLinea-1].getColumnas(); j++) {
        //     //std::cout << std::setw(2) << j << " ";
        // }
        // //std::cout << std::endl;
        
        // // Imprimir línea separadora
        // //std::cout << "   ";
        // for (int j = 0; j < salasJefes[numLinea-1].getColumnas(); j++) {
        //     //std::cout << "---";
        // }
        // //std::cout << std::endl;
        
        // Leer e imprimir el mapa de la sala del jefe
        for (int i = 0; i < salasJefes[numLinea-1].getFilas(); i++) {
            // Imprimir número de fila
            //std::cout << std::setw(2) << i << " |";
            
            for (int j = 0; j < salasJefes[numLinea-1].getColumnas(); j++) {
                std::getline(ss, valor, ',');
                salasJefes[numLinea-1].mapa[i][j] = valor[0];
                //std::cout << " " << salasJefes[numLinea-1].mapa[i][j] << " ";
            }
            // Salto de línea al final de cada fila
            //std::cout << std::endl;
        }
        
        // Crear la mazmorra con el mapa cargado (sin enemigos por ahora)
        std::vector<Enemigo> enemigosVacios; // Enemigos se cargarán por separado
        Mazmorra mazmorra(filas, columnas, mapa, enemigosVacios);
        
        // Agregar la mazmorra al vector
        mazmorras.push_back(mazmorra);
        
        //std::cout << "\n--- Mazmorra #" << numLinea << " procesada ---" << std::endl;
    }
    
    if (mazmorras.empty()) {
        std::cerr << "No se encontraron mazmorras en el archivo: " << path << std::endl;
    } 
    // else {
    //     std::cout << "\nMazmorras cargadas correctamente desde: " << path << std::endl;
    //     std::cout << "Total de mazmorras cargadas: " << mazmorras.size() << std::endl;
    // }
    
    return std::make_pair(mazmorras, salasJefes);
}


std::pair<std::vector<Enemigo>, std::vector<Boss>> Otros::cargarEnemigosCSV(const std::string& path) {
    std::vector<Enemigo> enemigos;
    std::ifstream archivo(path);
    std::vector<Boss> jefes;
    //std::vector<SalaJefe> salasJefes = cargarMazmorrasCSV(path).second; // Cargar las salas de jefes desde el archivo


    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo: " << path << std::endl;
        return std::make_pair(enemigos, jefes);
    }
    
    std::string linea;
    int numLinea = 0;

    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string valor;
        numLinea++;
        std::cout << "\n=== Procesando enemigo #" << numLinea << " ===\n" << std::endl;

        
        
        // Leer las propiedades del enemigo
        int x, y, numMovimientos, vida, dano, rango, frecuenciaAtaque;
        std::vector<std::pair<int,int>> patronMovimiento;
        
        //while (ss.peek() != EOF) {
        //    std::string valorPeek;

        //} 

        std::getline(ss, valor, ',');
        y = std::stoi(valor);
        std::cout << "Posición Y: " << y << std::endl;
        
        std::getline(ss, valor, ',');
        x = std::stoi(valor);
        std::cout << "Posición X: " << x << std::endl;
        
        std::getline(ss, valor, ',');
        numMovimientos = std::stoi(valor);
        std::cout << "Número de movimientos: " << numMovimientos << std::endl;

        std::cout << "Patrón de movimiento:" << std::endl;
        for (int i = 0; i < numMovimientos; i++) {
            std::getline(ss, valor, ',');
            int xMovimiento = std::stoi(valor);
            
            std::getline(ss, valor, ',');
            int yMovimiento = std::stoi(valor);
            
            patronMovimiento.push_back(std::make_pair(yMovimiento, xMovimiento));
            std::cout << "  Paso " << (i+1) << ": (" << yMovimiento << ", " << xMovimiento << ")" << std::endl;
        }
        
        std::getline(ss, valor, ',');
        vida = std::stoi(valor);
        std::cout << "Vida: " << vida << std::endl;
        
        std::getline(ss, valor, ',');
        dano = std::stoi(valor);
        std::cout << "Daño: " << dano << std::endl;
        
        std::getline(ss, valor, ',');
        rango = std::stoi(valor);
        std::cout << "Rango: " << rango << std::endl;
        
        std::getline(ss, valor, ',');
        frecuenciaAtaque = std::stoi(valor);
        std::cout << "Frecuencia de ataque: " << frecuenciaAtaque << std::endl;
        
        // Crear el enemigo y agregarlo al vector
        Enemigo enemigo(x, y, patronMovimiento, vida, dano, rango, frecuenciaAtaque);
        enemigos.push_back(enemigo);
        std::cout << "Enemigo creado y agregado a la lista." << std::endl;
    }
    
    if (enemigos.empty()) {
        std::cerr << "No se encontraron enemigos en el archivo: " << path << std::endl;
    } 
    // else {
    //     std::cout << "\nEnemigos cargados correctamente desde: " << path << std::endl;
    //     std::cout << "Total de enemigos cargados: " << enemigos.size() << std::endl;
    // }
    return std::make_pair(enemigos, jefes);
}


void Otros::mostrarMazmorras(std::vector<Mazmorra> mazmorras)
{
    std::cout << "\n=== Mazmorras ===" << std::endl;
    for (long unsigned int i = 0; i < mazmorras.size(); ++i) {
        std::cout << "Mazmorras #" << i + 1 << std::endl;
        mazmorras[i].mostrarMapa();
        std::cout << std::endl;

    }
}
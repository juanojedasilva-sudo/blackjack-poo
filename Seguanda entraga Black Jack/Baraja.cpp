/**
 * @file Baraja.cpp
 * @brief Implementación de la clase Baraja para el juego de Blackjack.
 *
 * @course Fundamentos de Programación Orientada a Objetos
 * @institution Universidad del Valle
 */

#include "Baraja.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>

// Nombres y valores de las cartas (índice 0-12: 2..10, J, Q, K, A)
static const std::string NOMBRES[] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
static const int         VALORES[] = { 2,  3,  4,  5,  6,  7,  8,  9,  10, 10, 10, 10, 11};

// ---- Métodos privados ----

void Baraja::crearCorazones() {
    for (int i = 0; i < 13; i++)
        cartas.push_back(Carta(NOMBRES[i], VALORES[i], "Corazones"));
}

void Baraja::crearDiamantes() {
    for (int i = 0; i < 13; i++)
        cartas.push_back(Carta(NOMBRES[i], VALORES[i], "Diamantes"));
}

void Baraja::crearTreboles() {
    for (int i = 0; i < 13; i++)
        cartas.push_back(Carta(NOMBRES[i], VALORES[i], "Treboles"));
}

void Baraja::crearPicas() {
    for (int i = 0; i < 13; i++)
        cartas.push_back(Carta(NOMBRES[i], VALORES[i], "Picas"));
}

// ---- Constructor ----

Baraja::Baraja() : siguienteArticulo(0) {
    reiniciarBaraja();
}

// ---- Métodos públicos ----

void Baraja::reiniciarBaraja() {
    cartas.clear();
    siguienteArticulo = 0;
    crearCorazones();
    crearDiamantes();
    crearTreboles();
    crearPicas();
}

int Baraja::obtenerTamaño() const {
    return static_cast<int>(cartas.size()) - siguienteArticulo;
}

Carta Baraja::obtenerSiguienteCarta() {
    if (siguienteArticulo >= static_cast<int>(cartas.size())) {
        // Mazo agotado: reiniciar y mezclar automáticamente
        reiniciarBaraja();
        barajarMazo();
    }
    return cartas[siguienteArticulo++];
}

void Baraja::barajarMazo() {
    std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)));
    std::shuffle(cartas.begin(), cartas.end(), rng);
    siguienteArticulo = 0;
}

void Baraja::mostrarBaraja() const {
    for (int i = siguienteArticulo; i < static_cast<int>(cartas.size()); i++) {
        cartas[i].mostrar();
        std::cout << "\n";
    }
}

bool Baraja::mazocompleto() const {
    return siguienteArticulo == 0;
}

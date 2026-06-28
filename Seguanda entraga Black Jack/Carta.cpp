/**
 * @file Carta.cpp
 * @brief Implementación de la clase Carta para el juego de Blackjack.
 *
 * @course Fundamentos de Programación Orientada a Objetos
 * @institution Universidad del Valle
 */

#include "Carta.h"
#include <iostream>

// ---- Constructores ----

Carta::Carta() : nombre(""), valor(0), tipo("") {}

Carta::Carta(const std::string& nombre, int valor, const std::string& tipo)
    : nombre(nombre), valor(valor), tipo(tipo) {}

// ---- Getters ----

std::string Carta::obtenerNombre() const {
    return nombre;
}

int Carta::obtenerValor() const {
    return valor;
}

std::string Carta::obtenerTipo() const {
    return tipo;
}

// ---- Setters ----

void Carta::establecerNombre(const std::string& nombre) {
    this->nombre = nombre;
}

void Carta::establecerValor(int valor) {
    this->valor = valor;
}

void Carta::establecerTipo(const std::string& tipo) {
    this->tipo = tipo;
}

// ---- Mostrar ----

void Carta::mostrar() const {
    std::cout << "[" << nombre << " de " << tipo << " (val:" << valor << ")]";
}

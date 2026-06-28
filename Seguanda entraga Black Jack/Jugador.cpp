/**
 * @file Jugador.cpp
 * @brief Implementación de la clase Jugador para el juego de Blackjack.
 *
 * @course Fundamentos de Programación Orientada a Objetos
 * @institution Universidad del Valle
 */

#include "Jugador.h"
#include <iostream>

// ---- Constructor ----

Jugador::Jugador(double dineroInicial, int limite)
    : limite(limite), dinero(dineroInicial) {}

// ---- Consultas de estado ----

bool Jugador::masCartas() const {
    return mano.obtenerValor() <= limite;
}

bool Jugador::sePaso() const {
    return mano.obtenerValor() > 21;
}

bool Jugador::tieneBlackjack() const {
    return mano.obtenerCantidadCartas() == 2 && mano.obtenerValor() == 21;
}

// ---- Interacción con la mano ----

void Jugador::obtenerCarta(const Carta& carta) {
    mano.agregarAMano(carta);
}

void Jugador::mostrarMano() const {
    mano.mostrarMano();
}

int Jugador::obtenerValorMano() const {
    return mano.obtenerValor();
}

void Jugador::limpiarMano() {
    mano.limpiarMano();
}

// ---- Dinero ----

double Jugador::obtenerDinero() const {
    return dinero;
}

bool Jugador::apostar(double monto) {
    if (monto > dinero) return false;
    dinero -= monto;
    return true;
}

void Jugador::ganar(double monto) {
    dinero += monto;
}

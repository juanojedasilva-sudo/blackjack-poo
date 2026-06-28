/**
 * @file Crupier.cpp
 * @brief Implementación de la clase Crupier para el juego de Blackjack.
 *
 * @course Fundamentos de Programación Orientada a Objetos
 * @institution Universidad del Valle
 */

#include "Crupier.h"
#include <iostream>

// ---- Constructor ----

Crupier::Crupier() {
    baraja.barajarMazo();
}

// ---- Gestión del juego ----

void Crupier::empezarJuego(Jugador& jugador) {
    // Limpiar manos anteriores
    iniciarNuevaMano(jugador);

    // Repartir 2 cartas a cada uno (intercaladas, como en el blackjack real)
    jugador.obtenerCarta(obtenerCarta());
    mano.agregarAMano(obtenerCarta());
    jugador.obtenerCarta(obtenerCarta());
    mano.agregarAMano(obtenerCarta());
}

Carta Crupier::obtenerCarta() {
    return baraja.obtenerSiguienteCarta();
}

void Crupier::darCarta(Jugador& jugador) {
    jugador.obtenerCarta(obtenerCarta());
}

// ---- Mostrar ----

void Crupier::mostrarMano() const {
    mano.mostrarMano();
}

void Crupier::mostrarManoParcial() const {
    mano.mostrarPrimeraCarta();
}

// ---- Estado ----

int Crupier::obtenerValorMano() const {
    return mano.obtenerValor();
}

bool Crupier::masCartas() const {
    return mano.obtenerValor() < LIMITE_CRUPIER;
}

bool Crupier::sePaso() const {
    return mano.obtenerValor() > 21;
}

// ---- Turno del crupier ----

void Crupier::jugarTurno() {
    std::cout << "\n--- Turno del Crupier ---\n";
    std::cout << "Mano del crupier: ";
    mostrarMano();

    while (masCartas()) {
        std::cout << "El crupier pide carta...\n";
        mano.agregarAMano(obtenerCarta());
        std::cout << "Mano del crupier: ";
        mostrarMano();
    }

    if (sePaso()) {
        std::cout << "El crupier se PASA de 21!\n";
    } else {
        std::cout << "El crupier se PLANTA con " << obtenerValorMano() << ".\n";
    }
}

// ---- Determinar ganador ----

void Crupier::determinarGanador(Jugador& jugador, double apuesta) {
    int valorJugador  = jugador.obtenerValorMano();
    int valorCrupier  = obtenerValorMano();

    std::cout << "\n=== Resultado ===\n";
    std::cout << "Jugador: " << valorJugador << "  |  Crupier: " << valorCrupier << "\n";

    if (jugador.sePaso()) {
        std::cout << "El jugador se paso. El crupier GANA.\n";
    } else if (sePaso()) {
        std::cout << "El crupier se paso. El jugador GANA!\n";
        jugador.ganar(apuesta * 2);
    } else if (valorJugador > valorCrupier) {
        std::cout << "El jugador GANA!\n";
        jugador.ganar(apuesta * 2);
    } else if (valorCrupier > valorJugador) {
        std::cout << "El crupier GANA.\n";
    } else {
        // Empate: el jugador recupera su apuesta (regla del documento)
        std::cout << "EMPATE. El jugador recupera su apuesta.\n";
        jugador.ganar(apuesta);
    }
}

// ---- Nueva mano ----

void Crupier::iniciarNuevaMano(Jugador& jugador) {
    mano.limpiarMano();
    jugador.limpiarMano();

    // Si quedan pocas cartas, reiniciar y mezclar
    if (baraja.obtenerTamaño() < 10) {
        std::cout << "[Baraja agotada, reiniciando mazo...]\n";
        baraja.reiniciarBaraja();
        baraja.barajarMazo();
    }
}

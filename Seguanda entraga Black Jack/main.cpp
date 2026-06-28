/**
 * @file main.cpp
 * @brief Programa de prueba (modelo de concepto) para el juego de Blackjack.
 *
 * Primera versión que demuestra que el diagrama de clases funciona:
 *  - Se crea un Jugador y un Crupier
 *  - Se juega una ronda completa: reparto, turno del jugador, turno del crupier
 *  - Se determina el ganador
 *
 * @course Fundamentos de Programación Orientada a Objetos
 * @institution Universidad del Valle
 */

#include <iostream>
#include <string>
#include "Jugador.h"
#include "Crupier.h"

int main() {
    std::cout << "========================================\n";
    std::cout << "   BLACKJACK - Modelo de Concepto v1.0  \n";
    std::cout << "========================================\n\n";

    // Crear jugador con $100 y crupier
    Jugador jugador(100.0);
    Crupier crupier;

    char seguir = 's';

    while (seguir == 's' || seguir == 'S') {
        // --- Apuesta ---
        double apuesta = 0;
        std::cout << "Dinero disponible: $" << jugador.obtenerDinero() << "\n";
        std::cout << "¿Cuanto deseas apostar? ";
        std::cin >> apuesta;

        if (apuesta <= 0 || !jugador.apostar(apuesta)) {
            std::cout << "Apuesta invalida o fondos insuficientes.\n";
            break;
        }

        // --- Repartir cartas iniciales ---
        crupier.empezarJuego(jugador);

        std::cout << "\n--- Mano inicial ---\n";
        std::cout << "Crupier muestra: ";
        crupier.mostrarManoParcial();
        std::cout << "Tu mano:         ";
        jugador.mostrarMano();

        // Verificar blackjack inmediato
        if (jugador.tieneBlackjack()) {
            std::cout << "¡BLACKJACK! Ganas automaticamente.\n";
            jugador.ganar(apuesta * 2.5); // pago 3:2
            crupier.iniciarNuevaMano(jugador);
        } else {
            // --- Turno del jugador ---
            std::cout << "\n--- Tu turno ---\n";
            char decision;
            while (!jugador.sePaso()) {
                std::cout << "Tu mano: ";
                jugador.mostrarMano();
                std::cout << "¿Pedir carta? (s/n): ";
                std::cin >> decision;

                if (decision == 's' || decision == 'S') {
                    crupier.darCarta(jugador);
                } else {
                    std::cout << "Te plantas con " << jugador.obtenerValorMano() << ".\n";
                    break;
                }
            }

            if (jugador.sePaso()) {
                std::cout << "¡Te pasaste de 21!\n";
                crupier.determinarGanador(jugador, apuesta);
            } else {
                // --- Turno del crupier ---
                crupier.jugarTurno();
                crupier.determinarGanador(jugador, apuesta);
            }
        }

        // --- ¿Continuar? ---
        std::cout << "\nDinero actual: $" << jugador.obtenerDinero() << "\n";
        if (jugador.obtenerDinero() <= 0) {
            std::cout << "Te quedaste sin dinero. Fin del juego.\n";
            break;
        }
        std::cout << "¿Jugar otra ronda? (s/n): ";
        std::cin >> seguir;
        std::cout << "\n";
    }

    std::cout << "\nGracias por jugar. Dinero final: $" << jugador.obtenerDinero() << "\n";
    return 0;
}

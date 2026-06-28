/**
 * @file Crupier.h
 * @brief Definición de la clase Crupier para el juego de Blackjack.
 *
 * Clase CRC - Crupier
 * -------------------------------------------------
 * Clase: Crupier
 * Responsabilidades:
 *   - Inicia/reinicia el juego (baraja y reparte cartas iniciales)
 *   - Obtiene cartas de la Baraja y las da a los jugadores
 *   - Muestra su propia mano
 *   - Calcula el valor de su mano
 *   - Decide si quiere más cartas (se planta en 17 o más, regla estándar)
 *   - Determina el ganador de la ronda
 *   - Inicia una nueva mano
 * Colaboraciones:
 *   - Baraja (la consulta para obtener cartas)
 *   - Jugador (le reparte cartas e interactúa)
 *   - Mano (la posee)
 * -------------------------------------------------
 *
 * @course Fundamentos de Programación Orientada a Objetos
 * @institution Universidad del Valle
 */

#ifndef CRUPIER_H
#define CRUPIER_H

#include "Baraja.h"
#include "Jugador.h"
#include "Mano.h"

class Crupier {
private:
    Mano   mano;    ///< Mano del crupier
    Baraja baraja;  ///< Baraja con la que se juega

    static const int LIMITE_CRUPIER = 17; ///< El crupier se planta en 17 o más

public:
    /**
     * @brief Constructor. Inicializa el crupier con una baraja nueva y barajada.
     */
    Crupier();

    /**
     * @brief Inicia una nueva ronda: limpia las manos y reparte 2 cartas a cada uno.
     * @param jugador Referencia al jugador participante.
     */
    void empezarJuego(Jugador& jugador);

    /**
     * @brief Obtiene la siguiente carta de la baraja.
     * @return La carta obtenida.
     */
    Carta obtenerCarta();

    /**
     * @brief Da una carta al jugador desde la baraja.
     * @param jugador Jugador que recibe la carta.
     */
    void darCarta(Jugador& jugador);

    /**
     * @brief Muestra la mano del crupier en consola (todas las cartas).
     */
    void mostrarMano() const;

    /**
     * @brief Muestra solo la primera carta del crupier (mano parcialmente oculta).
     */
    void mostrarManoParcial() const;

    /**
     * @brief Retorna el valor de la mano del crupier.
     * @return Valor de la mano.
     */
    int obtenerValorMano() const;

    /**
     * @brief Indica si el crupier desea otra carta (valor < LIMITE_CRUPIER).
     * @return true si pide carta.
     */
    bool masCartas() const;

    /**
     * @brief Indica si el crupier se pasó de 21.
     * @return true si el valor > 21.
     */
    bool sePaso() const;

    /**
     * @brief El crupier juega su turno automáticamente (pide cartas hasta alcanzar el límite).
     */
    void jugarTurno();

    /**
     * @brief Determina y muestra el resultado de la ronda.
     * @param jugador  Referencia al jugador.
     * @param apuesta  Monto apostado en la ronda.
     */
    void determinarGanador(Jugador& jugador, double apuesta);

    /**
     * @brief Reinicia las manos para una nueva ronda (sin re-barajar).
     * @param jugador Referencia al jugador.
     */
    void iniciarNuevaMano(Jugador& jugador);
};

#endif // CRUPIER_H

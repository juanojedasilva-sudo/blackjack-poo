/**
 * @file Jugador.h
 * @brief Definición de la clase Jugador para el juego de Blackjack.
 *
 * Clase CRC - Jugador
 * -------------------------------------------------
 * Clase: Jugador
 * Responsabilidades:
 *   - Decide si quiere más cartas (pedir o plantarse)
 *   - Muestra su mano
 *   - Conoce el valor de su mano
 *   - Sabe cuántas cartas tiene
 *   - Sabe si se pasó de 21, llegó a 21 (blackjack) o está por debajo
 *   - Gestiona su dinero y apuestas
 * Colaboraciones:
 *   - Mano (la posee y consulta)
 *   - Crupier (interactúa con él)
 * -------------------------------------------------
 *
 * @course Fundamentos de Programación Orientada a Objetos
 * @institution Universidad del Valle
 */

#ifndef JUGADOR_H
#define JUGADOR_H

#include "Mano.h"
#include <string>

class Jugador {
private:
    int    limite; ///< Límite mínimo en el que el jugador se planta (por defecto 16)
    double dinero; ///< Dinero disponible para apostar
    Mano   mano;   ///< La mano actual del jugador

public:
    /**
     * @brief Constructor. Inicializa el jugador con dinero inicial.
     * @param dineroInicial Cantidad de dinero con la que empieza el jugador.
     * @param limite        Valor de mano en el que el jugador se planta automáticamente.
     */
    explicit Jugador(double dineroInicial = 100.0, int limite = 16);

    // ---- Consultas de estado ----

    /**
     * @brief Indica si el jugador desea otra carta.
     *        Retorna true si el valor de la mano está por debajo del límite.
     * @return true si pide carta, false si se planta.
     */
    bool masCartas() const;

    /**
     * @brief Indica si el jugador se pasó de 21.
     * @return true si el valor de la mano > 21.
     */
    bool sePaso() const;

    /**
     * @brief Indica si el jugador tiene blackjack (exactamente 21 con 2 cartas).
     * @return true si cumple la condición de blackjack.
     */
    bool tieneBlackjack() const;

    // ---- Interacción con la mano ----

    /**
     * @brief Agrega una carta a la mano del jugador.
     * @param carta Carta recibida del crupier.
     */
    void obtenerCarta(const Carta& carta);

    /**
     * @brief Muestra la mano del jugador en consola.
     */
    void mostrarMano() const;

    /**
     * @brief Retorna el valor total de la mano del jugador.
     * @return Valor de la mano.
     */
    int obtenerValorMano() const;

    /**
     * @brief Limpia la mano para la siguiente ronda.
     */
    void limpiarMano();

    // ---- Dinero ----

    /**
     * @brief Retorna el dinero disponible del jugador.
     */
    double obtenerDinero() const;

    /**
     * @brief Realiza una apuesta. Resta el monto del dinero disponible.
     * @param monto Cantidad a apostar.
     * @return true si la apuesta pudo realizarse (hay suficiente dinero).
     */
    bool apostar(double monto);

    /**
     * @brief Suma ganancias al dinero del jugador.
     * @param monto Cantidad ganada.
     */
    void ganar(double monto);
};

#endif // JUGADOR_H

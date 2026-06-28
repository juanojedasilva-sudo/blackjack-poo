/**
 * @file Mano.h
 * @brief Definición de la clase Mano para el juego de Blackjack.
 *
 * Clase CRC - Mano
 * -------------------------------------------------
 * Clase: Mano
 * Responsabilidades:
 *   - Almacena las cartas que tiene un jugador o el crupier
 *   - Calcula y retorna el valor total de la mano
 *     (maneja el As como 1 u 11 según conveniencia)
 *   - Sabe cuántas cartas hay en la mano
 *   - Muestra la mano en consola
 * Colaboraciones:
 *   - Carta (la almacena)
 *   - Jugador (la posee)
 *   - Crupier (la posee)
 * -------------------------------------------------
 *
 * @course Fundamentos de Programación Orientada a Objetos
 * @institution Universidad del Valle
 */

#ifndef MANO_H
#define MANO_H

#include "Carta.h"
#include <vector>

class Mano {
private:
    std::vector<Carta> mano;   ///< Cartas actualmente en la mano
    int                valor;  ///< Valor calculado de la mano (se recalcula al agregar)

    /**
     * @brief Recalcula el valor total de la mano.
     *        Ajusta el As de 11 a 1 si el total supera 21.
     */
    void recalcularValor();

public:
    /**
     * @brief Constructor. Inicializa una mano vacía.
     */
    Mano();

    /**
     * @brief Retorna el valor total de la mano.
     * @return Valor de la mano (con lógica del As aplicada).
     */
    int obtenerValor() const;

    /**
     * @brief Retorna el número de cartas en la mano.
     * @return Cantidad de cartas.
     */
    int obtenerCantidadCartas() const;

    /**
     * @brief Agrega una carta a la mano y recalcula el valor.
     * @param carta La carta a agregar.
     */
    void agregarAMano(const Carta& carta);

    /**
     * @brief Limpia la mano para comenzar una nueva ronda.
     */
    void limpiarMano();

    /**
     * @brief Muestra todas las cartas de la mano y el valor total en consola.
     */
    void mostrarMano() const;

    /**
     * @brief Muestra solo la primera carta (para la mano oculta del crupier).
     */
    void mostrarPrimeraCarta() const;
};

#endif // MANO_H

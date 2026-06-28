/**
 * @file Baraja.h
 * @brief Definición de la clase Baraja para el juego de Blackjack.
 *
 * Clase CRC - Baraja
 * -------------------------------------------------
 * Clase: Baraja
 * Responsabilidades:
 *   - Contiene un mazo completo de 52 cartas
 *   - Puede barajar (aleatorizar) las cartas
 *   - Reparte la siguiente carta disponible
 *   - Sabe cuántas cartas quedan en el mazo
 *   - Puede reiniciarse a un mazo completo
 * Colaboraciones:
 *   - Carta (la contiene)
 *   - Crupier (la usa para repartir)
 * -------------------------------------------------
 *
 * @course Fundamentos de Programación Orientada a Objetos
 * @institution Universidad del Valle
 */

#ifndef BARAJA_H
#define BARAJA_H

#include "Carta.h"
#include <vector>

class Baraja {
private:
    std::vector<Carta> cartas;         ///< Conjunto de todas las cartas del mazo
    int                siguienteArticulo; ///< Índice de la próxima carta a repartir

    // Métodos privados para construir el mazo por palo
    void crearCorazones();
    void crearDiamantes();
    void crearTreboles();
    void crearPicas();

public:
    /**
     * @brief Constructor. Crea e inicializa un mazo completo de 52 cartas.
     */
    Baraja();

    /**
     * @brief Reinicia el mazo: vuelve a construir las 52 cartas y resetea el índice.
     */
    void reiniciarBaraja();

    /**
     * @brief Retorna el número de cartas que quedan por repartir.
     * @return Cantidad de cartas restantes.
     */
    int obtenerTamaño() const;

    /**
     * @brief Reparte la siguiente carta del mazo (la extrae y avanza el índice).
     * @return La carta en la posición actual.
     * @pre Debe haber al menos una carta disponible.
     */
    Carta obtenerSiguienteCarta();

    /**
     * @brief Mezcla aleatoriamente las cartas del mazo.
     */
    void barajarMazo();

    /**
     * @brief Muestra todas las cartas del mazo en consola (para depuración).
     */
    void mostrarBaraja() const;

    /**
     * @brief Indica si el mazo está completo (las 52 cartas sin repartir).
     * @return true si ninguna carta ha sido repartida.
     */
    bool mazocompleto() const;
};

#endif // BARAJA_H

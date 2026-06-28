/**
 * @file Carta.h
 * @brief Definición de la clase Carta para el juego de Blackjack.
 *
 * Clase CRC - Carta
 * -------------------------------------------------
 * Clase: Carta
 * Responsabilidades:
 *   - Conoce su nombre (valor nominal: "2".."10", "J", "Q", "K", "A")
 *   - Conoce su valor numérico en el juego (1-11)
 *   - Conoce su tipo o palo (Corazones, Diamantes, Tréboles, Picas)
 * Colaboraciones:
 *   - Baraja (la contiene y la reparte)
 *   - Mano (la almacena)
 * -------------------------------------------------
 *
 * @course Fundamentos de Programación Orientada a Objetos
 * @institution Universidad del Valle
 */

#ifndef CARTA_H
#define CARTA_H

#include <string>

class Carta {
private:
    std::string nombre;  ///< Nombre de la carta: "2".."10", "J", "Q", "K", "A"
    int         valor;   ///< Valor numérico de la carta en el juego (1-11)
    std::string tipo;    ///< Palo de la carta: "Corazones", "Diamantes", "Treboles", "Picas"

public:
    /**
     * @brief Constructor por defecto. Crea una carta vacía.
     */
    Carta();

    /**
     * @brief Constructor con parámetros.
     * @param nombre Nombre de la carta (ej. "A", "K", "7")
     * @param valor  Valor numérico de la carta
     * @param tipo   Palo de la carta
     */
    Carta(const std::string& nombre, int valor, const std::string& tipo);

    // ---- Getters ----

    /** @brief Retorna el nombre de la carta. */
    std::string obtenerNombre() const;

    /** @brief Retorna el valor numérico de la carta. */
    int obtenerValor() const;

    /** @brief Retorna el palo de la carta. */
    std::string obtenerTipo() const;

    // ---- Setters ----

    /** @brief Establece el nombre de la carta. */
    void establecerNombre(const std::string& nombre);

    /** @brief Establece el valor de la carta. */
    void establecerValor(int valor);

    /** @brief Establece el palo de la carta. */
    void establecerTipo(const std::string& tipo);

    /**
     * @brief Muestra la carta en consola con formato legible.
     */
    void mostrar() const;
};

#endif // CARTA_H

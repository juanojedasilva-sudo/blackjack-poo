/**
 * @file Mano.cpp
 * @brief Implementación de la clase Mano para el juego de Blackjack.
 *
 * @course Fundamentos de Programación Orientada a Objetos
 * @institution Universidad del Valle
 */

#include "Mano.h"
#include <iostream>

// ---- Constructor ----

Mano::Mano() : valor(0) {}

// ---- Privado ----

void Mano::recalcularValor() {
    valor = 0;
    int ases = 0;

    for (const auto& carta : mano) {
        valor += carta.obtenerValor();
        if (carta.obtenerNombre() == "A") ases++;
    }

    // Si se pasa de 21 y hay un As contado como 11, reducirlo a 1
    while (valor > 21 && ases > 0) {
        valor -= 10;
        ases--;
    }
}

// ---- Métodos públicos ----

int Mano::obtenerValor() const {
    return valor;
}

int Mano::obtenerCantidadCartas() const {
    return static_cast<int>(mano.size());
}

void Mano::agregarAMano(const Carta& carta) {
    mano.push_back(carta);
    recalcularValor();
}

void Mano::limpiarMano() {
    mano.clear();
    valor = 0;
}

void Mano::mostrarMano() const {
    for (const auto& carta : mano) {
        carta.mostrar();
        std::cout << " ";
    }
    std::cout << "  => Total: " << valor << "\n";
}

void Mano::mostrarPrimeraCarta() const {
    if (!mano.empty()) {
        mano[0].mostrar();
        std::cout << " [carta oculta]\n";
    }
}

#pragma once

#include <iostream>
#include <vector>
#include "Pokemon.h"
class Trainer {
    ///Klasa trainer odpowiedzialna za przechowywanie informacji o pokemonach wybranych przez gracza
private:
    ///Wector zapamietujacy jakie pokemony zostały wybrane przez gracza
    std::vector<Pokemon>ownedpokemons;
public:
    ///Kontruktor klasy
    Trainer();
    ///Destruktor klasy
    virtual ~Trainer();
    ///Funkcja ktora zwraca obiekt Pokemon znajdujacy sie w wektore "ownedpokemons" na danym indeksie
    ///@param index na ktorym int indexie ma byc zwrocony pokemon
    Pokemon& pokemon(int index);
    ///Funckja dodajaca obiekt Pokemon do wektora "ownedpokemons"
    ///@param pokemon ktory pokemon ma byc dodany do wektora "ownedpokemons"
    void addpokemon(Pokemon pokemon);
    ///Funckja zwracajaca rozmiar wektora "ownedpokemons"
    int sizeofpokemons();
    ///Funckja zwracajaca wektor "ownedpokemons"
    vector<Pokemon>ownedpokemon();
};



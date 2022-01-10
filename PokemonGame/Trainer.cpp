
#include "Trainer.h"

Trainer::Trainer() {
    ownedpokemons.reserve(6);
}
Trainer::~Trainer() {

}

void Trainer::addpokemon(Pokemon pokemon) {
    this->ownedpokemons.push_back(pokemon);
}

int Trainer::sizeofpokemons() {
    return ownedpokemons.size();
}

Pokemon& Trainer::pokemon(int index) {
    return ownedpokemons[index];
}

vector<Pokemon> Trainer::ownedpokemon() {
    return this->ownedpokemons;
}
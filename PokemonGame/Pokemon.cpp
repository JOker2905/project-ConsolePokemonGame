
#include "Pokemon.h"

Pokemon::Pokemon() {
    this->name = "";
    this->strength = 0;
    this->dexterity = 0;
    this->hp = 0;
    this->hpmax = 0;
    this->exp = 0;
    this->expNext = 0;
    this->pokemontype = "";
    this->spiecialpowername = "";
}
Pokemon::Pokemon(string name, int strength, int dexterity, int hp, string pokemontype, string specialpowername) {
    this->name = name;
    this->strength = strength;
    this->dexterity = dexterity;
    this->hp = hp;
    this->hpmax = hp;
    this->exp = 0;
    this->expNext = 10;
    this->pokemontype = pokemontype;
    this->spiecialpowername = specialpowername;
}
Pokemon::Pokemon(string name, int strength, int dexterity, int hp, string pokemontype) {
    this->name = name;
    this->strength = strength;
    this->dexterity = dexterity;
    this->hp = hp;
    this->hpmax = hp;
    this->pokemontype = pokemontype;
}
Pokemon::~Pokemon() {
}

void Pokemon::gainExp(int exp) {
    this->exp += exp;
}

void Pokemon::evolve() {
    if (this->exp >= this->expNext) {
        this->exp = 0;
        this->expNext+=10;
    }
}
void Pokemon::takeDamage(int damage) {
    this->hp -= damage;
    if (this->hp <= 0) {
        this->hp = 0;
    }
}

void Pokemon::ImproveStrength(int strength) {
    this->strength += strength;
}

void Pokemon::ImproveDexterity(int dexterity) {
    this->dexterity += dexterity;
}

void Pokemon::ImproveHp(int hp) {
    this->hpmax += hp;
    this->hp += hp;
}

void Pokemon::restorehp() {
    int hptorestore = this->hpmax / 2;
    this->hp += hptorestore;
    if (this->hp > this->hpmax) {
        this->hp = this->hpmax;
    }
}


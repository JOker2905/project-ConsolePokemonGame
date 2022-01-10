#pragma once

#include <iostream>
using namespace std;
class Pokemon {
    ///Klasa odpowiedzialna za przechowywanie informacji o pokemonach dostepnych w grze
private:
    ///Zmienna przechowujaca nazwe pokemona
    std::string name;
    ///Zmienna przechowujaca sila pokemona
    int strength;
    ///Zmienna przechowujaca zrecznosc pokemona
    int dexterity;
    ///Zmienna przechowujaca zycie pokemona
    int hp;
    ///Zmienna przechowujaca maksymalne zycie pokemona
    int hpmax;
    ///Zmienna przechowujaca punkty doswiadczenia pokemona
    int exp;
    ///Zmienna przechowujaca ile jest potrzebnych punktow doswiadczenia do ewolucji pokemona
    int expNext;
    ///Zmienna przechowujaca typ pokemona
    std::string pokemontype;
    ///Zmienna przechowujaca nazwe mocy specjalnej
    std::string spiecialpowername;
public:
    ///Kontruktor bazowy klasy pokemon
    Pokemon();
    ///Konstruktor klasy pokemon z poszczegolnymi danymi charakterystycznimi dla danego pokemona
    ///@param dexterity zrecznosc odpowiadajaca unikowi podczas ataku
    ///@param hp zycie odpowiadajace jak duzo obrazen moze zniesc pokemon
    ///@param name nazwa pokemona
    ///@param pokemontype typ pokemona
    ///@param specialpowername nazwa specjalnej umiejetnosci pokemona
    ///@param strength sila odpowiadajaca temu ile obrazen moze zadac pokemon podczas ataku
    Pokemon(string name, int strength, int dexterity, int hp, string pokemontype, string specialpowername);
    ///Konstruktor klasy pokemon dla przeciwnikow z poszczegolnymi danymi charakterystycznimi dla danego pokemona
    ///@param dexterity zrecznosc odpowiadajaca unikowi podczas ataku
    ///@param hp zycie odpowiadajace jak duzo obrazen moze zniesc pokemon
    ///@param name nazwa pokemona
    ///@param pokemontype typ pokemona
    ///@param strength sila odpowiadajaca temu ile obrazen moze zadac pokemon podczas ataku
    Pokemon(string name, int strength, int dexterity, int hp, string pokemontype);
    ///Destruktor klasy
    virtual ~Pokemon();

    ///Funkcja zwracajaca sile pokemona
    ///@return zwraca int ile sily ma pokemon
    int getStrength() { return this->strength; };
    ///Funkcja zwracajaca zrecznosc pokemona
    ///@return zwraca int ile zrecznosci ma pokemon
    int getDexterity() { return this->dexterity; };
    ///Funkcja zwracajaca zycie pokemona
    ///@return zwraca int ile zycia ma pokemon w danym momencie gry
    int getHP() { return this->hp; };
    ///Funkcja zwracajaca maksymalne zycie pokemona
    ///@return zwraca int ile maksymalnego zycia ma pokemon
    int getHPmax() { return this->hpmax; };
    ///Funkcja zwracajaca punkty doswiadczenia pokemona
    ///@return zwraca int ile punktow doswiadczenia ma pokemon
    int getExp() { return this->exp; };
    ///Funkcja zwracajaca punkty doswiadczenia potrzebne do ewolucji
    ///@return zwraca int ile punktow doswiadczenia jest potrzebnych na ewolucje
    int getExpNext() { return this->expNext; };
    ///Funkcja zwracajaca czy pokemon jest zdatny do walki
    ///@return zwraca bool true jesli pokemon jest zdatny do walki i false jesli nie jest
    bool ispokemonalive() { return this->hp > 0; }
    ///Funkcja zwracajaca nazwe pokemona
    ///@return zwraca string nazwe pokemona
    std::string getName() { return this->name; };
    ///Funkcja zwracajaca typ pokemona
    ///@return zwraca string typ pokemona
    std::string getPokemontype() { return this->pokemontype; };
    ///Funkcja zwracajaca nazwe mocy specjalnej pokemona
    ///@return zwraca string nazwe umiejetnosci specjalnej pokemona
    std::string getSpiecialPowerName() { return this->spiecialpowername; };

    ///Funkcja ewoluujaca pokemona
    void evolve();
    ///Funkcja dodajaca punkty doswiadczenia dla danego pokemona
    ///@param exp jaka wartosc int puntkow doswiadczenia otrzymuje pokemona
    void gainExp(int exp);
    ///Funkcja odpowiedzialna za dostawanie obrazen przez pokemona
    ///@param damage jaka wartosc int obrazen otrzymuje pokemon
    void takeDamage(int damage);
    ///Funkcja zwiekszajaca statystyke sily pokemona
    ///@param strength ile int sily dodac pokemonowi
    void ImproveStrength(int strength);
    ///Funkcja zwiekszajaca statystyke zrecznosci pokemona
    ///@param dexterity ile int zrecznosci dodac pokemonowi
    void ImproveDexterity(int dexterity);
    ///Funkcja zwiekszajaca statystyke zycia pokemona
    ///@param hp ile int punktow zycia dodac pokemonowi
    void ImproveHp(int hp);
    ///Funkcja przywracajaca zycie pokemonowi
    void restorehp();

};




#include <iostream>
#include <vector>
#include <algorithm>
#include "Battle.h"

class Game {
    ///Klasa odpowiedzialna za glowne menu gry
private:
    ///Zmienna przechowujaca informacje czy gracz jest w menu glownym gry
    bool isingame;
    ///Zmienna przechowujaca informacje czy gracz wybral juz swoja druzyne
    bool teamisfull;
    ///Zmienna przechowujaca informacje czy gracz wybral poziom trudnosci
    bool difficultychoose;
    ///Zmienna przechowujaca informacje czy gracz pokonal pierwszego przeciwnika
    bool battle1done;
    ///Zmienna przechowujaca informacje czy gracz pokonal drugiego przeciwnika
    bool battle2done;
    ///Zmienna przechowujaca informacje czy gracz pokonal trzeciego przeciwnika
    bool battle3done;
    ///Zmienna przechowujaca informacje czy gracz pokonal czwartego przeciwnika
    bool battle4done;
    ///Zmienna przechowujaca informacje o poziomie trudnosci
    int difficulty;
    ///Zmienna przechowujaca informacje jaki poziom trudnosci maja miec przeciwnicy (jaka liczbe dodac do kazdej statystyki przeciwnego pokemona(2,3,4))
    int difficultyforenemies;
    ///Zmienna przechowujaca informacje o wyborze opcji w menu glownym gry
    int choice;
    ///Zmienna przechowujaca informacje o wyborze pokemona przez gracza do jego druzyny
    int pokemonchoice;
    ///Zmienna klasy "Trainer" odpowiedzialna za gracza
    Trainer trainer;
    ///Zmienna klasy "Trainer" odpowiedzialna za pierwszego przeciwnika
    Trainer enemyTrainer1;
    ///Zmienna klasy "Trainer" odpowiedzialna za drugiego przeciwnika
    Trainer enemyTrainer2;
    ///Zmienna klasy "Trainer" odpowiedzialna za trzeciego przeciwnika
    Trainer enemyTrainer3;
    ///Zmienna klasy "Trainer" odpowiedzialna za czwartego przeciwnika
    Trainer enemyTrainer4;
    ///Wektor zawierajacy pokemony dostepne w grze
    std::vector<Pokemon>pokemons;
    ///Wektor zawierajacy pokemony dostepne dla przeciwnikow
    std::vector<Pokemon>enemypokemons;
    ///Wekttor zawierajacy wszyskie pokemony
    std::vector<Pokemon>allpokemons;
public:
    ///Kontruktor klasy
    Game();
    ///Destruktor klasy
    virtual ~Game();

    ///Funkcja zwracajaca zmienna "isingame" o aktualnym stanie glownego menu
    ///@return zwraca true jesli gracz nadal gra i false jesli przegral walke lub wygral wszyskie
    bool getIsingame() { return this->isingame; };
    ///Funkcja ustawiajaca zmienna "isingame" na false
    void setIsingame();
    ///Funkcja odpowiedzialna za wyswietlenie pokemonow dostepnych dla gracza i wybor przez gracza pokemon do swojej druzyny
    void choosepokemons();
    ///Funkcja wyswietlajaca wybrane przez gracza pokemony
    void showtrainerpokemons();
    ///Funkcja odpowiedzialna za wybor poziomu trudnosci gry
    void choosedifficulty();
    ///Funkcja odpowiedzialna za wywolanie pierwszej walki z pierwszym przeciwnikiem
    void battle1();
    ///Fukncja odpowiedzialna za wygenerowanie pierwszego przeciwnika
    void generate1enemy();
    ///Funkcja odpowiedzialna za wywolanie drugiej walki z drugim przeciwnikiem
    void battle2();
    ///Fukncja odpowiedzialna za wygenerowanie drugiego przeciwnika
    void generate2enemy();
    ///Funkcja odpowiedzialna za wywolanie trzeciej walki z trzecim przeciwnikiem
    void battle3();
    ///Fukncja odpowiedzialna za wygenerowanie trzeciego przeciwnika
    void generate3enemy();
    ///Funkcja odpowiedzialna za wywolanie czwartej walki z czwartym przeciwnikiem
    void battle4();
    ///Fukncja odpowiedzialna za wygenerowanie czwartego przeciwnika
    void generate4enemy();
    ///Funkcja generujaca menu glowne
    void game();
    ///Funkcja tworzaca pokemony dla gracza
    void createpokemons();
    ///Funkcja tworzaca pokemony dla przeciwnikow
    void createenemypokemons();
    ///Funkcja ustawiajaca zmienna "battle1done" na true po skonczonej pierwszej walce
    void setbattle1done();
    ///Funkcja ustawiajaca zmienna "battle2done" na true po skonczonej drugiej walce
    void setbattle2done();
    ///Funkcja ustawiajaca zmienna "battle3done" na true po skonczonej trzeciej walce
    void setbattle3done();
    ///Funkcja ustawiajaca zmienna "battle4done" na true po skonczonej czwartej walce
    void setbattle4done();
    ///Funkcja zwracajaca ilosc zdolnych do walki pokemonow gracza
    ///@return zwraca int zawierajacy ilosc pokemon ktore maja wiecej niz 0 zycia
    int traineralive();



};




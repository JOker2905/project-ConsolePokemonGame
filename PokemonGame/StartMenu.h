#include <iostream>
#include "Game.h"

using namespace std;

class StartMenu {
    ///Klasa odpowiedzialna za menu poczatkowe gry
private:
    ///Zmienna przechowujaca informacje czy gracz jest w menu startowym
    bool isinmainmenu;
    ///Zmienna zapamietujaca wybor opcji w startowym menu przez gracza
    int choice;

public:
    ///Kontruktor klasy
    StartMenu();
    ///Destruktor klasy
    virtual ~StartMenu();
    ///Funkcja odpowiedzialna za wyswietlenie menu
    void mainMenu();
    ///Funkcja odpowiedzialna za przejscie do glownego menu gry
    void play();

    ///Funkcja zwracajaca zmienna "isismenu" o aktualnym stanie startowego menu
    bool getPlaying()const;
};




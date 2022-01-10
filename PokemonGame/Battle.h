
#include "Trainer.h"


class Battle {
    ///Klasa odpowiedzialna za mechanizm walki pomiedzy graczem a przeciwnikami
private:
public:
    ///Kontruktor klasy
    Battle();
    ///Destruktor klasy
    virtual ~Battle();
    ///Funkcja odpowiedzialna za mechanizmy walki
    ///@param trainer Trener jako gracz ktory walczy
    ///@param enemyTrainer PrzeciwnyTrener jako przeciwnik jeden z czterech zelzny od walki w ktorej bierzemy udział
    void battle(Trainer& trainer, Trainer& enemyTrainer);
};




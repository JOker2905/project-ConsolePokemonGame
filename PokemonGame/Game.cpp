
#include "Game.h"

Game::Game() {
    choice = 0;
    difficulty=0;
    difficultyforenemies=0;
    pokemonchoice=0;
    isingame = true;
    teamisfull = false;
    difficultychoose = false;
    battle1done= false;
    battle2done= false;
    battle3done= false;
    battle4done= false;
    createpokemons();
}
Game::~Game() {
}

void Game::game() {
    if (teamisfull) {
        if (battle1done && traineralive() != 6) {
            cout << "YOU LOSE GAME" << "\n\n";
            cout<<endl;
            setIsingame();
        }
        if (battle2done && traineralive() != 6) {
            cout << "YOU LOSE GAME" << "\n\n";
            cout<<endl;
            setIsingame();
        }
        if (battle3done && traineralive() != 6) {
            cout << "YOU LOSE GAME" << "\n\n";
            cout<<endl;
            setIsingame();
        }
        if (battle4done && traineralive() != 6) {
            cout << "YOU LOSE GAME" << "\n\n";
            cout<<endl;
            setIsingame();
        }
        if (battle4done && traineralive() == 6) {
            cout << "YOU WON GAME" << "\n\n";
            cout<<endl;
            setIsingame();
        }
    }
    if (isingame) {
        cout << "YOU ARE IN GAME MENU" << "\n";
        cout << "CHOOSE ACTION" << "\n";
        cout << "0:Quit" << "\n";
        cout << "1:Choose pokemons" << "\n";
        cout << "2:Show your pokemons" << "\n";
        cout << "3:Choose difficulty" << "\n";
        cout << "4:Battle 1" << "\n";
        cout << "5:Battle 2" << "\n";
        cout << "6:Battle 3" << "\n";
        cout << "7:Battle 4" << "\n";
        cout << "\n";
        cout << "Choice: ";
        cin >> this->choice;

        while (cin.fail() || this->choice > 7) {
            cout << "Wrong input!" << "\n";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "\n" << "Choice (0-7): ";
            cin >> this->choice;
        }
        cout << "\n";
        switch (choice) {
            case 0:
                isingame = false;
                break;
            case 1:
                choosepokemons();
                break;
            case 2:
                showtrainerpokemons();
                break;
            case 3:
                choosedifficulty();
                break;
            case 4:
                battle1();
                break;
            case 5:
                battle2();
                break;
            case 6:
                battle3();
                break;
            case 7:
                battle4();
                break;
            default:
                break;
        }
    }
}

void Game::choosepokemons() {
    if (!teamisfull) {
        cout << "Now you need to choose 6 pokemons you want in your team" << "\n";
        cout << "Each pokemon can be choose once" << "\n";
        cout << "Here is a list" << "\n";
        for (int i = 1; i < this->allpokemons.size() +1; ++i) {
            cout << i << "." << this->allpokemons[i - 1].getName() << "  HP:" << this->allpokemons[i - 1].getHPmax()
                 << "  Strength:" << this->allpokemons[i - 1].getStrength() << "  Dexterity:"
                 << allpokemons[i - 1].getDexterity() << "\n";
        }
        bool samechoiceofpokemon = false;
        int howmanypokemons = 0;
        while (howmanypokemons != 6) {
            cout << "\n" << "Choice: ";
            cin >> this->pokemonchoice;
            while (cin.fail() || this->pokemonchoice >= 16) {
                cout << "Wrong input" << "\n";
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Choice (1-15): ";
                cin >> this->pokemonchoice;
            }
            for (int i = 0;i < trainer.ownedpokemon().size();i++) {
                if (allpokemons[pokemonchoice - 1].getName() == trainer.ownedpokemon()[i].getName()) {
                    samechoiceofpokemon = true;
                }
            }
            if (samechoiceofpokemon) {
                cout << "You choose the same pokemon" << "\n";
                cout << "Choose different" << "\n";
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cin >> this->pokemonchoice;
            }
            trainer.addpokemon(pokemons[pokemonchoice - 1]);
            samechoiceofpokemon = false;
            howmanypokemons++;
        }
        teamisfull = true;
    }
    else {
        cout << "\n" << "You already choose pokemons";
        cout << "\n";
    }
}
void Game::createpokemons() {
    Pokemon bulbasaur("Bulbasaur", 10, 5, 45, "ziemia", "chlorofil");
    Pokemon charmander("Charmander", 11, 5, 39, "ogien", "silaslonca");
    Pokemon squirtle("Squirtle", 9, 5, 44, "woda", "zbierakwody");
    Pokemon caterpie("Caterpie", 6, 5, 45, "ziemia", "unik");
    Pokemon weedle("Weedle", 8, 5, 40, "ziemia", "ucieczka");
    Pokemon pidgey("Pidgey", 9, 7, 40, "powietrze", "odpornosc");
    Pokemon rattata("Rattata", 12, 5, 30, "ziemia", "pospiech");
    Pokemon spearow("Spearow", 10, 8, 40, "powietrze", "snajper");
    Pokemon ekans("Ekans", 13, 8, 35, "ziemia", "unik");
    Pokemon pikachu("Pikachu", 15, 10, 35, "stal", "odpornosc");
    Pokemon sandshrew("Sandshrew", 13, 3, 50, "ziemia", "unik");
    Pokemon psyduck("Psyduck", 13, 2, 50, "lod", "unik");
    Pokemon voltorb("Voltorb", 6, 8, 40, "stal", "uziemienie");
    Pokemon rhyhorn("Rhyhorn", 12, 1, 70, "stal", "odpornosc");
    Pokemon zubat("Zubat", 10, 4, 40, "powietrze", "unik");

    pokemons.push_back(bulbasaur);
    pokemons.push_back(charmander);
    pokemons.push_back(squirtle);
    pokemons.push_back(caterpie);
    pokemons.push_back(weedle);
    pokemons.push_back(pidgey);
    pokemons.push_back(rattata);
    pokemons.push_back(spearow);
    pokemons.push_back(ekans);
    pokemons.push_back(pikachu);
    pokemons.push_back(sandshrew);
    pokemons.push_back(psyduck);
    pokemons.push_back(voltorb);
    pokemons.push_back(rhyhorn);
    pokemons.push_back(zubat);

    allpokemons = pokemons;
}

void Game::createenemypokemons() {

    Pokemon enemybulbasaur("Bulbasaur", 5+difficultyforenemies, 4 + difficultyforenemies, 37 + difficultyforenemies, "ziemia");
    Pokemon enemycharmander("Charmander", 6 + difficultyforenemies, 4 + difficultyforenemies, 32 + difficultyforenemies, "ogien");
    Pokemon enemysquirtle("Squirtle", 4 + difficultyforenemies, 4 + difficultyforenemies, 36 + difficultyforenemies, "woda");
    Pokemon enemycaterpie("Caterpie", 3 + difficultyforenemies, 4 + difficultyforenemies, 37 + difficultyforenemies, "ziemia");
    Pokemon enemyweedle("Weedle", 3 + difficultyforenemies, 4 + difficultyforenemies, 32 + difficultyforenemies, "ziemia");
    Pokemon enemypidgey("Pidgey", 4 + difficultyforenemies, 6 + difficultyforenemies, 27 + difficultyforenemies, "powietrze");
    Pokemon enemyrattata("Rattata", 7 + difficultyforenemies, 4 + difficultyforenemies, 27 + difficultyforenemies, "ziemia");
    Pokemon enemyspearow("Spearow", 5 + difficultyforenemies, 7 + difficultyforenemies, 42 + difficultyforenemies, "powietrze");
    Pokemon enemyekans("Ekans", 8 + difficultyforenemies, 7 + difficultyforenemies, 27 + difficultyforenemies, "ziemia");
    Pokemon enemypikachu("Pikachu", 10 + difficultyforenemies, 9 + difficultyforenemies, 27 + difficultyforenemies, "stal");
    Pokemon enemysandshrew("Sandshrew", 8 + difficultyforenemies, 2 + difficultyforenemies, 42 + difficultyforenemies, "ziemia");
    Pokemon enemypsyduck("Psyduck", 8 + difficultyforenemies, 1 + difficultyforenemies, 42 + difficultyforenemies, "lod");
    Pokemon enemyvoltorb("Voltorb", 1 + difficultyforenemies, 7 + difficultyforenemies, 32 + difficultyforenemies, "stal");
    Pokemon enemyrhyhorn("Rhyhorn", 7 + difficultyforenemies, 0 + difficultyforenemies, 57 + difficultyforenemies, "stal");
    Pokemon enemyzubat("Zubat", 5 + difficultyforenemies, 3 + difficultyforenemies, 32 + difficultyforenemies, "powietrze");


    enemypokemons.push_back(enemybulbasaur);
    enemypokemons.push_back(enemycharmander);
    enemypokemons.push_back(enemysquirtle);
    enemypokemons.push_back(enemycaterpie);
    enemypokemons.push_back(enemyweedle);
    enemypokemons.push_back(enemypidgey);
    enemypokemons.push_back(enemyrattata);
    enemypokemons.push_back(enemyspearow);
    enemypokemons.push_back(enemyekans);
    enemypokemons.push_back(enemypikachu);
    enemypokemons.push_back(enemysandshrew);
    enemypokemons.push_back(enemypsyduck);
    enemypokemons.push_back(enemyvoltorb);
    enemypokemons.push_back(enemyrhyhorn);
    enemypokemons.push_back(enemyzubat);
}
void Game::showtrainerpokemons() {
    if (teamisfull) {
        cout << "Your pokemons" << "\n";
        for (int i = 1; i < trainer.sizeofpokemons() + 1; ++i) {
            cout << i << "." << trainer.pokemon(i - 1).getName() << " HP:" << trainer.pokemon(i - 1).getHP() << " Strength:" << trainer.pokemon(i - 1).getStrength() << "\n";
        }
    }
    else {
        cout << "First you need to choose pokemons" << "\n";
    }
    cout << "\n";
}

void Game::choosedifficulty() {
    if (!difficultychoose) {
        cout << "Choose difficulty" << "\n";
        cout << "1.Easy" << "\n";
        cout << "2.Medium" << "\n";
        cout << "3.Hard" << "\n";
        cout << "\n";
        cout << "Choice: ";
        cin >> difficulty;
        while (cin.fail() || difficulty > 4) {
            cout << "Wrong input!" << "\n";
            cin.clear();
            cout << "\n" << "Choice (1-3): ";
            cin >> this->choice;
        }
        switch (difficulty) {
            case 1:
                difficultyforenemies = 2;
                break;
            case 2:
                difficultyforenemies = 3;
                break;
            case 3:
                difficultyforenemies = 4;
                break;
        }
        difficultychoose = true;
        cout << "\n";
        createenemypokemons();
    }
    else {
        cout << "\n" << "You already choose difficulty";
        cout << "\n";
    }
}

void Game::battle1() {
    if (teamisfull && difficultychoose) {
        if (!battle1done) {
            generate1enemy();
            Battle battle;
            battle.battle(this->trainer, this->enemyTrainer1);
            setbattle1done();
        }
        else {
            cout << "YOU ALREADY WON THIS BATTLE" << "\n";
        }
    }
    else {
        cout << "\n";
        cout << "Do previus steps" << "\n";
    }
}

void Game::battle2() {
    if (teamisfull && difficultychoose && battle1done) {
        if (!battle2done) {
            generate2enemy();
            Battle battle;
            battle.battle(this->trainer, this->enemyTrainer2);
            setbattle2done();
        }
        else {
            cout << "YOU ALREADY WON THIS BATTLE" << "\n";
        }
    }
    else {
        cout << "\n";
        cout << "You need to won 1 battle" << "\n";
    }
}

void Game::battle3() {
    if (teamisfull && difficultychoose && battle2done) {
        if (!battle3done) {
            generate3enemy();
            Battle battle;
            battle.battle(this->trainer, this->enemyTrainer3);
            setbattle3done();
        }
        else {
            cout << "YOU ALREADY WON THIS BATTLE" << "\n";
        }
    }
    else {
        cout << "\n";
        cout << "You need to won 2 battle" << "\n";
    }

}

void Game::battle4() {
    if (teamisfull && difficultychoose && battle3done) {
        if (!battle4done) {
            generate4enemy();
            Battle battle;
            battle.battle(this->trainer, this->enemyTrainer4);
            setbattle4done();
        }
        else {
            cout << "YOU ALREADY WON THIS BATTLE" << "\n";
        }
    }
    else {
        cout << "\n";
        cout << "You need to won 3 battle" << "\n";
    }
}

void Game::generate1enemy() {
    int number[4];
    int n;
    for (int i = 0; i < 4; ++i) {
        bool check;
        n = 0;
        do {
            n = rand() % 15 ;
            check = true;
            for (int j = 0; j < i; ++j) {
                if (n == number[j]) {
                    check = false;
                    break;
                }
            }
        } while (!check);
        number[i] = n;
    }
    for (int i : number) {
        enemyTrainer1.addpokemon(enemypokemons[i]);
    }
}

void Game::generate2enemy() {
    int number[4];
    int n;
    for (int i = 0; i < 4; ++i) {
        bool check;
        n = 0;
        do {
            n = rand() % 15 ;
            check = true;
            for (int j = 0; j < i; ++j) {
                if (n == number[j]) {
                    check = false;
                    break;
                }
            }
        } while (!check);
        number[i] = n;
    }
    for (int i : number) {
        enemyTrainer2.addpokemon(enemypokemons[i]);
    }
}

void Game::generate3enemy() {
    int number[4];
    int n;
    for (int i = 0; i < 4; ++i) {
        bool check;
        n = 0;
        do {
            n = rand() % 15 ;
            check = true;
            for (int j = 0; j < i; ++j) {
                if (n == number[j]) {
                    check = false;
                    break;
                }
            }
        } while (!check);
        number[i] = n;
    }
    for (int i : number) {
        enemyTrainer3.addpokemon(enemypokemons[i]);
    }
}

void Game::generate4enemy() {
    int number[4];
    int n;
    for (int i = 0; i < 4; ++i) {
        bool check;
        n = 0;
        do {
            n = rand() % 15 ;
            check = true;
            for (int j = 0; j < i; ++j) {
                if (n == number[j]) {
                    check = false;
                    break;
                }
            }
        } while (!check);
        number[i] = n;
    }
    for (int i : number) {
        enemyTrainer4.addpokemon(enemypokemons[i]);
    }
}
void Game::setIsingame() {
    this->isingame = false;
}

void Game::setbattle1done() {
    this->battle1done = true;
}

void Game::setbattle2done() {
    this->battle2done = true;
}

void Game::setbattle3done() {
    this->battle3done = true;
}

void Game::setbattle4done() {
    this->battle4done = true;
}

int Game::traineralive() {
    int alive = 0;
    for (int i = 0; i < 6; ++i) {
        if (trainer.pokemon(i).ispokemonalive())
            alive++;
    }
    return alive;
}



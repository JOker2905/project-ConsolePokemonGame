
#include "StartMenu.h"

StartMenu::StartMenu() {
    choice = 0;
    isinmainmenu = true;
}
StartMenu::~StartMenu() {

}

void StartMenu::mainMenu() {
    cout << "**WELCOME TO TURN-BASED GAME**" << "\n";
    cout << "**SELECT ACTION**" << "\n";
    cout << "0: Quit" << "\n";
    cout << "1: Play" << "\n";

    cout << "\n";

    cout << "Choice: ";
    cin >> this->choice;
    while (cin.fail() || this->choice > 2) {
        cout << "Wrong input!" << "\n";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "\n" << "Choice(0-1): ";
        cin >> this->choice;
    }
    switch (this->choice) {
        case 0:
            isinmainmenu = false;
            break;
        case 1:
            play();
            break;
    }
}

void StartMenu::play() {
    Game game;
    while (game.getIsingame()) {
        game.game();
    }

}
bool StartMenu::getPlaying() const {
    return this->isinmainmenu;
}

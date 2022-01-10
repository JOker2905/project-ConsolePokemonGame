#include "StartMenu.h"

int main() {

    StartMenu game;

    while (game.getPlaying()) {
        game.mainMenu();
    }
    return 0;
}

using namespace std;
#include <conio.h>

#include <iostream>

#include "Pendu.h"

int main() {
    Pendu p;
    p.Run();

    bool keepPlaying = true;
    int character;

    while (keepPlaying) {
        cout << "\nPress Y to play again ...";
        character = _getche();
        if (character == 'Y' || character == 'y') {
            p.Run();
        } else {
            cout << "The game was exited successfully" << endl;
            keepPlaying = false;
        }
    }
    return 0;
}
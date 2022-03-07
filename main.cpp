
#include <iostream>
using namespace std;

#include <conio.h>

// include "Pendu.h" -> can cause some linker issues in some IDES
#include "Pendu.cpp"  // use this instead

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
    system("pause");
    return 0;
}
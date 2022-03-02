#include "Pendu.h"

Pendu::Pendu() {
    init();
}

Pendu::~Pendu() {
    delete[] foundLetter;
    foundLetter = nullptr;
}

void Pendu::set_secretWord(string secretWord) {
    this->secretWord = secretWord;
}

void Pendu::set_remainingTries(int remainingTries) {
    this->remainingTries = remainingTries;
}

void Pendu::set_letter(char letter) {
    this->letter = letter;
}

string Pendu::get_secretWord() const {
    return this->secretWord;
}

int Pendu::get_remainingTries() const {
    return this->remainingTries;
}

char Pendu::get_letter() const {
    return this->letter;
}

void Pendu::Play() {
    Display();

    bool playerWins = win();

    if (playerWins) {
        cout << "\n*****************" << endl;
        cout << "*    YOU WIN    *" << endl;
        cout << "*****************" << endl;
        cout << "The secret word was: " << get_secretWord() << endl;
    } else {
        cout << "\n*****************" << endl;
        cout << "*    YOU LOSE    *" << endl;
        cout << "*****************" << endl;
        cout << "The secret word was: " << get_secretWord() << endl;
    }
    Reset();
}

void Pendu::Run() {
    Play();
}

void Pendu::init() {
    set_secretWord("");
    i = 0;
    set_remainingTries(10);
    set_letter(0);
    gameOver = false;
}

void Pendu::Display() {
    DrawMan();
    cout << "Welcome..." << endl;
    cout << "I am thinking of a word:" << endl;

    try {
        if (!find_word())
            throw(string) "the program failed to generete a word";
        else {
            set_secretWord(chosenWord);
            wordsize = (int)secretWord.size();
            foundLetter = new int[wordsize]{0};
            if (wordsize <= 0) {
                throw(string) "secret Word Size can not be <= 0";
            }
        }

        while (!gameOver) {
            cout << "\nYou have " << get_remainingTries() << " remaining tries" << endl;
            cout << "\nwhat is the secret word?" << endl;
            for (i = 0; i < wordsize; i++) {
                if (foundLetter[i]) {
                    cout << secretWord[i];
                } else {
                    cout << "*";
                }
            }
            cout << "\nSuggest a letter : ";
            letter = readCharacter();
            if (!findLetter()) {
                remainingTries--;
            }
            gameOver = (get_remainingTries() <= 0 || win());
        }
    } catch (...) {
    }
}

void Pendu::DrawMan() {
    cout << endl
         << endl;
    cout << "  -----" << endl;
    cout << "  |   |" << endl;
    cout << "  |";
    if (get_remainingTries() >= 1) cout << "   O    ";
    cout << endl;
    cout << "  |";
    if (get_remainingTries() >= 3) cout << "  /|\\   ";
    cout << endl;
    cout << "  |";
    if (get_remainingTries() >= 5) cout << "  / \\    ";
    cout << endl;
    cout << "  |" << endl;
    cout << "__|__" << endl;
    cout << "\n";
}

void Pendu::Reset() {
    init();
}

char Pendu::readCharacter() {
    char character;
    character = getchar();
    character = toupper(character);
    while (getchar() != '\n') {
        // do nothing
    }
    return character;
}

bool Pendu::find_word() {
    int wordsNumber = 0;       // counter
    int chosenWordNumber = 0;  // index
    vector<string> lines;      // array of words in file
    string word;               // read word after word in the file
    ifstream file;             // file that contain the string words

    file.open("words.txt");
    if (!file) {
        cerr << "\nfile could not be opened" << endl;
        return false;
    }

    // first count all the words in the file
    while (file >> word) {
        wordsNumber++;
        lines.push_back(word);  // store the words that we read in the file
    }

    // then chose a random word
    chosenWordNumber = aleatoryNumber(wordsNumber);
    chosenWord = lines[chosenWordNumber];

    // Start reading from the beginning and stop when finding the right word
    file.clear();
    file.seekg(0);
    while (file >> word && chosenWordNumber > 0) {
        chosenWordNumber--;
    }

    // chosenWord[chosenWord.size() - 1] = '\0';
    file.close();
    return true;
}

int Pendu::aleatoryNumber(int maxNumber) {
    // generate a random number
    srand(time(0));
    return rand() % maxNumber;
}

int Pendu::findLetter() {
    int i = 0;
    int rightLetter = 0;

    for (i = 0; secretWord[i] != '\0'; i++) {
        if (letter == secretWord[i]) {
            rightLetter = 1;
            foundLetter[i] = 1;
        }
    }
    return rightLetter;
    // Do you really needs to return here ?
}

bool Pendu::win() {
    for (int i = 0; i < wordsize; i++) {
        if (foundLetter[i] == 0) {
            return false;
        }
    }
    return true;
}
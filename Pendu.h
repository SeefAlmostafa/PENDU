#pragma once

using namespace std;
#include <ctype.h>
#include <stdio.h>

#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Pendu {
   private:
    int* foundLetter;
    int i;
    int wordsize;
    string secretWord;
    string chosenWord;
    void DrawMan();

    int remainingTries;
    bool gameOver;
    char letter;

   public:
    Pendu();
    ~Pendu();

    // Setters & Getters
    void set_secretWord(string secretWord);
    void set_remainingTries(int remainingTries);
    void set_letter(char letter);

    // think of inline functions
    string get_secretWord() const;
    int get_remainingTries() const;
    char get_letter() const;

    // Functions
    char readCharacter();
    void Play();
    void Run();
    void init();
    void Display();
    void Reset();
    bool find_word();
    int findLetter();
    int aleatoryNumber(int maxNumber);
    bool win();
};

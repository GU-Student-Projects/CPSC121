/**
 * File:            hangman.cpp
 * Author:          Gabe DiMartino
 * Date Modified:   30 April 2023
 * Description:     hangman game with arrays
 */

#include<iostream>
#include<fstream>
using namespace std;

// reads the list of words from a file named as filename param and saves them into the words string array
void readFromFile(string filename, string words[]);

// randomly picks a word from the words array, and returns that word
string selectWord(string words[]);

// generates a random number between [lowerBound, upperBound]
// lowerbound should be beginning index of the words array,
// upperbound should be the ending index of the words array
int getRandomNumber(int lowerBound, int upperBound);

// starts the main game loop
// plays the game of hangman.
// Program will stop running after 1 game is completed, either win or lose
void playGame(string words[]);

const int WORD_COUNT = 10;
const int WORD_LENGTH = 5;
const int MAX_GUESSES = 5;


int main(){

    srand(time(NULL));

    string filename = "WordList.txt";
    string words[WORD_COUNT];
    readFromFile(filename, words);
    playGame(words);
    //you implement
    

    return 0;
}

void readFromFile(string filename, string words[]){
    ifstream readLine(filename);
    int i = 0;
    string word;
    while (getline(readLine, word)){
        words[i++]=word;
    }
    readLine.close();
}

string selectWord(string words[]){
    int randNum = getRandomNumber(0, WORD_COUNT);
    string selWord = words[randNum];
    return selWord;
}

int getRandomNumber(int lowerBound, int upperBound){
    int randNum = rand()%(upperBound - lowerBound);
    return randNum;
}

void playGame(string words[]){
    string hiddenWordInit[WORD_LENGTH];
    string hiddenWord;
    string guess;
    string tempGuess = "";
    char wrongGuess[MAX_GUESSES];
    string randWord = selectWord(words);

    for (int i = 0; i < WORD_LENGTH; i++){
        hiddenWordInit[i] = "-";
        hiddenWord += hiddenWordInit[i];
    }

    int correctChar = 0;
    int incorrectGuess = 0;
    int guessRemain = MAX_GUESSES;

    while (guessRemain > 0 && correctChar < WORD_LENGTH) {
        cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Hidden Word: " << hiddenWord << "\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Correct Characters: " << correctChar << "\n";
        cout << "Incorrect Guesses: " << incorrectGuess << "\n";
        cout << "Guesses Remaining: " << guessRemain << "\n";
        cout << "Wrong Guesses: [";
        for (int i = 0; i < incorrectGuess; i++) {
            cout << wrongGuess[i] << "] [";
        }
        cout << "]\n\n";

        cout << "Guess a letter: ";
        getline(cin, guess);
        cout << endl;

        bool match = false;
        for (int i = 0; i < WORD_LENGTH; i++) {
            if (guess[0] == tempGuess[0]){
                match = false;
                break;
            }
            if (guess[0] == randWord[i]) {
                hiddenWordInit[i] = guess[0];
                correctChar++;
                match = true;
            }
        }

        if (!match) {
            if (guess[0] == tempGuess[0]){
                continue;
            }else{
                wrongGuess[incorrectGuess] = guess[0];
                incorrectGuess++;
                guessRemain--;
            }
        }

        hiddenWord = "";
        for (int i = 0; i < WORD_LENGTH; i++) {
            hiddenWord += hiddenWordInit[i];
            }
        tempGuess = guess;
        }

    if (correctChar == WORD_LENGTH) {
        cout << "Congratulations! You beat me with the word '" << randWord << "'\n";
    } else {
        cout << "You Failed!. The word was '" << randWord << "'\n";
    }

}
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

    string filename = "WordList.txt"; //designiate the wordlist to be read from the program
    string words[WORD_COUNT]; //create an array size of WORD_COUNT
    readFromFile(filename, words); //opend and read the file
    playGame(words);
    

    return 0;
}

void readFromFile(string filename, string words[]){
    ifstream readLine(filename); //open file frome passed through value filename
    int i = 0;
    string word;
    while (getline(readLine, word)){ //while there are words, set an element of the array to each word
        words[i++]=word;
    }
    readLine.close();
}

string selectWord(string words[]){
    int randNum = getRandomNumber(0, WORD_COUNT); //call random number and find the corresponding number in the array words[]
    string selWord = words[randNum];
    return selWord; //return the word
}

int getRandomNumber(int lowerBound, int upperBound){
    int randNum = rand()%(upperBound - lowerBound); //get a random number from 0 : 10
    return randNum;
}

void playGame(string words[]){
    string hiddenWordInit[WORD_LENGTH]; //array for the ---- on the ui
    string hiddenWord;
    string guess;
    string tempGuess = ""; //initianlize the temp guess as nothing
    char wrongGuess[MAX_GUESSES];
    string randWord = selectWord(words); //set the random word equal to the random generated word

    for (int i = 0; i < WORD_LENGTH; i++){
        hiddenWordInit[i] = "-";
        hiddenWord += hiddenWordInit[i]; //combine and initialize the char array into a string
    }

    int correctChar = 0;
    int incorrectGuess = 0;
    int guessRemain = MAX_GUESSES;

    while (guessRemain > 0 && correctChar < WORD_LENGTH) { //while there are guesses left and the word is not guessed loop
        cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Hidden Word: " << hiddenWord << "\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Correct Characters: " << correctChar << "\n";
        cout << "Incorrect Guesses: " << incorrectGuess << "\n";
        cout << "Guesses Remaining: " << guessRemain << "\n";
        cout << "Wrong Guesses: [";
        for (int i = 0; i < incorrectGuess; i++) { //loop through the amount of incorrect guesses, displaying the wrong values
            cout << wrongGuess[i] << "] ["; //the times this loop runs changes depending on howmany incorrect guesses there are
        }
        cout << "]\n\n";

        cout << "Guess a letter: ";
        getline(cin, guess);
        cout << endl;

        if (guess[0] > 64 && guess[0] < 91){ //convert all uppercase letters to lower
            guess[0] += 32;
        }

        if (guess == randWord){ //if the guess matches completely the random word, the game is ended
            cout << "Congratulations! You beat me with the word '" << randWord << "'\n";
            return;
        }

        bool match = false; //loop to test if the word matches
        for (int i = 0; i < WORD_LENGTH; i++) {
            if ((guess[0] == tempGuess[0]) && (guess[0] == randWord[i])){ //if the word matches and is the same do not increase the correct count
                match = true;
            }
            else if (guess[0] == randWord[i]) { //if the first char matches the rand word chars
                hiddenWordInit[i] = guess[0]; // change the array hiddenWordInt so it would look like {-, -, a, -, -}
                correctChar++;
                match = true;
            }
        }

        if (!match) {
            wrongGuess[incorrectGuess] = guess[0]; //array index determened by what incorrect guess it is 1-5
            incorrectGuess++; //if not correct, the array wrongGuess adds the value
            guessRemain--;
        }

        hiddenWord = "";
        for (int i = 0; i < WORD_LENGTH; i++) {
            hiddenWord += hiddenWordInit[i]; //combine the array hiddenWordInit into a string to be used in the ui. E.G --a--
            }
        tempGuess = guess; //remember the previous guess
        }

    cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "Hidden Word: " << hiddenWord << "\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "Correct Characters: " << correctChar << "\n";
    cout << "Incorrect Guesses: " << incorrectGuess << "\n";
    cout << "Guesses Remaining: " << guessRemain << "\n";
    cout << "Wrong Guesses: ";
    for (int i = 0; i < incorrectGuess; i++) {
        cout << "["<<wrongGuess[i] << "] ";
    }
        cout << "\n\n";
    if (correctChar == WORD_LENGTH) {
        cout << "Congratulations! You beat me with the word '" << randWord << "'\n";
    } else {
        cout << "You Failed!. The word was '" << randWord << "'\n";
    }

}
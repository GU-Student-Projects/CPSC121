/**
 * File:            hangman.cpp
 * Author:          your name
 * Date Modified: 
 * Description:
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
    cout << "test"; 
    //you implement
    

    return 0;
}

void readFromFile(string filename, string words[]){
    //you implement
}

string selectWord(string words[]){
    //you implement
    return nullptr;
}

int getRandomNumber(int lowerBound, int upperBound){

    return 0;
}

void playGame(string words[]){
    //you implement

}
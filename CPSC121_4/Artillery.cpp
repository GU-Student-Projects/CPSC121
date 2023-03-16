/**
 * File:            Artillery.cpp
 * Author:          Gabe DiMartino
 * Date Modified:   3/16/2023
 * Description:     TankProjectile game
*/

#include<iostream>
#define _USE_MATH_DEFINES
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include <chrono>
#include <thread>
#include <algorithm>
#include <string>

#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif

using namespace std;

void clearScreen(){ //function to clear terminal
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void warGames(const string& text, int delayMS = 50) { //function to print characters one at a time
    for (char c : text) {
        cout << fixed << setprecision(2) << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delayMS));
    }
    cout << endl;

}

string toUpper(const string& str) { //convert text to uppercase
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

string getValidation(const string& prompt) { //validate strings for yes or no
    string toLower;
    bool validInput = false;

    while(!validInput) {
        warGames(prompt, 50);
        cin >> toLower;
        transform(toLower.begin(), toLower.end(), toLower.begin(), ::tolower);
        if (toLower == "yes" || toLower == "no") {
            validInput = true;
    } else {
            string message = "INVALID INPUT";
            warGames(message, 50);
            cin.clear();
            validInput = false;

        }
    }
    return toLower;
}

string getValidDifficulty(const string& prompt) { //validate difficulty options
    string toLower;
    bool validInput = false;

    while(!validInput) {
        warGames(prompt, 50);
        cin >> toLower;
        transform(toLower.begin(), toLower.end(), toLower.begin(), ::tolower);
        if (toLower == "easy" || toLower == "medium" || toLower == "hard" || toLower == "exit") {
            validInput = true;
    } else {
            string message = "INVALID INPUT";
            warGames(message, 50);
            cin.clear(); 
            validInput = false;

        }
    }
    return toLower;
}

double getValidDegreeInput(const string& prompt){ // function to test if a valid double has been input
    int input;
    bool validInput = false;
    string message;

    while (!validInput) {
        warGames(prompt, 50);
        if (cin >> input && (input >= 0 && input < 360)){ // check to see if value is greater than 0
            validInput = true; // if the statement is valid, the boolean is changed to true and accepted
        } else {
            message =  "Invalid input";
            message = toUpper(message);
            warGames(message, 50);
            cin.clear(); // if the number is less than or = 0, the input is ignored
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            validInput = false;
        }
    }

    return input;
}

double getValidVelocityInput(const string& prompt){ // function to test if a valid double has been input
    double input;
    bool validInput = false;
    string message;

    while (!validInput) {
        warGames(prompt, 50);
        if (cin >> input && input >= 0){ // check to see if value is greater than 0
            validInput = true; // if the statement is valid, the boolean is changed to true and accepted
        } else {
            message =  "Invalid input";
            message = toUpper(message);
            warGames(message, 50);
            cin.clear(); // if the number is less than or = 0, the input is ignored
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            validInput = false;
        }
    }

    return input;
}



void tankBattle(const string& difficulty, const string& playerName = ""){
    double velocity = 0.0; //function for running the tank game
    double angle = 0.0;
    int roundNumber = 1;
    int minDistance = 50, maxDistance = 200, tankPosition = 0;
    double distanceTraveled;
    double adjustPositionLower = 0.0, adjustPositionUpper = 0.0;
    string message;

    srand(time(NULL));
    tankPosition = minDistance + (rand()%(maxDistance-minDistance+1));

    if (difficulty=="EASY") {
        adjustPositionLower = (tankPosition - 10);
        adjustPositionUpper = (tankPosition + 10);
    }
    else if (difficulty=="MEDIUM") {
        adjustPositionLower = (tankPosition - 5);
        adjustPositionUpper = (tankPosition + 5);
    }    
    else if (difficulty=="HARD") {
        adjustPositionLower = (tankPosition - 2.5);
        adjustPositionUpper = (tankPosition + 2.5);
    }

    clearScreen();

    // cout << tankPosition << endl; //Debug tool

    for (int i =0; i<3; i++) {

        cout << "-------------------------------------" << endl;
        cout << "ROUND NUMBER: " + to_string(roundNumber++) + " DIFFICULTY: " + difficulty << endl;
        cout << "-------------------------------------" << endl << endl;

        angle = getValidDegreeInput("ENTER AN ANGLE (IN DEGREES):");
        velocity = getValidVelocityInput("ENTER VELOCITY:");
        distanceTraveled = round(100 * (velocity * cos((angle * M_PI)/180))) / 100.0;

        if ((distanceTraveled > adjustPositionLower) && (distanceTraveled < adjustPositionUpper)){
            if (difficulty=="EASY") {
                 message += "HIT!\n";
                 message += "TANK LOCATED AT: " + to_string(tankPosition) + "\n";
                 message += "CONGRATULATIONS " + playerName + "! YOU HAVE BEATEN ME. BUT THATS NOT TOO HARD SEEING AS IT IS ON EASY.";
                toUpper(message);                 
            }
            else if (difficulty=="MEDIUM") {
                message += "HIT!\n";
                message += "TANK LOCATED AT: " + to_string(tankPosition) + "\n";
                message += "CONGRATULATIONS " + playerName + "! YOU HAVE BEATEN ME. YOU ARE GETTING BETTER AT THIS, TRY ME ON HARD.";
                toUpper(message);            
            }    
            else if (difficulty=="HARD") {
                message += "HIT!\n";
                message += "TANK LOCATED AT: " + to_string(tankPosition) + "\n";
                message += "CONGRATULATIONS " + playerName + "! YOU HAVE BEATEN ME. YOU ARE MY SUPERIOR.";
                toUpper(message);            
            } 
         
            warGames(message, 50);
            this_thread::sleep_for(chrono::seconds(3));
            return;
        }

        else if (distanceTraveled < tankPosition){
            message = "YOUR SHOT LANDED AT: " + to_string(distanceTraveled) + " AND WAS TOO SHORT.";
        } 
        
        else if (distanceTraveled > tankPosition) {
            message = "YOUR SHOT LANDED AT: " + to_string(distanceTraveled) + " AND WAS TOO FAR.";
        }

        toUpper(message);
        warGames(message, 50);
    }
    message = "YOU FAILED TO DEFEAT ME, BUT I WILL GIVE YOU A SECOND CHANCE " + playerName;
    toUpper(message);
    warGames(message, 50);
    this_thread::sleep_for(chrono::seconds(3)); 
    return;

}

void endBattle(){ //function to end the game
        clearScreen();
        string message = "TOO BAD, MAYBE NEXT TIME.";
        warGames(message, 50);
        this_thread::sleep_for(chrono::seconds(1));
        clearScreen();
        return;
}


int main(){

    string difficulty = "";
    string playerName = "";
    string reply = "";
    bool playAgain = true;

    clearScreen();

    string banner;
    banner += "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    banner += "  _______          _      ____        _   _   _       \n";
    banner += " |__   __|        | |    |  _ \\      | | | | | |      \n";
    banner += "    | | __ _ _ __ | | __ | |_) | __ _| |_| |_| | ___  \n";
    banner += "    | |/ _` | '_ \\| |/ / |  _ < / _` | __| __| |/ _ \\ \n";
    banner += "    | | (_| | | | |   <  | |_) | (_| | |_| |_| |  __/ \n";
    banner += "    |_|\\__,_|_| |_|_|\\_\\ |____/ \\__,_|\\__|\\__|_|\\___| \n";
    banner += "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                                                     
    cout << banner << endl << endl;
    
    string message = "ENTER YOUR NAME: ";
    warGames(message, 100);
    getline(cin, playerName);
    playerName = toUpper(playerName);
    clearScreen();
    message = "GREETINGS " + playerName + "\n\n"; 
    message += "HELLO \n \n";
    message += "A STRANGE GAME. \n";
    message += "THE ONLY WINNING MOVE IS \n";
    message += "NOT TO PLAY. \n\n";
    message += "HOW ABOUT A NICE GAME OF TANK BATTLE?";
    warGames(message, 50);
    this_thread::sleep_for(chrono::seconds(1));
    clearScreen();
    string prompt = "SHALL WE PLAY A GAME? (YES/NO)";
    string result = getValidation(prompt);
    while(playAgain) {
        if (result == "yes") {
            cout << "" << endl;
            message = "SELECT A DIFFICULTY: \n";
            message += "1. EASY \n";
            message += "2. MEDIUM \n";
            message += "3. HARD \n";
            message += "4. EXIT \n";
            string Diffresult = getValidDifficulty(message);
            if (Diffresult == "exit") {
                endBattle();
                playAgain = false;
            }else {
                difficulty = toUpper(Diffresult);
                tankBattle(difficulty, playerName);
                clearScreen();
                prompt = "SHALL WE PLAY A GAME?";
                result = getValidation(prompt);
                if (result == "no"){
                    endBattle();
                    playAgain = false;
                }
            }
        } else {
            endBattle();
            playAgain = false;
        }
    }
    return 0;
}





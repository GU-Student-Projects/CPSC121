/**
 * file:            LoopPractice.cpp
 * author:          Gabe DiMartino 
 * date modified:   3/27/2023
 * description:     Small program to calculate several complex numbers without math libraries
 * 
 */

#include<iostream>
#include<time.h>
#include<chrono>
#include<thread>
#include<string>
#include<limits>

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

void fibonacciGenerator(){
    int nthNumber;
    int fibNumber;
    int fibNumber1 = 1;
    int fibNumber2 = 1;
    cout << "For what number do you want the fibonacci generator to calculate? " << endl;
    cin >> nthNumber;
    cout << endl;
    if(nthNumber == 1){
        cout << fibNumber1 <<endl;
    }
    else if(nthNumber == 2) {
        cout << fibNumber2 <<endl;
    }
    else{
        for(int i=3; i<=nthNumber; i++){
            fibNumber = fibNumber1 + fibNumber2;
            fibNumber1 = fibNumber2;
            fibNumber2 = fibNumber; 
        }
        cout << "The number associated with the " << nthNumber << " of the fibonacci sequence is: " << fibNumber <<endl;
        this_thread::sleep_for(chrono::seconds(3));
    }
}

bool isPrime(int n){
    if(n<2)
        return false;

    for(int i = 2; i<n; i++){
        if(n%i == 0)
            return false;
        }
        return true;
}

void primeGenerator(){
    int nthNumber;
    cout << "For what number do you want to find the prime numbers in its range from 0? " << endl;
    cin >> nthNumber;
    cout << endl;
    for(int i=1; i<=nthNumber; i++){
        if(isPrime(i))
        cout << i << " ";
    }
    this_thread::sleep_for(chrono::seconds(3));    
}

void randomNumberTest(){
    int upperBound, randomNumber, secRandNumber;
    int i = 1;
    bool sameNumber = false;
    cout << "For what number do you want the upper bound of the random number generator to be? "<< endl;
    cin >> upperBound;

    srand(time(NULL));
    randomNumber = rand()%upperBound;

    while(!sameNumber){
        secRandNumber = rand()%upperBound;
        if (secRandNumber==randomNumber){
            sameNumber = true;
        }else{
            i++;
            sameNumber = false;
        }
    }
    cout << "It took: " << i << " attempts to find " << randomNumber << " again." << endl;
    this_thread::sleep_for(chrono::seconds(3));   
}    

void exponentCalculator(){
    int base, exponent, answer;
    cout << "Enter a base: ";
    cin >> base;
    cout << "Enter an exponent: ";
    cin >> exponent;
    
    answer = base;
    for(int i = 1; i < exponent; i++){
        answer = answer * base;
    }
    cout << "The answer is: " << answer << endl;
    this_thread::sleep_for(chrono::seconds(3)); 
}

void approximatePi(){
    int upperBound = numeric_limits<int>::max();
    int j = 1;
    double answer = 0.0;
    for (int i = 1; i <= upperBound; i++){
        int denominator = 2*i-1;
        answer += j * 4.0/denominator;
        j *= -1;
    }
    cout << answer <<endl;
    this_thread::sleep_for(chrono::seconds(3));    
}
    
int main(){
    
    string menuPrompt = "";
    menuPrompt += "-------------------------------------\n";
    menuPrompt += "1. Calculate the nth Fibonacci Number\n";
    menuPrompt += "2. Prime Number Printer\n";
    menuPrompt += "3. Random Number Tester\n";
    menuPrompt += "4. Exponent Calculator\n";
    menuPrompt += "5. Approximate pi\n";
    menuPrompt += "6. Quit program\n";
    menuPrompt += "-------------------------------------\n";
    menuPrompt += "Enter your choice: ";

    bool runProgram = true;
    srand(time(NULL));

    // main program loop
    do{

        // print the menu to the console
        clearScreen();
        cout << menuPrompt;
        int choice;
        cin >> choice;

        switch(choice){
            case 1:
                // write your code for case 1 here
                clearScreen();
                fibonacciGenerator();
                clearScreen();
                // end case 1
                break;
            case 2:
                // write your code for case 2 here
                clearScreen();
                primeGenerator();
                clearScreen();
                // end case 2
                break;
            case 3:
                // write your code for case 3 here
                clearScreen();
                randomNumberTest();
                clearScreen();
                // end case 3
                break;
            case 4:
                // write your code for case 4 here
                clearScreen();
                exponentCalculator();
                clearScreen();
                // end case 4
                break;
            case 5:
                // write your code for case 5 here
                clearScreen();
                approximatePi();
                clearScreen();
                // end case 5
                break;
            case 6:
                // write your code for case 6 here
                runProgram = false;
                // end case 6
                break;
            default:
                // default case executes if non of the cases match
                clearScreen();
                cout << "You entered [" << choice << "] Please enter a valid menu choice (1-6). " << endl;
                this_thread::sleep_for(chrono::seconds(2));
                break;
        }

    }while(runProgram);

    // exit the program
    return 0;
}
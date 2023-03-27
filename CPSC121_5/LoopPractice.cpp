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
#include<iomanip>

#ifdef _WIN32 //This if statement is used to change the library used depending on OS architecture.
#include <windows.h>
#else
#include <cstdlib>
#endif

using namespace std;

void clearScreen(){ //function to clear terminal
#ifdef _WIN32
    system("cls"); //Run system command CLS or CLear
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
    if(nthNumber == 1){//If the number selected is 1 or 2, output the preset values of the Fibonacci sequence
        cout << fibNumber1 <<endl;clearScreen();
    }
    else if(nthNumber == 2) {
        cout << fibNumber2 <<endl;
    }
    else{
        for(int i=3; i<=nthNumber; i++){//For anything else, use the For loop to calculate the value
            fibNumber = fibNumber1 + fibNumber2;
            fibNumber1 = fibNumber2;
            fibNumber2 = fibNumber; //sets value 2 as the previously calculated value
        }
        cout << "The number associated with the " << nthNumber << " of the fibonacci sequence is: " << fibNumber <<endl;
        this_thread::sleep_for(chrono::seconds(3)); //sleep before clearing screen
    }
}

bool isPrime(int n){
    if(n<2)
        return false;

    for(int i = 2; i<n; i++){ //loop to determine if a number is prime using the Not Prime case first.
        if(n%i == 0)
            return false; //if the number N % the iteration i is = 0, the number is not prime.
        }
        return true;
}

void primeGenerator(){
    int nthNumber;
    cout << "For what number do you want to find the prime numbers in its range from 0? " << endl;
    cin >> nthNumber;
    cout << endl;
    for(int i=1; i<=nthNumber; i++){
        if(isPrime(i)){ // if the function isPrime returns true and print the number
            cout << i << " ";}
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
    randomNumber = rand()%upperBound; //generate a random number

    while(!sameNumber){// while the value is set to not true, run the following loop
        secRandNumber = rand()%upperBound;
        if (secRandNumber==randomNumber){ //if the new number = the original number, break the loop
            sameNumber = true;
        }else{
            i++; //else increase the counter
            sameNumber = false;
        }
    }
    cout << "It took: " << i << " attempts to find " << randomNumber << " again." << endl; //Output the attempts it took.
    this_thread::sleep_for(chrono::seconds(3));   
}    

void exponentCalculator(){
    int base, exponent, answer;
    cout << "Enter a base: ";
    cin >> base;
    cout << "Enter an exponent: ";
    cin >> exponent;
    
    answer = base; //set the anser equal to the base due to 2^1 = 2
    for(int i = 1; i < exponent; i++){
        answer = answer * base; //multiply by 2 until the exponent desired is reached.
    }
    cout << "The answer is: " << answer << endl;
    this_thread::sleep_for(chrono::seconds(3)); 
}

void approximatePi(){
    int upperBound = 214748364; //UpperBound at the max Int limit was not precise so I decreased it.
    int j = 1;
    double answer = 0.0;
    for (int i = 1; i <= upperBound; i++){ //Run a loop that runs the function until the upperBound is met
        int denominator = 2*i-1; //determine the denominator depending on the iteration
        answer += j * 4.0/denominator;
        j *= -1; //change the sign by multiplying by -1
    }

    int precision;
    cout << "To what percision of decimals do you want PI to be calculated? "<<endl;
    cin >> precision;

    cout << setprecision(precision) << answer <<endl;
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
        cin >> choice; // using CIN instead of Getline due to STOI errors found with newlines or empty characters.

        switch(choice){
            case 1:
                // write your code for case 1 here
                clearScreen();
                fibonacciGenerator(); //function for fibonacci
                clearScreen();
                // end case 1
                break;
            case 2:
                // write your code for case 2 here
                clearScreen();
                primeGenerator(); //function for prime Number
                clearScreen();
                // end case 2
                break;
            case 3:
                // write your code for case 3 here
                clearScreen();
                randomNumberTest(); //function for randonNumber
                clearScreen();
                // end case 3
                break;
            case 4:
                // write your code for case 4 here
                clearScreen();
                exponentCalculator(); //function for exponent calculation
                clearScreen();
                // end case 4
                break;
            case 5:
                // write your code for case 5 here
                clearScreen();
                approximatePi(); //function for PI
                clearScreen();
                // end case 5
                break;
            case 6:
                // write your code for case 6 here
                clearScreen();
                cout << "Exiting program, have a great day!" << endl;
                this_thread::sleep_for(chrono::seconds(2));
                clearScreen();
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
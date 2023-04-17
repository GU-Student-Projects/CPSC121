/**
 * Author:
 * Date Modified
 * Description:
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

/**
 * Function:        clearScreen();
 * Return:          none (void)
 * Description:     Clear Screen using terminal command cls or clear
*/
void clearScreen();

/**
 * Function:        printReverse(const int NUMBER);
 * Parameters:      integer NUMBER is the original number we will print in reverse
 *                  NUMBER must be a positive integer with 1 or more digits
 * Return:          none (void)
 * Description:     Print the digits of NUMBER in reverse order.
 *                  E.g. if NUMBER is 12345, function should print 54321 
*/
void printReverse(const int NUMBER);
/**
 * Function:        oddEvenZero(const int NUMBER);
 * Parameters:      integer NUMBER
 *                  NUMBER passed in must be an integer zero or greater
 * Return:          none (void)
 * Description:     Count and print how many even, odd, and zero numbers are in
 *                  NUMBER. Zero does not count toward the even/odd count.
 *                  E.g. 
 *                  if NUMBER is 012345, print:
 *                      Even numbers:   2
 *                      Odd numbers:    3
 *                      Zero numbers:   1
 * 
 *                  if NUMBER is 0001111, print:
 *                      Even numbers:   0
 *                      Odd numbers:    4
 *                      Zero numbers:   3
 * 
 *                  if NUMBER is 23232222, print:
 *                      Even numbers:   6
 *                      Odd numbers:    2
 *                      Zero numbers:   0
 * 
 * 
*/
void oddEvenZero(const int NUMBER);
/**
 * Function:        nFactorial(const int NUMBER);
 * Parameters:      integer NUMBER is the number of terms to calculate factorial
 *                  NUMBER passed in must be 1 or greater
 * Return:          int (nFactorial)
 * Description:     Calculate the factorial to the nth term.
*/
double nFactorial(int NUMBER);

/**
 * Function:        printE(const int NUMBER);
 * Parameters:      integer NUMBER is the number of terms to calculate E
 *                  NUMBER passed in must be 1 or greater
 * Return:          none (void)
 * Description:     Print the calculated value of E
 *                  The value of e is the value (1 + 1/n)n
 *                  In other words e is equal to 1 + 1/1! + 1/2! + 1/3! + 1/4! + 1/5! + 1/6! + 1/7! + ... (etc)
 *                  For n == 1 e is 2.0000, for n == 2 e is 2.25, for n == 10 e is 2.59374
 * 
 *                  NOTE: You can't use arrays, strings or any methods from any classes.  You have to 
 *                  brute force the answer
*/
void printE(const int NUMBER);

/**
 * Function:        printMenu()
 * Parameters:      none
 * Return:          none (void)
 * Description:     prints the menu to the terminal
*/
void printMenu();

int main(){

    bool runProgram = true;
    string menuChoice;

    do{
        printMenu();
        getline(cin, menuChoice);
        int choice = stoi(menuChoice);

        switch(choice){
            case 1:
            {
                clearScreen();
                cout << "What number would you like reversed? ";
                string input;
                getline(cin, input);
                int number = stoi(input);
                clearScreen();
                printReverse(number);
                clearScreen();
                break;
            }
            case 2:
            {
                clearScreen();
                cout << "What number would you like to input? ";
                string input;
                getline(cin, input);
                int number = stoi(input);
                clearScreen();
                oddEvenZero(number);
                clearScreen();
                break;
            }
            case 3:
            {
                clearScreen();
                cout << "For what value of N would you like to aproximate Euler's number? ";
                string input;
                getline(cin, input);
                int number = stoi(input);
                clearScreen();
                printE(number);
                clearScreen();
                break;
            }
            case 4:
            {
                clearScreen();
                cout << "Exiting program, have a great day!" << endl;
                this_thread::sleep_for(chrono::seconds(2));
                clearScreen();
                runProgram = false;
                break;
            }
            default:
                {
                clearScreen();
                cout << "You entered [" << choice << "] Please enter a valid menu choice (1-4). " << endl;
                this_thread::sleep_for(chrono::seconds(2));
                break;
                }
        }


    }while(runProgram);

    return 0;
}

void printMenu(){
    string menuPrompt = "";
    menuPrompt += "-------------------------------------\n";
    menuPrompt += "1. Print Reverse\n";
    menuPrompt += "2. Odd Even Zero\n";
    menuPrompt += "3. Print e\n";
    menuPrompt += "4. Quit program\n";
    menuPrompt += "-------------------------------------\n";
    menuPrompt += "Enter your choice: ";
    cout << menuPrompt << endl;
}

//write your functions below here

void printReverse(const int NUMBER){
    int baseNumber = NUMBER;
    int reverseNumber = 0;

    while(baseNumber != 0){
        reverseNumber *= 10;
        reverseNumber += baseNumber % 10;
        baseNumber /= 10;
    }
    cout << "The reverse of " << NUMBER << " is " << reverseNumber << "." << endl;
    this_thread::sleep_for(chrono::seconds(3)); //sleep before clearing screen
}

void oddEvenZero(const int NUMBER){
    int baseNumber = NUMBER;
    int evenCount =0; int oddCount = 0; int zeroCount = 0;

    while(baseNumber!=0){
        int resultant = baseNumber % 10;
        if (resultant % 10 == 0){
            zeroCount++;
        }
        else if (resultant % 2 == 0){
            evenCount++;
        }
        else{
            oddCount++;
        }
        baseNumber /= 10;
    }

    string message = "In the number " + to_string(NUMBER) + "\n";
    message += "\t Even Numbers: " + to_string(evenCount) + "\n";
    message += "\t Odd Numbers: " + to_string(oddCount) + "\n";
    message += "\t Zero Numbers: " + to_string(zeroCount) + "\n";
    cout << message << endl;
    this_thread::sleep_for(chrono::seconds(3)); //sleep before clearing screen

}
void printE(const int NUMBER){
    int baseNumber = NUMBER;
    double eulerAprox = 1;
    for(int i = 1; i<= baseNumber; i++){
        int factorialNumber = nFactorial(i);
        eulerAprox += (1.0/factorialNumber);
        
    }
    cout << setprecision(5) << fixed << "The approximation of euler's number to the " << NUMBER;
    if (NUMBER == 1){
        cout << "st term is " << eulerAprox << endl;
    }
    else if (NUMBER == 2){
        cout << "nd term is " << eulerAprox << endl;
    }
    else if (NUMBER == 3){
        cout << "rd term is " << eulerAprox << endl;
    }    
    else{
        cout << "th term is " << eulerAprox << endl;
    } 
    this_thread::sleep_for(chrono::seconds(3)); //sleep before clearing screen

}

double nFactorial(const int NUMBER){
    int baseNumber = NUMBER;
    double factorialNumber = NUMBER;
    while (baseNumber > 1){
        factorialNumber *= --baseNumber;
    }
    return factorialNumber;
}
void clearScreen(){ //function to clear terminal
#ifdef _WIN32
    system("cls"); //Run system command CLS or CLear
#else
    system("clear");
#endif
}
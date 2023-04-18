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
#include<fstream>

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
 * Function:        getValidInput(const string&);
 * Parameters:      string Prompt is the prompt
 * Return:          number (int)
 * Description:     Validate input n>=1
*/
int getValidInput(const string& prompt);
/**
 * Function:        printMenu()
 * Parameters:      none
 * Return:          none (void)
 * Description:     prints the menu to the terminal
*/
void printMenu();

void writeToFile(string input, string filename);

int main(){
    bool runProgram = true;
    string menuChoice;
    string filename = "output.txt";

    do{
        clearScreen();
        printMenu();
        getline(cin, menuChoice);
        writeToFile(menuChoice, "output.txt");
        int choice = stoi(menuChoice);

        switch(choice){
            case 1:
            {
                string prompt = "What number would you like reversed? ";
                cout << prompt;
                writeToFile(prompt, "output.txt");
                string input;
                getline(cin, input);
                writeToFile(input, "output.txt");
                int number = stoi(input);
                printReverse(number);
                break;
            }
            case 2:
            {
                string prompt = "What number would you like to input? ";
                cout << endl << prompt;
                writeToFile(prompt, "output.txt");
                string input;
                getline(cin, input);
                writeToFile(input, "output.txt");
                int number = stoi(input);
                oddEvenZero(number);
                break;
            }
            case 3:
            {
                string prompt = "For what value of N would you like to aproximate Euler's number? ";
                writeToFile(prompt, "output.txt");
                int number = getValidInput(prompt);
                printE(number);
                break;
            }
            case 4:
            {
                clearScreen();
                string prompt = "Exiting program, have a great day!";
                cout << prompt << endl;
                writeToFile(prompt, "output.txt");
                this_thread::sleep_for(chrono::seconds(2));
                clearScreen();
                runProgram = false;
                break;
            }
            default:
                {
                clearScreen();
                string prompt = "You entered [" + to_string(choice) + "] Please enter a valid menu choice (1-4). ";
                cout << prompt << endl;
                writeToFile(prompt, "output.txt");
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
    cout << menuPrompt << " ";
    writeToFile(menuPrompt, "output.txt");
}

//write your functions below here

void printReverse(const int NUMBER){
    clearScreen();
    int baseNumber = NUMBER;
    int reverseNumber = 0;

    while(baseNumber != 0){
        reverseNumber *= 10;
        reverseNumber += baseNumber % 10; //add the remainder of % 10 to the reversed number
        baseNumber /= 10;
    }

    string output = "The reverse of " + to_string(NUMBER) + " is " + to_string(reverseNumber) + ".\n";
    cout << output;
    writeToFile(output, "output.txt");
    this_thread::sleep_for(chrono::seconds(3)); //sleep before clearing screen
}
void oddEvenZero(const int NUMBER){
    clearScreen();
    int baseNumber = NUMBER;
    int evenCount =0; int oddCount = 0; int zeroCount = 0;

    while(baseNumber!=0){
        int resultant = baseNumber % 10;
        if (resultant % 10 == 0){ //if % matches one of these conditionals, add 1 to there tally
            zeroCount++;
        }
        else if (resultant % 2 == 0){
            evenCount++;
        }
        else{
            oddCount++;
        }
        baseNumber /= 10; //dividing by 10 to get the next number in the input
    }

    string message = "In the number " + to_string(NUMBER) + "\n"; //convert int to string to accomodate for tabs
    message += "\t Even Numbers: " + to_string(evenCount) + "\n";
    message += "\t Odd Numbers: " + to_string(oddCount) + "\n";
    message += "\t Zero Numbers: " + to_string(zeroCount) + "\n";
    cout << message << endl;
    writeToFile(message, "output.txt");
    this_thread::sleep_for(chrono::seconds(3)); //sleep before clearing screen

}
void printE(const int NUMBER){
    clearScreen();
    int baseNumber = NUMBER;
    double eulerAprox = 1;
    for(int i = 1; i<= baseNumber; i++){
        int factorialNumber = nFactorial(i); //call the function to calculate the factorial
        eulerAprox += (1.0/factorialNumber); // add by 1/factorial number
        
    }
    string output = "The approximation of euler's number to the " + to_string(NUMBER);
    cout << setprecision(5) << fixed;
    if (NUMBER == 1){
        output += ("st term is" + to_string(eulerAprox));
        writeToFile(output, "output.txt");
        cout << output << endl; //conditional to change the suffix
    }
    else if (NUMBER == 2){
        output += ("nd term is " + to_string(eulerAprox));
        writeToFile(output, "output.txt");
        cout << output << endl;
    }
    else if (NUMBER == 3){
        output += ("rd term is " + to_string(eulerAprox));
        writeToFile(output, "output.txt");
        cout << output << endl;
    }    
    else{
        output += ("th term is " + to_string(eulerAprox));
        writeToFile(output, "output.txt");
        cout << output << endl;
    } 
    this_thread::sleep_for(chrono::seconds(3)); //sleep before clearing screen

}
double nFactorial(const int NUMBER){ //calculate the factorial to the nth term
    int baseNumber = NUMBER;
    double factorialNumber = NUMBER;
    while (baseNumber > 1){
        factorialNumber *= --baseNumber; //multiply the factorial number by baseNumber - 1
    }
    return factorialNumber;
}
int getValidInput(const string& prompt){ //input validation for non numbers and ints < 1
    string input;
    int number;
    bool validInput = false;
    cout << endl << prompt;
    string error = "Invalid input, please enter a valid integer greater than or equal to 1.";               
    while (!validInput) {
        getline(cin, input);
        writeToFile(input, "output.txt");
        try {
            number = stoi(input);
            }
        catch (const invalid_argument&) {
            clearScreen();
            cout << error << endl;
            writeToFile(error, "output.txt");
            cout << prompt;
            writeToFile(prompt, "output.txt");
            continue;
        }
        if (number < 1) {
            clearScreen();
            cout << error << endl;
            writeToFile(error, "output.txt");
            cout << prompt;
            writeToFile(prompt, "output.txt");
        }
        else {
            clearScreen();
            validInput = true;
        }
    }
    return number;
}
void clearScreen(){ //function to clear terminal
#ifdef _WIN32
    system("cls"); //Run system command CLS or CLear
#else
    system("clear");
#endif
}

void writeToFile(string input, string filename) {
    ofstream outputFile(filename, ios::app);
    outputFile << input << endl;
    outputFile.close();
}
/**
 * file:            UtilityCalculator.cpp
 * author:          Gabe DiMartino
 * date modified:   February 20 2023
 * description:     Calculate water bill for the month
*/

#include<iostream>
#include<cmath>
#include<string>

using namespace std;

double meterStart, meterEnd;

double getValidInput(const string& prompt){ // function to test if a valid double has been input
    double input;
    bool validInput;

    while (!validInput) {
        cout << prompt;
        if (cin >> input && (input >= 0 && input < 1000000000)){ // check to see if value is greater than 0
            validInput = true; // if the statement is valid, the boolean is changed to true and accepted
        } else {
            cout << "Invalid input. Please enter a number greater than or equal 0"<<endl;
            cin.clear(); // if the number is less than or = 0, the input is ignored
            validInput = false;
        }
    }

    return input;
}


char getValidCodeInput(const string& prompt){ // function to test if a valid double has been input
    char input;
    const char acceptableInputs[] = {'r','R','c','C','i','I'};
    bool validInput;

    while (!validInput) {
        cout << prompt;
        if (cin >> input) { 
            for (char c : acceptableInputs) {
                if (input == c){
                    validInput = true; // if the statement is valid, the boolean is changed to true and accepted
                }
            }   
        } 
        if (!validInput) {
            cout << "Invalid input. Please enter a valid character R C or I"<<endl;
            cin.clear(); // if the value is not on the list, the input is ignored
            validInput = false;
        }
    }

    return input;
}

int main(int argc, char *argv[]){

    char customerCode;
    string bannerMessage;
    bannerMessage += "+-----------------------+\n";
    bannerMessage += "|  Utility  Calculator  |\n";
    bannerMessage += "+-----------------------+\n";
    cout << bannerMessage << endl;
    cout.precision(2);

    meterStart = getValidInput("What is your starting value? "); // runs the function get ValidInput with the prompt
    meterEnd = getValidInput("What is your ending value value? ");
    customerCode = getValidCodeInput("What is your customer code? ");

    meterStart = meterStart/10.0;
    meterEnd = meterEnd/10.0;

    if (meterStart > meterEnd){ //if the ending value is less than the starting, 100000000 is added due to the analog limitation of 9 digits
         meterEnd += 100000000;
    }

    double waterCost = 0;

    cout << "You used " << fixed << (meterEnd - meterStart) << " gallons of water this month!" << endl;


    if (customerCode == 'r' || customerCode ==  'R') { // comparison statement for both lower and capital cased letters
            waterCost = (((meterEnd - meterStart) * 0.0005) + 15);
            cout << "Your cost is $" << fixed << waterCost << endl; // ensures non scientific notation and precision of 2 decimals

    }

    if (customerCode == 'c' || customerCode == 'C'){
            waterCost = (((meterEnd - meterStart) * 0.00002) + 1000);
            cout << "Your cost is $" << fixed << waterCost << endl;

    }

    if (customerCode == 'i' || customerCode == 'I'){
        if (meterEnd - meterStart < 4000000){ // series of IF statements to determine if water is less that 4 million, between 4 and 10 million, or greater
            waterCost = (((meterEnd-meterStart)*0.00002) + 1000);
            cout << "Your cost is $" << fixed << waterCost << endl;

        }
        if (((meterEnd - meterStart) >= 4000000) && ((meterEnd - meterStart) < 10000000)){
            waterCost = (((meterEnd - meterStart)*0.00001) + 2000);
            cout << "Your cost is $" << fixed << waterCost << endl;

        }
        if (meterEnd - meterStart >= 10000000){
            waterCost = ((((meterEnd-meterStart)-10000000)*0.0025) + 2500);
            cout << "Your cost is $" << fixed << waterCost << endl;
        }
    }
    
    return 0;
}
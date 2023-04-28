/**
 * file:            ica1.cpp
 * author:          Gabe DiMartino
 * date modified:   13 February 2023 22:53
 * description:     Calculate a cars monthly payment and total interest.
 * 
 */

#include<iostream>
#include<cmath>
#include<string>

using namespace std;
const int MONTHS_IN_YEAR = 12;

double getValidInput(const string& prompt){ // function to test if a valid double has been input
    double input;
    bool validInput;

    while (!validInput) {
        cout << prompt;
        if (cin >> input && input > 0){ // check to see if value is greater than 0
            validInput = true; // if the statement is valid, the boolean is changed to true and accepted
        } else {
            cout << "Invalid input. Please enter a number greater than 0"<<endl;
            cin.clear(); // if the number is less than or = 0, the input is ignored
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // paramaters to ignore if the number is too big
            validInput = false;
        }
    }

    return input;
}

int main(){
    string fullName, dreamCar;
    double carCost, carApr, monthsFinanced, monthInterest, monthlyPay, totalInterest;
    
    do {
    cout <<"What is your name? ";
    getline(cin,fullName);
    } while (fullName.empty()); // test to ensure the string value is not empty. Will loop if so.
    
    do {
    cout <<"What is your dream car? ";
    getline(cin,dreamCar);
    } while (dreamCar.empty());
    
    carCost = getValidInput("What is your dream car's cost? $"); // call the function getValidInput with the specified prompt
    carApr = getValidInput("What is your dream car's anual percentage rate? ");
    monthsFinanced = getValidInput("How many months will you be financing it? ");  

    monthInterest = (carApr/100)/MONTHS_IN_YEAR; // divide by 1200 to convert from APR to monthly interest rate

    monthlyPay = (monthInterest*carCost)/(1-pow(1 + monthInterest, -monthsFinanced)); // calculate the monthly payment

    totalInterest = monthInterest * monthsFinanced * carCost;

    cout.precision(2); //set precision to 2 decimal places
    cout << "Congratulations " << fullName <<" on buying a new "<< dreamCar << "!"<< endl;
    cout << "Your monthly paymont would $" << fixed << monthlyPay <<" with a total paid interest of $"<< totalInterest << endl;
    

    return 0;
}
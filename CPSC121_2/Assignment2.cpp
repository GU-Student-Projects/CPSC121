/**
 * file:            Assignment2.cpp
 * author:          Gabe DiMartino
 * date modified:   3 February 2023 9:53
 * description:     Calculate distance traveled in one day st vsrying speeds of the speed of light.
 * 
 */

#include<iostream>
using namespace std;

int main(int argc, char *argv[]){

    // Constant representing the speed of light, multiplied by a factor of 2.237 to turn it from m/s into mph
    const double SPEED_OF_LIGHT = 299792458 * 2.237;
    double oneP,tenP,fiftyP, hundredP;

    // Calculate the distance traveled at 1%, 10%, 50%, and 100% of the speed of light
    oneP = (0.01 * SPEED_OF_LIGHT)*24;
    tenP = (0.1 * SPEED_OF_LIGHT)*24;
    fiftyP = (0.5 * SPEED_OF_LIGHT)*24;
    hundredP = SPEED_OF_LIGHT * 24;

    // Output the results
    cout << "--Light Speed Distance Calculator--" << endl;
    cout << "Traveling at one-percent the Speed of Light, we will go: " << oneP << " miles in one day!" << endl;
    cout << "Traveling at ten-percent the Speed of Light, we will go: " << tenP << " miles in one day!" << endl;
    cout << "Traveling at fifty-percent the Speed of Light, we will go: " << fiftyP << "miles in one day!" << endl;
    cout << "Traveling at one-hundred-percent the Speed of Light, we will go: " << hundredP << " miles in one day!" << endl;


    return 0;
}
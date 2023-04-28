#include<iostream>
using namespace std;

int main(){
 
    cout << "----------------------------------------" << endl;
    cout << "Pattern 1" << endl;
    for (int i =0; i<10; i++){
        cout << "*" << endl;
            }
   

    cout << "----------------------------------------" << endl;
    cout << "Pattern 2" << endl;
    for (int i =0; i<10; i++){
        cout << "* ";
            }
    cout << endl;

    cout << "----------------------------------------" << endl;
    cout << "Pattern 3" << endl;

    for (int i = 0; i < 10; i ++) {
        for (int j = 0; j < 10; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    cout << "----------------------------------------" << endl;
    cout << "Pattern 4" << endl;

    for(int i = 0; i < 10; i++) {
        for(int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    cout << "----------------------------------------" << endl;
    cout << "Pattern 5" << endl;
    
    for(int i = 10; i > 0; i--) {
        for(int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    cout << "----------------------------------------" << endl;
    cout << "Pattern 6" << endl;
    
    for(int i = 0; i < 10; i+=2) {

        for(int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl << endl;
    }

    cout << "----------------------------------------" << endl;
    cout << "Pattern 7" << endl;

    for(int i = 1; i < 10; i+=2) {

        for(int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl << "*" << endl;
    }    


    cout << "----------------------------------------" << endl;
    cout << "Pattern 8" << endl;

    for (int i = 0; i < 10; i += 2) {
        for (int j = 0; j < 10; j++) {
            cout << "X ";
        }
        cout << endl;
        for (int j = 0; j < 10; j++) {
            cout << "O ";
        }
        cout << endl;
    }


    cout << "----------------------------------------" << endl;
    cout << "Pattern 9" << endl;
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (j%2 == 0){
                cout << "X ";
            }
            else{
                cout << "O ";
            }  

        }
        cout << endl;
    }

    cout << "----------------------------------------" << endl;
    cout << "Pattern 10" << endl;

    int decreasing = 9;
    int increasing = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            if ((j == increasing) || (j == decreasing)){
                cout << "X ";
                
            }
            else{
                cout << "O ";
            }  

        }
        increasing++;
        decreasing--;
        cout << endl;
    }
    for (int i = 0; i < 5; i++) {
        increasing--;
        decreasing++;
        for (int j = 0; j < 10; j++) {
            if ((j == increasing) || (j == decreasing)){
                cout << "X ";
                
            }
            else{
                cout << "O ";
            }  

        }
        cout << endl;
    }
    
    return 0;
}
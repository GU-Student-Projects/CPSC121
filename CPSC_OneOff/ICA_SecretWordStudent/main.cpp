#include<iostream>
#include<fstream>

using namespace std;

//encryption is the original ascii char + 2

string readFromFile(string filename);
string decrypt(string str);
string encrypt(string str);
string writeToFile(string filename);

int main(){
    
    string phrase = readFromFile("Phrase.txt");
    cout << "Encrypted Phrase: " << phrase << endl;
    phrase = decrypt(phrase);
    cout << "Decrypted Phrase: " << phrase << endl;

    return 0;
}

string readFromFile(string filename){
    string phrase;
    ifstream readLine(filename, ios::app);
    getline(readLine, phrase);
    return phrase;
}

string decrypt(string str){
    for( int i = 0; i<sizeof(str); i++){
        str[i] -= 2;
    }
    return str;
}

string encrypt(string str){
    for( int i = 0; i<sizeof(str); i++){
        str[i] += 2;
    }
    return str;    
}
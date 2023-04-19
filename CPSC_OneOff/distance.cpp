#include<iostream>
#include<cmath>

using namespace std;

void findDistance(const int x1, const int x2, const int y1, const int y2);

int main(){
    findDistance(5,8,6,11);
    return 0;
}

void findDistance(const int x1, const int x2, const int y1, const int y2){
    double distance = sqrt((pow((x2-x1),2))+(pow((y2-y1),2)));
    cout << distance << endl;
}


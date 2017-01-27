// Kate Archer
// Lab1b.cpp
// The purpose of this program is to calculate the nth term of a
// sequence (summation) using a single arithmetic expression.

#include <iostream>
#include <ctime>
using namespace std;

int main(){
    unsigned long n, nthTerm;

    cout << endl << "Enter the value for n: ";
    cin >> n;

    double startTime = clock();
    nthTerm = (n * (n + 1)) / 2;
    double endTime = clock();
    double totalTime = (endTime - startTime) / CLOCKS_PER_SEC;

    cout << "The " << n << "th term is : " << nthTerm << endl;
    cout << "Single Expression Time: " << totalTime << endl << endl;
    return 0;
}

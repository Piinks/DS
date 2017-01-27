// Kate Archer
// Lab1a.cpp
// The purpose of this program is to calculate the nth term of a
// sequence using a recursive function. The nth term is found by the
// summation of n and all preceding terms, the first being 1.

#include <iostream>
#include <ctime>
using namespace std;

unsigned long summation(unsigned long n);

int main(){
    unsigned long n, nthTerm;

    cout << endl << "Enter the value for n: ";
    cin >> n;

    double startTime = clock();
    nthTerm = summation(n);
    double endTime = clock();
    double totalTime = (endTime - startTime) / CLOCKS_PER_SEC;

    cout << "The " << n << "th term is: " << nthTerm << endl;
    cout << "Recursive Time: " << totalTime << endl << endl;
    return 0;
}

unsigned long summation(unsigned long n){
    if (n == 1)
        return 1;
    else
        return (summation(n-1) + n);
}

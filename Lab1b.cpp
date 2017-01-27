// Kate Archer
// Lab1b.cpp
// The purpose of this program is to calculate the nth term of a
// sequence using a for loop. The nth term is found by the
// summation of n and all preceding terms, the first being 1.

#include <iostream>
#include <ctime>
using namespace std;

int main(){
    int n;
    unsigned long nthTerm = 0;

    cout << endl << "Enter the value for n: ";
    cin >> n;

    double startTime = clock();
    for(int i = 1; i <= n; i++){
        nthTerm+=i;
    }
    double endTime = clock();
    double totalTime = (endTime - startTime) / CLOCKS_PER_SEC;

    cout << "The " << n << "th term is : " << nthTerm << endl;
    cout << "For Loop Time: " << totalTime << endl << endl;
    return 0;
}

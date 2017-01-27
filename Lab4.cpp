// Kate Archer
// Lab4.cpp
// The purpose of this lab is to create and implement a finite state machine that is capable of
// recognizing a*b*ab. The machine will read in ONE character at a time, change states and output
// before reading the next character.

#include <iostream>
using namespace std;

int main(){                     // Table for stateMatrix in comments below.
    int stateMatrix[6][6] = { {0, 1, 0}, {3, 2, 1}, {3, 2, 0}, {5, 4, 0}, {5, 5, 1}, {5, 5, 0}};
    char input;
    int currentState = 0;
    cout << stateMatrix[currentState][2];
    cin.get(input);             // Reads one character.
    while (input != '\n'){      // Then changes state and outputs.
        currentState = (input == 'a' ? stateMatrix[currentState][0] : stateMatrix[currentState][1]);
        cout << stateMatrix[currentState][2];
        cin.get(input);         // Reads the next character.
    }
    return 0;
}

//      a    b   out
//-------------------
// s0 | s0 | s1 | 0
// s1 | s3 | s2 | 1 * Recognizing State
// s2 | s3 | s2 | 0
// s3 | s5 | s4 | 0
// s4 | s5 | s5 | 1 * Recognizing State
// s5 | s5 | s5 | 0   Can no longer reach recognizing state

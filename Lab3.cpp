// Kate Archer
// Lab3.cpp
// The purpose of this program is to read in data for a graph, creating an adjacency matrix.
// It will then provide the user with a number of options: printing the matrix, finding
// isolated nodes, determining the degree of a node, fining euler paths, and checking
// the adjacency of two given nodes.

#include <iostream>
using namespace std;

void printMenu();

int main(){
    int numNodes;
    cout << "Please enter the number of nodes: ";
    cin >> numNodes;
    int adjMatrix[numNodes][numNodes];

    for(int i = 0; i < numNodes; i++){      // Inititalize zero matrix.
        for(int j = 0; j < numNodes; j++){
            adjMatrix[i][j]= 0;
        }
    }

    char marker;
    int startNode, endNode;
    int count = 1;
    cout << "Please enter the binary relation: " << endl;
    cin >> marker >> marker;                    // Reads the first { and then a ( or }.
    while(marker != '}'){                       // Tests for closing bracket.
        if(count > 1)
            cin >> marker;                      // After the first case, an additional read needs to take place for (
        cin >> startNode;
        cin >> marker;                          // Read the comma
        cin >> endNode;
        adjMatrix[startNode-1][endNode-1] += 1; // Updates adjacency matrix.
        cin >> marker >> marker;                // Will read in ) and then a , or } to test for the next loop
        count++;
    }

    int choice, zeroCount, degreeCount, node1, node2, oddCount;
    cout << endl;
    printMenu();
    cout << "What would you like to do? ";
    cin >> choice;
    while(choice < 6){

        switch(choice){

            case 1:
                // Print Adjacency Matrix
                cout << endl;
                for(int j = 0; j < numNodes; j++){
                    cout << endl;
                    for(int k = 0; k < numNodes; k++){
                        cout << adjMatrix[j][k] << ' ';
                    }
                }
                cout << endl;
                break;

            case 2:
                // Find Isolated Nodes
                cout << endl;
                zeroCount = 0;
                for(int i = 0; i < numNodes; i++){
                    for(int j = 0; j < numNodes; j++){
                        if(j==i)            // This is for the case of an isolated node that has loops
                            continue;
                        else if(adjMatrix[i][j] == 0)
                            zeroCount += 1;
                    }
                    if(zeroCount == numNodes-1)
                        cout << i+1 << " is an isolated node." << endl;
                    zeroCount = 0;
                }
                cout << endl;
                break;

            case 3:
                // Find the degree of a given node
                cout << endl;
                degreeCount = 0;
                cout << "Please enter the node: ";
                cin >> node1;
                for(int i = 0; i < numNodes; i++){
                    degreeCount += adjMatrix[node1-1][i];
                }
                cout << "The degree of node " << node1 << " is " << degreeCount << '.' << endl;
                break;

            case 4:
                // Find if there is an Euler path
                cout << endl;
                degreeCount = 0;
                oddCount = 0;
                for(int i = 0; i < numNodes; i++){
                    for(int j =0; j < numNodes; j++){
                        degreeCount += adjMatrix[i][j];
                    }
                    if (degreeCount%2 != 0)
                        oddCount += 1;
                    degreeCount = 0;
                }
                if(oddCount == 0 || oddCount == 2)
                    cout << "This graph has an Euler path." << endl;
                else
                    cout << "This graph does not have an Euler path." << endl;
                break;

            case 5:
                // Test if two nodes are adjacent
                cout << endl;
                cout << "Please enter the first node: ";
                cin >> node1;
                cout << "Please enter the second node: ";
                cin >> node2;
                if(adjMatrix[node1-1][node2-1] > 0)
                    cout << "Node " << node1 << " is adjacent to node " << node2 << '.' << endl;
                else
                    cout << "Node " << node1 << " is not adjacent to node " << node2 << '.' << endl;
                break;

            default:
                break;
        }
        cout << endl;
        printMenu();
        cout << "What would you like to do? ";
        cin >> choice;
    }
    cout << "Buh-Bye!" << endl;
    return 0;
}

void printMenu(){
    cout << "1. Print the Adjacency Matrix." << endl;
    cout << "2. Determine if there are any isolated nodes." << endl;
    cout << "3. Determine the degree of a node." << endl;
    cout << "4. Determine if an Euler path exists." << endl;
    cout << "5. Determine is one node is adjacent to another." << endl;
    cout << "6. Quit" << endl;
}

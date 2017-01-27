// Kate Archer
// Lab2.cpp
// The purpose of this program is to read in and sort a matrix.
// The matrix will be sorted according to the column specified by the user.

#include <iostream>
using namespace std;

void swapRow(int matrix[][10], int row1, int row2, int size);
				// ^ With a given max size of 10, the column of the matrix has been initialized
				// as such for the purpose of this function call.
int main() {
	int rows, col, sortCol;
	cout << "Input the rows and columns: ";
	cin >> rows >> col;					// Reads in rows and columns.
	int matrix[rows][10];

	cout << "Input the matrix: " << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < col; j++) {
			cin >> matrix[i][j];		// Reads in the matrix.
		}
	}

	cout << "Input the sort column number: ";
	cin >> sortCol;						// Reads in the column to sort by.
	sortCol -= 1;

	for(int i = rows-1; i >= 0; i--){	// Sorts the matrix via bubble sort.
		for(int j = 0; j < i; j ++){
			if(matrix[j][sortCol] > matrix[j+1][sortCol])
				swapRow(matrix, j, j+1, col);
		}
	}

    cout << "The sorted matrix:";		// Prints the sorted matrix.
    for (int i = 0; i < rows; i++) {
        cout << endl;
		for (int j = 0; j < col; j++) {
			cout << matrix[i][j] << " ";
		}
	}
    cout << endl;
	return 0;
}

void swapRow(int matrix[][10], int row1, int row2, int size){
	int tempRow[size];
	for(int i = 0; i < size; i++){			// Copies row1 into a temp array
		tempRow[i] = matrix[row1][i];
	}
	for(int j = 0; j < size; j++){			// Replaces row1 with row2.
		matrix[row1][j] = matrix[row2][j];
	}
	for(int k = 0; k < size; k++){			// Repplaces row2 with row 1.
		matrix[row2][k] = tempRow[k];
	}
}

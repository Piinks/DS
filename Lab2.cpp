// Kate Archer
// Lab2.cpp
// The purpose of this program is to read in and sort a matrix.

#include <iostream>
using namespace std;
void copyRow(int matrix[][10], int rowToInsert[], int size, int rowNum);
					// ^ With a max size of 10, the column of the matrix has been initialized
					// as such for the purpose of this function.
int main() {
	int rows, col, sortCol;
	cout << "Input the rows and columns: ";
	cin >> rows >> col;				// Reads in rows and columns.
	int matrix[rows][10];
	int rowToInsert[col];

	cout << "Input the matrix: " << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < col; j++) {
			cin >> matrix[i][j];	// Reads in the matrix.
		}
	}

	cout << "Input the sort column number: ";
	cin >> sortCol;					// Reads in the column to sort by.
	sortCol -= 1;

	for (int i = 1; i < rows; i++) {
		copyRow(matrix, rowToInsert, col, i);
		int j = i;
		while (j > 0 && matrix[j - 1][sortCol] > rowToInsert[sortCol]) {
			for (int k = 0; k < col; k++) {
				matrix[j][k] = matrix[j - 1][k];
				//cout << "Changed row " << j << " to row " << j-1 << endl;
			}
			j--;
		}
		copyRow(matrix, rowToInsert, col, j);
	}

    cout << "The sorted matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        cout << endl;
		for (int j = 0; j < col; j++) {
			cout << matrix[i][j] << " ";
		}
	}
    cout << endl;



	return 0;
}

void copyRow(int matrix[][10], int rowToInsert[], int size, int rowNum) {
    //cout << "Copied Row: ";
    for (int k = 0; k < size; k++) {
		rowToInsert[k] = matrix[rowNum][k];
        //cout << " " << rowToInsert[k];
	}
    //cout << endl;
}

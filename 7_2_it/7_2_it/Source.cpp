#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void CreateMatrix(int** matrix, int rows, int cols, int minVal, int maxVal) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = minVal + rand() % (maxVal - minVal + 1);
        }
    }
}

void PrintMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

int FindMinInEvenColumn(int** matrix, int rows, int cols, int col) {
    int minVal = matrix[0][col];
    for (int i = 1; i < rows; i++) {
        if (matrix[i][col] < minVal) {
            minVal = matrix[i][col];
        }
    }
    return minVal;
}

int FindMaxInOddColumn(int** matrix, int rows, int cols, int col) {
    int maxVal = matrix[0][col];
    for (int i = 1; i < rows; i++) {
        if (matrix[i][col] > maxVal) {
            maxVal = matrix[i][col];
        }
    }
    return maxVal;
}

void SwapElements(int** matrix, int rows, int evenCol, int oddCol) {
    int minInEven = FindMinInEvenColumn(matrix, rows, rows, evenCol);
    int maxInOdd = FindMaxInOddColumn(matrix, rows, rows, oddCol);

    for (int i = 0; i < rows; i++) {
        if (matrix[i][evenCol] == minInEven) {
            matrix[i][evenCol] = maxInOdd;
        }
        if (matrix[i][oddCol] == maxInOdd) {
            matrix[i][oddCol] = minInEven;
        }
    }
}
void HelpSwap(int cols, int** matrix, int rows) {
    for (int col = 0; col < cols - 1; col += 2) {
        SwapElements(matrix, rows, col, col + 1);
    }
}


int main() {
    srand(static_cast<unsigned>(time(NULL)));

    const int rows = 5, cols = 4;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    int minVal = -100;
    int maxVal = 100;

    CreateMatrix(matrix, rows, cols, minVal, maxVal);

    cout << "Original Matrix:" << endl;
    PrintMatrix(matrix, rows, cols);

    HelpSwap(cols, matrix, rows);

    cout << "Modified Matrix:" << endl;
    PrintMatrix(matrix, rows, cols);

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

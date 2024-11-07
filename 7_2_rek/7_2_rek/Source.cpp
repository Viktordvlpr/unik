#include <iostream>
#include <ctime>
#include <iomanip>
#include <climits>

using namespace std;

void Create(int** matrix, const int rowCount, const int colCount,
    const int Low, const int High, int i, int j)
{
    matrix[i][j] = Low + rand() % (High - Low + 1);

    if (j < colCount - 1)
        Create(matrix, rowCount, colCount, Low, High, i, j + 1);
    else
        if (i < rowCount - 1)
            Create(matrix, rowCount, colCount, Low, High, i + 1, 0);
}

void Print(int** matrix, const int rowCount, const int colCount, int i, int j)
{
    cout << setw(4) << matrix[i][j];
    if (j < colCount - 1)
        Print(matrix, rowCount, colCount, i, j + 1);
    else
        if (i < rowCount - 1)
        {
            cout << endl;
            Print(matrix, rowCount, colCount, i + 1, 0);
        }
        else
            cout << endl << endl;
}
int FindMinInColumn(int** matrix, int rows, int col, int row = 0, int minVal = -1) {
    if (row >= rows) {
        return minVal;
    }

    if (matrix[row][col] < minVal) {
        minVal = matrix[row][col];
    }

    return FindMinInColumn(matrix, rows, col, row + 1, minVal);
}

int FindMaxInColumn(int** matrix, int rows, int col, int row = 0, int maxVal = -1) {
    if (row >= rows) {
        return maxVal;
    }

    if (matrix[row][col] > maxVal) {
        maxVal = matrix[row][col];
    }

    return FindMaxInColumn(matrix, rows, col, row + 1, maxVal);
}

void SwapPairsOfColumns(int** matrix, int rows, int cols, int evenCol = 0) {
    if (evenCol >= cols - 1) {
        return;
    }

    int oddCol = evenCol + 1;
    int minInEven = FindMinInColumn(matrix, rows, evenCol);
    int maxInOdd = FindMaxInColumn(matrix, rows, oddCol);

    for (int i = 0; i < rows; i++) {
        if (matrix[i][evenCol] == minInEven) {
            matrix[i][evenCol] = maxInOdd;
        }
        if (matrix[i][oddCol] == maxInOdd) {
            matrix[i][oddCol] = minInEven;
        }
    }

    SwapPairsOfColumns(matrix, rows, cols, evenCol + 2);
}

int main() {
    srand(static_cast<unsigned>(time(NULL)));

    const int rows = 5, cols = 4;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    int minVal = -99;
    int maxVal = 99;

    Create(matrix, rows, cols, minVal, maxVal, 0, 0);

    cout << "Original Matrix:" << endl;
    Print(matrix, rows, cols, 0, 0);

    SwapPairsOfColumns(matrix, rows, cols);

    cout << "Modified Matrix:" << endl;
    Print(matrix, rows, cols, 0, 0);

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

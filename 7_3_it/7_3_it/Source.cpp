#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void CreateMatrixRecursive(int** matrix, int i, int j, int rows, int cols, int minVal, int maxVal) {
    if (i >= rows) {
        return;
    }

    matrix[i][j] = minVal + rand() % (maxVal - minVal + 1);

    if (j + 1 < cols) {
        CreateMatrixRecursive(matrix, i, j + 1, rows, cols, minVal, maxVal);
    }
    else {
        CreateMatrixRecursive(matrix, i + 1, 0, rows, cols, minVal, maxVal);
    }
}

void PrintMatrix(int** matrix, int rows, int cols, int i, int j) {
    if (i >= rows) {
        return;
    }

    cout << setw(4) << matrix[i][j];

    if (j + 1 < cols) {
        PrintMatrix(matrix, rows, cols, i, j + 1);
    }
    else {
        cout << endl;
        PrintMatrix(matrix, rows, cols, i + 1, 0);
    }
}

int countRowsWithZerosRecursive(int** matrix, int k, int n, int i = 0, int j = 0, int count = 0) {
    if (i >= k) {
        return count;
    }

    if (j >= n) {
        return countRowsWithZerosRecursive(matrix, k, n, i + 1, 0);
    }

    if (matrix[i][j] == 0) {
        count = 1 + countRowsWithZerosRecursive(matrix, k, n, i, j + 1);
    }
    else {
        return countRowsWithZerosRecursive(matrix, k, n, i, j + 1);
    }
}

void findLongestSeriesColumnRecursive(int** matrix, int i, int j, int k, int n, int& columnWithMaxSeries, int maxSeriesLength, int currentSeries) {
    if (j >= n) {
        return;
    }

    if (i < k) {
        if (i > 0 && matrix[i][j] == matrix[i - 1][j]) {
            currentSeries++;
        }

        if (currentSeries > 0 && currentSeries > maxSeriesLength) {
            maxSeriesLength = currentSeries;
            columnWithMaxSeries = j;
        }

        findLongestSeriesColumnRecursive(matrix, i + 1, j, k, n, columnWithMaxSeries, maxSeriesLength, currentSeries);
    }
    else {
        findLongestSeriesColumnRecursive(matrix, 0, j + 1, k, n, columnWithMaxSeries, maxSeriesLength, 0);
    }
}

int main() {
    srand(static_cast<unsigned>(time(NULL)));

    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    int minVal = -10;
    int maxVal = 10;

    int columnWithMaxSeries = -1;

    CreateMatrixRecursive(matrix, 0, 0, rows, cols, minVal, maxVal);

    PrintMatrix(matrix, rows, cols, 0, 0);

    cout << "Count zero: " << countRowsWithZerosRecursive(matrix, rows, cols) << endl;
    findLongestSeriesColumnRecursive(matrix, 1, 0, rows, cols, columnWithMaxSeries, 0, 0);
    cout << "Series(col): " << columnWithMaxSeries << endl;

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

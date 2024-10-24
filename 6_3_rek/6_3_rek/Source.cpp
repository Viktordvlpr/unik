#include <iostream>
#include <iomanip>
using namespace std;

void CreateArray(int* arr, int size, int Low, int High) {
    for (int i = 0; i < size; i++) {
        arr[i] = Low + rand() % (High - Low + 1);
    }
}

void PrintArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(4) << arr[i];
    }
    cout << endl;
}


void SwapEvenOddIndicesRecursive(int* arr, int size, int index = 0) {
    if (index >= size - 1) 
        return;

    swap(arr[index], arr[index + 1]);

    SwapEvenOddIndicesRecursive(arr, size, index + 2); // Рек викликається
}

int main() {
    srand((unsigned)time(0));

    const int n = 10;
    int arr[n];

    int Low = 1, High = 100;
    CreateArray(arr, n, Low, High);

    cout << "Original array: ";
    PrintArray(arr, n);
    SwapEvenOddIndicesRecursive(arr, n);

    cout << "Modified array: ";
    PrintArray(arr, n);

    return 0;
}
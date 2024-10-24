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


int MaxIndex(int* arr, int size) {
    int maxIdx = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIdx]) {
            maxIdx = i;
        }
    }
    return maxIdx;
}


int MinIndex(int* arr, int size) {
    int minIdx = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[minIdx]) {
            minIdx = i;
        }
    }
    return minIdx;
}


int SumIndices(int* arr, int size) {
    int maxIdx = MaxIndex(arr, size);
    int minIdx = MinIndex(arr, size);
    return maxIdx + minIdx;
}

int main() {
    srand((unsigned)time(0));

    const int n = 10;
    int arr[n];

    int Low = 1, High = 100;


    CreateArray(arr, n, Low, High);


    cout << "Array: ";
    PrintArray(arr, n);


    int sum = SumIndices(arr, n);


    cout << "Sum of indices of max and min elements: " << sum << endl;

    return 0;
}

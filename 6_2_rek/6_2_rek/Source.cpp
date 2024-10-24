#include <iostream>
#include <iomanip>
using namespace std;


void CreateArray(int* arr, int size, int Low, int High, int i = 0) {
    if (i == size) return;
    arr[i] = Low + rand() % (High - Low + 1);
    CreateArray(arr, size, Low, High, i + 1);
}


void PrintArray(int* arr, int size, int i = 0) {
    if (i == size) {
        cout << endl;
        return;
    }
    cout << setw(4) << arr[i];
    PrintArray(arr, size, i + 1);
}


int MaxIndex(int* arr, int size, int i = 0, int maxIdx = 0) {
    if (i == size) return maxIdx;
    if (arr[i] > arr[maxIdx]) maxIdx = i;
    return MaxIndex(arr, size, i + 1, maxIdx);
}


int MinIndex(int* arr, int size, int i = 0, int minIdx = 0) {
    if (i == size) return minIdx;
    if (arr[i] < arr[minIdx]) minIdx = i;
    return MinIndex(arr, size, i + 1, minIdx);
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

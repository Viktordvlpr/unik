#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;


void CreateArrayRecursive(double* arr, const int size, const int Low, const int High, int index = 0) {
    if (index == size) {
        return;
    }
    arr[index] = Low + rand() % (High - Low + 1) + (rand() % 100) / 100.0;
    CreateArrayRecursive(arr, size, Low, High, index + 1);
}


int CountLessThanCRecursive(const double* arr, const int size, const double C) {
    if (size == 0) {
        return 0;
    }
    int count = (arr[0] < C) ? 1 : 0;
    return count + CountLessThanCRecursive(arr + 1, size - 1, C);
}


int FindLastNegativeIndexRecursive(const double* arr, const int size, int currentIndex = 0) {
    if (currentIndex == size) {
        return -1;
    }
    int lastNegativeIndex = FindLastNegativeIndexRecursive(arr, size, currentIndex + 1);
    if (arr[currentIndex] < 0 && lastNegativeIndex == -1) {
        return currentIndex;
    }
    return lastNegativeIndex;
}

int SumAfterLastNegativeRecursive(const double* arr, const int size, int currentIndex, int sum = 0) {
    if (currentIndex == size) {
        return sum;
    }
    return SumAfterLastNegativeRecursive(arr, size, currentIndex + 1, sum + (int)arr[currentIndex]);
}


double FindMaxRecursive(const double* arr, const int size, int index = 0, double maxElement = -1e9) {
    if (index == size) {
        return maxElement;
    }
    if (arr[index] > maxElement) {
        maxElement = arr[index];
    }
    return FindMaxRecursive(arr, size, index + 1, maxElement);
}

void CopyElementsWithinThresholdRecursive(double* arr, double* temp, const double maxElement, const int size, int& j, int index = 0) {
    if (index == size) {
        return;
    }
    if (fabs(arr[index] - maxElement) / maxElement <= 0.2) {
        temp[j++] = arr[index];
    }
    CopyElementsWithinThresholdRecursive(arr, temp, maxElement, size, j, index + 1);
}

void CopyOtherElementsRecursive(double* arr, double* temp, const double maxElement, const int size, int& j, int index = 0) {
    if (index == size) {
        return;
    }
    if (fabs(arr[index] - maxElement) / maxElement > 0.2) {
        temp[j++] = arr[index];
    }
    CopyOtherElementsRecursive(arr, temp, maxElement, size, j, index + 1);
}


void CopyArrayRecursive(double* arr, double* temp, const int size, int index = 0) {
    if (index == size) {
        return;
    }
    arr[index] = temp[index];
    CopyArrayRecursive(arr, temp, size, index + 1);
}

void TransformArrayRecursive(double* arr, const int size) {
    double maxElement = FindMaxRecursive(arr, size);
    double* temp = new double[size];
    int j = 0;


    CopyElementsWithinThresholdRecursive(arr, temp, maxElement, size, j);


    CopyOtherElementsRecursive(arr, temp, maxElement, size, j);


    CopyArrayRecursive(arr, temp, size);

    delete[] temp;
}

int main() {
    srand((unsigned)time(NULL));

    int n;
    double C;
    cout << "Enter the size of the array (n): ";
    cin >> n;
    cout << "Enter the value of C: ";
    cin >> C;

    if (n <= 0) {
        cout << "Size must be positive." << endl;
        return 1;
    }

    double* arr = new double[n];
    int Low = -10;
    int High = 10;


    CreateArrayRecursive(arr, n, Low, High);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 1.1
    int count = CountLessThanCRecursive(arr, n, C);
    cout << "Count of elements less than C: " << count << endl;
    // 1.2
    int lastNegativeIndex = FindLastNegativeIndexRecursive(arr, n);
    int sum = SumAfterLastNegativeRecursive(arr, n, lastNegativeIndex + 1);
    cout << "Sum of integer parts after last negative element: " << sum << endl;
    // 2.
    TransformArrayRecursive(arr, n);

    cout << "Transformed array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}

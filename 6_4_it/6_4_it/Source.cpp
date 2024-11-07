#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;


void CreateArray(double* arr, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++) {
        arr[i] = Low + rand() % (High - Low + 1) + (rand() % 100) / 100.0;
    }
}


int CountLessThanC(const double* arr, const int size, const double C) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < C) {
            count++;
        }
    }
    return count;
}


int SumAfterLastNegative(const double* arr, const int size) {
    int sum = 0;
    int lastNegativeIndex = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            lastNegativeIndex = i;
        }
    }
    if (lastNegativeIndex != -1) {
        for (int i = lastNegativeIndex + 1; i < size; i++) {
            sum += (int)arr[i];
        }
    }
    return sum;
}


void TransformArray(double* arr, const int size) {
    double maxElement = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    double* temp = new double[size];
    int j = 0;


    for (int i = 0; i < size; i++) {
        if (fabs(arr[i] - maxElement) / maxElement <= 0.2) {
            temp[j++] = arr[i];
        }
    }


    for (int i = 0; i < size; i++) {
        if (fabs(arr[i] - maxElement) / maxElement > 0.2) {
            temp[j++] = arr[i];
        }
    }

    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }

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

    CreateArray(arr, n, Low, High);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 1.1. 
    int count = CountLessThanC(arr, n, C);
    cout << "Count of elements less than C: " << count << endl;


    int sum = SumAfterLastNegative(arr, n);
    cout << "Sum of integer parts after last negative element: " << sum << endl;

    // 2. 
    TransformArray(arr, n);

    cout << "Transformed array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}

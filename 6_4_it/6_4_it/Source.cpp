#include <iostream>
#include <iomanip>
#include <cmath> 
using namespace std;


double* CreateArray(int size) {
    double* arr = new double[size];
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
    return arr;
}


void PrintArray(double* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(8) << arr[i];
    }
    cout << endl;
}

// 1.1
int CountElementsLessThanC(double* arr, int size, double C) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < C) {
            count++;
        }
    }
    return count;
}

// 1.2
double SumOfIntegersAfterLastNegative(double* arr, int size) {
    int lastNegativeIndex = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            lastNegativeIndex = i;
        }
    }

    double sum = 0;
    for (int i = lastNegativeIndex + 1; i < size; i++) {
        sum += floor(arr[i]);
    }
    return sum;
}


double FindMaxElement(double* arr, int size) {
    double maxElement = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    return maxElement;
}

// 2
void TransformArray(double* arr, int size) {
    double maxElement = FindMaxElement(arr, size);
    double threshold = maxElement * 0.20;

    double* tempArray = new double[size]; 
    int j = 0;


    for (int i = 0; i < size; i++) {
        if (abs(arr[i] - maxElement) <= threshold) {
            tempArray[j++] = arr[i];
        }
    }


    for (int i = 0; i < size; i++) {
        if (abs(arr[i] - maxElement) > threshold) {
            tempArray[j++] = arr[i];
        }
    }


    for (int i = 0; i < size; i++) {
        arr[i] = tempArray[i];
    }

    delete[] tempArray;
}

int main() {
    int n;
    double C;


    cout << "Enter n: ";
    cin >> n;
    cout << "Enter C: ";
    cin >> C;


    double* arr = CreateArray(n);


    cout << "Original array: ";
    PrintArray(arr, n);

    int countLessThanC = CountElementsLessThanC(arr, n, C);
    cout << "Number of elements less than C: " << countLessThanC << endl;

    double sumIntegersAfterLastNegative = SumOfIntegersAfterLastNegative(arr, n);
    cout << "Sum of integer parts after the last negative element: " << sumIntegersAfterLastNegative << endl;
    TransformArray(arr, n);
    cout << "Transformed array: ";
    PrintArray(arr, n);

    delete[] arr;
    return 0;
}

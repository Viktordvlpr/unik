#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm> 


void createArray(std::vector<double>& arr, int n) {
    std::cout << "Введіть " << n << " елементів масиву:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
}


void printArray(const std::vector<double>& arr) {
    for (double el : arr) {
        std::cout << std::fixed << std::setprecision(2) << el << " ";
    }
    std::cout << std::endl;
}


int countLessThanC(const std::vector<double>& arr, double C, int index) {
    if (index >= arr.size()) {
        return 0;
    }
    return (arr[index] < C ? 1 : 0) + countLessThanC(arr, C, index + 1);
}


double sumIntegerPartsAfterLastNegative(const std::vector<double>& arr, int index) {
    if (index < 0) {
        return 0;
    }
    if (arr[index] < 0) {
        double sum = 0;
        for (int i = index + 1; i < arr.size(); ++i) {
            sum += static_cast<int>(arr[i]);
        }
        return sum;
    }
    return sumIntegerPartsAfterLastNegative(arr, index - 1);
}


void rearrangeArray(std::vector<double>& arr, double maxElement, int index, int& newSize) {
    if (index >= arr.size()) {
        return;
    }

    if (arr[index] >= maxElement * 0.8 && arr[index] <= maxElement * 1.2) {
        arr[newSize++] = arr[index];
    }

    rearrangeArray(arr, maxElement, index + 1, newSize);

    if (!(arr[index] >= maxElement * 0.8 && arr[index] <= maxElement * 1.2)) {
        arr[newSize++] = arr[index];
    }
}


int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int n;
    double C;


    std::cout << "Введіть розмір масиву (n): ";
    std::cin >> n;

    std::vector<double> arr(n);


    createArray(arr, n);


    std::cout << "Масив: ";
    printArray(arr);


    std::cout << "Введіть значення C: ";
    std::cin >> C;


    int count = countLessThanC(arr, C, 0);
    std::cout << "Кількість елементів, менших " << C << ": " << count << std::endl;


    double sum = sumIntegerPartsAfterLastNegative(arr, n - 1);
    std::cout << "Сума цілих частин елементів після останнього від'ємного: " << sum << std::endl;


    double maxElement = *std::max_element(arr.begin(), arr.end());


    int newSize = 0;
    rearrangeArray(arr, maxElement, 0, newSize);


    std::cout << "Модифікований масив: ";
    printArray(std::vector<double>(arr.begin(), arr.begin() + newSize));

    return 0;
}

#include <iostream>
#include <time.h>
using namespace std;


void Create(int* b, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++) {
        b[i] = Low + rand() % (High - Low + 1);
    }
}


int CountElements(const int* b, const int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (!(b[i] % 2 != 0 || i % 7 == 0)) {
            count++;
        }
    }
    return count;
}


int SumElements(const int* b, const int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (!(b[i] % 2 != 0 || i % 7 == 0)) {
            sum += b[i];
        }
    }
    return sum;
}



void ReplaceElements(int* b, const int size, int& count)
{
    count = 0;
    for (int i = 0; i < size; i++)
    {
        if (b[i] % 2 == 0 || i % 7 == 0)
        {
            b[i] = 0;
            count++;
        }
    }
}


int main() {
    srand((unsigned)time(NULL));

    const int r = 23;
    int b[r];
    int Low = 3;
    int High = 92;


    Create(b, r, Low, High);


    cout << "Start: ";
    for (int i = 0; i < r; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    int count = CountElements(b, r);
    int sum = SumElements(b, r);


    ReplaceElements(b, r, count);


    cout << "Count: " << count << endl;
    cout << "Sum: " << sum << endl;


    cout << "Mod: ";
    for (int i = 0; i < r; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}


#pragma execution_character_set("utf-8")
#include <fstream>
#include <iostream>
#include <iomanip> 
#include <string>
#include <Windows.h>
using namespace std;
struct Price {
    string productName;
    string shopName;
    double cost;
};
void EnterData(Price* array, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Товар " << i + 1 << ":" << endl;
        cout << "Назва товару: ";
        cin >> array[i].productName;
        cout << "Назва магазину: ";
        cin >> array[i].shopName;
        cout << "Вартість товару: ";
        cin >> array[i].cost;
    }
}

void Print(const Price* array, int size) {
    cout << "=========================================" << endl;
    cout << "|  Товар  |  Магазин  |  Вартість, грн  |" << endl;
    cout << "-----------------------------------------" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "| " << setw(7) << left << array[i].productName << " | "
            << setw(9) << left << array[i].shopName << " | "
            << setw(15) << right << fixed << setprecision(2) << array[i].cost << " |" << endl;
    }
    cout << "=========================================" << endl;
}
void SortByShopName(Price* array, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (array[i].shopName > array[j].shopName) {
                swap(array[i], array[j]);
            }
        }
    }
}
void SearchProductByName(const Price* array, int size, const string& productName) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (array[i].productName == productName) {
            cout << "Знайдено товар '" << productName << "':" << endl;
            cout << "Магазин: " << array[i].shopName << ", Вартість: " << array[i].cost << " грн" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Товар з назвою '" << productName << "' не знайдено." << endl;
    }
}

void LoadFromFile(Price*& p, int& N, const char* filename)
{
    delete[] p;

    ifstream fin(filename, ios::binary);

    fin.read((char*)&N, sizeof(N));

    p = new Price[N];

    for (int i = 0; i < N; i++)
        fin.read((char*)&p[i], sizeof(Price));

    fin.close();
}

void SaveToFile(Price* p, const int N, const char* filename) {
    ofstream fout(filename, ios::binary);

    fout.write((char*)&N, sizeof(N));

    for (int i = 0; i < N; i++)
        fout.write((char*)&p[i], sizeof(Price));

    fout.close();
}
int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int N;
    cout << "Введіть N: "; cin >> N;

    Price* p = new Price[N];

    int found;
    char filename[100];
    string iproduct;
    string productName;

    int menuItem;
    do {
        cout << endl << endl << endl;
        cout << "Виберіть дію:" << endl << endl;
        cout << "  [1] - введення даних з клавіатури" << endl;
        cout << "  [2] - вивід даних на екран" << endl;
        cout << "  [3] - фізично впорядкувати масив" << endl;
        cout << "  [4] - пошук товару" << endl;
        cout << "  [5] - запис даних у файл" << endl;
        cout << "  [6] - зчитування даних із файлу" << endl << endl;
        cout << "  [0] - вихід та завершення роботи програми" << endl << endl;
        cout << "Введіть значення: "; cin >> menuItem;
        cout << endl << endl << endl;

        switch (menuItem)
        {
        case 1:
            EnterData(p, N);
            break;
        case 2:
            Print(p, N);
            break;
        case 3:
            SortByShopName(p, N);

            break;
        case 4:
            cout << "Введіть ключі пошуку:" << endl;
            cin.get();
            cin.sync();

            cout << "    назва товару: "; getline(cin, productName);
            cout << endl;
            SearchProductByName(p, N, productName);
            break;
        case 5:
            cin.get();
            cin.sync();

            cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
            SaveToFile(p, N, filename);

            break;
        case 6:
            cin.get();
            cin.sync();

            cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
            LoadFromFile(p, N, filename);

            break;
        case 0:
            break;
        default:
            cout << "Ви ввели помилкове значення! "
                "Слід ввести число - номер вибраного пункту меню" << endl;
        }
    } while (menuItem != 0);

    return 0;
}

#pragma execution_character_set("utf-8")

#include <iostream> 
#include <iomanip> 
#include <string> 
#include <Windows.h>
using namespace std;

enum Special { CS, INF, MATH, PHYS, HAND };

string specialStr[] = { "��������� �����", "�����������", "���������� �� ��������", "Գ���� �� �����������", "������� ��������" };

struct Student
{
    string   prizv;
    unsigned kurs;
    Special   special;
    int phys;
    int math;
    union
    {
        int prog;
        int chisMet;
        int pedagog;
    };
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
int* BuildIndex(Student* p, const int N);
void PrintIndexSorted(Student* p, int* I, const int N);
bool binarySearch(Student* p, int left, int right, Special special, const string& prizv, int kurs);
void SortBySpecializationLastNameCourse(Student* p, const int N);
void SwapStudents(Student& a, Student& b);
void FindStudent(Student* p, int N);
int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int N;
    cout << "������ N: "; cin >> N;

    Student* p = new Student[N];


    int menuItem;
    do {
        cout << endl << endl << endl;
        cout << "������� ��:" << endl << endl;
        cout << "  [1] - �������� ����� � ���������" << endl;
        cout << "  [2] - ���� ����� �� �����" << endl;
        cout << "  [3] - ������� ������������ �����" << endl;
        cout << "  [4] - ��������� ��������� �����" << endl;
        cout << "  [5] - ����� ��������" << endl;
        cout << "  [0] - ����� �� ���������� ������ ��������" << endl << endl;
        cout << "������ ��������: "; cin >> menuItem;
        cout << endl << endl << endl;

        switch (menuItem)
        {
        case 1:
            Create(p, N);
            break;
        case 2:
            Print(p, N);
            break;
        case 3:
            SortBySpecializationLastNameCourse(p, N);
            cout << "����� �����������." << endl;
            break;
        case 4:
            PrintIndexSorted(p, BuildIndex(p, N), N);
            break;
        case 5:
            FindStudent(p, N);
            break;
        case 0:
            break;
        default:
            cout << "�� ����� ��������� ��������! "
                "��� ������ ����� - ����� ��������� ������ ����" << endl;
        }
    } while (menuItem != 0);


    return 0;
}

void Create(Student* p, const int N)
{
    int spec;
    for (int i = 0; i < N; i++)
    {
        cout << "������� � " << i + 1 << ":" << endl;

        cin.get();
        cin.sync();

        cout << "    �������: "; getline(cin, p[i].prizv);
        cout << "    ����: "; cin >> p[i].kurs;
        cout << "    ������ � ����������: "; cin >> p[i].math;
        cout << "    ������ � ������: "; cin >> p[i].phys;
        cout << "    ������������ (0 - ��������� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - Գ���� �� �����������, 4 - ������� ��������): ";
        cin >> spec;
        p[i].special = (Special)spec;
        switch (p[i].special)
        {
        case CS:
            cout << "    ������ � ������������� : "; cin >> p[i].prog;
            break;
        case INF:
            cout << "    ������ � ��������� ������ : "; cin >> p[i].chisMet;
            break;
        case MATH:
        case PHYS:
        case HAND:
            cout << "    ������ � ��������� : "; cin >> p[i].pedagog;
            break;
        }
        cout << endl;
    }
}

void Print(Student* p, const int N)
{
    cout << "================================================================================================================================" << endl;
    cout << "|  �  |   �������   |  ����  |   ������������   |   Գ����   |   ����������   | ������������� | ������� ������ | ��������� |" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(3) << right << i + 1 << " ";
        cout << "| " << setw(13) << left << p[i].prizv
            << "|    " << setw(1) << right << p[i].kurs << "    "
            << "| " << setw(25) << left << specialStr[p[i].special]
            << "| " << setw(3) << right << p[i].phys << "    | " << setw(3) << right << p[i].math;

        switch (p[i].special)
        {
        case CS:
            cout << "             | " << setw(13) << right << p[i].prog << "     |" << setw(16) << right << "      |" << endl;
            break;
        case INF:
            cout << "    | " << setw(14) << right << p[i].chisMet << "  |" << setw(15) << right << "       |" << endl;
            break;
        case MATH:
        case PHYS:
        case HAND:
            cout << "             |" << setw(19) << right << "      | " << setw(14) << right << p[i].pedagog << "  |" << endl;
            break;
        }
    }
    cout << "================================================================================================================================" << endl;
    cout << endl;
}
bool binarySearch(Student* p, int left, int right, Special special, const string& prizv, int kurs) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (p[mid].special == special && p[mid].prizv == prizv && p[mid].kurs == kurs) {
            return true;
        }
        else if (p[mid].special < special ||
            (p[mid].special == special && p[mid].prizv < prizv) ||
            (p[mid].special == special && p[mid].prizv == prizv && p[mid].kurs < kurs)) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return false;
}
int* BuildIndex(Student* p, const int N) {
    int* indexes = new int[N];

    for (int i = 0; i < N; ++i) {
        indexes[i] = i;
    }

    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (p[indexes[i]].special > p[indexes[j]].special ||
                (p[indexes[i]].special == p[indexes[j]].special && p[indexes[i]].prizv > p[indexes[j]].prizv) ||
                (p[indexes[i]].special == p[indexes[j]].special && p[indexes[i]].prizv == p[indexes[j]].prizv && p[indexes[i]].kurs > p[indexes[j]].kurs)) {
                int temp = indexes[i];
                indexes[i] = indexes[j];
                indexes[j] = temp;
            }
        }
    }

    return indexes;
}

void PrintIndexSorted(Student* p, int* I, const int N) {
    cout << "================================================================================================================================" << endl;
    cout << "|  �  |   �������   |  ����  |   ������������   |   Գ����   |   ����������   | ������������� | ������� ������ | ��������� |" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++) {
        cout << "| " << setw(3) << right << i + 1 << " ";
        cout << "| " << setw(13) << left << p[I[i]].prizv
            << "|    " << setw(1) << right << p[I[i]].kurs << "    "
            << "| " << setw(25) << left << specialStr[p[I[i]].special]
            << "| " << setw(3) << right << p[I[i]].phys << "    | " << setw(3) << right << p[I[i]].math;

        switch (p[I[i]].special) {
        case CS:
            cout << "             | " << setw(13) << right << p[I[i]].prog << "     |" << setw(16) << right << "      |" << endl;
            break;
        case INF:
            cout << "    | " << setw(14) << right << p[I[i]].chisMet << "  |" << setw(15) << right << "       |" << endl;
            break;
        case MATH:
        case PHYS:
        case HAND:
            cout << "             |" << setw(19) << right << "      | " << setw(14) << right << p[I[i]].pedagog << "  |" << endl;
            break;
        }
    }
    cout << "================================================================================================================================" << endl;
    cout << endl;
}
void SortBySpecializationLastNameCourse(Student* p, const int N) {
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            if (p[j].special < p[j + 1].special ||
                (p[j].special == p[j + 1].special && p[j].prizv > p[j + 1].prizv) ||
                (p[j].special == p[j + 1].special && p[j].prizv == p[j + 1].prizv && p[j].kurs > p[j + 1].kurs)) {
                SwapStudents(p[j], p[j + 1]);
            }
        }
    }
}

void SwapStudents(Student& a, Student& b) {
    Student temp = a;
    a = b;
    b = temp;
}

void FindStudent(Student* p, int N) {
    string searchLastName;
    int searchCourse;
    int searchSpecialization;

    cout << "������ �������: ";
    cin >> searchLastName;
    cout << "������ ����: ";
    cin >> searchCourse;
    cout << "������ ������������ (0 - ��������� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - Գ���� �� �����������, 4 - ������� ��������): ";
    cin >> searchSpecialization;
    if (binarySearch(p, 0, N - 1, (Special)searchSpecialization, searchLastName, searchCourse)) {
        cout << "�������� ��������." << endl;
    }
    else {
        cout << "�������� �� ��������." << endl;
    }
}

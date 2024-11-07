#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void Create(int** x, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Print(int** x, const int rowCount, const int colCount, int i, int j);
void Sort(int** x, const int rowCount, const int colCount, int i0, int i1);
void Change(int** x, int row1, int row2, int colCount, int j);
void Calc(int** x, const int rowCount, const int colCount, int& S, int& k, int i, int j);

int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    int Low = -12;
    int High = 23;

    int rowCount = 7;
    int colCount = 6;

    int** x = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        x[i] = new int[colCount];

    Create(x, rowCount, colCount, Low, High, 0, 0);
    Print(x, rowCount, colCount, 0, 0);
    Sort(x, rowCount, colCount, 0, 0);
    Print(x, rowCount, colCount, 0, 0);

    int S = 0;
    int k = 0;
    Calc(x, rowCount, colCount, S, k, 0, 0);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Print(x, rowCount, colCount, 0, 0);

    for (int i = 0; i < rowCount; i++)
        delete[] x[i];
    delete[] x;

    return 0;
}

void Create(int** x, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
    if (i < rowCount)
    {
        if (j < colCount)
        {
            x[i][j] = Low + rand() % (High - Low + 1);
            Create(x, rowCount, colCount, Low, High, i, j + 1);
        }
        else
        {
            Create(x, rowCount, colCount, Low, High, i + 1, 0);
        }
    }
}

void Print(int** x, const int rowCount, const int colCount, int i, int j)
{
    cout << setw(4) << x[i][j];
    if (j < colCount - 1)
        Print(x, rowCount, colCount, i, j + 1);
    else
        if (i < rowCount - 1)
        {
            cout << endl;
            Print(x, rowCount, colCount, i + 1, 0);
        }
        else
            cout << endl << endl;
}


void Sort(int** x, const int rowCount, const int colCount, int i0, int i1)
{
    if (i0 < rowCount - 1)
    {
        if (i1 < rowCount - i0 - 1)
        {
            if ((x[i1][0] > x[i1 + 1][0]) || (x[i1][0] == x[i1 + 1][0] && x[i1][1] > x[i1 + 1][1]) || (x[i1][0] == x[i1 + 1][0] && x[i1][1] == x[i1 + 1][1] && x[i1][3] < x[i1 + 1][3]))
            {
                Change(x, i1, i1 + 1, colCount, 0);
            }
            Sort(x, rowCount, colCount, i0, i1 + 1);
        }
        else
        {
            Sort(x, rowCount, colCount, i0 + 1, 0);
        }
    }
}

void Change(int** x, int row1, int row2, int colCount, int j)
{
    if (j < colCount)
    {
        int tmp = x[row1][j];
        x[row1][j] = x[row2][j];
        x[row2][j] = tmp;
        Change(x, row1, row2, colCount, j + 1);
    }
}

void Calc(int** x, const int rowCount, const int colCount, int& S, int& k, int i, int j)
{
    if (i < rowCount)
    {
        if (j < colCount)
        {
            if (x[i][j] % 2 != 0 || !(x[i][j] < 0))
            {
                S += x[i][j];
                k++;
                x[i][j] = 0;
            }
            Calc(x, rowCount, colCount, S, k, i, j + 1);
        }
        else
        {
            Calc(x, rowCount, colCount, S, k, i + 1, 0);
        }
    }
}

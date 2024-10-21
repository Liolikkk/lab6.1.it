//рекурсивний спосіб
#include <iostream>
#include <cstdlib> 
#include <ctime>   
using namespace std;

static void InitArray(int p[], const int size, int i)
{
    if (i < size)
    {
        p[i] = 15 + rand() % 94;
        InitArray(p, size, i + 1);
        return;
    }
}


static void PrintArray(int p[], const int size, int i) {
    if (i < size)
    {
        if (i == 0)
            cout << "{";
        cout << p[i];
        if (i != size - 1)
            cout << ", ";
        else cout << "}" << endl;
        PrintArray(p, size, i + 1);
        return;
    }
}

static int SumArray(const int* const p, const int size, int i)
{
    if (i < size) {
        if (i % 2 == 0 && i % 13 == 0)
            return p[i] + SumArray(p, size, i + 1);
        else
            return SumArray(p, size, i + 1);
    }
    else return 0;
}


static int CountElementArray(const int* const p, const int size, int i)
{
    if (i < size)
    {
        if (i % 2 == 0 && i % 13 == 0)
            return 1 + CountElementArray(p, size, i + 1);
        else
            return CountElementArray(p, size, i + 1);
    }
    else return 0;
}


static void ReplaceElementArray(int p[], const int size, int i)
{
    if (i < size)
    {
        if (i % 2 == 0 && i % 13 == 0)
            p[i] = 0;
        ReplaceElementArray(p, size, i + 1);
        return;
    }
}

int main()
{
    srand(time(0));
    const int size = 25;
    int p[size];

    InitArray(p, size, 0);
    PrintArray(p, size, 0);
    cout << "Array sum by condition = " << SumArray(p, size, 0) << endl;
    cout << "Count element by condition = " << CountElementArray(p, size, 0) << endl;
    ReplaceElementArray(p, size, 0);
    PrintArray(p, size, 0);

    return 0;
}



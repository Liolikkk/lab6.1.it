#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
static void Create(int* p, const int size, const int A, const int B)
{
	for (int i = 0; i < size; i++)
		p[i] = A + rand() % (B - A + 1);
}
static void Print(int* p, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << p[i];
	cout << endl;
}
static int Sum(const int* const p, const int size)
{
	int S = 0;
	for (int i = 0; i < size; i++)
		if (i % 2 == 0 && i % 13 == 0)
			S += p[i];
	return S;
}
static int Count(const int* const p, const int size)
{
	int a = 0;
	for (int i = 0; i < size; i++)
		if (i % 2 == 0 && i % 13 == 0) 
			a++;
	return a;
}
static void Replacement(int p[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		if(i % 2 == 0 && i % 13 == 0)
			p[i] = 0;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	const int n = 25;
	int p[n];
	int A = 15;
	int B = 94;
	Create(p, n, A, B);
	Print(p, n);
	cout << "The sum of the elements that satisfy the condition = " << Sum(p, n) << endl;
	cout << "The number of elements that satisfy the condition = " << Count(p, n) << endl;
	Replacement(p, n);
	Print(p, n);
	return 0;
}



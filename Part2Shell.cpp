#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Random(int a[], int n);
void Shell(int a[], int n);
void Print(int a[], int n);

int main()
{
	srand(time(0));
	const int n = 10;
	int a[n];
	int j;
	Random(a, n);
	Shell(a, n);
	Print(a, n);
}

void Random(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = 50 + rand() % 52;
	}
}

void Shell(int a[], int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i++)
		{
			int temp = a[i];
			int j = i;
			for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
			{
				a[j] = a[j - gap];
			}
			a[j] = temp;
		}
	}
}

void Print(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << setw(5) << a[i];
	}
}
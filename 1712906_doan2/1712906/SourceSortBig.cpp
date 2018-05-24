#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<time.h>
#include <cstdio>
#include"BigNum.h"
#pragma warning(disable: 4496)
#define MAXDIGTS 100
#define PLUS 1
#define MINUS -1
using namespace std;
unsigned long int  Nswaps;
unsigned long int  Ncompares;
struct bignum
{
	char digits[MAXDIGTS];
	int signbit;
	int lastdigit;
};
void thay(bignum &A, bignum &B)
{
	A = B;
	A.lastdigit = B.lastdigit;
	A.signbit = B.signbit;
}
void Swaps(bignum &A, bignum &B)
{
	bignum C = A;
	C.lastdigit = A.lastdigit;
	C.signbit = A.signbit;
	A= B;
	A.lastdigit =B.lastdigit;
	A.signbit = B.signbit;
	B = C;
	B.lastdigit = C.lastdigit;
	B.signbit = C.signbit;
 
}
int compare_bignums(bignum a, bignum b)
{
	int i;
	if ((a.signbit == MINUS) && (b.signbit == PLUS)) return(PLUS);
	if ((a.signbit == PLUS) && (b.signbit == MINUS)) return(MINUS);
	if (b.lastdigit > a.lastdigit)return (PLUS*a.signbit);
	if (a.lastdigit > b.lastdigit) return (MINUS*a.signbit);
	for (i = a.lastdigit; i >= 0; i--)
	{
		if (a.digits[i] > b.digits[i])
			return(MINUS*a.signbit);
		if (b.digits[i] > a.digits[i])
		{
			return(PLUS*a.signbit);
		}
	}
	return(0);
}
void SlectionSorts(bignum *arr, int n)
{
 
	Ncompares = 0;
	Nswaps = 0;
	printf("--------------------------SLECTION SORT-------------------------------\n");
	int min;
	clock_t start = clock();
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j<n; j++)
			if (compare_bignums(arr[j],arr[min])==PLUS)
			{
 
				Ncompares++;
				min = j;
			}
		Swaps(arr[min], arr[i]);
		Nswaps++;
	}

	printf("\n");
	clock_t finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Time: %.5fs\t Swap: %5lu \t Compare: %5lu\n", duration, Nswaps, Ncompares);
	 
}
void InsertSorts(bignum *A, int n)
{
	printf("--------------------------INSERT SORT-------------------------------\n");
 
	Ncompares = Nswaps = 0;
	int pos, i;
	bignum x;
	clock_t start = clock();
	for (i = 1; i < n; i++)
	{
		thay(x, A[i]); pos = i - 1;
		while (pos >= 0 && compare_bignums(A[i],x)==MINUS)
		{
			Ncompares++;
			thay(A[pos + 1], A[pos]);
			Nswaps++;
			pos--;
		}
		thay(A[pos + 1], x);
		Nswaps++;
	}
	printf("\n");
	clock_t finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Time: %.5fs\t Swap: %5lu \t Compare: %5lu\n", duration, Nswaps, Ncompares);
	 
}
void  BubbleSorts(bignum * A, int n)
{
	printf("--------------------------BUBLE SORT-------------------------------\n");
	 
	Ncompares = Nswaps = 0;
	int i, j;
	clock_t start = clock();
	for (i = 0; i < n - 1; i++)
	{
		for (j = n - 1; j > i; j--)
		{
			if (compare_bignums(A[j],A[i])==PLUS)
			{
				Ncompares++;
				Swaps(A[j], A[j - 1]);
				Nswaps++;
			}
		}
	}
	printf("\n");
	clock_t finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Time: %.5fs\t Swap: %5lu \t Compare: %5lu\n", duration, Nswaps, Ncompares);
	 
}
void Heapifys(bignum *A, int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n &&compare_bignums(A[l],A[largest])==MINUS)
	{
		Ncompares++;
		largest = l;
	}
	if (r < n && compare_bignums(A[r], A[largest]) == MINUS)
	{
		Ncompares++;
		largest = r;
	}
	if (largest != i)
	{
		Swaps(A[i], A[largest]);
		Nswaps++;
		Heapifys(A, n, largest);
	}
}
void HeapSorts(bignum *A, int n)
{
	printf("--------------------------HEAP SORT-------------------------------\n");
	 
	Ncompares = Nswaps = 0;
	int r;
	clock_t start = clock();
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapifys(A, n, i);
	for (int i = n - 1; i >= 0; i--)
	{

		Swaps(A[0], A[i]);
		Nswaps++;
		Heapifys(A, i, 0);
	}

	cout << endl;
	clock_t finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Time: %.5fs\t Swap: %5lu \t Compare: %5lu\n", duration, Nswaps, Ncompares);
	 
}
void ShellSorts(bignum *A, int n)
{
	printf("--------------------------SHELL SORT-------------------------------\n");
	 
	Ncompares = Nswaps = 0;
	int gap, i;
	clock_t start = clock();
	for (gap = n / 2; gap > 0; gap /= 2)
	{

		for (i = gap; i < n; i += 1)
		{
			bignum temp = A[i];

			int j;
			for (j = i; j >= gap && compare_bignums(A[j - gap], temp)==MINUS; j -= gap)
			{
				Nswaps++;
				Ncompares++;
				A[j] = A[j - gap];
			}
			A[j] = temp;
			Nswaps++;
		}
	}
	cout << endl;
	clock_t finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Time: %.5fs\t Swap: %5lu \t Compare: %5lu\n", duration, Nswaps, Ncompares);
	 
}
void quickSorts(bignum *&A, int l, int r)
{
	int i, j;
	bignum x;
	thay(x, A[(l + r) / 2]);
	i = l; j = r;
	do
	{
		while (compare_bignums(A[i], x)==PLUS)
		{
			i++;
			Ncompares++;
		}
		while (compare_bignums(A[j],x)==MINUS)
		{
			j--;
			Ncompares++;
		}
		if (i <= j)
		{
			Swaps(A[i], A[j]);
			Nswaps++;
			i++; j--;
		}
	} while (i < j);
	if (l < j)
	{
		quickSorts(A, l, j);
	}
	if (i < r)
	{
		quickSorts(A, i, r);
	}
}
void QuickSorts(bignum *A, int n)
{
	printf("-------------------------QUICK SORT-------------------------------\n");
	Ncompares = Nswaps = 0;
	clock_t start = clock();
 
	quickSorts(A, 0, n);
	cout << endl;
	clock_t finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
 
	printf("Time: %.5fs\t Swap: %5lu \t Compare: %5lu\n", duration, Nswaps, Ncompares);
}
void InterchangeSorts(bignum *A, int n)
{
	printf("-------------------------INTERCHANGE SORT-------------------------------\n");
	 
	int i, j;
	Ncompares = Nswaps = 0;
	clock_t start = clock();
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (compare_bignums(A[i], A[j])==MINUS)
			{
				Ncompares++;
				Swaps(A[i], A[j]);
				Nswaps++;
			}
		}
	}
	cout << endl;
	clock_t finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Time: %.5fs\t Swap: %5lu \t Compare: %5lu\n", duration, Nswaps, Ncompares);
 	delete[] A;
}
void Merges(bignum *A, int left, int mid, int right)
{

	bignum *temp1;
	int i = left;
	int j = mid + 1;
	temp1 = new bignum[right - left + 1];
	for (int k = 0; k <= right - left; k++)
	{
		if (compare_bignums(A[i],A[j])==PLUS)
		{
			Ncompares++;
			thay(temp1[k],A[i]);
			i++;
		}
		else
		{
			Ncompares++;
			thay(temp1[k], A[i]);
			j++;
		}
		if (i == mid + 1)
		{
			while (j <= right)
			{
				k++;
				thay(temp1[k], A[i]);
				j++;
			}
			break;
		}
		if (j == right + 1)
		{
			while (i <= mid)
			{
				k++;
				thay(temp1[k], A[i]);
				i++;
			}
			break;
		}
	}
	for (int k = 0; k <= right - left; k++) // Chep mang tam vao mang chinh

	{
		thay(A[left + k],temp1[k]);
		Nswaps++;
	}
	delete temp1;
}
void mergesorts(bignum *A, int left, int right)
{
	if (right > left)
	{
		int mid; // Phan tu o giua
		mid = (left + right) / 2;
		mergesorts(A, left, mid); // Goi de quy mang con ben trai
		mergesorts(A, mid + 1, right); // Goi de quy mang con ben phai
		Merges(A, left, mid, right); // Goi ham so sanh hai mang con
	}
}
 
void MergeSorts(bignum *A, int n)
{
	printf("-------------------------MERGE SORT-------------------------------\n");
	 
	Ncompares = Nswaps = 0;
	clock_t start = clock();
	mergesorts(A, 0, n - 1);
	cout << endl;
	clock_t finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Time: %.5fs\t Swap: %5lu \t Compare: %5lu\n", duration, Nswaps, Ncompares);
	 
}
void ShakerSorts(bignum *A, int n)
{
	printf("-------------------------SHAKER SORT-------------------------------\n");
	 
	Ncompares = Nswaps = 0;
	clock_t start = clock();
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	int i;
	while (Left < Right)
	{
		for (i = Left; i < Right; i++)
		{
			if (compare_bignums(A[i],A[i + 1])==MINUS)
			{
				Ncompares++;
				Swaps(A[i], A[i + 1]);
				Nswaps++;
				k = i;
			}
		}
		Right = k;
		for (i = Right; i > Left; i--)
		{
			if (compare_bignums(A[i],A[i - 1])==PLUS)
			{
				Ncompares++;
				Swaps(A[i], A[i - 1]);
				Nswaps++;
				k = i;
			}
		}
		Left = k;
	}
	cout << endl;
	clock_t finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Time: %.5fs\t Swap: %5lu \t Compare: %5lu\n", duration, Nswaps, Ncompares);
 
}



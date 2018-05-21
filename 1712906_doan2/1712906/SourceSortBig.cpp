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
unsigned long int  Nswap;
unsigned long int  Ncompare;
struct bignum
{
	char digits[MAXDIGTS];
	int signbit;
	int lastdigit;
};
int compare_bignum(bignum a, bignum b);
void Swaps(bignum &A, bignum &B)
{
	bignum C = A;
	A = B;
	B = C;
 
}
void SlectionSort(bignum *arr, int n)
{
 
	Ncompare = 0;
	Nswap = 0;
	printf("--------------------------SLECTION SORT-------------------------------\n");
	int min;
	clock_t start = clock();
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j<n; j++)
			if (compare_bignum(arr[j],arr[min])==PLUS)
			{
				Ncompare++;
				min = j;
			}
		Swaps(arr[min], arr[i]);
		Nswap++;
	}

	printf("\n");
	clock_t finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Time: %.5fs\t Swap: %5lu \t Compare: %5lu\n", duration, Nswap, Ncompare);
}
void InsertSort(bignum *A, int n)
{
	printf("--------------------------INSERT SORT-------------------------------\n");
 
	Ncompare = Nswap = 0;
	int pos, i;
	bignum x;
	clock_t start = clock();
	for (i = 1; i < n; i++)
	{
		x = A[i]; pos = i - 1;
		while (pos >= 0 && compare_bignum(A[i],x)==MINUS)
		{
			Ncompare++;
			A[pos + 1] = A[pos];
			Nswap++;
			pos--;
		}
		A[pos + 1] = x;
		Nswap++;
	}
	printf("\n");
	clock_t finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Time: %.5fs\t Swap: %5lu \t Compare: %5lu\n", duration, Nswap, Ncompare);
}
void  BubbleSort(bignum * A, int n)
{
	printf("--------------------------BUBLE SORT-------------------------------\n");
	 
	Ncompare = Nswap = 0;
	int i, j;
	clock_t start = clock();
	for (i = 0; i < n - 1; i++)
	{
		for (j = n - 1; j > i; j--)
		{
			if (compare_bignum(A[j],A[i])==PLUS)
			{
				Ncompare++;
				Swaps(A[j], A[j - 1]);
				Nswap++;
			}
		}
	}
	printf("\n");
	clock_t finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Time: %.5fs\t Swap: %5lu \t Compare: %5lu\n", duration, Nswap, Ncompare);
}
void Heapify(bignum *A, int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n &&compare_bignum(A[l],A[largest])==MINUS)
	{
		Ncompare++;
		largest = l;
	}
	if (r < n && compare_bignum(A[r], A[largest]) == MINUS)
	{
		Ncompare++;
		largest = r;
	}
	if (largest != i)
	{
		Swaps(A[i], A[largest]);
		Nswap++;
		Heapify(A, n, largest);
	}
}
void HeapSort(bignum *A, int n)
{
	printf("--------------------------HEAP SORT-------------------------------\n");
	 
	Ncompare = Nswap = 0;
	int r;
	clock_t start = clock();
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(A, n, i);
	for (int i = n - 1; i >= 0; i--)
	{

		Swaps(A[0], A[i]);
		Nswap++;
		Heapify(A, i, 0);
	}

	cout << endl;
	clock_t finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Time: %.5fs\t Swap: %5lu \t Compare: %5lu\n", duration, Nswap, Ncompare);
}
void ShellSort(bignum *A, int n)
{
	printf("--------------------------SHELL SORT-------------------------------\n");
	 
	Ncompare = Nswap = 0;
	int gap, i;
	clock_t start = clock();
	for (gap = n / 2; gap > 0; gap /= 2)
	{

		for (i = gap; i < n; i += 1)
		{
			bignum temp = A[i];

			int j;
			for (j = i; j >= gap && compare_bignum(A[j - gap], temp)==MINUS; j -= gap)
			{
				Nswap++;
				Ncompare++;
				A[j] = A[j - gap];
			}
			A[j] = temp;
			Nswap++;
		}
	}
	cout << endl;
	clock_t finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Time: %.5fs\t Swap: %5lu \t Compare: %5lu\n", duration, Nswap, Ncompare);
}
void quickSort(bignum *A, int l, int r)
{
	int i, j;
	bignum x = A[(l + r) / 2];
	i = l; j = r;
	do
	{
		while (compare_bignum(A[i], x)==PLUS)
		{
			i++;
			Ncompare++;
		}
		while (compare_bignum(A[j],x)==MINUS)
		{
			j--;
			Ncompare++;
		}
		if (i <= j)
		{
			Swaps(A[i], A[j]);
			Nswap++;
			i++; j--;
		}
	} while (i < j);
	if (l < j)
	{
		quickSort(A, l, j);
	}
	if (i < r)
	{
		quickSort(A, i, r);
	}
}
void QuickSort(bignum *A, int n)
{
	printf("-------------------------QUICK SORT-------------------------------\n");
	 
	Ncompare = Nswap = 0;
	clock_t start = clock();
	quickSort(A, 0, n);
	cout << endl;
	clock_t finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Time: %.5fs\t Swap: %5lu \t Compare: %5lu\n", duration, Nswap, Ncompare);
}
void InterchangeSort(bignum *A, int n)
{
	printf("-------------------------INTERCHANGE SORT-------------------------------\n");
	 
	int i, j;
	Ncompare = Nswap = 0;
	clock_t start = clock();
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (compare_bignum(A[i], A[j])==MINUS)
			{
				Ncompare++;
				Swaps(A[i], A[j]);
				Nswap++;
			}
		}
	}
	cout << endl;
	clock_t finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Time: %.5fs\t Swap: %5lu \t Compare: %5lu\n", duration, Nswap, Ncompare);
}
void Merge(bignum *A, int left, int mid, int right)
{

	bignum *temp;
	int i = left;
	int j = mid + 1;
	temp = new bignum[right - left + 1];
	for (int k = 0; k <= right - left; k++)
	{
		if (compare_bignum(A[i],A[j])==PLUS)
		{
			Ncompare++;
			temp[k] = A[i];
			i++;
		}
		else
		{
			Ncompare++;
			temp[k] = A[j];
			j++;
		}
		if (i == mid + 1)
		{
			while (j <= right)
			{
				k++;
				temp[k] = A[j];
				j++;
			}
			break;
		}
		if (j == right + 1)
		{
			while (i <= mid)
			{
				k++;
				temp[k] = A[i];
				i++;
			}
			break;
		}
	}
	for (int k = 0; k <= right - left; k++) // Chep mang tam vao mang chinh

	{
		A[left + k] = temp[k];
		Nswap++;
	}
	delete temp;
}
void mergesort(bignum *A, int left, int right)
{
	if (right > left)
	{
		int mid; // Phan tu o giua
		mid = (left + right) / 2;
		mergesort(A, left, mid); // Goi de quy mang con ben trai
		mergesort(A, mid + 1, right); // Goi de quy mang con ben phai
		Merge(A, left, mid, right); // Goi ham so sanh hai mang con
	}
}
 
void MergeSort(bignum *A, int n)
{
	printf("-------------------------MERGE SORT-------------------------------\n");
	 
	Ncompare = Nswap = 0;
	clock_t start = clock();
	mergesort(A, 0, n - 1);
	cout << endl;
	clock_t finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Time: %.5fs\t Swap: %5lu \t Compare: %5lu\n", duration, Nswap, Ncompare);
}
void ShakerSort(bignum *A, int n)
{
	printf("-------------------------SHAKER SORT-------------------------------\n");
	 
	Ncompare = Nswap = 0;
	clock_t start = clock();
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	int i;
	while (Left < Right)
	{
		for (i = Left; i < Right; i++)
		{
			if (compare_bignum(A[i],A[i + 1])==MINUS)
			{
				Ncompare++;
				Swaps(A[i], A[i + 1]);
				Nswap++;
				k = i;
			}
		}
		Right = k;
		for (i = Right; i > Left; i--)
		{
			if (compare_bignum(A[i],A[i - 1])==PLUS)
			{
				Ncompare++;
				Swaps(A[i], A[i - 1]);
				Nswap++;
				k = i;
			}
		}
		Left = k;
	}
	cout << endl;
	clock_t finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Time: %.5fs\t Swap: %5lu \t Compare: %5lu\n", duration, Nswap, Ncompare);
}



#include"Sort.h"
#include <stdio.h> 
#include<conio.h>
#include<iostream>
#include<time.h>
#include <cstdio>
#define max 100
using namespace std;
unsigned long int  Nswap;
unsigned long int  Ncompare;
#pragma warning(disable: 4996);
void Swaps(int &A, int &B)
{
	
	 A =  A +  B;
	 B = A -  B;
	 A =  A- B;
 }
void create(int *A, int n)
{
	
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % max + 1;
	}
}
void SlectionSort(int *arr, int n)
{
	create(arr, n);
	Ncompare = 0;
	 Nswap = 0;
	printf("--------------------------SLECTION SORT-------------------------------\n");
	int min;
	clock_t start = clock();
	for (int i = 0; i < n-1; i++)
	{
		min = i;
			for(int j=i+1;j<n;j++)
				if (arr[j] < arr[min])
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
void InsertSort(int *A, int n)
{
	printf("--------------------------INSERT SORT-------------------------------\n");
	create(A, n);
	Ncompare  = Nswap = 0;
	int pos, i,x;
	clock_t start = clock();
	for (i = 1; i < n; i++)
	{
		x = A[i]; pos = i - 1;
		while (pos >= 0 && A[pos] > x)
		{	Ncompare++;
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
void  BubbleSort(int * A, int n)
{
	printf("--------------------------BUBLE SORT-------------------------------\n");
	create(A, n);
	Ncompare = Nswap = 0;
	int i, j;
	clock_t start = clock();
	for (i = 0; i < n - 1; i++)
	{
		for (j = n-1; j > i; j--)
		{
			if (A[j] < A[j - 1])
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
void Heapify(int *A, int n, int i)
{
	int largest = i;  
	int l = 2 * i + 1;  
	int r = 2 * i + 2;
	if (l < n && A[l] > A[largest])
	{
		Ncompare++;
		largest = l;
	}
	if (r < n && A[r] >A[largest])
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
void HeapSort(int *A, int n)
{
	printf("--------------------------HEAP SORT-------------------------------\n");
	create(A, n);
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
void ShellSort(int *A, int n)
{
	printf("--------------------------SHELL SORT-------------------------------\n");
	create(A, n);
	Ncompare = Nswap = 0;
	int gap,i;
	clock_t start = clock();
	for (  gap = n / 2; gap > 0; gap /= 2)
	{
		 
		for ( i = gap; i < n; i += 1)
		{
			int temp =A[i];
			
			int j;
			for (j = i; j >= gap && A[j - gap] > temp; j -= gap)
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
void quickSort(int *A, int l, int r)
{
	int i, j;
	int x = A[(l + r) / 2];
	i = l; j = r;
	do
	{
		while (A[i] < x)
		{
			i++; 
			Ncompare++;
		}
		while (A[j] > x)
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
void QuickSort(int *A, int n)
{
	printf("-------------------------QUICK SORT-------------------------------\n");
	create(A, n);
	Ncompare = Nswap = 0;
	clock_t start = clock();
	quickSort(A, 0, n);
	cout << endl;
	clock_t finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Time: %.5fs\t Swap: %5lu \t Compare: %5lu\n", duration, Nswap, Ncompare);
}
void InterchangeSort(int *A, int n)
{
	printf("-------------------------INTERCHANGE SORT-------------------------------\n");
	create(A, n);
	int i, j;
	Ncompare = Nswap = 0;
	clock_t start = clock();
	for (  i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (A[i] > A[j])
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
void Merge(int *A, int left, int mid, int right)
{
	 
	int *temp;
	int i = left;
	int j = mid + 1;
	temp = new int[right - left + 1];
	for (int k = 0; k <= right - left; k++)
	{
		if (A[i] < A[j])
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
void mergesort(int *A, int left, int right)
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
int getMax(int *A, int n)
{
	int mx = A[0];
	for (int i = 1; i < n; i++)
		if (A[i] > mx)
		{
			Ncompare++;
			Nswap++;
			mx = A[i];
		}
	return mx;
}
void countSort(int *A, int n, int exp)
{
	int *output = new int[n];
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[(A[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(A[i] / exp) % 10] - 1] = A[i];
		count[(A[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++)

	{
		Nswap++;
		A[i] = output[i];
	}
	delete[]output;
}

 
void Radixsort(int *A, int n)
{
	printf("-------------------------RADIX SORT-------------------------------\n");
	create(A, n);
	Ncompare = Nswap = 0;
	clock_t start = clock();
 
	int m = getMax(A, n);
	for (int exp = 1; m / exp > 0; exp *= 10)

	{
		countSort(A, n, exp);
	}
	cout << endl;
	clock_t finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Time: %.5fs\t Swap: %5lu \t Compare: %5lu\n", duration, Nswap, Ncompare);
}
void MergeSort(int *A, int n)
{
	printf("-------------------------MERGE SORT-------------------------------\n");
	create(A, n);
	Ncompare = Nswap = 0;
	clock_t start = clock();
	mergesort(A, 0, n - 1);
	cout << endl;
	clock_t finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Time: %.5fs\t Swap: %5lu \t Compare: %5lu\n", duration, Nswap, Ncompare);
}
void ShakerSort(int *A, int n)
{
	printf("-------------------------SHAKER SORT-------------------------------\n");
	create(A, n);
	Ncompare = Nswap = 0;
	clock_t start = clock();
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	int i;
	while (Left < Right)
	{
		for ( i = Left; i < Right; i++)
		{
			if (A[i] > A[i + 1])
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
			if (A[i] < A[i - 1])
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
 


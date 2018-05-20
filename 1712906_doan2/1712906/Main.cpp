#include"Sort.h"
#include <stdio.h> 
#include<conio.h>
#include<iostream>
#include<time.h>
#include <cstdio>
using namespace std;
void SlectionSort(int *A, int n);
void InsertSort(int *A, int n);
void  BubbleSort(int * A, int n);
void HeapSort(int *A, int n);
void ShellSort(int *A, int n);
void QuickSort(int *A, int n);
void InterchangeSort(int *A, int n);
void MergeSort(int *A, int n);
void Radixsort(int *A, int n);
void ShakerSort(int *A, int n);
void main()
{ 
	int *A;
	int n;
	cout << "Input  n = ";
	cin >> n;
	A = new int[n];
	SlectionSort(A,n);
	InsertSort(A, n);
	BubbleSort(A, n);
	HeapSort(A, n);
	ShellSort(A, n);
	QuickSort(A, n);
	InterchangeSort(A, n);
	MergeSort(A, n);
	Radixsort(A, n);
	ShakerSort(A, n);
	cout << endl;
	system("pause");
	exit(1);
	delete[]A;

}
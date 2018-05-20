#pragma once
#ifdef Sort.h
#define sort
 
#include<conio.h>
 
#include<time.h>
#include <cstdio>
using namespace std;
void Swaps(int &A, int &B);
void  BubbleSort(int * arr, int n);
void SlectionSort(int *arr, int n);
void create(int *A, int n);
void InsertSort(int *A, int n);
void Heapify(int *A, int n, int i);
void ShellSort(int *A, int n);
void HeapSort(int *A, int n);
void quickSort(int *A, int l, int r);
void QuickSort(int *A, int n);
void InterchangeSort(int *A, int n);
void mergesort(int *A, int left, int right);
void Merge(int *A, int left, int mid, int right);
void MergeSort(int *A, int n);
int getMax(int *A, int n);
void countSort(int *A, int n, int exp);
void ShakerSort(int *A, int n);
#endif
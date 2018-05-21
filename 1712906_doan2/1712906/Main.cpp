#include"Sort.h"
#include <stdio.h> 
#include<conio.h>
#include<iostream>
#include<time.h>
#include <cstdio>
#include"BigNum.h"
#define MAXDIGTS 1000
using namespace std;
struct bignum
{
	char digits[MAXDIGTS];
	int signbit;
	int lastdigit;
};
struct  Node
{
	char   data;
	struct Node * pnext;
};
struct Stack
{
	Node *Top;
};
struct SO
{
	bignum data;
	SO * pnext;

};
struct StackSo
{
	SO* Top;
};
bignum Evaluate(char postfix[]);
void divison(bignum a, bignum b, bignum& c);
void multiplication(bignum a, bignum b, bignum&c);
void print_bignum(bignum n);
int kiemtra(char s[]);
void scan_bignum(bignum &n);
void zero_justify(bignum n);
void add_bignum(bignum a, bignum b, bignum &c);
void subtract_bignum(bignum a, bignum b, bignum &c);
int compare_bignum(bignum a, bignum b);
void init(Stack &stack);
bool isEmpty(Stack stack);
Node * getNode(char x);
void push(Stack &stack, char x);
char  pop(Stack  &stack);
char peek(Stack stack);
bool checknumber(char x);
int Precedence(char x);
void InfixtoPostfix(char infix[], char postfix[]);
void prints(char B[]);
int max(int a, int b);
void multiplications(bignum a, bignum b, bignum& d);
void divison(bignum a, bignum b, bignum& c);
bool isEmptys(StackSo stack);
void inits(StackSo &stack);
SO * getNodes(bignum x);
void pushs(StackSo &stack, bignum x);
bignum pops(StackSo  &stack);
bignum Evaluate(char postfix[]);
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
	/*int *A;
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
	delete[]A;*/
	char A[200], B[200];
	printf("Infix : ");
	gets_s(A);


	InfixtoPostfix(A, B);
	printf("Equals is: \n");
	print_bignum(Evaluate(B));
	system("pause");


}
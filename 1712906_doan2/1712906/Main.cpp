#include"Sort.h"
#include <stdio.h> 
#include<conio.h>
#include<iostream>
#include<time.h>
#include <cstdio>
#include"BigNum.h"
#define MAXDIGTS 100
#pragma warning ( disable:4996 )
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
void Evaluate(char postfix[], bignum &C);
void SlectionSorts(bignum *arr, int n);
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
//BIG NUM VA PHEP TINH 
void  BubbleSorts(bignum  * arr, int n);
void SlectionSorts(bignum  *arr, int n);
void creates(bignum  *&A, int &n);
void InsertSorts(bignum  *A, int n);
void ShellSorts(bignum  *A, int n);
void HeapSorts(bignum  *A, int n);
void quickSorts(bignum  *A, int l, int r);
void QuickSorts(bignum  *A, int n);
void InterchangeSorts(bignum *A, int n);
void MergeSorts(bignum *A, int n);
void ShakerSorts(bignum *A, int n);
void creates(bignum  *&C, int &n)
{
	char A[200], B[200];
	C =(bignum*) malloc(100 * sizeof(bignum));
	FILE * fin = fopen("test.txt", "rt");
	if (fin == NULL)
	{
		cout << "KHONG DOC DUOC" << endl;
		return;
	}
	while (!feof(fin))
	{
		fgets(A, 100, fin);
		InfixtoPostfix(A, B);
		Evaluate(B, C[n - 1]);
		if (!feof(fin))
		{
			n++;
		}
	}
	C = (bignum*)realloc(C, n * sizeof(bignum));
	fclose(fin);
}
void Level_one(int *&A, int &n)
{
	cout << "\t\t LEVEL 1:\n\n";
	cout << "Input  n = ";
	cin >> n;
	A = new int[n];
	SlectionSort(A, n);
	InsertSort(A, n);
	BubbleSort(A, n);
	HeapSort(A, n);
	ShellSort(A, n);
	QuickSort(A, n);
	InterchangeSort(A, n);
	MergeSort(A, n);
	Radixsort(A, n);
	ShakerSort(A, n);
	cout << "\t\t END LEVEL 1:\n\n";
}
void Level_two()
{
	cout << "\t\t LEVEL 2:\n\n";
	bignum *A=NULL;
	int n=1;
	creates(A, n);
	SlectionSorts(A, n);
	delete A;
	bignum *B = NULL;
	creates(B, n);
	InsertSorts(B, n);
	delete B;
	bignum *C = NULL;
	creates(C, n);
	BubbleSorts(C, n);
	delete C;
	bignum *D = NULL;
	creates(D, n);
	HeapSorts(D, n);
	delete D;
	bignum *E = NULL;
	creates(E, n);
	ShellSorts(E, n);
	delete E;
	 bignum *F = NULL;
	 creates(F, n);
	MergeSorts(F, n);
 
	bignum *G = NULL;
	creates(G, n);
	InterchangeSorts(G, n);
	delete G;
	bignum *H = NULL;
	creates(H, n);
	ShakerSorts(H, n);
	delete H;
	cout << "\t\t END LEVEL 2:\n\n";
}
void Level_three()
{
	cout << "\t\t LEVEL 3:\n\n";
	bignum *A=NULL;
	int n=1;
	creates(A, n);
	SlectionSorts(A, n);
	delete A;
	bignum *B;
	creates(B, n);
	InsertSorts(B, n);
	delete B;
	bignum *C;
	creates(C, n);
	BubbleSorts(C, n);
	delete C;
	bignum *D;
	creates(D, n);
	HeapSorts(D, n);
	delete D;
	bignum *E;
	creates(E, n);
	ShellSorts(E, n);
	delete E;
	 bignum *F;
	creates(F, n);
	MergeSorts(F, n);
	delete F; 
	bignum *G;
	creates(G, n);
	InterchangeSorts(G, n);
	delete G;
	bignum *H;
	creates(H, n);
	//MergeSorts(A, n);


	ShakerSorts(H, n);
	delete H;
 
	cout << "\t\t END LEVEL 3:\n\n";
}
void main()
{
 
	int n;
	int *A;
	Level_one(A, n);
	Level_two( );
	Level_three();

 

	
	system("pause");


}
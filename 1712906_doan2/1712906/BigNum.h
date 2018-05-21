#pragma once
#ifdef BigNum.h
#define bignums
#define MAXDIGTS 100
#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<iomanip>
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
void Swaps(bignum &A, bignum  &B);
void  BubbleSorts(bignum  * arr, int n);
void SlectionSorts(bignum  *arr, int n);
void create(bignum  *A, int n);
void InsertSorts(bignum  *A, int n);
void Heapifys(bignum *A, int n, int i);
void ShellSorts(bignum  *A, int n);
void HeapSorts(bignum  *A, int n);
void quickSorts(bignum  *A, int l, int r);
void QuickSorts(bignum  *A, int n);
void InterchangeSorts(bignum *A, int n);
void mergesorts(bignum  *A, int left, int right);
void Merges(bignum *A, int left, int mid, int right);
void MergeSorts(bignum *A, int n);
void ShakerSorts(bignum *A, int n);
#endif

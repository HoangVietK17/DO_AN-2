#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<iomanip>
#include"BigNum.h"
#include<string.h>
#pragma warning(disable: 4496)
#define MAXDIGTS 100
#define PLUS 1
#define MINUS -1
using namespace std;
struct  Node
{
	char   data;
	struct Node * pnext;
};
struct Stack
{
	Node *Top;
};
void init(Stack &stack)
{
	stack.Top = NULL;
}
bool isEmpty(Stack stack)
{
	if (stack.Top == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
Node * getNode(char x)
{
	Node *p = new Node;
	p->data = (char)x;
	p->pnext = NULL;
	return p;
}
void push(Stack &stack, char x)
{

	Node *p = new Node;
	p = getNode(x);
	if (isEmpty(stack))
	{
		stack.Top = p;
	}
	else
	{

		p->pnext = stack.Top;
		stack.Top = p;
	}
}
char  pop(Stack  &stack)
{

	Node *p = stack.Top;
	char data = p->data;
	stack.Top = stack.Top->pnext;
	delete p;
	return data;
}
char peek(Stack stack)
{

	if (stack.Top != NULL)
	{

		return (char)stack.Top->data;
	}
	else
	{

	}
}
int Precedence(char x)
{

	if (x == '(')
		return 0;
	if (x == '+' || x == '-')
		return 1;
	if (x == '*' || x == '/' || x == '%')
		return 2;
	else
		return 3;
}
bool checknumber(char x)
{
	if (x <= '9'&&x >= '0')
	{
		return true;
	}
	return false;
}
void InfixtoPostfix(char infix[], char postfix[])
{
	Stack  stack;
	char x, token;
	int i = 0, j = 0;
	init(stack);

	for (int i = 0; infix[i] != '\n'; i++)
	{
		if (infix[i] == '\0') return;
		token = infix[i];
		if (checknumber(token))
		{
			
			postfix[j++] = token;
		}
		else
		{
			postfix[j++] = ',';
			if (token == '(')
			{

				push(stack, '(');
			}
			else
			{
				if (token == ')')
				{
					while ((x = pop(stack)) != '(')
					{
						postfix[j++] = x;
					}
				}
				else
				{
					while (Precedence(token) <= Precedence(peek(stack)) && !isEmpty(stack) && peek(stack) != ',')
					{

						x = pop(stack);

						postfix[j++] = x;
					}
					push(stack, token);


				}
			}
		}

	}
	while (!isEmpty(stack))
	{
		x = pop(stack);
		postfix[j++] = x;
	}

	postfix[j] = '\0';
}
void prints(char B[])
{
	for (int i = 0; B[i] != '\0'; i++)
	{
		if (B[i] == ',') continue;
		else
		{
			printf("%c", B[i]);
		}
	}
	printf("\n");
}
struct bignum
{
	char digits[MAXDIGTS];
	int signbit;
	int lastdigit;
};
void divison(bignum a, bignum b, bignum& c);
void multiplication(bignum a, bignum b, bignum&c);
void print_bignum(bignum n);
int kiemtra(char s[]);
void scan_bignum(bignum &n);
void zero_justify(bignum n);
void add_bignum(bignum a, bignum b, bignum &c);
void subtract_bignum(bignum a, bignum b, bignum &c);
int compare_bignum(bignum a, bignum b);
int max(int a, int b)
{
	return a > b ? a : b;
}
void print_bignum(bignum n)
{
	int i;
	if (n.signbit == MINUS) printf("-");
	for (i = n.lastdigit; i >= 0; i--)
	{
		printf("%d", n.digits[i]);
	}
	printf("\n");
}
int kiemtra(char s[])
{
	if (s[0] != '-' && !isdigit(s[0]))
	{
		return 0;
	}
	int len = strlen(s);
	for (int i = 1; i < len; i++)
	{
		if (!isdigit(s[i])) return 0;
		return 1;
	}
}
void scan_bignum(bignum &n)
{
	char temp[256];
	gets_s(temp, 256);
	if (!kiemtra(temp))
	{
		n.signbit = PLUS;
		n.lastdigit = 0;
		n.digits[0] = 0;

	}
	else
	{
		if (temp[0] != '-')
		{
			n.signbit = PLUS;
			n.lastdigit = strlen(temp) - 1;
			for (int i = 0; i <= n.lastdigit; i++)
			{
				n.digits[i] = temp[n.lastdigit - i] - 48;
			}
		}
		else
		{
			n.signbit = MINUS;
			n.lastdigit = strlen(temp) - 2;
			for (int i = 0; i <= n.lastdigit; i++)
				n.digits[i] = temp[n.lastdigit + 1 - i] - 48;
		}
	}
}
void scan(char temp[], bignum &n, int index)
{

	n.lastdigit = index - 1;
	for (int i = 0; i <= n.lastdigit; i++)
	{
		n.digits[i] = temp[n.lastdigit - i] - 48;
	}

}
void zero_justify(bignum n)
{
	while ((n.lastdigit > 0) && (n.digits[n.lastdigit] == 0))
	{
		n.lastdigit--;
	}
	if ((n.lastdigit == 0) && (n.digits[0] == 0))
	{
		n.signbit = PLUS;
	}
}
int compare_bignum(bignum a, bignum b)
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
void add_bignum(bignum a, bignum b, bignum &c)
{
	bignum d;
	int carry;
	int i;
	if (a.signbit == b.signbit) c.signbit = a.signbit;
	else
	{
		if (a.signbit == MINUS)
		{
			a.signbit = PLUS;
			subtract_bignum(b, a, c);
			a.signbit = MINUS;
		}
		else
		{
			b.signbit = PLUS;
			subtract_bignum(a, b, c);
			b.signbit = MINUS;
		}
		return;
	}
	d.lastdigit = max(a.lastdigit, b.lastdigit) + 1;
	for (i = a.lastdigit + 1; i <= d.lastdigit; i++)
	{
		a.digits[i] = 0;
	}
	for (i = b.lastdigit + 1; i <= d.lastdigit; i++)
	{
		b.digits[i] = 0;
	}
	carry = 0;
	for (i = 0; i <= d.lastdigit; i++)
	{
		d.digits[i] = (char)
			(carry + a.digits[i] + b.digits[i]) % 10;
		carry = (carry + a.digits[i] + b.digits[i]) / 10;
	}
	zero_justify(d);
	int index = d.lastdigit;
	int temp = 0;
	while (d.digits[index] == 0)
	{
		temp++;
		index -= temp;

	}
	c.lastdigit = index;
	if (index<0) c.lastdigit = 0;
	for (int i = 0; i <= c.lastdigit; i++)
	{
		c.digits[i] = d.digits[i];
	}
	zero_justify(c);

}
void subtract_bignum(bignum a, bignum b, bignum&c)
{
	bignum d;
	int borrow;
	int v;
	int i;
	if ((a.signbit == MINUS) || (b.signbit == MINUS))
	{
		b.signbit = -1 * b.signbit;
		add_bignum(a, b, c);
		b.signbit = -1 * b.signbit;
		return;
	}
	if (compare_bignum(a, b) == PLUS) {
		subtract_bignum(b, a, c);
		c.signbit = MINUS;
		return;
	}
	c.signbit = PLUS;
	d.lastdigit = max(a.lastdigit, b.lastdigit);
	for (i = a.lastdigit + 1; i <= d.lastdigit; i++)
		a.digits[i] = 0;
	for (i = b.lastdigit + 1; i <= d.lastdigit; i++)
		b.digits[i] = 0;
	borrow = 0;
	for (int i = 0; i <= (d.lastdigit); i++)
	{
		v = (a.digits[i] - borrow - b.digits[i]);
		if (a.digits[i] > 0) borrow = 0;
		if (v < 0)
		{
			v = v + 10;
			borrow = 1;
		}
		d.digits[i] = (char)v % 10;

	}
	zero_justify(d);
	int index = d.lastdigit;
	int temp = 0;
	while (d.digits[index] == 0)
	{
		temp++;
		index -= temp;

	}
	c.lastdigit = index;
	if (index<0) c.lastdigit = 0;
	for (int i = 0; i <= c.lastdigit; i++)
	{
		c.digits[i] = d.digits[i];
	}
	zero_justify(c);
}
void multiplications(bignum a, bignum b, bignum& d)
{

	int i, j, index;
	int carry = 0;
	d.lastdigit = a.lastdigit + b.lastdigit + 5;
	for (i = 0; i <= d.lastdigit; i++)
	{
		d.digits[i] = 0;
	}
	if (a.signbit*b.signbit == PLUS)
	{
		d.signbit = a.signbit;
	}
	if (a.signbit*b.signbit == MINUS)
	{
		d.signbit = MINUS;
	}
	for (i = 0; i <= a.lastdigit; i++)
	{
		carry = 0;
		for (j = 0; j <= b.lastdigit; j++)
		{
			index = i + j;

			int a1 = (int)((a.digits[i])*(b.digits[j]) + carry + d.digits[index]);


			carry = (a1) / 10; d.digits[index] = char(a1 % 10);

		}
		if (carry) d.digits[index + b.lastdigit] = d.digits[index + b.lastdigit] + carry;
	}
	zero_justify(d);

}
void multiplication(bignum a, bignum b, bignum& c)
{
	bignum d;
	int i, j, index;
	int carry = 0;
	d.lastdigit = a.lastdigit + b.lastdigit + 5;
	for (i = 0; i <= d.lastdigit; i++)
	{
		d.digits[i] = 0;
	}
	if (a.signbit*b.signbit == PLUS)
	{
		c.signbit = a.signbit;
	}
	if (a.signbit*b.signbit == MINUS)
	{
		c.signbit = MINUS;
	}
	for (i = 0; i <= a.lastdigit; i++)
	{
		carry = 0;
		for (j = 0; j <= b.lastdigit; j++)
		{
			index = i + j;

			int a1 = (int)((a.digits[i])*(b.digits[j]) + carry + d.digits[index]);


			carry = (a1) / 10; d.digits[index] = char(a1 % 10);

		}
		if (carry) d.digits[index + b.lastdigit] = d.digits[index + b.lastdigit] + carry;
	}
	zero_justify(d);
	index = d.lastdigit;
	int temp = 0;
	while (d.digits[index] == 0)
	{
		temp++;
		index -= temp;

	}
	c.lastdigit = index + 1;
	if (index<0) c.lastdigit = 0;
	for (int i = 0; i <= c.lastdigit; i++)
	{
		c.digits[i] = d.digits[i];
	}
	zero_justify(c);
}
void divison(bignum a, bignum b, bignum& c)
{
	bignum temp1;
	bignum d;
	bignum e;
	e.signbit = PLUS;
	d.signbit = PLUS;
	e.digits[0] = 1;
	e.lastdigit = 0;
	d.lastdigit = a.lastdigit + b.lastdigit;
	temp1.lastdigit = a.lastdigit;
	if (a.signbit*b.signbit == PLUS)
	{
		c.signbit = a.signbit;
	}
	for (int i = 0; i <= d.lastdigit; i++)
	{
		d.digits[i] = 0;
	}
	if (a.signbit*b.signbit == MINUS)
	{
		c.signbit = MINUS;
	}
	a.signbit = PLUS;
	b.signbit = PLUS;
	if (compare_bignum(a, b) == PLUS)
	{
		c.lastdigit = 0;
		c.digits[0] = 0;
		return;
	}
	while (compare_bignum(a, temp1) == MINUS || compare_bignum(a, temp1) == 0)
	{

		add_bignum(d, e, d);

		/*cout << "\nSO LAN";*/
		/*print_bignum(d);*/
		multiplications(b, d, temp1);
		temp1.lastdigit = a.lastdigit;
	}
	subtract_bignum(d, e, d);
	zero_justify(d);
	int index = d.lastdigit;
	int temp = 0;
	while (d.digits[index] == 0)
	{
		temp++;
		index -= temp;

	}
	c.lastdigit = index;
	if (index<0) c.lastdigit = 0;
	for (int i = 0; i <= c.lastdigit; i++)
	{
		c.digits[i] = d.digits[i];
	}
	zero_justify(c);
}
struct SO
{
	bignum data;
	SO * pnext;

};
struct StackSo
{
	SO* Top;
};
bool isEmptys(StackSo stack)
{
	if (stack.Top == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void inits(StackSo &stack)
{
	stack.Top = NULL;
}
SO * getNodes(bignum x)
{
	SO *p = new SO;
	p->data = x;
	p->pnext = NULL;
	return p;
}
void pushs(StackSo &stack, bignum x)
{

	SO *p = new SO;
	p = getNodes(x);
	if (isEmptys(stack))
	{
		stack.Top = p;
	}
	else
	{
		p->pnext = stack.Top;
		stack.Top = p;
	}
}
bignum pops(StackSo  &stack)
{

	SO *p = stack.Top;
	bignum data = p->data;
	stack.Top = stack.Top->pnext;
	delete p;
	return data;
}
void Evaluate(char postfix[], bignum &C)
{
	StackSo stack;
	bignum  op1, op2;
	bignum result;
	inits(stack);
	int i = 0;
	while (postfix[i] != '\0')
	{
		if (checknumber(postfix[i]))
		{
			bignum num;
			char A[MAXDIGTS];
			num.signbit = PLUS;
			int index = 0;
			while (checknumber(postfix[i]))
			{

				A[index] = postfix[i];
				index++;
				i++;
			}

			scan(A, num, index);

			pushs(stack, num);
		}
		else if (postfix[i] == ' ' || postfix[i] == ',' || postfix[i] == '\t')
		{
			i++;
		}
		else
		{

			op1 = pops(stack);
			op2 = pops(stack);
			switch (postfix[i])
			{
			case '+':

				add_bignum(op2, op1, result);
				break;
			case '-':

				subtract_bignum(op2, op1, result);
				break;
			case '/':
				divison(op2, op1, result);
				break;
			case '*':
				multiplication(op2, op1, result);
			}
			pushs(stack, result);
			i++;
		}

	}
	result = pops(stack);
	C = result;
	C.lastdigit = result.lastdigit;
	C.signbit = result.signbit;

}
 

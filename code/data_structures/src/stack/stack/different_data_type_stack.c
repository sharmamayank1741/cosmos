//Solution Q5 : Variable Data Type Stack
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#define max 50
#define INT 1
#define FLOAT 2
#define CHAR 3
union val
		{
			int ival;
			float fval;
			char cval;
		};
struct stkelement
	{
		int type;
		val value;
		
	};
struct stk
	{
		int top;
		stkelement info[max];
	public:
		void push(int x);
		void push(double x);
		void push(char x);
		void push(char x[]);
		void pop();
		stk(){top = -1;}
	};
void  stk :: push(int x)
 	{
 		top++;
 		info[top].type=INT;
 		info[top].value.ival=x;
 	}
void  stk :: push(char x)
 	{
 		top++;
 		info[top].type=CHAR;
 		info[top].value.cval=x;
 	}
void  stk :: push(double x)
 	{
 		top++;
 		info[top].type=FLOAT;
 		info[top].value.fval=x;
 	}
 void stk::pop()
 {
	switch(this->info[top].type)
	{
		case INT : printf("%d  ",this->info[top].value.ival);
					break;
		case FLOAT : printf("%f  ",info[top].value.fval);
					break;
		case CHAR  : printf("%c  ",info[top].value.cval);
					break;
	}
 	--top;
 }
int main()
{
	stk STACK;
	STACK.push(50);
	printf("Pushed 50 to Stack \n");
	STACK.push(2.52);
	printf("Pushed 2.52 to Stack\n");
	STACK.push('A');
	printf("Pushed A to stack\n");
	printf("Top element popped : ");
	STACK.pop();
	STACK.pop();
	STACK.pop();

	return 0;
}

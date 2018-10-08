//Solution Q2 : Infix to postfix expression
#include<bits/stdc++.h>
using namespace std;
#define max 50
class stk
{
	int ctop;
	char arr[max];
	public :
	stk()  {ctop=-1;};
	void push(char x);
	void pop();
	bool isempty();
	char top();
};
void stk::push(char x)
{
	ctop++;
	arr[ctop]=x;	
}
void stk::pop()
{
		ctop--;
}
bool stk::isempty()
{
if(ctop==-1)	
	return true;
	else return false;
}
char stk::top()
{

	if(!isempty())
	return arr[ctop];
	else return '\0';
}
string INF_T_PF(string exp)
	{
	stk s;
	string result;
	for(int i=0;i<exp.size();i++)
	{
		switch(exp[i])
		{
			case '(' : s.push('(');
							 break;

			case '/'  : s.push('/');
							 break;

			case '*'  : while(s.top()=='/')
						{
							result+=s.top();
							s.pop();
						}
						s.push('*');
						break;

			case '+'   : while(s.top()=='*' || s.top()=='/')
						 {
							result+=s.top();
							s.pop();
						 }
						 s.push('+');
						 break;

			case '-'	: while(s.top()=='+' || s.top()=='*' || s.top()=='/')
							{
							result+=s.top();
							s.pop();
							}
							s.push('-');
							break;
			case ')'	:  while(s.top()!='(')

							{
								result+=s.top();
								s.pop();
							}
							s.pop();
							break;
			default      :  result+=exp[i];
			}
	}
	while(!s.isempty())
	{
		result+=s.top();
		s.pop();
	}
	return result;
	}
int main()
{
	string exp;
	cout<<"Input Expression : ";
	cin>>exp;
	string res=INF_T_PF(exp);
	cout<<"\nPostfix Form : "<<res;
return 0;
}


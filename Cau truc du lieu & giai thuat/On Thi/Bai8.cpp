//Stack mang
#include <iostream>
#define MAX 1000
#include<cstring>
#include<stack>
#include<cmath>
using namespace std;

struct Stack{
	int top;
	int node[MAX];
};

bool Empty(Stack *s)
{
	if(s->top == -1) return true;
	return false;
}

bool Full(Stack *s)
{
	if(s->top == MAX-1) return true;
	return false;
}

void Push(Stack *s,int x)
{
	if(!Full(s))
	{
		s->top=(s->top)+1;
		s->node[s->top]=x;
	}
	else cout<<endl<<"Stack day"<<endl;
}

int Top(Stack *s)
{
	if(!Empty(s))
	{
		int x=s->node[s->top];
	//	s->top=(s->top)-1;
		return x;
	}
	else cout<<endl<<"Stack rong"<<endl;
}

void Pop(Stack *s)
{
	if(!Empty(s))
	{
		s->top=(s->top)-1;
	}
	else cout<<endl<<"Stack rong"<<endl;
}

int Size(Stack *s)
{
	return (s->top)+1;
}

void Display(Stack *s)
{
	while(!Empty(s))
	{
		cout<<Top(s)<<" ";
		Pop(s);
	}
}

bool LaSo(char c)
{
	return (c>='0' && c<='9');
}
bool LaTT(char c)
{
	return (c=='+' || c=='-' || c=='*' || c=='/');
}
int UT(char c)
{
	if(c=='+' || c=='-') return 1;
	if(c=='*' || c=='/') return 2;
	return 0;
}

string ChuyenTrungToSangHauTo(string str)
{
	string temp="";
	stack<char> st;
	int s = str.size();
	for(int i=0;i<s;i++)
	{
		if(LaSo(str[i]))
		{
			while(LaSo(str[i]))
			{
				temp +=str[i++];
			}
			
			temp+=' ';
		}
		if(str[i]=='(')
			st.push(str[i]);
		if(str[i]==')')
		{
			while(st.top()!='(')
			{
				temp +=st.top();
				st.pop();
			}
			st.pop();
		}
		if(LaTT(str[i]))
		{
			if(!st.empty() && UT(st.top()) >= UT(str[i]))
			{
				temp += st.top();
				temp +=' ';
				st.pop();
			}
			st.push(str.at(i));
		}
	}
	while(!st.empty())
	{
		temp+= st.top();
		temp+=' ';
		st.pop();
	}
	return temp;
}

int tinh(string str)
{
	stack<int> st;
	int x=0,a,b,c;
	int len = str.size();
	for(int i=0;i<len;i++)
	{
		if(LaSo(str[i]))
		{
			while(LaSo(str[i]))
				x = x*10 + str[i++] - 48;
			st.push(x);
			x=0;
		}
		if(LaTT(str[i]))
		{
			b = st.top(); st.pop();
			a = st.top(); st.pop();
			if(str[i]=='+') c = a + b;
			if(str[i]=='-') c = a - b;
			if(str[i]=='*') c = a * b;
			if(str[i]=='/') c = a / b;
			st.push(c);
		}
	}
	return st.top();
}

main()
{
	Stack *s;
	s->top=-1;
	for(int i=1;i<=10;i++)
	Push(s,i);
	
	cout<<endl<<"Size:"<<Size(s)<<endl;
	
	string str;
	cout<<"Nhap bieu thuc can tinh: ";
	getline(cin, str);
	string a=ChuyenTrungToSangHauTo(str);
	cout<<a<<endl;
	cout<<tinh(a)<<endl;
}

#include<iostream>
#include<conio.h>
#include<stack>
using namespace std;

double tinh(double a,double b,char c)
{
	if(c=='+') return a+b;
	if(c=='-') return a-b;
	if(c=='*') return a*b;
	if(c=='/')
	{
		if(b==0) {cout<<"Co loi chia 0 !\n";return -1;}
		else return a/b;
	}
}
int hang(char a)
{
	if(a=='*'||a=='/') return 2;
	if(a=='+'||a=='-') return 1;
	if(a==')'||a=='(') return 0;
	return -1;
}
main()
{
	stack <char> T;
	char x[100],y[100];
	int v=0;
	cout<<"Nhap bieu thuc:";fflush(stdin);gets(x);
	//chuyen qua hau to
	for(int i=0;i<=strlen(x);i++)
	{
		if(x[i]==' ') continue;
		if((x[i]>='0'&&x[i]<='9')) 
		{
			if(x[i-1]<'0'||x[i-1]>'9') y[v++]='.';
			y[v++]=x[i];
		}
		
		else if(x[i]==')'||x[i]==NULL)
			while(!T.empty())
			{
				if(T.top()!='(') {y[v++]='.';y[v++]=T.top();}
				T.pop();
			}
		else if(hang(x[i])!=-1)
		{
			if(T.empty()) T.push(x[i]);
			else 
			{
				if(x[i]!='('&&hang(x[i])<=hang(T.top())) 
					{y[v++]='.';y[v++]=T.top();T.pop();}
				T.push(x[i]);
			}
		}
	}
	y[v++]='.';
	y[v]=0;
	char so[100];
	int skt=0,a,b;
	stack <double> Hauto;
	//tinh gia tri hau to
	strcpy(so,"");
	for(int i=1;i<strlen(y);i++)
	{
		if(y[i]=='.'&&i>0) 
		{
			if(so[0]=='*'||so[0]=='-'||so[0]=='+'||so[0]=='/')
			{
				a=Hauto.top();Hauto.pop();
				b=Hauto.top();Hauto.pop();
				Hauto.push(tinh(b,a,so[0]));
			}
			else Hauto.push(atoi(so));
			strcpy(so,"");
		}
		else 
		{
			so[strlen(so)+1]=0;
			so[strlen(so)]=y[i];
		}
	}
	cout<<"Ket qua = "<<Hauto.top();
}

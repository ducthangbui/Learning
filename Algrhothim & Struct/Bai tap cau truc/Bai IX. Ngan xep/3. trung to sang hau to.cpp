#include<iostream>
#include<string>
#include<stack>
using namespace std;

int hang(char a)
{
	if(a=='*'||a=='/') return 2;
	if(a=='+'||a=='-') return 1;
	if(a==')'||a=='(') return 0;
	return -1;
}
main()
{
	//stack T;
	stack <char> T;
	string x;
	cout<<"Nhap bieu thuc:";//fflush(stdin);gets(x);
	getline(cin,x);
	for(int i=0;i<=x.length();i++)
	{
		if(x[i]==' ') continue;
		if((x[i-1]<'0'||x[i-1]>'9')&&hang(x[i])!=0) cout<<' ';
		if(x[i]>='0'&&x[i]<='9') cout<<x[i];
		else if(x[i]==')'||x[i]==NULL)
			while(!T.empty())
			{
				if(T.top()!='(') cout<<' '<<T.top();
				T.pop();
			}
		else if(hang(x[i])!=-1)
		{
			if(T.empty()) T.push(x[i]);
			else 
			{
				if(x[i]!='('&&hang(x[i])<=hang(T.top())) 
				{
					cout<<' '<<T.top();
					T.pop();
				}
				T.push(x[i]);
			}
		}
	}
}

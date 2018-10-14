#include<iostream>
#include<cstring>
#include<stack>
#include<cmath>
using namespace std;

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

int main()
{
	stack <int> s;
	for(int i=1;i<=10;i++)
	s.push(i);
	
	cout<<"Size:"<<s.size()<<endl
		<<"Top:"<<s.top()<<endl;
	
	cout<<"Stack:";
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}	
	string str;
	cout<<endl<<"Nhap bieu thuc can tinh: ";
	getline(cin, str);
	string a=ChuyenTrungToSangHauTo(str);
	cout<<"Hau to:"<<a<<endl;
	cout<<"Ket qua:"<<tinh(a)<<endl;
	return 0;
}

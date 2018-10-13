#include<iostream>
#include<string>
#include<stack>
using namespace std;

int bieuthuc(string a)
{
	int ketqua;
	stack <char> T;
	for(int i=0;i<=a.length();i++)
	{
		if(a[i]>='0'&&a[i]<='9') T.push(a[i]);
		else
		{
			int x=(int)T.top();
			T.pop();
			int y=(int)T.top();
			T.pop();
			if(a[i]=='+') T.push(x+y);
			if(a[i]=='-') T.push(x-y);
			if(a[i]=='*') T.push(x*y);
			if(a[i]=='/') T.push(x/y);
		}
		if(a[i]==NULL) {
			ketqua=(int)T.top();
			T.pop();
		}
	}
	return ketqua;
}
main()
{
	string s;
	cout<<"Nhap bieu thuc:";
	getline(cin,s);
	cout<<bieuthuc(s);
}

/*Stack mang*/
#include<iostream>
using namespace std;
void push(string a,string x)
{
	a=x;
}
int ktra(string a)
{
	for(int i=0;i<a.length();i++)
		for(int j=a.length()-1;j>=i;j--)
		if(a[i]==a[j]) return 1;
						return 0;
}
main()
{
	string a,x="11";
	//int n=0;
	//cout<<"Nhap vao mang can kiem tra:";
	//cin>>x;
	push(a,x);
	if(ktra(a)==1) cout<<"OK!!!";
				else cout<<"NO!!!";
}


#include<iostream>
#include<string.h>
using namespace std;
main()
{
	//char a[10];
	string a;
	//cin>>a;
	getline(cin,a);
	//scanf("%c",a);
	//cout<<static_cast<char>(a[0]+'');
	//printf("%c",a+32);
	//if(a[0]>="a"&&a[0]<="z") cout<<a;
	//a.erase(0,1);
	cout<<strupr(a);
}

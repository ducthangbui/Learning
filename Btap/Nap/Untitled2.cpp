#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
main()
{
	string s1;
	string s2;
	cout<<"Enter string 1:";
	getline(cin,s1);
	cout<<"enter string 2:";
	getline(cin,s2);
	for(int i=0;i<s1.length();i++)
	printf("%3c",s1[i]&s2[i]);
}

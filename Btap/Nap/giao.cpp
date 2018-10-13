#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
void Giao(string s1,string s2)
{
	string s=s1+s2;
	int j;
	for(int i=0;i<s.length();i++)
	{
		for(j=s.length()-1;j>i;j--)
		if(s[i]==s[j]) s.erase(j,1);//s.earase(int a,int b)=xoa b ki tu cua chuoi s tu vi tri a
		if(s[i]!=s[j]) s.erase(j,1); 
	}
	for(int i=1;i<s.length();i=i+2)
	s.insert(i,1,'	');
	cout<<setw(10)<<s;
}
void Hop(string s1,string s2)
{
	string s=s1+s2;
	for(int i=0;i<s.length();i++)
	{
		for(int j=s.length()-1;j>i;j--)
		if(s[i]==s[j]) s.erase(j,1);//s.earase(int a,int b)=xoa b ki tu cua chuoi s tu vi tri a 
	}
	for(int i=1;i<s.length();i=i+2)
	s.insert(i,1,'	');
	cout<<setw(10)<<s;
}
void Tru(string &s1,string s2)
{
	string kqua;
	string s=s1+s2;
	for(int i=0;i<s1.length();i++)
	{
		for(int j=0;j<s2.length();j++)
		if(s1[i]==s2[j]) s1.erase(i,1);
	}
	for(int i=1;i<s1.length();i=i+2)
	s1.insert(i,1,'	');//s1/insert(int a,int b,char c)= chen vao chuoi s1 vi tri i, b ki tu bang chuoi c 
	cout<<setw(3)<<s1;
}
main()
{
	string s1;
	string s2;
	cout<<"Enter string 1:";
	getline(cin,s1);
	cout<<"enter string 2:";
	getline(cin,s2);
	cout<<"S1 U S2:";
	Giao(s1,s2);
	cout<<endl<<"S1 V S2 :";
	Hop(s1,s2);
	cout<<endl<<"S1 tru S2:";
	Tru(s1,s2);
}

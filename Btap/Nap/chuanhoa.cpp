#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;
//string chuanhoa1(string s)
void chuanhoa(string s)
{
	const char *ptr1=0;
	int length=s.length();
	char *ptr2=new char[length+1];
	s.copy(ptr2,length,0);
	//ptr2[length]='\0';
	strcpy(ptr2,s.c_str());
	if(ptr2[0]>='a'&&ptr2[0]<='z') ptr2[0]=ptr2[0]-32;
	for(int i=1;i<length;i++)
	{
		if(ptr2[i]=='.'&&(ptr2[i+2]>='a'&&ptr2[i+2]<='z')) ptr2[i+2]=ptr2[i+2]-32;
		if(ptr2[i]>='A'&&ptr2[i]<='Z'&&ptr2[i-2]!='.') ptr2[i]=ptr2[i]+32;
	}
	//for(int i=0;i<length;i++)
	cout<<ptr2;
	
}
string chuanhoa1(string s)
{
	int dem=0,i=0;
	if(s[0]==' ') s.erase(0,2);
	for(int i=1;i<s.length();i++)
	{
		if(s[i]==' '&&s[i+1]==' ') s.erase(i,1);
	}

	for(int i=0;i<s.length();i++)
	{
		if(s[i]==','||s[i]==';'||s[i]==':'||s[i]=='?'||s[i]=='.') s.insert(i+1,1,' '); 
	}
	return s;
}
main()
{
	string s;
	//getline(cin,s);
	ifstream File("chuanhoa.txt",ios::in);
	//while(File>>s)
	getline(File,s);
	chuanhoa(chuanhoa1(s));	//cout<<chuanhoa1(s);
}

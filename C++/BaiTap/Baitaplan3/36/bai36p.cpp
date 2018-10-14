#include "bai36p.h" // class's header file

#include <iostream>
#include <string>

using namespace std;

void Bai36p::TachTen()
{
	getline(cin,s);
	cout<<"Nhap ten can tach:";
	getline(cin,s);
	int dem1 = 0, dem2 = 0;
	string ho, tendem, ten;
	for(int i=0; i <= s.length(); i++)
			{
				if(s[i] != ' ') dem1++; 
				else break;
			}
 
	ho = s.substr(0,dem1);//lay dem1 ki tu tu vi tri 0
	s.erase(0,dem1);//xoa dem1 ki tu tu vi tri 0
	
	for(int i = s.length()-1; i >= 0; i--)
		{
			if(s[i] != ' ') dem2++;
		 	else break;
		}
	//cout<<endl<<"dem2:"<<dem2<<endl;
	ten = s.substr(s.length()-dem2,s.length());
	s.erase(s.length()-dem2,s.length());
	
	cout<<"Ho:"<<ho <<endl
		<<"Ten dem:"<<s << endl
		<<"Ten:"<<ten << endl;
}


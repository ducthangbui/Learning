#include <iostream>
#include <string>

using namespace std;

void TachTen(string s)
{
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
int main()
{
	string s;
	cout<<"Nhap ten can tach:";
	getline(cin,s);
	TachTen(s);
	return 0;
}

#include "d:\lap trinh\c++\function.cpp"

main()
{
	char x[100];
	cout<<"Nhap xau :";fflush(stdin);gets(x);
	cout<<"Ma hoa   :";
	for(int i=0;i<strlen(x);i++)
	cout<<chanhoa(x[i]);
	cout<<"\nGiai ma  :";
	for(int i=0;i<strlen(x);i++)
	cout<<giaimachan(chanhoa(x[i]));


}

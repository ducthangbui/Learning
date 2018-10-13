#include "d:\lap trinh\c++\function.cpp"

main()
{
	char a[100];
	cin>>a;
	for(int i=0;i<strlen(a);i++)
	{
		cout<<giaimachan(chanhoa(a[i]));
	}
}

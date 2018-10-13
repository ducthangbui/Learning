#include "d:\lap trinh\c++\function.cpp"

main()
{
	list <char> T;
	char s1[100],s2[100];
	fflush(stdin);gets(s1);
	fflush(stdin);gets(s2);
	for(int i=0;i<strlen(s1);i++)
	{
		T.remove(s1[i]);
		T.push_back(s1[i]);
	}
	for(int i=0;i<strlen(s2);i++)
	{
		T.remove(s2[i]);
		T.push_back(s2[i]);
	}
	T.remove(' ');
	while(!T.empty())
	{
		cout<<T.back()<<' ';
		T.pop_back();
	}
	



}

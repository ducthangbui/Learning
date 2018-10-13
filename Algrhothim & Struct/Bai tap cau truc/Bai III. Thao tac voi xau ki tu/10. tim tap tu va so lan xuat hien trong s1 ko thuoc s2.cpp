#include "d:\lap trinh\c++\function.cpp"

main()
{
	stringX s1,s2,s;
	s1.nhap();
	s2.nhap();
	s.add(s1);
	s.add(s2);
	int dem[s.count];
	for(int i=0;i<s.count;i++)
	{
		dem[i]=0;
		for(int j=0;j<s.count;j++)
			if(s.str[i]==s.str[j]) dem[i]++;
	}
	
	for(int i=0;i<s.count;i++)
	{
		int k=1;
		for(int j=0;j<i;j++)
			if(s.str[i]==s.str[j]) k=0;
		if(k&&s1.exist(s.str[i])&&!s2.exist(s.str[i])) 
			cout<<setw(10)<<s.str[i]<<" : "<<dem[i]<<endl;
	}
}

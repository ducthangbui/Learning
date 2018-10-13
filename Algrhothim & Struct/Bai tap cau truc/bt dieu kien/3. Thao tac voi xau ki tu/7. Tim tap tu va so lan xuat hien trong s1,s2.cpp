#include "d:\lap trinh\c++\function.cpp"

main()
{
	stringX s;
	s.nhap();
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
		if(k) cout<<setw(10)<<s.str[i]<<" : "<<dem[i]<<endl;
	}
}

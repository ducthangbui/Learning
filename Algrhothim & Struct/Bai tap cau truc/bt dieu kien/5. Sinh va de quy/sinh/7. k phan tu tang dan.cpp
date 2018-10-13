#include "D:\lap trinh\c++\function.cpp"

int x[MAX],n,OK,k,dayso[MAX],truoc;
bool test()
{
	truoc=0;
	for(int i=1;i<=k;i++)
	{
		if(dayso[x[i]]<dayso[truoc]) return false;
		truoc=x[i];
	}
	return true;
}
main()
{
	Init_NC_(x,n,k,OK);
	dayso[0]=-100;
	for(int i=1;i<=n;i++)
	{
		cout<<"Nhap phan tu thu "<<i<<" : ";cin>>dayso[i];
	}
	while(OK)
	{
		if(test())
		{
			for(int i=1;i<=k;i++)
				cout<<dayso[x[i]]<<' ';
			cout<<endl;
		}
		next_com(x,n,k,OK);
	}
}


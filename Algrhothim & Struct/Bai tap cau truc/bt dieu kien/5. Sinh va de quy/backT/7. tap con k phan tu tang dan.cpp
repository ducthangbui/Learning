#include "D:\lap trinh\c++\function.cpp"
int x[MAX],n,k,truoc=0,dayso[MAX];
void Init()
{
	cout<<"Nhap n=";cin>>n;
	cout<<"Nhap k=";cin>>k;
	for(int i=1;i<=n;i++)
	{
		cout<<"Nhap phan tu thu "<<i<<" : ";cin>>dayso[i];
	}
	dayso[0]=-1000;
}
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
void BackT_COM(int i=1)
{
	for(int j=x[i-1]+1;j<=n-k+i;j++)
	{
		x[i]=j;
		if(i==k)
		{
			if(test()==1)
			{
				for(int i=1;i<=k;i++)
				cout<<dayso[x[i]]<<' ';
				cout<<endl;
			}
		}
		else BackT_COM(i+1);
	}
}
main()
{
	Init();
	BackT_COM();
}
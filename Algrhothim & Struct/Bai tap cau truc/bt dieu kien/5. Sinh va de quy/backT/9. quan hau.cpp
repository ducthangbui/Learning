#include "D:\lap trinh\c++\function.cpp"
int x[MAX],n,chuaxet[MAX];
void Init()
{
	cout<<"Nhap n=";cin>>n;
	for(int i=1;i<=n;i++) chuaxet[i]=1;
}
bool test()
{
	int Chinh[MAX],Phu[MAX];
	for(int i=0;i<2*n;i++) Chinh[i]=Phu[i]=0;
	for(int i=1;i<=n;i++)
	{
		if(Chinh[x[i]-i+n]||Phu[x[i]+i-1]) return false;
		Chinh[x[i]-i+n]++;
		Phu[x[i]+i-1]++;
	}
	return true;
}
void BackT_PER(int i=1)
{
	for(int j=1;j<=n;j++)
		if(chuaxet[j]) 
		{
			x[i]=j;
			chuaxet[j]=0;
			if(i==n) 
			{
				if(test()) 
				{
					for(int i=1;i<=n;i++) cout<<i<<x[i]<<' ';
					cout<<endl;
				}
			}
			else BackT_PER(i+1);
			chuaxet[j]=1;
		}
	
}
main()
{
	Init();
	BackT_PER();
}
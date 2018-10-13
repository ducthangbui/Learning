#include "D:\Learning\Algrhothim & Struct\Bai tap cau truc\function.cpp"
int x[MAX],n,OK;
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
main()
{
	Init_NP_(x,n,OK);
	while(OK)
	{
		if(test())
		{
			for(int i=1;i<=n;i++) cout<<i<<x[i]<<' ';
			cout<<endl;
		}
	
		next_per(x,n,OK);
	}
}

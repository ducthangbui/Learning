#include "E:\\goc hoc tap\\lap trinh\\c++\\function.cpp"

int n,x[MAX][MAX],sc,l[MAX][MAX];
void Init()
{
	mo_fDoc("lienthuoc.txt");
	mo_fGhi("dscanh.txt");
	fi>>n>>sc;
	fo<<n<<' '<<sc<<endl;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=sc;j++)
		fi>>l[i][j];
	int p,q;	
	for(int i=1;i<=sc;i++)
	{
		p=q=0;
		for(int j=1;j<=n;j++)
		{
			if(l[j][i]==1) p=j;
			if(l[j][i]==-1) q=j;
		}
		fo<<p<<' '<<q<<endl;
	}	
}
main()
{
	Init();
}

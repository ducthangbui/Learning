#include "E:\\goc hoc tap\\lap trinh\\c++\\function.cpp"

int n,x[MAX][MAX],sc,l[MAX][MAX];
void Init()
{
	mo_fDoc("lienthuoc.txt");
	mo_fGhi("mtke.txt");
	fi>>n>>sc;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=sc;j++)
		fi>>l[i][j];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=sc;j++)
		if(l[i][j]==1)
			for(int k=1;k<=n;k++)
				if(k==i) continue;
				else if(l[k][j]==-1) x[i][k]=1;
	fo<<n<<endl;
	for(int i=1;i<=n;fo<<endl,i++)
	for(int j=1;j<=n;j++) fo<<x[i][j]<<' ';
}
main()
{
	Init();
}

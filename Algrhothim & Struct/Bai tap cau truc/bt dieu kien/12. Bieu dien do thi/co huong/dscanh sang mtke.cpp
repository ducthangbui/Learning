#include "E:\\goc hoc tap\\lap trinh\\c++\\function.cpp"

int n,x[MAX][MAX],sc;
void Init()
{
	int i,j;
	mo_fDoc("dscanh.txt");
	fi>>n>>sc;
	mo_fGhi("mtke.txt");
	fo<<n<<endl;
	
	for(int k=1;k<=sc;k++)
	{
		fi>>i>>j;
		x[i][j]=1;
	}
	for(int i=1;i<=n;fo<<endl,i++)
	for(int j=1;j<=n;j++)
		 fo<<x[i][j]<<' ';
	dong_FDoc();
	dong_FGhi();
}
main()
{
	Init();
}

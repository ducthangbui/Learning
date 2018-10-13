#include "E:\\goc hoc tap\\lap trinh\\c++\\function.cpp"

int n,x[MAX][MAX],sc,l[MAX][MAX];
void Init()
{
	int i,j;
	mo_fDoc("dscanh.txt");
	fi>>n>>sc;
	mo_fGhi("lienthuoc.txt");
	fo<<n<<' '<<sc<<endl;
	
	for(int k=1;k<=sc;k++)
	{
		fi>>i>>j;
		l[i][k]=l[j][k]=1;
		
	}
	for(int i=1;i<=n;fo<<endl,i++)
	for(int j=1;j<=sc;j++)
	 	fo<<l[i][j]<<' ';
	dong_FDoc();
	dong_FGhi();
}
main()
{
	Init();
}

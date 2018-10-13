#include "E:\\goc hoc tap\\lap trinh\\c++\\function.cpp"
int n,x[MAX][MAX],demcanh=0,l[MAX][MAX];
void Init()
{
	mo_fDoc("mtke.txt");
	fi>>n;
	mo_fGhi("lienthuoc.txt");
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		fi>>x[i][j];
		if(i<j&&x[i][j]) {demcanh++;l[i][demcanh]=l[j][demcanh]=1;}
	}
	dong_FDoc();
	fo<<n<<' '<<demcanh<<endl;
	for(int i=1;i<=n;fo<<endl,i++)
	for(int j=1;j<=demcanh;j++)
		fo<<l[i][j]<<' ';
	dong_FGhi();
}
main()
{
	Init();
}
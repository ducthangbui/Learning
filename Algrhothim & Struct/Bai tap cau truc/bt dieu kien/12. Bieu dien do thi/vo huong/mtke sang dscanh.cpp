#include "E:\\goc hoc tap\\lap trinh\\c++\\function.cpp"

int n,x[MAX][MAX],demcanh=0;
void Init()
{
	mo_fDoc("mtke.txt");
	fi>>n;
	mo_fGhi("dscanh.txt");
	fo<<"            "<<endl;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		fi>>x[i][j];
		if(i<j&&x[i][j]) {fo<<i<<' '<<j<<endl;demcanh++;}
	}
	dong_FDoc();
	fo.seekp(ios::beg);
	fo<<n<<' '<<demcanh;
	dong_FGhi();
}
main()
{
	Init();
}
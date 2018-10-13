#include "E:\\goc hoc tap\\lap trinh\\c++\\function.cpp"

int n,x[MAX][MAX];

void Init()
{
	mo_fDoc("mtke.txt");
	mo_fGhi("dske.txt");
	fi>>n;fo<<n<<endl;
	for(int i=1;i<=n;fo<<endl,i++)
	for(int j=1;j<=n;j++)
	{
		fi>>x[i][j];
		if(x[i][j]) fo<<j<<' ';
	}
	dong_FGhi();
	dong_FDoc();
}
main()
{
	Init();
}
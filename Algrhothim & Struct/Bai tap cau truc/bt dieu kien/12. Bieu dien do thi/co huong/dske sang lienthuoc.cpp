#include "E:\\goc hoc tap\\lap trinh\\c++\\function.cpp"

int n,x[MAX][MAX],sc,demcanh=0,l[MAX][MAX];
void Init()
{
	char tmp[10*MAX];
	int tong=0;
	mo_fDoc("dske.txt");
	mo_fGhi("lienthuoc.txt");
	fi>>n;fi.getline(tmp,1000);
	for(int i=1;i<=n;i++)
	{
		fi.getline(tmp,1000);
		int k=strlen(tmp);
		for(int j=0;j<k;j++)
			if(tmp[j]==' '||tmp[j]==NULL)
			{
				demcanh++;
				l[i][demcanh]=1;l[tong][demcanh]=-1;
				tong=0;	
			} 
			else tong=tong*10+(tmp[j]-48);
	}
	fo<<n<<' '<<demcanh<<endl;
	for(int i=1;i<=n;fo<<endl,i++)
	for(int j=1;j<=demcanh;j++) fo<<setw(3)<<l[i][j]<<' ';
	dong_FGhi();
	dong_FDoc();
}
main()
{
	Init();
}

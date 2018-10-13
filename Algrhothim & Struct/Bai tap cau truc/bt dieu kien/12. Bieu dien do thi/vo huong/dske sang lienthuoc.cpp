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
				if(i<tong) 
				{
					demcanh++;
					l[i][demcanh]=l[tong][demcanh]=1;
				}
				tong=0;	
			} 
			else tong=tong*10+(tmp[j]-48);
	}
	fo<<n<<' '<<demcanh<<endl;
	for(int i=1;i<=n;fo<<endl,i++)
	for(int j=1;j<=demcanh;j++) fo<<l[i][j]<<' ';
	dong_FGhi();
	dong_FDoc();
}
main()
{
	Init();
}

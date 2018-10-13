#include "E:\\goc hoc tap\\lap trinh\\c++\\function.cpp"

int n,x[MAX][MAX],sc=0;
stack <int> a[MAX];
void Init()
{
	char tmp[10*MAX];
	int tong=0;
	mo_fDoc("dske.txt");
	mo_fGhi("dscanh.txt");
	fi>>n;fi.getline(tmp,1000);
	for(int i=1;i<=n;i++)
	{
		fi.getline(tmp,1000);
		int k=strlen(tmp);
		for(int j=0;j<k;j++)
			if(tmp[j]==' '||tmp[j]==NULL)
			{
				if(i>tong) sc++;
				a[i].push(tong);
				tong=0;			
			} 
			else tong=tong*10+(tmp[j]-48);
	}
	fo<<n<<' '<<sc<<endl;
	for(int i=1;i<=n;i++)
		while(!a[i].empty())
		{
			if(i<a[i].top()) fo<<i<<' '<<a[i].top()<<endl;
			a[i].pop();
		}
	dong_FDoc();
	dong_FGhi();
}
main()
{
	Init();
}

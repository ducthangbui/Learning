#include "E:\\goc hoc tap\\lap trinh\\c++\\function.cpp"

int n,x[MAX][MAX],sc;
stack <int> a[MAX];
void Init()
{
	char tmp[10*MAX];
	int tong=0;
	mo_fDoc("dske.txt");
	mo_fGhi("mtke.txt");
	fi>>n;fi.getline(tmp,1000);
	for(int i=1;i<=n;i++)
	{
		fi.getline(tmp,1000);
		int k=strlen(tmp);
		for(int j=0;j<k;j++)
			if(tmp[j]==' '||tmp[j]==NULL)
			{
				a[i].push(tong);
				tong=0;			
			} 
			else tong=tong*10+(tmp[j]-48);
	}
	int k;
	fo<<n<<endl;
	for(int i=1;i<=n;fo<<endl,i++)
		for(int j=1;j<=n;j++)
			if(!a[i].empty()) 
			{
				k=a[i].top();a[i].pop();
				for(;j<k;j++) fo<<0<<' ';fo<<1<<' ';
			}
			else fo<<0<<' ';
	dong_FDoc();
}
main()
{
	Init();
}

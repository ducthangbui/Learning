#include "E:\\goc hoc tap\\lap trinh\\c++\\function.cpp"

int n,x[MAX][MAX],sc;
stack <int> a[MAX];
void Init()
{
	int i,j;
	mo_fDoc("dscanh.txt");
	fi>>n>>sc;
	mo_fGhi("dske.txt");
	fo<<n<<endl;
	
	for(int k=1;k<=sc;k++)
	{
		fi>>i>>j;
		if(i<j) 
		{
			a[i].push(j);	
			a[j].push(i);
		}
		
	}
	
	for(int i=1;i<=n;fo<<endl,i++)
		while(!a[i].empty())
		{
			fo<<a[i].top()<<' ';
			a[i].pop();
		}
	dong_FDoc();
	dong_FGhi();
}
main()
{
	Init();
}

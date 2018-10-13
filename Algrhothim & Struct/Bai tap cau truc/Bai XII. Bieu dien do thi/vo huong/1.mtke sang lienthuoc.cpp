#include<iostream>
#include<fstream>
#define MAX 100
using namespace std;
ifstream fi;
ofstream fo;
int n,x[MAX][MAX],demcanh=0,l[MAX][MAX];
void Init()
{
	fi.open("mtke.txt");
	fi>>n;
	fo.open("lienthuoc.txt");
	for(int k=1;k<=n;k++)
	for(int j=1;j<=n;j++)
	{
		fi>>x[k][j];
		if(k<j&&x[k][j]) {demcanh++;l[k][demcanh]=l[j][demcanh]=1;}
	}
	fi.close();
	fo<<n<<' '<<demcanh<<endl;
	for(int i=1;i<=n;fo<<endl,i++)
	for(int j=1;j<=demcanh;j++)
		fo<<l[i][j]<<' ';
	fo.close();
}
main()
{
	Init();
}

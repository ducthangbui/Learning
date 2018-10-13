#include<iostream>
#include<fstream>
#include<stack>
using namespace std;
fstream fi;
stack <int > x,e;
int a[100][100],n,u,k;
int d1=0,d2=0,d=0;

void init()
{
	fi.open("duongdieulercohuong.txt");
	fi>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	fi>>a[i][j];
	fi.close();
}

int kiemtravaora()
{
    for(int i=1;i<=n;i++)
    {
   	    int dvao=0,dra=0;
    	for(int j=1;j<=n;j++) {dvao+=a[i][j]; dra+=a[j][i];}
        if((dvao-dra)==1)
    	{
	    	k=i;
	    	d1++;
	    }	
      	else
			if((dra-dvao)==1)
				d2++;
			else
			if(dvao==dra)
				d++;
    }
    if(d==(n-2)&&d1==1&&d2==1)
	return 1;  // co duong di euler
    else
   	return 0;   //khong co duong di euler
}

void euler(int v)
{
	x.push(v);
	while(!x.empty())
	{
		int dem=1;
		int k=x.top();
		//cout<<"nhan";
		for(int i=1;i<=n;i++)
		{
			if(a[k][i]==1)
	  		{
			  	x.push(i); 
				a[k][i]=0;a[i][k]=0;
				dem++;
				break;//Duyet lan luot 1 canh 1 trong moi vong if
			
			}
		}
		if(dem==1)
		{
			e.push(k);
			x.pop();
		}
	}
}
void xuat()
{
	while(!e.empty())
	{
		cout<<e.top()<<" ";
		e.pop();
	}
}
main()
{
	init();
	if(kiemtravaora())
	{
		euler(k);
	}
	xuat();
}
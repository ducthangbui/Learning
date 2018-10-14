#include<iostream>
#include<string.h>

using namespace std;
char *doihe(char *number,int m,int n)
{
	static char ketqua[33];
	char chuso[]="0123456789ABCDGHIJKLMNOPQRSTUVWX";
	int i=0,giatri=0,len;
	len=strlen(number);
	while(i<len)
	{
		giatri=giatri*m+(strchr(chuso,number[i])-chuso);
		i++;
	}
	i=16;
	ketqua[33]=0;
	do
	{
		ketqua[i]=chuso[giatri%n];
		giatri/=n;
		i--;
	}while(giatri>0);
	return ketqua+i+1;
}
main()
{
	char number[33],*ketqua;
	int n;
	cout<<"Nhap vao he so can chuyen:";
	cin>>n;
	cout<<"Nhap vao so can chuyen:";
	cin>>number;
	ketqua=doihe(number,10,n);
	cout<<"So sau khi chuyen tu co so 10 sang co so "<<n<<" la:"<<ketqua;
	
}

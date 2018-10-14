#include<stdio.h>
#include<math.h>
int ngto(int n)
{
	if(n<=1) return 0;
	int ktra=0;
	for(int i=2;i<=sqrt(n);i++)
	if(n%i==0) ktra++;
	if(ktra==0) return 1;
	return 0;
}
int tach(int n)
{
	int ktra=0,i=0;
	while(n!=0)
	{
		int m=n%10;
		if(ngto(m)==1) ktra++;
		n=n/10;
		i++;
	}	
	if(ktra==i) return 1;
	else return 0;
}
int tong(int n)
{
	int tong=0;
	while(n!=0)
	{
		 tong=tong+n%10;
		 n/=10;
	}
	if(ngto(tong)==1) return 1;
	return 0;
}
main()
{
	int dem=0;
	for(int i=2345;i<=6789;i++)
	{
	if(ngto(i)==1&&tach(i)==1&&tong(i)==1)
	printf("%d ",i);}
	//if(tong(11)==1) printf("Dung roi");
	//else printf("Sai cmnr");
	//if(tach(2351)==1) printf("Dung roi");
	//for(int i=1;i<=20;i++)
	//if(ngto(i)==1) printf("%d\t",i);
}

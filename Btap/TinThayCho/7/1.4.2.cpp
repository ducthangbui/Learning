#include<stdio.h>
int thuannghich(int n)
{
	int m=0;
	int tmp=n;
	while(n!=0)
	{
		m=m*10+n%10;
		n=n/10;
	}
	if (tmp==m) return 1;
	else return 0;
}
void File()
{
	FILE *f;
	int n,dem=0;
	f=fopen("1.4.2.txt","rt");
	while(!feof(f))
	{
		fscanf(f,"%d",&n);
		if(thuannghich(n)==1) dem++;
	}
	fclose(f);
	printf("%d",dem);
}
main()
{
	File();
}

#include<stdio.h>
int kiemtratang(int a[],int n)
{
    int i,dem=0;
    for(i=0;i<n-1;i++)
    {
                 if(a[i]>=a[i+1])
                 dem++;
    }
                    if(dem==(n-1))
                    return 1;
                    return 0;
}
int kiemtragiam(int a[],int n)
{
	int i,dem=0;
	for(i=0;i<n-1;i++)
	if(a[i]<=a[i+1]) dem++;
	if(dem==(n-1)) return 1;
	else return 0;
}
void sochanle(int a[],int n)
{
	int i,chan=0,le=0;
	for(i=0;i<=n-1;i++)
	{
		if(a[i]%2==0) chan++;
		else le++;
	}
	printf("So chu so chan la:%d\nSo chu so le la:%d",chan,le);
}
main()
{
	int n,a[100],i=0;
	scanf("%d",&n);
	while (n!=0)
	{
		a[i]=n%10;
		n=n/10;
		i++;
	}
	if(kiemtratang(a,i)==1&&kiemtragiam(a,i)==1) printf("Khong tang,khong giam\n");
	else if(kiemtratang(a,i)==1) printf("Tang\n");
	else if(kiemtragiam(a,i)==1) printf("Giam\n");
	else printf("K dc sap xep\n");
	sochanle(a,i);
}

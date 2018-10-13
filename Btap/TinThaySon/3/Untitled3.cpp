#include<stdio.h>
int ktratang(int a[],int n)
{
    int i,dem=0;
    for(i=0;i<n-1;i++)
    {
                 if(a[i]<=a[i+1])
                 dem++;
    }
                    if(dem==(n-1))
                    return 1;
                    return 0;
}
main()
{
	int n,a[10],i=0;
	scanf("%d",n);
	while (n!=0)
	{
		a[i]=n%10;
		n=n/10;
		i++;
	}
	if(ktratang(a,i)==1) printf("Tang");
}

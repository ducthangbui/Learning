#include<stdio.h>
#include<math.h>
int giaithua(int n)
{
	if (n==o||n==1) return 1;
	else return n*giaithua(n-1);
}
int TichGiaiThua(int a[])
{
	int s=1;
	for (int i=0;i<n;i++)
	s=s*giaithua(a);
	return s;
}



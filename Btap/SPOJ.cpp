#include<stdio.h>
#include<math.h>
int ngto(long long &n)
{
	int ktra=0;
	if(n<2) return 0;
	for(int i=2;i<=sqrt(n);i++)
	if(n%i==0) return 0;
	return 1;
}
main()
{
	long long a,b;
	scanf("%lld%lld",&a,&b);
	for(long long i=a;i<=b;i++)
	if(ngto(i)==1) printf("%lld\n",i);
}

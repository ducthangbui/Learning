#include<stdio.h>
#include<math.h>

int kiemtranguyento(int n)
{
	int ktra=0,i;
	if(n<2) return 0;
	for(i=2;i<=sqrt(n);i++)
	if(n%i==0) ktra++;
	if(ktra==0) return 1;
	else return 0;
}
int kiemtra(int n)
{
	int s=0,m;
	while(n!=0)
	{
		m=n%10;
		n=n/10;
		s=s+m;
	}
	if (kiemtranguyento(s)==1) return 1;
	else return 0;
}
/********Bai1**************/
int Fibo(int n)
{
	if (n==1||n==2) return 1;
	else return (Fibo(n-1)+Fibo(n-2));
}
/********Bai2*************/
int ThuanNghich(int n)
{
	int tmp=n,m = 0;
	while(n!=0)
	{
		m= m * 10 + n%10;
		n=n/10;
	}
	if(m==tmp) return 1;
	else return 0;
}
////////////////////////////////////
void Fibo1(int a[],int n)
{
	int i;
	a[0]=0,a[1]=1;
	for(i=2;i<n;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
}

void Xuat(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%3d ",a[i]);
}
//////////////////////////////////////

void TichNgto(int n)
{
	int i=2;
	while(i<=sqrt(n))
	{
		while(n%i==0)
		{
			if(n==i) printf("%d",i);
			else printf("%d*",i);
			n=n/i;
		}
		i++;
	}
	if(n>1) printf("%d",n);
}
///////////////////////////////////////////
int TongChuSo(int n)
{
	int s=0,m;
	while(n!=0)
	{
		m=n%10;
		n=n/10;
		s=s+m;
	}
	return s;
}
void Chuyen16(int n)
{
	int i=0,a[1000],m,j;
	while(n!=0)
	{
		a[i]=n%16;
		n=n/16;
		i++;
	}
	for(j=i-1;j>=0;j--)
	{
	switch(a[j])
	{
		case 10: printf("A");break;
		case 11: printf("B");break;
		case 12: printf("C");break;
		case 13: printf("D");break;
		case 14: printf("E");break;
		case 15: printf("F");break;
		default: printf("%d",a[j]);
	}
	}
}
/////////////////////////////////////////////
void uocngto(int n)
{
	int i,j;
	int dem=0,m=0,a[100],ktra=0;
	for(i=1;i<=n;i++)
	{
		if(n%i==0) a[m]=i,m++,printf("%3d",i),dem++;
	//printf("%d ",songto(c));
	}
	
	printf("\nSo uoc la:%d\n",dem);
	printf("Cac uoc so la so ngto la:");
	for(j=1;j<m;j++)
	{
		int k=2;
		while(k<a[j])
		{
		if(a[j]%k==0) ktra++;
		k++;
		}
		if(ktra==0) printf("%d ",a[j]);
	}
}
/////////////////////////////////////////

void innguyento(int n)
{
	int dem=0,i=2;
	printf("\n%d so nguyen to dau la:",n);
	while(dem<n)
	{
		if(kiemtranguyento(i)==1) dem++,
		printf("%d ",i);
		i++;
	}
	//printf("\n%d ",i);
}
///////////////////////////////////////
int kiemtratang(int n)
{
	int a[100],i=0;
	while (n!=0)
	{
		a[i]=n%10;
		n=n/10;
		i++;
	}
    int j,dem=0;
    for(j=0;j<i-1;j++)
    {
                 if(a[j]>=a[j+1])
                 dem++;
    }
                    if(dem==(i-1))
                    return 1;
                    return 0;
}


/////////////////////////////////
int baso1(int n)
{
	//int a[100],i=0;
	int m,ktra=0;
	while(n!=0)
	{
		m=n%10;
		n=n/10;
		if(m==1) ktra++;
	}
	if(ktra==3) return 1;
	else return 0;
}
////////////////////////////////////
int TongChiaHetCho10(int n)
{
	int s=0,m;
	while(n!=0)
	{
		m=n%10;
		n=n/10;
		s=s+m;
	}
	if(s%10==0) return 1;
	else return 0;
}
int kiemtra068(int n)
{
	int ktra=0,m;
	while(n!=0)
	{
		m=n%10;
		n=n/10;
		if(m!=0||m!=6||m!=8) ktra++;
	}
	if(ktra==0) return 1;
	else return 0;
}
////////////////////////////
int Chuso(int n)
{
	int m,i=0,ktra=0;
	while(n!=0)
	{
		m=n%10;
		n=n/10;
		i++;
		if(kiemtranguyento(m)==1) ktra++;
	}
	if(ktra==i) return 1;
	else return 0;
}
int Dao(int n)
{
	int tmp=n,m=0;
	while(n!=0)
	{
		m=m*10+n%10;
		n=n/10;
	}
	if(kiemtranguyento(m)==1) return 1;
	return 0;
}
/////////////Bai13/////////////////////
float giaithua(int n)
{
	if(n==0||n==1) return 1;
	else return n*giaithua(n-1);
}
float tong(int n,float x)
{
	int i;
	float s=0;
	for(i=0;i<=n;i++)
	s=s+(pow(x,i)/giaithua(i));
	return s;
}
float emu(float x,float c)
{
	int n=0;
	while(fabs((pow(x,n)/giaithua(n)))>c)
	{
		n++;
	}
	//printf("%f",n);
	return tong(n,x);
	//printf("e^%.f=%f",x,tong(n,x));
}
float amu(float a,float x,float c)
{
	return emu(x*log(a),c);
}
////////////////Bai14//////////////
int Tohop(int k,int n)
{
	int c=giaithua(n)/(giaithua(n-k)*giaithua(k));
	return c;
}
void Pascal(int n)
{
	int i=1,j;
	while(i<=n)
	{
		for(j=0;j<=i;j++)
		printf("%3d ",Tohop(j,i));
		printf("\n");
		i++;
	}
}

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

void FailureFunction(char P[],int F[],int m)
{
	int i,j;
	F[0]=0;
	j=0;
	i=1;
	while(i < m)//Lap khi i dnag nho hon do dai cua mau
	{
		if(P[i] == P[j])
		{
			F[i]=j+1;
			i++;
			j++;
		}
		else if(j > 0) j=F[j-1];
		else {
			F[i]=0;
			j++;
		}
	}
}

int KMP(char T[],char P[])
{
	int i,j,F[100];//,au P khong qua 100 ky tu
	int m=strlen(P);
	int n=strlen(T);
	FailureFunction(P,F,m);
	i=0;
	j=0;
	while(i < n)
	{
		if(T[i] == P[j])
		{
			if(j == m-1) return i-j;//vi tri tim thay la i-j;
			else {
				i++;
				j++;
			}
		}
		else if(j > 0)
		{
			j=F[j-1];
		}
			else i++;
	}
	return -1;//tra ve -1 neu khong khop
}

main()
{
	char T[10000],P[10000];
	cout<<"Nhap doan van ban:";
	gets(T);
	cout<<"Nhap mau can tim kiem:";
	gets(P);
	if(KMP(T,P) != -1) cout<<"Tim thay mau tai vi tri "<<KMP(T,P);
	else cout<<"Mau vau nhap khong khop voi doan van ban:";
}

#include<iostream>
#include<string.h>
using namespace std;
int max(int a[],int n)
{
	int max=a[0];
	for(int i=1;i<n;i++)
	if(a[i]>max) max=a[i];
	return max;
}
void ViTriMax(int a[],int n)
{
	for(int i=0;i<n;i++)
	if(max(a,n)==a[i]) cout<<"Max Index :"<<i<<endl;
}
int Program(char *s)
{
	int MaxLength=0,MaxIndex=0;
	int a[strlen(s)];
	for(int i=0;i<=strlen(s);i++)
	{
		MaxLength++;
		//MaxIndex++;
		if(s[i]==' '||s[i]=='\0')
		{
			a[MaxIndex++]=MaxLength-1;
			MaxLength=0;
		}
	}
	int result=max(a,MaxIndex);
	ViTriMax(a,MaxIndex);
	return result;
}
main()
{
	char s[30];
	cin.getline(s,30);
	//char s[]="Em nguoc duong nguoc nang de yeu anh";
	cout<<Program(s);
	
}

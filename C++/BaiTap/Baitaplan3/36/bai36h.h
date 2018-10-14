#ifndef BAI36H_H
#define BAI36H_H
#include <iostream>
#include <string.h>
using namespace std;
/*
 * No description
 */
class Bai36h
{
	// private section
	public:
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
		void Nhap(){
			cin.ignore();			
			cout<<"Nhap chuoi:";
			cin.getline(s,30);
		}
		void Xuat(){
			cout<<endl
			<<Bai36h::Program(s)<<endl;
		}	
	protected:
		char s[30];
		int a[100],n;
};

#endif // BAI36H_H


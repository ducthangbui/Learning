/*Dao Chuoi*/

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

void Reverse(char str[],int index,int size)
{
	char tmp = str[index];
	str[index] = str[size-index];
	str[size-index]=tmp;
	if(index==size/2) return;
	else Reverse(str,index+1,size);
}
main()
{
	char str[100];
	cout<<"Nhap chuoi:";
	gets(str);
	int size = strlen(str);
	Reverse(str,0,size-1);
	cout<<"Ket qua la:";
	for(int i=0;i<strlen(str);i++)
	cout<<str[i];
	
}

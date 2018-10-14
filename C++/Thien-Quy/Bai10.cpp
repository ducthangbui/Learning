#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<cstdlib>
using namespace std;
int setdau(char *s){
	if (s[strlen(s)-1]=='-'){
		s[strlen(s)-1]='\0';
		return -1;
	}
	return 1;
}
void nhap(char *s1, int *d1, char *s2, int *d2){
	cout<<"Nhap vao hai so nguyen: \n";
	gets(s1);
	strrev(s1);
	gets(s2);
	strrev(s2);
	*d1=setdau(s1);
	*d2=setdau(s2);
}
void doi(char *s1, char *s2){
	char *s;
	strcpy(s,s1);
	strcpy(s1,s2);
	strcpy(s2,s);
}

int sosanh(char *s1, char *s2){
	int kt;
	strrev(s1);
	strrev(s2);
	if (strcmp(s1, s2)<0) kt = -1;
	else if (strcmp(s1, s2)==0) kt = 0;
	else kt = 1;
	strrev(s1);
	strrev(s2);
	return kt;
}

void hieu_tunhien(char *s1, char *s2, char *s3){
	//Ap dung cho s1>s2
	int i=0, tmp=0, s;
	s3[i]=0;
	while(s1[i]!='\0'){
		if (s2[i]>'9' || s2[i]<'0') s=0;
		else s=s2[i]-'0';
		tmp+=(s1[i]-'0')-s;
		if (tmp<0) {
			s3[i]=10+tmp+'0';
			tmp=-1;
		}
		else{
			s3[i]=tmp+'0';
			tmp=0;
		}
		i++;
	}
	if (tmp!=0) {
		s3[i]=10-tmp;
		s3[i+1]=0;
	}
	else s3[i]=tmp;
}

void tong_tunhien(char *s1, char *s2, char *s3){
	int i=0, tmp=0, s;
	s3[i]=0;
	while(s1[i]!='\0'){
		if (s2[i]>'9' || s2[i]<'0') s=0;
		else s=s2[i]-'0';
		tmp+=(s1[i]-'0')+s;
		if (tmp>9) {
			s3[i]=tmp%10+'0';
			tmp=1;
		}
		else{
			s3[i]=tmp+'0';
			tmp=0;
		}
		i++;
	}
	if (tmp>0) {
		s3[i]=tmp+'0';
		s3[i+1]=0;
	}
	else s3[i]=tmp;
}

void tong(char *s1, int d1, char *s2, int d2, char *s3, int *d3){
	if (d1==d2){
		*d3=d1;
		tong_tunhien(s1,s2,s3);
	}
	else{
		if(sosanh(s1,s2)>=0){
			*d3=d1;
			hieu_tunhien(s1,s2,s3);
		}
		else{
			*d3=d2;
			hieu_tunhien(s2,s1,s3);
		}
	}
}

void hieu(char *s1, int d1, char *s2, int d2, char *s3, int *d3){
	tong(s1,d1,s2,0-d2,s3,d3);
}

void inso(char *s, int d){
	char tmp[100];
	strcpy(tmp,s);
	while(tmp[strlen(tmp)-1]=='0') tmp[strlen(tmp)-1]=0;
	if (strlen(tmp)==0) tmp[0]='0';
	if (d<0){
		if (tmp[0]!='0' || strlen(s)!=1) {
			tmp[strlen(s)]='-';
			tmp[strlen(s)+1]='\0';
		}
	}
	strrev(tmp);
	puts(tmp);
}

void tich_1cs(char *s1, int cs, char *s2){
	int n=strlen(s1), i, tmp=1, nho=0;
	for (i=0; i<n; i++){
		tmp=(s1[i]-'0')*cs+nho;
		if(tmp>9){
			s2[i]=tmp%10+'0';
			nho=tmp/10;
		}
		else{
			s2[i]=tmp+'0';
			nho=0;
		}
	}
	if (nho>0) {
		s2[i]=nho+'0';
		s2[i+1]=0;
	}
	else s2[i]=0;
}

void tich(char *s1, int d1, char *s2, int d2, char *s3, int *d3){
	int i=0, j, n=strlen(s2), ntmp;
	char atmp[100], atmp2[100];
	s3[0]='0';
	s3[1]=0;
	if(d1==d2) *d3=1;
	else *d3=-1;
	for (i=0; i<n; i++){
		tich_1cs(s1,s2[i]-'0',atmp);
		strrev(atmp);
		for (j=0; j<i; j++){
			ntmp=strlen(atmp);
			atmp[ntmp]='0';
			atmp[ntmp+1]=0;
		}
		strrev(atmp);
		strcpy(atmp2,s3);
		tong_tunhien(atmp, atmp2, s3);
	}
}

main(){
	char s1[100], s2[100], s3[100];
	int d1, d2, d3;
	nhap(s1,&d1,s2,&d2);
	tong(s1,d1,s2,d2,s3,&d3);
	cout<<"\nTong=";
	inso(s3,d3);
	hieu(s1,d1,s2,d2,s3,&d3);
	cout<<"\nHieu=";
	inso(s3,d3);
	if (strlen(s1)+strlen(s2)>99){
		cout<<"Ngoai pham vi tinh toan";
		return 0;
	}
	tich(s1,d1,s2,d2,s3,&d3);
	cout<<"\nTich=";
	inso(s3,d3);
}

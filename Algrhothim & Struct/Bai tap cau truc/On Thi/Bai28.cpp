#include<iostream>
#define MAX 50
using namespace std;
int n, x[MAX];
void nhapmang(int &n,int x[MAX]){
	cout<<"\n nhap vao so phan tu cua mang:"<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"\n nhap vao gia tri cua phan tu thu "<<i<<" : "<<endl;
		cin>>x[i];
	}
}
//selection sort
void swap(int *p,int *q){
	int temp=*p;
	*p=*q;
	*q=temp;
}
void selectionsort(int n,int x[MAX]){
	int min;
	for(int i=0;i<n-1;i++){
		min=i;//gan cho phan tu dau tien cua mang gia tri nho nhat
		for(int j=i+1;j<n;j++)
			if(x[j]<x[min])
				min=j;
		swap(&x[min],&x[i]);
	}
}
//bubble sort
void bubblesort(int n,int x[MAX]){
	for(int i=0;i<n-1;i++){//duyet tu dau den phan tu cuoi cung
		for(int j=0;j<n-i-1;j++){//duyet tu dau den phan tu ngay truoc phan tu cuoi cung, moi lan thuc hien cac thao tac nay co nghia la giam thieu do dai mang duoc sap xep
			if(x[j]>x[j+1])
				swap(&x[j],&x[j+1]);
		}
	}
}
//insersort
void insertsort(int n,int x[MAX]){
	int key;
	for(int i=1;i<n;i++){
		key=x[i];//gan key la phan tu dung ngay sau phan tu dau tien
		int j=i-1;
		while(j>=0&&x[j]>key){
			x[j+1]=x[j];
			j=j-1;
		}
		x[j+1]=key;
	}
}
//quicksort
int partition(int x[MAX],int high,int low){
	int pivot=x[high];
	int i=low-1;
	for(int j=low;j<=high-1;j++){
		if(x[j]<=pivot){
			i++;
			swap(&x[i],&x[j]);
		}
	}
	swap(&x[i+1],&x[high]);
	return i+1;
}
void quicksort(int x[MAX],int high,int low){
	if(low<high){
		int pi=partition(x,high,low);
		quicksort(x,pi-1,low);
		quicksort(x,high,pi+1);
	}
}
//mergesort
void merge(int x[MAX],int l,int m,int r){
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	int L[n1],R[n2];
	for(i=0;i<n1;i++)
		L[i]=x[l+i];
	for(j=0;j<n2;j++)
		R[j]=x[m+1+j];
	i=0;//khoi tao chi so ban dau cua mang con dau tien
	j=0;//khoi tao chi so ban dau cua mang con thu hai
	k=l;//chi so ban dau cua mang con sap nhap
	while(i<n1&&j<n2){
		if(L[i]<=R[j]){
			x[k]=L[i];
			i++;
		}
		else{
			x[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		x[k]=L[i];
		i++;
		k++;
	}
	while(j<n2){
		x[k]=R[j];
		j++;
		k++;
	}
}
void mergesort(int x[MAX],int l,int r){
	if(l<r){
		int m=l+(r-l)/2;
		mergesort(x,l,m);
		mergesort(x,m+1,r);
		merge(x,l,m,r);
	}
}
//sellsort
int sellsort(int n,int x[MAX]){
	//khoi dau bang viec su dung bien p co gia tri n/2, sau do ta se giam dan gia tri cua bien nay
	for(int p=n/2;p>0;p=p/2){
		for(int i=p;i<n;i++){
			int temp=x[i];
			int j;
			for(j=i;j>=p&&x[j-p]>temp;j=j-p)
				x[j]=x[j-p];
			x[j]=temp;
		}
	}
	return 0;
}
//radixsort
int getmax(int n,int x[MAX]){
	int mx=x[0];
	for(int i=1;i<n;i++)
		if(x[i]>mx)
			mx=x[i];
	return mx;
}
void countsort(int n,int x[MAX],int exp){
	int output[n];//mang ra
	int i,count[10]={0};
	for(i=0;i<n;i++)
		count[(x[i]/exp)%10]++;
	for(i=1;i<10;i++)
		count[i]+=count[i-1];
	//xay dung mang ra
	for(i=n-1;i>=0;i--){
		output[count[(x[i]/exp)%10]-1]=x[i];
		count[(x[i]/exp)%10]--;
	}
	for(i=0;i<n;i++)
		x[i]=output[i];
}
void radixsort(int n,int x[MAX]){
	int m=getmax(n,x);
	for(int exp=1;m/exp>0;exp*=10)
		countsort(n,x,exp);
}
//shakersort
void shakersort(int n,int x[MAX]){
	for(int i=0;i<n/2;i++){
		bool swapped=false;
		for(int j=i;j<n-i-1;j++){
			if(x[j]<x[j+1]){
				int tmp=x[j];
				x[j]=x[j+1];
				x[j+1]=tmp;
				swapped=true;
			}
		}
		for(int j=n-2-i;j>i;j--){
			if(x[j]>x[j-1]){
				int tmp=x[j];
				x[j]=x[j-1];
				x[j-1]=tmp;
				swapped=true;
			}
		}
		if(!swapped) break;
	}
}
void xuatmang(int n,int x[MAX]){
	cout<<"\n ket qua cua ban:"<<endl;
	for(int i=0;i<n;i++){
		cout<<x[i]<<"  ";
	}
}
int main(){
	int select;
	do{
		system("cls");
		cout<<"\n\t\a**************XIN CHAO MUNG DEN VOI NUOC NGA VI DAI**************\t"<<endl;
		cout<<"\n 1. nhap vao mang can theo yeu cau"<<endl;
		cout<<"\n 2. hien thi mang"<<endl;
		cout<<"\n 3. thuat toan selection sort"<<endl;
		cout<<"\n 4. thuat toan bubble sort"<<endl;
		cout<<"\n 5. thuat toan insertsort"<<endl;
		cout<<"\n 6. thuat toan quicksort"<<endl;
		cout<<"\n 7. thuat toan mergesort"<<endl;
		cout<<"\n 8. thuat toan sellsort"<<endl;
		cout<<"\n 9. thuat toan radixsort"<<endl;
		cout<<"\n 10. thuat toan shakersort"<<endl;
		cout<<"\n 0. thoat ra khoi chuong trinh"<<endl;
		cout<<"\n lua chon cua ban:"<<endl;
		cin>>select;
		switch(select){
			case 1:{
				system("cls");
				nhapmang(n,x);
				system("pause");
				break;
			}
			case 2:{
				system("cls");
				xuatmang(n,x);
				system("pause");
				break;
			}
			case 3:{
				system("cls");
				selectionsort(n,x);
				xuatmang(n,x);
				system("pause");
				break;
			}
			case 4:{
				system("cls");
				bubblesort(n,x);
				xuatmang(n,x);
				system("pause");
				break;
			}
			case 5:{
				system("cls");
				insertsort(n,x);
				xuatmang(n,x);
				system("pause");
				break;
			}
			case 6:{
				system("cls");
				quicksort(x,n-1,0);
				xuatmang(n,x);
				system("pause");
				break;
			}
			case 7:{
				system("cls");
				mergesort(x,0,n-1);
				xuatmang(n,x);
				system("pause");
				break;
			}
			case 8:{
				system("cls");
				sellsort(n,x);
				xuatmang(n,x);
				system("pause");
				break;
			}
			case 9:{
				system("cls");
				radixsort(n,x);
				xuatmang(n,x);
				system("pause");
				break;
			}
			case 10:{
				system("cls");
				shakersort(n,x);
				xuatmang(n,x);
				system("pause");
				break;
			}
			default:cout<<"\n chien thang la cua chung ta, day la Ngay Chien thang"<<endl;
		}
	}while(select!=0);
	system("pause");
	return 0;
}
//copyright by PHAN ANH LE

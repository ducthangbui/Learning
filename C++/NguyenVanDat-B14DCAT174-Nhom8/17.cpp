#include<iostream>
#include<windows.h>
#define MAX 50
using namespace std;

void input(int a[], unsigned int &n){
	system("cls");
	n=MAX;
	cout<<"Nhap so phan tu cua mang: (<"<<n<<"): ";
	cin>>n;
	while (n>MAX||n<0){
		cout<<"Nhap lai: ";
		cin>>n;
	}
	for (int i=0; i<n; i++){
		cout<<"A["<<i<<"] = ";
		cin>>a[i];
	}
}

void output(int a[], unsigned int n){
	cout<<"Mang A: "<<endl;
	for (int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	system("pause");
}

void findMax(int a[], unsigned int n){
	cout<<"-------------Find Max----------"<<endl;
	int max1=-1, max2=-1, i1=-1, i2=-1;
	for (int i=0; i<n; i++){
		if (a[i]>max1) {
			max1=a[i];
			i1=i;
		}
	}
	for (int i=0; i<n; i++){
		if (a[i]>max2&&a[i]<max1){
			max2=a[i];
			i2=i;
		}
	}
	cout<<"So lon nhat la: ";
	if (i1!=-1) {
		cout<<max1<<" vi tri: "<<i1<<endl;
	} else cout<<"Khong tim thay"<<endl;
	cout<<"So lon thu hai la: ";
	if (i2!=-1) {
		cout<<max2<<" vi tri: "<<i2<<endl;
	} else cout<<"Khong tim thay"<<endl;
	system("pause");	
}

void sortA(int a[], unsigned int n){
	for (int i=0; i<n; i++){
		for (int j=0; j<n-i-1; j++){
			if (a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
}

void insertA(int a[], unsigned int &n, unsigned int x){
	int i=0;
	for (i=0; i<n; i++){
		if (a[i]>x) break;
	}
	n++;
	for (int j=n-1; j>i; j--){
		a[j]=a[j-1];
	}
	a[i]=x;
}

void display(int a[], unsigned int n){
	int chon;
	input(a,n);
	do{
		system("cls");
		cout<<"------------MAIN MENU----------"<<endl;
		cout<<"1. Tim Max1, Max2"<<endl;
		cout<<"2. Sap xep mang"<<endl;
		cout<<"3. Chen phan tu"<<endl;
		cout<<"4. Nhap lai mang"<<endl;
		cout<<"0. Ket thuc"<<endl;
		cout<<"-------------------------------"<<endl;
		cin>>chon;
		switch(chon){
			case 1:{
				findMax(a, n);
				break;
			}
			case 2:{
				sortA(a, n);
				output(a, n);
				break;
			}
			case 3:{
				int x;
				cout<<"Nhap vao x= ";
				cin>>x;
				insertA(a, n, x);
				output(a, n);
				break;
			}
			case 4:{
				input(a,n);
				break;
			}
		}
	} while (chon!=0);
}

int main(){
	int A[MAX], n;
	display(A, n);
	return 0;
}

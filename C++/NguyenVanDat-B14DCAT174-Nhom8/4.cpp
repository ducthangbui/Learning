#include<iostream>
#include<math.h>
using namespace std;

void input(int a[]){
	cout<<"Nhap vao 5 so nguyen: ";
	for (int i=0; i<5; i++){
		cin>>a[i];
	}
}
void min_max(int a[], int &mi, int &ma){
	mi=a[0];
	ma=a[0];
	for (int i=1; i<5; i++){
		if (a[i]>ma){
			ma=a[i];
		}
		if (a[i]<mi){
			mi=a[i];
		}
	}
}
void display(int a[]){
	int min, max;
	min_max(a,min,max);
	cout<<"So lon nhat la: "<<max<<endl;
	cout<<"So nho nhat la: "<<min<<endl;
}
main(){
	int a[5];
	input(a);
	display(a);
	return 0;
}

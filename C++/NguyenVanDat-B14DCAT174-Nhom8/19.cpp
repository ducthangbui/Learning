#include<iostream>
#include<string>
#include<windows.h>
#define MAX 10
using namespace std;
void input(float a[MAX][MAX], int &n){
	cout<<"Nhap kich thuoc ma tran vuong: ";
	cin>>n;
	while (n<0||n>MAX){
		cout<<"Nhap lai: ";
		cin>>n;
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cout<<"A["<<i+1<<"]["<<j+1<<"]=";
			cin>>a[i][j];
		}
	}
}

void output(float a[MAX][MAX], int n){
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cout<<a[i][j]<<"	";
		}
		cout<<endl;
	}
}

void find_max(float a[MAX][MAX], int n, int option){ //option=1 or 2 {row, col}
	cout<<"----------- TIM ";
	if (option==1) cout<<"HANG";
	else if (option==2) cout<<"COT";
	cout<<" LON NHAT --------"<<endl;
	float sum[MAX], max, vt;
	for (int i=0; i<n; i++){
		sum[i]=0;
		for (int j=0; j<n; j++){
			if (option == 1){
				sum[i]+=a[i][j];
			}
			else
			if (option == 2){
				sum[i]+=a[j][i];
			}
		}
	}
	max=sum[0];
	vt=0;
	for (int i=1; i<n; i++){
		if (sum[i]>max){
			max=sum[i];
			vt=i;
		}
	}
	if (option == 1){
		cout<<"Hang co tong phan tu lon nhat la hang "<<vt+1<<endl;
		cout<<"Tong = "<<max<<endl;
	}
	else if (option == 2){
		cout<<"Cot co tong phan tu lon nhat la cot "<<vt+1<<endl;
		cout<<"Tong = "<<max<<endl;
	}
}

void trans_matrix(float a[MAX][MAX], int n, float b[MAX][MAX]){
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			b[j][i]=a[i][j];
		}
	}
}

void display(){
	int choose=1, n=MAX;
	float A[MAX][MAX];
	input(A,n);
	do{
		system("cls");
		cout<<"--------------------------------------"<<endl;
		cout<<"1. Tim hang co tong lon nhat"<<endl;
		cout<<"2. Tim cot co tong lon nhat"<<endl;
		cout<<"3. Tim ma tran chuyen vi"<<endl;
		cout<<"4. Tim dinh thuc"<<endl;
		cout<<"5. Tim ma tran nghich dao"<<endl;
		cout<<"6. Nhap lai ma tran"<<endl;
		cout<<"0. Ket thuc"<<endl;
		cout<<"--------------------------------------"<<endl;
		cin>>choose;
		cin.clear();
		cin.ignore();
		switch(choose){
			case 1:{
				find_max(A,n,1);
				break;
			}
			case 2:{
				find_max(A,n,2);
				break;
			}
			case 3:{
				float B[MAX][MAX];
				cout<<"---------- MA TRAN CHUYEN VI ---------"<<endl;
				trans_matrix(A,n,B);
				output(B,n);
				break;
			}
			case 4:{
				cout<<"Chua hoan thanh..."<<endl;
				break;
			}
			case 5:{
				cout<<"--------- MA TRAN NGHICH DAO ---------"<<endl;
				cout<<"Chua hoan thanh..."<<endl;
				break;
			}
			case 6:{
				input(A,n);
				break;
			}
		}
		system("pause");
	} while (choose!=0);
}

int main(){
	display();
	return 0;
}

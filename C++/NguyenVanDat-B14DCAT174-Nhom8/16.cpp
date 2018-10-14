#include<iostream>
#include<math.h>
#include<windows.h>
using namespace std;
void input(float dt[], unsigned int &n){
	cout<<"Nhap vao bac cua da thuc (<=20): ";
	cin>>n;
	while (n<0||n>20){
		cout<<"Nhap lai: ";
		cin>>n;
	}
	cout<<"Nhap vao cac he so cua da thuc (bat dau tu bac 0): "<<endl;
	for (int i=0; i<=n; i++){
		cin>>dt[i];
	}
}

float gtHorner(float dt[], unsigned int n){
	float x, gt=dt[n];
	int i=n;
	cout<<"Nhap vao gia tri cua x= ";
	cin>>x;
	while(i!=0){
		i--;
		gt*=x+dt[i];
	};
	return gt;
}

void d(float dt1[], unsigned int n1, float dt2[], unsigned int &n2){
	n2=n1-1;
	for (int i=0; i<=n2; i++){
		dt2[i]=dt1[i+1]*(i+1);
	}
}

void add(float dt1[], unsigned int n1, float dt2[], unsigned int n2, float dt3[], unsigned int &n3){
	n3=n2>n1?n2:n1;
	for (int i=0; i<=n3; i++){
		dt3[i]=dt1[i]+dt2[i];
	}
}

void output(float dt[], unsigned int n){
	for (int i=n; i>=0; i--){
		cout<<dt[i];
		if (i!=0){
			cout<<"x";
			if (i>1) cout<<"^"<<i;
			cout<<" + ";
		}
	}
}

void display(){
	unsigned int np=0, nq=0, nr=0, chon;
	float P[20], Q[20], R[20];
	cout<<"----------------"<<endl;
	cout<<"Nhap da thuc P:"<<endl;
	input(P,np);
	do{
		system("cls");
		cout<<"----------------"<<endl;
		cout<<"1. Tinh gia tri P theo cong thuc Horner"<<endl;
		cout<<"2. Tinh dao ham cua P"<<endl;
		cout<<"3. Tinh tong P + Q"<<endl;
		cout<<"4. Nhap lai P"<<endl;
		cout<<"0. Ket thuc"<<endl;
		cin>>chon;
		switch(chon){
			case 1: {
				cout<<"----------------"<<endl;
				cout<<"P= ";
				cout<<gtHorner(P,np);
				cout<<endl;
				system("pause");
				break;
			}
			case 2: {
				cout<<"----------------"<<endl;
				cout<<"Dao ham bac 1 cua P: "<<endl;
				d(P,np, R, nr);
				output(R,nr);
				cout<<endl;
				system("pause");
				break;
			}
			case 3: {
				cout<<"----------------"<<endl;
				cout<<"Nhap vao them da thuc Q:"<<endl;
				input(Q,nq);
				add(P,np,Q,nq,R,nr);
				output(R,nr);
				cout<<endl;
				system("pause");
				break;
			}
			case 4: {
				cout<<"----------------"<<endl;
				cout<<"Nhap da thuc P:"<<endl;
				input(P,np);
				break;
			}
		}
	} while (chon!=0);
}

int main(){
	display();
	return 0;
}

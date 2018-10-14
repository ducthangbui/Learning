#include<iostream>
#include<math.h>
#include<windows.h>
using namespace std;
void input(int &m, int &n){
	cout<<"Nhap 2 so m, n: ";
	cin>>m>>n;
	if (m>n){
		swap(m,n);
	}
}

int isSquareNumber(int n){
	return (sqrt(n)==(int)sqrt(n));
}
void display(){
	int chon=1, m, n, count=0;;
	do{
		system("cls");
		cout<<"----------------"<<endl;
		input(m,n);
		cout<<"Cac so chinh phuong trong doan ["<<m<<","<<n<<"]:"<<endl;
		for (int i=m; i<=n; i++){
			if (isSquareNumber(i)) {
				cout<<i<<" ";
				count++;
			}
		}
		cout<<endl;
		cout<<"Co "<<count<<" so chinh phuong trong doan ["<<m<<","<<n<<"]"<<endl;
		cout<<"----------------"<<endl;
		cout<<"1.Tiep tuc		0. Ket thuc"<<endl;
		cin>>chon;
	} while (chon!=0);
}

int main(){
	display();
	return 0;
}

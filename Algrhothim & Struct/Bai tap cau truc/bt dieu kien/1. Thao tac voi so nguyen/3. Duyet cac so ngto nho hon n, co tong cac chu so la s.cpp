#include "d:\lap trinh\c++\function.cpp"
/*
	De bai: duyet cac so nguyen to nho hon n, co tong cac chu so la s
	Thuat toan: 
		
		Thuc hien vong lap toi khi khong thoa man dieu kien (A)
		Buoc 1: kiem tra 1 co phai so nguyen to va co tong = S
				Yes -> 	Thuc hien hanh dong (*)
				Thuc hien buoc 1+1
		Buoc i: kiem tra i co phai so nguyen to va co tong = S 
				Yes -> 	Thuc hien hanh dong (*)
				Thuc hien buoc i+1
		 
	 	Chu' thich':
	 		(A): vi de bai yeu cau ta tim cac so < n 
	 				-> chi can loop : 1 -> n-1
			
			(*): In ra gia' tri. cua? so' do'
					.... 
*/
main()
{
	int n,s;
	cout<<"Nhap n=";cin>>n;
	cout<<"Nhap s=";cin>>s;
	for(int i=1;i<n;i++)
		if(ngto(i)&&tong_cacso(i)==s)
			cout<<i<<endl;
}
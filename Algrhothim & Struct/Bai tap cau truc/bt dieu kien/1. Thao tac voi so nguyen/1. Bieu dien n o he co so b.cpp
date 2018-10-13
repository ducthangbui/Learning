#include "d:\lap trinh\c++\function.cpp"
/*
	De bai: chuyen N tu he 10 sang he B
	Thuat toan: 
		
		Buoc 1: chia du N cho B 
				luu ket qua vao mang a
		Buoc 2: neu N khac 0 thi quay lai buoc 1
				nguoc lai: doc nguoc mang a -> ket qua
				
		Chu' y': B > 9	thi mang a se co cac so > 10 (11,12,14.. ma khong phai la B,C,E...)
		
					neu' ko xu ly'
						vi'du.: so' 13 =>  a={13} trong he. 16 => ket qua : 13
					neu' xu ly'
						vi'du.: so' 13 =>  a={13} trong he. 16 => ket qua : D
		
		Xu ly: o? day t dung 1 mang ki tu
			char x[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		
		vi. tri' [0] ='0' => in ra ki tu 0
		...
		vi. tri' [13] ='D' => in ra ki tu D
*/
main()
{
	int n,b;//1<b<=36
	char x[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cout<<"Nhap n=";cin>>n;
	cout<<"Nhap b=";cin>>b;
	stack <int> a;
	while(n)
	{
		a.push(n%b);
		n/=b;
	}
	while(!a.empty())
	{
		cout<<x[a.top()];
		a.pop();
	}
}
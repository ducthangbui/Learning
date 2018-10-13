#include "d:\lap trinh\c++\function.cpp"
/*
	De bai: phan tich n thanh thua so nguyen to
	Thuat toan: 
		
		Thuc hien vong lap toi khi khong thoa man dieu kien (A)
		Buoc 1: kiem tra 1 co phai so nguyen to 
				Yes -> 	Thuc hien hanh dong (*)
				Thuc hien buoc 1+1
		Buoc i: kiem tra i co phai so nguyen to 
				Yes -> 	Thuc hien hanh dong (*)
				Thuc hien buoc i+1
		 
	 	Chu' thich':
	 		(A): de phan tich n thanh thua so nguyen to( vi du. so nguyen to i ) 
	 				thi n lon hon hoac bang i
			
			(*): neu' i la so nguyen to ta tien' hanh hut' tat' ca cac so nguyen to i ra khoi n
					vi du n=2*2*2*3*3*4
					
					i=2: - vi n chia het cho 2
						=> hut lan 1: n=n/2 		luc nay n=2*2*3*3*4
						
						 - vi n chia het cho 2
						=> hut lan 2: n=n/2	 		luc nay n=2*3*3*4
						
						- vi n chia het cho 2 		
						=> hut lan 3: n=n/2			luc nay n=3*3*4
					.... 
*/
main()
{
	int n;
	cout<<"Nhap n=";cin>>n;
	for(int i=2;i<=n;i++)
	{
		while(ngto(i)&&n%i==0)
		{
			cout<<i<<"*";
			n/=i;
		}
	}
	cout<<'\b';
}
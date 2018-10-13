#include "D:\lap trinh\c++\function.cpp"

vector <float> a[MAX];
int n;
void Init()
{
	mo_fDoc("gauss.txt");
	fi>>n;
	float r;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			fi>>r;
			a[i].push_back(r);
		}
}
void xuat_mt()
{
	for(int i=0;i<n;i++,cout<<endl)
	for(int j=0;j<n;j++)	
		cout<<setw(7)<<setprecision(3)<<a[i].at(j)<<' ';
	cout<<"\n\n\n";
}
void Lamtron(float &a)
{
	if(a<0.001) a=0;
}
void khuGauss(vector <float> a[],int n,int vt=0)
{
	float max=fabs(a[vt].at(vt));
	if(vt==n-1) return ; // ket thuc qua trinh khu
	int dem=0;
	if(a[vt].at(vt)==0) dem++;
	for(int i=vt+1;i<n;i++)// tim tru toi dai
	{
		if(a[i].at(vt)==0) dem++;
		if(fabs(a[i].at(vt))>max)	a[i].swap(a[vt]);
	}
	if(dem==n-vt) {cout<<"Suy bien\n";return ;} // suy bien
	
	for(int i=vt+1;i<n;i++)// xoa bo X(i);
		for(int j=n-1;j>=0;j--)
		{
			a[i].at(j)-=a[vt].at(j)*a[i].at(vt)/a[vt].at(vt);
			Lamtron(a[i].at(j));
		}
	khuGauss(a,n,vt+1);
}
main()
{
	Init();
	khuGauss(a,n);
	cout<<"Ket qua sau khi khu gauss !\n\n";
	xuat_mt();
	int dt=0;
	for(int i=0;i<n;i++)
	{
		 dt*=a[i].at(i);
	}
	cout<<"Dinh thuc mt = "<<dt<<endl;
}

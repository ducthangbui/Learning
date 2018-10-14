#ifndef BAI36G2_H
#define BAI36G2_H

/*
 * No description
 */
class Bai36g2
{
	// private section
	public:
		void Nhap(int &n,int a[]);
		void Max(int &n,int a[]);
		void Xuat(int n,int a[]);
		void Swap(int &a,int &b)
			{
				int tmp=a;
				a=b;
				b=tmp;
			}
		void Sort(int n,int a[])
		{
			for(int i=0;i<n;i++)
			for(int j=n-1;j>i;j--)
			if(a[i]<a[j]) Swap(a[i],a[j]);
		}
		void Insert(int &n,int &x,int a[]);
		
	protected:
		int n,a[100],x;
};

#endif // BAI36G2_H


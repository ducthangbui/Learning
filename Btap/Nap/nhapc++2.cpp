#include<iostream>
using namespace std;
int main()
{
	int a[100],i;
	cout<<"nhap day"<<endl;
	  for(i=0;i<5;i++)
		{
			cout<<"Nhap a["<<i<<"]:";
	    	cin>>a[i];
	    }
	    int max=a[0], min=a[0];
	for(i=0;i<5;i++)
	{
	  if(a[i]<min) 
     	  {
	        min=a[i]; 
		  }  
	  if(a[i]>max)
	      {
	      	max=a[i];
	      }    	
    }
    cout<<"so be nhat la:"<<min<<endl;
    cout<<"so lon nhat la:"<<max;
}

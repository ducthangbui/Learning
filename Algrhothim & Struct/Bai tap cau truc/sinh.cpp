void Init_NB_(int *x,int &n,int &OK)
{
	cout<<"Nhap n= ";cin>>n;
	for(int i=1;i<=n;x[i]=0,i++);
	OK=1;
}
void next_bit(int *x,int n,int &OK)
{
	int i=n;
	while(i>0&&x[i]==1) x[i--]=0;
	if(i==0) 	OK=0;
	else 		x[i]=1;
}
void Xuat(int *x,int n)
{
	for(int i=1;i<=n;i++) cout<<x[i]<<' ';
	cout<<endl;
}


void Init_NC_(int *x,int &n,int &k,int &OK)
{
	do
	{
	cout<<"Nhap n= ";cin>>n;
	cout<<"Nhap k= ";cin>>k;
	if(k>n) cout<<"Nhap sai roi ! \n";
	}while(k>n);
	for(int i=1;i<=k;x[i]=i,i++);
	OK=1;
}

void next_com(int *x,int n,int k,int &OK)
{
	int i=k;
	while(x[i]==n-k+i) i--;
	if(i>0)
	{
		x[i]++;
		for(int j=i+1;j<=n;j++)
			x[j]=x[i]+j-i;
	}
	else OK=0;
}
void Init_ND_(int *x,int &n,int &k,int &OK)
{
	cout<<"Nhap n= ";cin>>n;
	k=OK=1;
	x[1]=n;
}
void next_div(int *x,int &k,int &OK)
{
	int i=k;
	while(i>0&&x[i]==1) i--;
	if(i>0) 
	{
		x[i]--;
		int d=k-i+1;
		int r=d/x[i];
		int s=d%x[i];
		k=i;
		if(r>0)
		{
			for(int j=i+1;j<=i+r;j++)
				x[j]=x[i];
			k+=r;
		}
		if(s>0)
		{
			k++;x[k]=s;
		}
	}
	else OK=0;
}
void Init_NP_(int *x,int &n,int &OK)
{
	cout<<"Nhap n= ";cin>>n;
	for(int i=1;i<=n;x[i]=i,i++);
	OK=1;
}
void next_per(int *x,int n,int &OK)
{
	int i=n-1;
	while(i>0&&x[i]>x[i+1]) i--;
	if(i==0) OK=0;
	else
	{
		int j=n;
		while(x[j]<x[i]) j--;
		int r=x[i];x[i]=x[j];x[j]=r;
		int a=i+1,b=n;
		while(a<b)
		{
			r=x[a];x[a]=x[b];x[b]=r;
			a++;b--;
		}
	}
}

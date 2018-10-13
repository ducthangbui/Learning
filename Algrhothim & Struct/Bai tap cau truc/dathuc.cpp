struct dathuc
{
	int n;
	float *heso;
	dathuc(int n_=-1,float *heso_=NULL)
	{
		this->n=n_;
		if(n==-1) return;
		while(heso_[n]==0) n--;
		heso=new float[n+1];
		for(int i=0;i<=n;i++)
			heso[i]=heso_[i];
	}
	void nhap()
	{
		cout<<"Nhap so mu lon nhat: ";cin>>n;
		cout<<"Nhap he so !\n";
		heso=new float[n+1];
		for(int i=0;i<=n;i++)
		{
			cout<<"x^"<<i<<" :";cin>>heso[i];
		}
	}
	void xuat()
	{
		if(heso[0]) cout<<heso[0]<<" + ";
		for(int i=1;i<=n;i++)
		{
			if(heso[i]==0) continue;
			cout<<heso[i]<<"*x^"<<i<<" + ";
		}
		cout<<"\b\b";
	}
	dathuc daoham()
	{
		for(int i=0;i<n;i++)
		{
			heso[i]=(i+1)*heso[i+1];
		}
		n--;
	}
	dathuc operator+(dathuc p)
	{
		int maxx;
		if(n<p.n) {maxx=p.n;}
		else maxx=n;
		float *heso_;
		heso_=new float[maxx+1];
		for(int i=0;i<=maxx;i++) 
		{
			heso_[i]=0;
			if(i<=p.n) heso_[i]+=p.heso[i];
			if(i<=n) heso_[i]+= heso[i];
		}
		return dathuc(maxx,heso_);
	}
	dathuc operator-(dathuc p)
	{
		int maxx;
		if(n<p.n) {maxx=p.n;}
		else maxx=n;
		float *heso_;
		heso_=new float[maxx+1];
		for(int i=0;i<=maxx;i++) 
		{
			heso_[i]=0;
			if(i<=p.n) heso_[i]-=p.heso[i];
			if(i<=n) heso_[i]+= heso[i];
		}
		return dathuc(maxx,heso_);
	}
	dathuc operator*(dathuc p)
	{
		float *heso_= new float[n+p.n+1];
		for(int i=0;i<=p.n+n;i++) heso_[i]=0;
		
		for(int i=0;i<=n;i++)
		for(int j=0;j<=p.n;j++)
			heso_[i+j]+=heso[i]*p.heso[j];
			
		return dathuc(p.n+n,heso_);
	}
	dathuc operator/(dathuc p)
	{
		dathuc x=*this;
		dathuc y=p;
		dathuc rx;
		while(x>=y)
		{
			dathuc r=x.hangtuMax().donthuc(y.hangtuMax());
			rx=rx+r;
			r=r*y;
			x=x-r;
		}
		return rx;
	}
	dathuc donthuc(dathuc p)
	{
		dathuc r;
		if(this<&p) return dathuc();
		r.n=n-p.n;
		r.heso=new float[r.n+1];
		r.heso[r.n]=heso[n]/p.heso[p.n];
		for(int i=0;i<r.n;i++) r.heso[i]=0;
		return r;
	}
	void operator=(dathuc a)
	{
		this->n=a.n;
		this->heso=a.heso;
	}
	bool operator>=(dathuc a)
	{
		if(n>=a.n) return 1;
		return 0;
	}	
	dathuc hangtuMax()
	{
		dathuc p;
		p.n=n;
		p.heso=new float[n+1];
		p.heso[n]=this->heso[n];
		for(int i=0;i<n;i++)
			p.heso[i]=0;
		return p;
	}
};

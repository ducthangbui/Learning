bool ngto(int k)
{
	int r=int(sqrt(k));
	if(k<=1) return false;
	for(int i=2;i<=r;i++)
		if(k%i==0) return false;
	return true;
}
int tong_cacso(int k)
{
	int s=0;
	while(k)
	{
		s=s+k%10;
		k/=10;
	}
	return s;
}
int tong_uoc(int k)
{
	int r=k/2,tong=1;
	for(int i=2;i<=r;i++)
		if(k%i==0) tong+=i;
	return tong;
}
bool thuannghich(int k)
{
	int r=k,tn=0;
	while(r)
	{
		tn=tn*10+r%10;
		r/=10;
	}
	if(tn==k) return true;
	return false;
}

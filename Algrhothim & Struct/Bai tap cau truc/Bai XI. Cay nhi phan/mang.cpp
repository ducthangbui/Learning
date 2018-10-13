#include "E:\goc hoc tap\lap trinh\c++\function.cpp"

typedef int tree[MAX];

void Init(tree x)
{
	for(int i=1;i<MAX;i++) x[i]=0; 
}
void Root(tree x,int k)
{
	x[1]=k;
}
int Search(tree x,int k)
{
	int i=1;
	for(int i=1;i<MAX;i++) if(x[i]==k) return i;
	return -1;
}
void Add_left(tree x,int m,int n)
{
	int i=Search(x,m);
	if(i==-1) return;
	if(x[i*2]==0) x[i*2]=n;
}
void Add_right(tree x,int m,int n)
{
	int i=Search(x,m);
	if(i==-1) return;
	if(x[i*2+1]==0) x[i*2+1]=n;
}
void NLR(tree x,int n=1)
{
	if(x[n]) cout<<x[n]<<' ';
	if(x[2*n]) 	NLR(x,2*n);
	if(x[2*n+1])NLR(x,2*n+1);
}
void LNR(tree x,int n=1)
{
	if(x[2*n]) 	LNR(x,2*n);
	if(x[n]) cout<<x[n]<<' ';
	if(x[2*n+1])LNR(x,2*n+1);
}
void LRN(tree x,int n=1)
{
	if(x[2*n]) 	LRN(x,2*n);
	if(x[2*n+1])LRN(x,2*n+1);
	if(x[n]) cout<<x[n]<<' ';
}
main()
{
	tree x;
	Init(x);
	Root(x,1);	
	Add_right(x,1,66);
	Add_right(x,66,65);
	Add_right(x,65,63);
	//cout<<Search(x,65);
	LRN(x);	
}
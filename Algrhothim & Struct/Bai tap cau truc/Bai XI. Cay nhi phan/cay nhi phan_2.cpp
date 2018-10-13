/*
	Cay nhi nhan !
	
	1, khoi tao cay nhi phan
	2, tao nut goc
	3, them mot nut la vao cay
			a, trai
			b, phai
	4, xoa mot nut la trong cay
			a, trai
			b, phai
	5, duyet qua cac nut tren cay nhi phan
	6, tim 1 nut
*/
#include<iostream>
#include<queue>
using namespace std;
typedef struct node 
{
	int info;
	node *right,*left;
	node()
	{
		right=left=NULL;
	}
} *tree;

void Init(tree &x) {x=NULL;}//khoi tao
void Root(tree &x,int k)
{
	x=new node;
	x->info=k;
}
node *Getnode(int x=0)
{
	tree q;
	q=new node ;
	q->info=x;
	return q;
}
int Empty(tree &x)
{
	if(x==NULL) return 1;
	return 0;
}
tree Search(tree &x,int k)
{
	queue <tree> T;
	tree q=x;
	if(x==NULL) return x;
	T.push(q);
	while(!T.empty())
	{
		q=T.front();
		if(q->info==k) return q;
		T.pop();
		if(q->left) 	T.push(q->left);
		if(q->right) 	T.push(q->right);
	}
	return NULL;
}
void Add_left(tree &x,int k,int e)//them 1 nut con trai vao nut k
{
	tree q=Search(x,k);
	if(q==NULL) return; 
	if(q->left==NULL) 
}
main()
{
	tree q;
	Init(q);
	
}
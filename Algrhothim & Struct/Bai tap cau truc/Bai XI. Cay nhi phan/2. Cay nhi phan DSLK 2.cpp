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
	{
		tree p=Getnode(e);
		q->left=p;
	}
}
void Add_right(tree &x,int k,int e)//them 1 nut con phai vao nut k
{
	tree q=Search(x,k);
	if(q==NULL) return; 
	if(q->right==NULL) 
	{
		tree p=Getnode(e);
		q->right=p;
	}
}
void Del_left(tree &x,int k)// tim nut k va xoa con trai
{
	tree q=Search(x,k);
	if(q==NULL) return; 
	if(q->left!=NULL) //kiem tra no co nut con
		if(q->left->right==NULL&&q->left->left==NULL)//kiem tra nut con la nut la'
		{
			tree xx=q->left;
			q->left=NULL;
			delete xx;
		}
}
void Del_right(tree &x,int k)// tim nut k va xoa con phai
{
	tree q=Search(x,k);
	if(q==NULL) return; 
	if(q->right!=NULL) //kiem tra no co nut con
		if(q->right->right==NULL&&q->right->left==NULL)//kiem tra nut con la nut la'
		{
			tree xx=q->right;
			q->right=NULL;
			delete xx;
		}
}
void NLR(tree &x)
{
	if(x)cout<<x->info<<' ';
	if(x->left) NLR(x->left);
	if(x->right) NLR(x->right);
}
void LNR(tree &x)
{
	if(x->left) LNR(x->left);
	if(x)cout<<x->info<<' ';
	if(x->right) LNR(x->right);
}
void LRN(tree &x)
{
	if(x->left) LRN(x->left);
	if(x->right) LRN(x->right);
	if(x)cout<<x->info<<' ';
}
main()
{
	tree q;
	Init(q);
	Root(q,1);
	cout<<Search(q,1)->info;
}
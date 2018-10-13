/*
	Cay nhi nhan !
	
	1, khoi tao cay nhi phan
	2, tao nut goc
	3, them mot nut  vao cay
	4, xoa mot nut  trong cay
	5, duyet qua cac nut tren cay nhi phan
	6, tim 1 nut
*/
#include<iostream>
#include<queue>
#include<conio.h>
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
	tree q=x;
	if(q==NULL) return NULL;
	if(q->info==k) return q;
	if(q->info>k) return Search(x->left,k);
	return Search(q->right,k);
}
void Add(tree &x,int e)//them 1 nut con trai vao nut k
{
	tree q=Search(x,e),xx=Getnode(e),p=x;
	if(q!=NULL) return; // ton tai nut
	if(p==NULL) {x=xx;return;}// cay rong
	while(!(p->right==NULL&&p->info<e)&&!(p->left==NULL&&p->info>e))
		if(p->info>e) p=p->left;
		else p=p->right;
	if(p->right==NULL&&p->info<e) p->right=xx;
	else p->left=xx;	
}
void NLR(tree x)
{
	if(x==NULL) return;
	cout<<x->info<<' ';
	NLR(x->left);
	NLR(x->right);
}
void LNR(tree x)
{
	if(x==NULL) return;
	LNR(x->left);
 	cout<<x->info<<' ';
	LNR(x->right);
}
void LRN(tree x)
{
	if(x==NULL) return;
	LRN(x->left);
	LRN(x->right);
	cout<<x->info<<' ';
}
void Del(tree &x,int k)//xoa nut k trong cay
{
	tree q=x,e=Search(x,k);
	if(q==NULL||e==NULL) return ;
	if(q->left==NULL&&q->right==NULL&&q->info==k) {x=NULL;delete q;return;}// xoa nut goc
	if(q->left==NULL&&q->right!=NULL&&q->info==k) {x=x->right;delete q; return;}// xoa nut goc
	if(q->left!=NULL&&q->right==NULL&&q->info==k) {x=x->left;delete q; return;}// xoa nut goc
	while(q!=NULL&&q->info!=k)
	{	
		e=q;
		if(q->info>k) q=q->left;
		if(q->info<k) q=q->right;
	}
	if(q==NULL) return;//khong ton tai nut
	int lock=1;
	if(q->left==NULL&&q->right!=NULL) 	// nut q co 1 nut con phai
		{
			if(e->right==q) e->right=q->right;
			else e->left=q->right;
		}
	else if(q->left!=NULL&&q->right==NULL) 	// nut q co 1 nut con trai
		if(e->right==q) e->right=q->left;
		else e->left=q->left;
	else if(q->left==NULL&&q->right==NULL) //khong co nut con
		if(e->right==q) e->right=NULL;
		else e->left=NULL;
	else // co ca 2 nut con
	{
		k=0;
		tree xx=q->left,eef=NULL;
		if(xx->right==NULL) 
		{
			int tmp=xx->info;xx->info=q->info;q->info=tmp;
			q->left=NULL;delete xx;
		}
		else 
		{
			while(xx->right!=NULL)//tim max right cua nut trai
			{
				eef=xx;
				xx=xx->right;
			}
			int tmp=xx->info;xx->info=q->info;q->info=tmp;
			eef->right=NULL;
			delete xx;	
		}
	}
	if(k) delete q;
}
main()
{
	tree q;
	Init(q);
	Root(q,2);
	Add(q,1);
	Add(q,4);
	
	Del(q,4);
	Del(q,2);
	NLR(q);

}
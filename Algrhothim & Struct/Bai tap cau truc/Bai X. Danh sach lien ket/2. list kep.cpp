#include<iostream>
using namespace std;
typedef struct node
{
	int info;
	node *left;
	node *right;
	node()
	{
		info=0;
		right=left=NULL;
	}
} *pnode;
struct list
{
	node *head,*tail;
};
void Init(list &l)
{
	l.head=l.tail=NULL;
} 
node *Getnode()
{
	return new node;
}
int Empty(list &l)
{
	if(l.head==NULL) return 1;
	return 0;
}
void Add_Left(list &l,int x)
{
	pnode p;
	p=Getnode();
	p->info=x;
	if(Empty(l)) {l.head=l.tail=p;return;}
	p->right=l.head;
	l.head->left=p;
	l.head=p;
}
void Add_Right(list &l,int x)
{
	pnode p;
	p=Getnode();
	p->info=x;
	if(Empty(l)) {l.head=l.tail=p;return;}
	p->left=l.tail;
	l.tail->right=p;
	l.tail=p;
}

void Add_After(list &l,int x,int y)
{
	pnode q=l.head;
	while(q!=NULL&&q->info!=x) q=q->right;
	if(q==NULL) return ;
	if(q->right==NULL) Add_Right(l,y);
	else 
	{
		pnode p;
		p=Getnode();
		p->info=y;
		p->right=q->right;
		q->right=p;
		p->right->left=p;
		p->left=q;
	}
}
void Del_Right(list &l)
{
	pnode p=l.tail;
	if(p==NULL) return ;
	if(p->left==NULL) l.head=l.tail=NULL;
	else {l.tail=l.tail->left;l.tail->right=NULL;}
	delete p;
}

void Del_Left(list &l)
{
	pnode p=l.head;
	if(p==NULL) return ;
	if(p->right==NULL) l.tail=l.head=NULL;
	else {l.head=l.head->right;l.head->left=NULL;}
}

void Del_After(list &l,int x)
{
	pnode p=l.head;
	while(p!=NULL&&p->info!=x) p=p->right;
	if(p==NULL) return; 
	if(p->right==NULL) return;
	if(p->right->right==NULL) {Del_Right(l);return;}
	
	pnode q=p->right;
	p->right=q->right;
	p->right->left=p;
	delete q;
}

void Print(list &l)
{
	pnode p=l.head;
	while(p!=NULL)
	{
		cout<<p->info<<' ';
		p=p->right;
	}
}

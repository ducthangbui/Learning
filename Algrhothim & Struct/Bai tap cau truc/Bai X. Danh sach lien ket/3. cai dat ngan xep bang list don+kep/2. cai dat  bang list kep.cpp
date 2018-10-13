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
struct stack
{
	node *head,*tail;
};
void Init(stack &l)
{
	l.head=l.tail=NULL;
} 
node *Getnode()
{
	return new node;
}
int Empty(stack &l)
{
	if(l.head==NULL) return 1;
	return 0;
}
void Push(stack &l,int x)
{
	pnode p;
	p=Getnode();
	p->info=x;
	if(Empty(l)) {l.head=l.tail=p;return;}
	p->left=l.tail;
	l.tail->right=p;
	l.tail=p;
}
void Pop(stack &l)
{
	pnode p=l.tail;
	if(p==NULL) return ;
	if(p->left==NULL) l.head=l.tail=NULL;
	else {l.tail=l.tail->left;l.tail->right=NULL;}
	delete p;
}
int retrieve(stack &l)
{
	if(l.tail==NULL) return -1;
	return l.tail->info;
}
void Print(stack &l)
{
	pnode p=l.head;
	while(p!=NULL)
	{
		cout<<p->info<<' ';
		p=p->right;
	}
}
main()
{
	stack a;
	Init(a);

}

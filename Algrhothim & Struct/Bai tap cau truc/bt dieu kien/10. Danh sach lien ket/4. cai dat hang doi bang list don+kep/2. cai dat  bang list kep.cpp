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
struct queue
{
	node *head,*tail;
};
void Init(queue &l)
{
	l.head=l.tail=NULL;
} 
node *Getnode()
{
	return new node;
}
int Empty(queue &l)
{
	if(l.head==NULL) return 1;
	return 0;
}

void Push(queue &l,int x)
{
	pnode p;
	p=Getnode();
	p->info=x;
	if(Empty(l)) {l.head=l.tail=p;return;}
	p->left=l.tail;
	l.tail->right=p;
	l.tail=p;
}
void Pop(queue &l)
{
	pnode p=l.head;
	if(p==NULL) return ;
	if(p->right==NULL) l.tail=l.head=NULL;
	else {l.head=l.head->right;l.head->left=NULL;}
}

int Retrieve(queue &a)
{
	if(a.head==NULL) return -1;
	return a.head->info;
}
void Print(queue &l)
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
	queue a;
	Init(a);
	Push(a,1);
	Push(a,2);
	Push(a,3);
	Pop(a);

	
	cout<<Retrieve(a);
}

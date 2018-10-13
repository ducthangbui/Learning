#include<iostream>
using namespace std;
typedef struct node
{
	int info;
	node *next;
	node()
	{
		info=0;
		next=NULL;
	}
} *stack;
void Init(stack &l)
{
	l=NULL;
} 
node *Getnode()
{
	return new node;
}
int Empty(stack &l)
{
	if(l==NULL) return 1;
	return 0;
}

void Push(stack &l,int x)
{
	stack q;
	q=Getnode();
	q->info=x;
	if(Empty(l)) l=q;
	else 
	{
		stack p=l;
		while(p->next!=NULL) p=p->next;
		p->next=q;
	}
}

int Pop(stack &l)
{
	stack p=l;
	int t;
	if(p==NULL) return -1;
	if(p->next!=NULL)
	{
		while(p->next->next!=NULL)	p=p->next;
		stack q=p->next;
		t=q->info;
		p->next=NULL;
		delete q;
	}
	else {t=p->info;l=NULL;}
	return t;
}
void Print(stack &l)
{
	stack p=l;
	while(p!=NULL)
	{
		cout<<p->info<<' ';
		p=p->next;
	}
}

main()
{
	stack a;
	Init(a);

	char x[100];
	cout<<"Nhap xau x= ";
	fflush(stdin);gets(x);
	for(int i=0;i<strlen(x);i++)
		Push(a,x[i]);
	while(!Empty(a)) cout<<char(Pop(a));
}

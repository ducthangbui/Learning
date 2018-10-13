#include<iostream>
#include<fstream>
using namespace std;
struct word
{
	char value[100];
	int n;
	word()
	{
		strcpy(value,"");
		n=0;
	}
	void Print()
	{
		cout<<value<<'\t'<<n<<endl;
	}
	bool operator==(word b)
	{
		if(!strcmp(value,b.value)) return true;
		return false;
	}
	void operator=(word b)
	{
		strcpy(value,b.value);
		n=b.n;
	}
};
typedef struct node
{
	word info;
	node *next;
	node()
	{
		strcpy(info.value,"");
		info.n=0;
		next=NULL;
	}
} *list;
void Init(list &l)
{
	l=NULL;
} 
node *Getnode()
{
	return new node;
}
int Empty(list &l)
{
	if(l==NULL) return 1;
	return 0;
}
void Add_Left(list &l,word x)
{
	list p;
	p=Getnode();
	p->info=x;
	p->next=l;
	l=p;
}
void Add_Right(list &l,word x)
{
	list q;
	q=Getnode();
	q->info=x;
	if(Empty(l)) l=q;
	else 
	{
		list p=l;
		while(p->next!=NULL) p=p->next;
		p->next=q;
	}
}
void Add_After(list &l,word x,word y)
{
	list q=l;
	while(q!=NULL&&!(q->info==x)) q=q->next;
	if(q==NULL) return ;
	if(q->info==x)
	{
		list p;
		p=Getnode();
		p->info=y;
		p->next=q->next;
		q->next=p;
	}
}
void Del_Right(list &l)
{
	list p=l;
	if(p==NULL) return ;
	if(p->next!=NULL)
	{
		while(p->next->next!=NULL)	p=p->next;
		list q=p->next;
		p->next=NULL;
		delete q;
	}
	else l=NULL;
}
void Del_Left(list &l)
{
	list p=l;
	if(p==NULL) return ;
	l=l->next;
	delete p;
}
void Del_After(list &l,word x)
{
	list p=l;
	while(p!=NULL&&!(p->info==x)) p=p->next;
	if(p==NULL) return; 
	if(p->next==NULL) return;
	list q=p->next;
	p->next=NULL;
	delete q;
}
list Search(list &l,word x)
{
	list p=l;
	while(p!=NULL&&!(p->info==x)) p=p->next;
	return p;
}
void Print(list &l)
{
	list p=l;
	while(p!=NULL)
	{
		p->info.Print();
		p=p->next;
	}
}
//////////////////////////////////////////////// xu ly 
list a;
word x;
ifstream fi;
void Init()
{
	fi.open("tap tu 1.txt");
	list k;
	while(fi)
	{
		fi>>x.value;
		if(!fi) break;
		x.n=1;
		k=Search(a,x);
		if(k==NULL) Add_Right(a,x);
		else k->info.n++;
	}
}

main()
{
	Init();
	Print(a);
}

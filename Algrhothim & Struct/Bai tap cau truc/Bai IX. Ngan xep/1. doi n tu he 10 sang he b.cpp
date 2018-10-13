#include<iostream>
using namespace std;
typedef struct node
{
	int info;
	node *next;
	node()
	{
		info=0;//thong tin cua o nho
		next=NULL;//o tiep theo
	}
} *stack;
//Khoi tao
void Init(stack &l)
{
	l=NULL;//khoi tao rong
} 
node *Getnode()//cap bo nho cho node
{
	return new node;
}
//Kiem tra tinh rong
int Empty(stack &l)
{
	if(l==NULL) return 1;
	return 0;
}
//Dua 1 phan tu vao ngan xep
void Push(stack &l,int x)
{
	stack q;//q mang day du info,next
	q=Getnode();//cap bo nho cho q
	q->info=x;//thong tin q <=x
	if(Empty(l)) l=q;//trong stack ko co gi gan l=q
	else 
	{
		stack p=l;//khong rong thi khai bao p=l
		while(p->next!=NULL) p=p->next;//tao them o nho moi hay ngan xep moi
		p->next=q;//q gan o nho tiep theo
	}
}
//Lay 1 phan tu ra khoi ngan xep
int Pop(stack &l)
{
	stack p=l;//khai bao moi p = l da trong ngan xep
	int t;
	if(p==NULL) return -1;//neu kho co p trong ngan xep =>return thoat
	if(p->next!=NULL)//neu co p trong ngan xep
	{
		while(p->next->next!=NULL)	p=p->next;//p gan ngan xep tiep theo
		stack q=p->next;//khao bao moi q = ngan xep tiep theo o tren
		t=q->info;//t gan lam noi dung cua con tro q
		p->next=NULL;//p tiep theo rong
		delete q;//xoa q
	}
	else {t=p->info;l=NULL;}
	return t;//tra lai t
}
//Xuat ra khoi ngan xep
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
	int n,b;
	char x[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cout<<"Nhap n= ";cin>>n;
	cout<<"Nhap b= ";cin>>b;
	while(n)
	{
		Push(a,n%b);
		n/=b;
	}
	while(!Empty(a)) cout<<x[Pop(a)];
}

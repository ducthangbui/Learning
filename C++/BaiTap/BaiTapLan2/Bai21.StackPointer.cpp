#include<iostream>
using namespace std;
struct Stack
{
	int data;
	Stack *next;
};
Stack *TaoStack(int x)
{
	Stack *StackMoi;
	StackMoi=new Stack;
	StackMoi->data=x;
	StackMoi->next=NULL;
	return StackMoi;
}
void push(Stack *&head,int x)
{
	Stack *StackThem=TaoStack(x);
	if(head==NULL)
	{
		head=StackThem;
		return;
	}
	StackThem->next=head;
	head=StackThem;
}
//Xoa Node dau tien
void pop(Stack *&head,int x)//lay ra x phan tu cua stack
{
	int dem=1;
	while(dem<=x)
	{	
	Stack *p=head;
	if(p==NULL) return;//
	head=head->next;
	delete p;
	dem++;
	}
}
void Xuat(Stack *head)
{
	Stack *p=head;
	while(p!=NULL)
	{
		cout<<p->data<<"\t";
		p=p->next;
	}
}

main()
{
	Stack *head=NULL;
	push(head,1);
	push(head,2);
	push(head,3);
	Xuat(head);
	int x=0;
	cout<<endl<<"Lay ? phan tu cua Stack?";
	cout<<"ban chon:";
	//cin>>x;
	cout<<endl<<"Stack sau khi pop "<<x<<" phan tu la:"<<endl;
	pop(head,x);
	Xuat(head);
}

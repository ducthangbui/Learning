//Danh sach lien ket kep
#include <iostream>

using namespace std;

struct node{
	int data;
	node *prev;
	node *next;
};

node *start = NULL;

node *CreateNode(int value)
{
	node *tmp=new node;
	tmp->data=value;
	tmp->prev=NULL;
	tmp->next=NULL;
	return tmp;
}

void InsertBegin(int value)
{
	node *tmp=CreateNode(value);
	node *p=start;
	if(start == NULL)//neu danh sach chong
	{
		start=tmp;
		start->next=NULL;
		start->prev=NULL;
	}
	else
	{
		tmp->next=p;
		tmp->prev=NULL;
		start=tmp;
	}
}

void InsertLast(int value)
{
	node *tmp=CreateNode(value);
	node *p=start;
	if(start == NULL)
	{
		start=tmp;
		start->next=NULL;
		start->prev=NULL;
	}
	else
	{
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=tmp;
		tmp->prev=p;
		tmp->next=NULL;
	}
}

//Them vao vi tri pos
void InsertPos(int pos,int value)
{
	node *p=start;
	int count=1;
	while(p != NULL)
	{
		p=p->next;
		count++;
	}
	
	if(pos == 1) {
		InsertBegin(value);
		return;
	}
	
	if(pos == count){
		InsertLast(value);
		return;
	}
	
	if(pos > 1 && pos < count)
	{
		node *ptr=start;
		for(int i=1;i<pos-1;i++)
		ptr=ptr->next;
		
		node *ptr2=ptr->next;
		node *tmp=CreateNode(value);
		ptr->next=tmp;
		tmp->prev=ptr;
		tmp->next=ptr2;
		ptr2->prev=tmp;
	}
}

//Tim node co gia tri x
int Search(int x)
{
	node *p=start;
	int count=1;
	while(p != NULL)
	{
		if(p->data == x) return count;
		count++;
		p=p->next;
	}
}

//Sap xep
void Sort()
{
	for(node *i=start;i != NULL;i=i->next)
		for(node *j=i->next;j != NULL;j=j->next)
		{
			if(i->data > j->data)
			{
				int tmp=i->data;
				i->data=j->data;
				j->data=tmp;
			}
		}
}

void DeleteBegin()
{
	node *p=start;
	start=p->next;
	start->prev=NULL;
	delete p;
}

void DeleteLast()
{
	node *p=start;
	while(p->next!=NULL)
	p=p->next;
	
	node *del=p;
	p->prev->next=NULL;
	delete del;
}

void DeletePos(int pos)
{
	int count=1;
	node *p=start;
	while(p->next != NULL)
	{
		p=p->next;
		count++;
	}
	
	if(pos == 1){
		DeleteBegin();
		return;
	}
	
	if(pos == count){
		DeleteLast();
		return;
	}
	
	if(pos > 1 && pos < count)
	{
		node *ptr=start;
		for(int i=1;i<pos;i++)
		ptr=ptr->next;
		
		node *del=ptr;
		ptr->prev->next=ptr->next;
		ptr->next->prev=ptr->prev;
		delete del;
	}
}

void Display()
{
	node *p=start;
	while(p!=NULL)
	{
		cout<<p->data<<"->";
		p=p->next;
	}
	cout<<"NULL";
}

//Dao nguoc cac node
void Reverse()
{
	node *ptr1,*ptr2,*ptr3;
	if(start == NULL)
	{
		cout<<"Danh sach rong"<<endl;
		return;
	}
	
	ptr1=start;
	ptr2=ptr1->next;
	ptr3=ptr2->next;
	ptr1->next=NULL;//ngat lien kt ptr1
	ptr2->next=ptr1;//node ptr2 bay gio dung truoc node ptr1
	while(ptr3 != NULL)//Lap neu ptr3 != rong
	{
		ptr1=ptr2;//ptr1 lai bat dua tai vi tri ptr2
		ptr2=ptr3;//ptr2 lai bat dau tai vi tri ptr3
		ptr3=ptr3->next;//ptr3 tro den node ke tiep
		ptr2->next=ptr1;//Thiet lap lien ket cho ptr2
	}
	start=ptr2;//node dau tien bay gio la node ptr2
}
int main()
{
	for(int i=1;i<=4;i++)
	InsertLast(i);
	Display();
	
	int pos,value;
	cout<<endl<<"Nhap vi tri can them:";
	cin>>pos;
	cout<<endl<<"Nhap gia tri can them:";
	cin>>value;
	InsertPos(pos,value);
	cout<<"Day sau khi them:";
	Display();
	
	cout<<endl<<"Day sau khi da sap xep:";
	Sort();
	Display();
		
	int posDel;
	cout<<endl<<"Nhap vi tri can xoa:";
	cin>>posDel;
	DeletePos(posDel);
	cout<<endl<<"Dau sau khi xoa la:";
	Display();
	
	cout<<endl<<"Day sau khi dao nguoc la:";
	Reverse();
	Display();
	
	int x;
	cout<<endl<<"Nhap gia tri can tim:";
	cin>>x;
	if(Search(x) == 0) cout<<endl<<"Khong tim thay"<<endl;
	else cout<<endl<<"Tim thay "<<x<<" tai vi tri "<<Search(x)<<endl;
	return 0;
}

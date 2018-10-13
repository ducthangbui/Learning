#include <iostream>

using namespace std;

struct node{
	int data;
	node *next;
};

node *start=NULL;

//Tao node
node *CreateNode(int value)
{
	node *tmp=new node;
	tmp->data=value;
	tmp->next=NULL;
	return tmp;
}

//Chen cuoi
void InsertLast(int value)
{
	node *tmp=CreateNode(value);
	node *p=start;
	if(start == NULL)//Neu danh sach rong
	{
		start=tmp;//Node dau tien la tmp
		start->next=NULL;
	}
	else//Neu danh sach khong rong
	{
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=tmp;
		tmp->next=NULL;
	}
}

//Chen dau
void InsertBegin(int value)
{
	node *tmp=CreateNode(value);
	node *p=start;
	if(start == NULL)
	{
		start = tmp;
		start->next=NULL;
	}
	else
	{
		tmp->next=p;
		start=tmp;
	}
}

//Chen vi tri bat ky
void InsertPos(int value,int pos)
{
	int count=1;//Dem so node
	node *tmp=CreateNode(value);
	node *p=start;
	while(p->next!=NULL)
	{
		count++;
		p=p->next;
	}

	if(pos == 1)//Neu pos == count tuc la chen vao cuoi danh sach
	{
		InsertBegin(value);
	}

	else if(pos <= count && pos > 1)
	{
		node *ptr=start;
		for(int i=1;i<pos-1;i++)
		{
			ptr=ptr->next;
		}
		tmp->next=ptr->next;
		ptr->next=tmp;
	}
	else
		cout<<endl<<"Vi tri can chen vuot qua tam kiem soat"<<endl;
}

//Xoa node dau tien
void DeleteBegin()
{
	node *ptr=start;
	start=ptr->next;
	delete ptr;
}

//Xoa node cuoi cung
void DeleteLast()
{
	node *p=start;
	while(p->next->next!=NULL)
	{
		p=p->next;
	}
	node *del=p->next;
	p->next=NULL;
	delete del;
}

//Xoa tai vi tri bat ky
void DeleteNode(int pos)
{
	int count=1;
	node *p=start;
	while(p->next!=NULL)
	{
		count++;
		p=p->next;
	}

	if(pos == 1)
	{
		node *ptr=start;
		start=ptr->next;
		delete ptr;
	}
	else if(pos <= count && pos > 1)
	{
		node *ptr=start;
		for(int i=1;i<pos-1;i++)
		ptr=ptr->next;
		node *del=ptr->next;
		ptr->next=del->next;
		delete del;
	}
	else cout<<"Qua tam kiem soat"<<endl;
}

//Sap xep
void Sort()
{
	node *p,*q;
	for(p=start;p!=NULL;p=p->next)
		for(q=p->next;q!=NULL;q=q->next)
		if(p->data > q->data)
		{
			int temp=p->data;
			p->data = q->data;
			q->data = temp;
		}
}

//Tim 
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

void Display()//Hien thi
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
	InsertBegin(i);
	
	Display();
	
	int pos;
	cout<<endl<<"Nhap vi tri can chen:";
	cin>>pos;
	int value;
	cout<<"Nhap gia tri can chen:";
	cin>>value;
	InsertPos(value,pos);
	
	Display();
	
	int delPos;
	cout<<endl<<"Nhap vi tri can xoa:";
	cin>>delPos;
	DeleteNode(delPos);
	
	Display();
	
	cout<<endl<<"Danh sach sau khi sap xep:"<<endl;
	Sort();
	Display();
	
	cout<<endl<<"Danh sach sau khi dao:"<<endl;
	Reverse();
	Display();
	
	int x;
	cout<<endl<<"Nhap gia tri can tim:";
	cin>>x;
	if(Search(x) == 0) cout<<"Khong tim thay"<<endl;
	else
	cout<<"Tim thay "<<x<<" tai vi tri "<<Search(x);
	return 0;
}

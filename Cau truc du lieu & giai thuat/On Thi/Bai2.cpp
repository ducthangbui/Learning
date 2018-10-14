#include <iostream>

using namespace std;

struct node{
	int data;
	node *next;
};

node *last=NULL;

node *CreateNode(int value)
{
	node *tmp=new node;
	tmp->data=value;
	tmp->next=tmp;
	return tmp;
}

void InsertBegin(int value)
{
	node *tmp=CreateNode(value);
	if(last == NULL)
	{
		last=tmp;
		last->next=last;
	}
	else
	{
		tmp->next=last->next;
		last->next=tmp;
	}
}

void InsertLast(int value)
{
	node *tmp=CreateNode(value);
	if(last == NULL)
	{
		last=tmp;
		last->next=last;
	}
	else
	{
		tmp->next=last->next;
		last->next=tmp;
		last=tmp;
	}
}

void InsertPos(int value,int pos)
{
	node *p=last->next;
	for(int i=1;i<pos-1;i++)
	{
		p=p->next;
		if(p == last->next)
		{
			cout<<"So node trong danh sach < vi tri "<<pos<<endl;
			return;
		}
	}
	node *tmp=CreateNode(value);
	tmp->next=p->next;
	p->next=tmp;
	if(p == last) last=tmp;
}

void DeletePos(int pos)
{
	int count=1;
	node *p=last->next;
	while(p != last)
	{
		count++;
		p=p->next;
	}
	
	if(pos == 1)
	{
		node *ptr=last->next;
		last->next=ptr->next;
		delete ptr;
		return;
	}
	
	if(pos == count)
	{
		node *s=last->next;
		for(int i=1;i<pos-1;i++)
		s=s->next;
		node *ptr=s->next;
		s->next=last->next;
		delete ptr;
		last=s;
		return;
	}
	
	if(pos > 1 && pos < count)
	{
		node *ptr=last;
		for(int i=1;i<=pos-1;i++)
		ptr=ptr->next;
		node *del=ptr->next;
		ptr->next=del->next;
		delete del;
		return;
	}
	
}

//Tim node co khoa x
int Search(int x)
{
	node *p=last->next;
	int count=1;
	while(p != last)
	{
	
		if(p->data == x)
		{
			return count;
		}
		p=p->next;
		count++;
	}
	if(p->data == x)
		return count;
		else return -1;
}

//Sap xep
void Sort()
{
	for(node *i=last->next;i != last;i=i->next)
		for(node *j=i->next; j != last->next; j=j->next)
		{
			if(i->data > j->data)
			{
				int tmp=i->data;
				i->data=j->data;
				j->data=tmp;
			}
		}
}
void Display()
{
	node *p=last->next;
	while(p != last)
	{
		cout<<p->data<<"->";
		p=p->next;
	}
	cout<<p->data<<" ";
}

//Dao nguoc cac node
void Reverse()
{
	node *ptr1,*ptr2,*ptr3;
	node *tmp=last->next;
	ptr1=last->next;
	ptr2=ptr1->next;
	ptr3=ptr2->next;
	ptr1->next=last;//ngat lien kt ptr1
	ptr2->next=ptr1;//node ptr2 bay gio dung truoc node ptr1
	last=ptr1;
	while(ptr3 != last)//Lap neu ptr3 != rong
	{
		ptr1=ptr2;//ptr1 lai bat dua tai vi tri ptr2
		ptr2=ptr3;//ptr2 lai bat dau tai vi tri ptr3
		ptr3=ptr3->next;//ptr3 tro den node ke tiep
		cout<<endl<<"ptr3=ptr3->next:"<<ptr3->data;
		ptr2->next=ptr1;//Thiet lap lien ket cho ptr2
	}
	last->next=ptr2;//node dau tien bay gio la node ptr2
}
main()
{
	for(int i=1;i<=10;i++)
	InsertLast(i);
	Display();
	
	cout<<endl;
	DeletePos(2);
	Display();
	
	Reverse();
	cout<<endl<<"Chuoi sau khi dao nguoc:";
	Display();
	
	Sort();
	cout<<endl<<"Day sau khi da sap xep:";
	Display();
	
	cout<<endl<<"Nhap gia tri can tim:";
	int x;
	cin>>x;
	if(Search(x) == -1) cout<<endl<<"Khong tim thay"<<endl;
	else cout<<endl<<"Tim thay "<<x<<" tai vi tri "<<Search(x);
}

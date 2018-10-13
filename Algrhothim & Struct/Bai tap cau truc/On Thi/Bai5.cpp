#include <iostream>

using namespace std;

struct node{
	int data;
	node *next;
	node *prev;
};

node *start=NULL;
node *last=NULL;

node *CreateNode(int value)
{
	node *tmp=new node;
	tmp->data=value;
	tmp->next=NULL;
	tmp->prev=NULL;
	return tmp;
}

void InsertBegin(int value)
{
	node *tmp=CreateNode(value);
	if(start == NULL && last == NULL)
	{
		start=last=tmp;
		start->next=last->next=NULL;
		start->prev=last->prev=NULL;
	}
	else
	{
		tmp->next=start;
		start->prev=tmp;
		start=tmp;
		start->prev=last;
		last->next=start;
	}
}

void InsertLast(int value)
{
	node *tmp=CreateNode(value);
	if(start == NULL && last == NULL)
	{
		start=last=tmp;
		start->next=last->next=NULL;
		start->prev=last->prev=NULL;
	}
	else
	{
		last->next=tmp;
		tmp->prev=last;
		last=tmp;
		last->next=start;
		start->prev=last;
	}
}

void InsertPos(int pos,int value)
{
	int count=1;
	node *p=start;
	while(p != last)
	{
		count++;
		p=p->next;
	}
//	cout<<endl<<"Count:"<<count<<endl;
	if(pos == 1) InsertBegin(value);
//	else if(pos == count) InsertLast(value);
	else if(pos > 1 && pos <= count)
	{
		node *ptr=start;
		node *tmp=CreateNode(value);
		for(int i=1;i<pos;i++)
		{
		//	cout<<endl<<"ptr->data:"<<ptr->data<<" ";
			ptr=ptr->next;
		}
		node *ptr2=ptr;
	//	cout<<endl<<"ptr2->data:"<<ptr2->prev->data<<endl;
		ptr->prev->next=tmp;
		tmp->next=ptr2;
		tmp->prev=ptr2->prev;
		ptr2->prev=tmp;
	}
}

void DeleteBegin()
{
		node *ptr=start;
		last->next=ptr->next;
		ptr->next->prev=last;
		start=ptr->next;
		delete ptr;
		return;
}

void DelteLast()
{
		node *ptr=last;
	//	cout<<endl<<"ptr->prev->data:"<<last->data<<endl;;
		ptr->prev->next=start;
		start->prev=ptr->prev;
		last=ptr->prev;
		delete ptr;
		return;
}
void DeletePos(int pos)
{
	int count=1;
	node *p=start;
	while(p!=last)
	{
		count++;
		p=p->next;
	}
	
	if(pos == 1)
	{
		node *ptr=start;
		last->next=ptr->next;
		ptr->next->prev=last;
		start=ptr->next;
		delete ptr;
		return;
	}
	
	if(pos == count)
	{
		node *ptr=last;
	//	cout<<endl<<"ptr->prev->data:"<<last->data<<endl;;
		ptr->prev->next=start;
		start->prev=ptr->prev;
		last=ptr->prev;
		delete ptr;
		return;	
	}
	
	if(pos > 1 && pos < count)
	{
		node *ptr=start;
		for(int i=1;i<pos;i++)
		ptr=ptr->next;
		node *del=ptr;
		del->prev->next=del->next;
		del->next->prev=del->prev;
		delete del;
		return;
	}
}

//Tim kiem node co gia tri x
int Search(int x)
{
	node *p=start;
	int count=1;
	bool flag;
	while(p != last)
	{
		if(p->data == x){
			flag=true;
			return count;
		}
		count++;
		p=p->next;
	}
	if(p->data == x){
		flag=true;
		return count;
	}
	if(flag == false) return -1; 
}

//Sap xep
void Sort()
{
	node *p=start;
	for(node *i=start; i != last; i=i->next)
		for(node *j=last;j != i;j=j->prev)
		{
			if(i->data > j->data)
			{
				int tmp=i->data;
				i->data=j->data;
				j->data=tmp;
			}
		}
}

//Dao nguoc cac node
void Reverse()
{
	node *ptr1,*ptr2,*ptr3;
	
	ptr1=start;
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
		ptr2->next=ptr1;//Thiet lap lien ket cho ptr2
	}
	start=ptr2;//node dau tien bay gio la node ptr2
}
void Display()
{
	node *p=start;
	while(p != last)
	{
		cout<<p->data<<"->";
		p=p->next;
	}
	cout<<p->data;
}

main()
{
	for(int i=1;i<=5;i++)
	InsertLast(i);
	Display();
	
	int pos,value;
	cout<<endl<<"Nhap vi tri can them:";
	cin>>pos;
	cout<<endl<<"Nhap gia tri can them:";
	cin>>value;
	InsertPos(pos,value);
	Display();
	
	int posDel;
	cout<<endl<<"Nhap vi tri can xoa:";
	cin>>posDel;
	DeletePos(posDel);
	Display();
	
	cout<<endl<<"Day sau khi sap xep la:";
	Sort();
	Display();
		
	int x;
	cout<<endl<<"Nhap so can tim:";
	cin>>x;
	if(Search(x) == -1) cout<<endl<<"Khong tim thay"<<endl;
	else cout<<"Tim thay "<<x<<" tai vi tri "<<Search(x)<<endl;
	
	cout<<endl<<"Day sau khi dao nguoc la:";
	Reverse();
	Display();
}

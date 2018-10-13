/*
	Cai dat supList 
	
	Chuc nang:
	
	// them 
	.push_back(int value)		//them vao cuoi danh sach(ds)
	.push_front(int value)		//them vao dau ds

	//xoa
	.pop_front()				//xoa phan tu dau ds
	.pop_back()					//xoa phan tu cuoi ds

	
	// thao tac
	.back()						//xem phan tu cuoi		
	.front()					//xem phan tu dau
	.at(int pos)				//xem phan tu thong qua chi so
	.swap()						//doi cho 2 phan tu
	.sort()						//sap xep list theo chieu tang dan
	.remove(value)				//xoa phan tu
	.empty()					//kiem tra rong
	.size()						//return kich thuoc list
	.reverse()					//dao nguoc list
*/
#include<iostream>
#include<list>
#include<fstream>
using namespace std;
struct node
{
	int 	value;
	node 	*left,*right;
	
	node();
	bool operator==(node p)
	{
		if(value==p.value) return true;
		return false;
	}
	bool operator>(node p)
	{
		if(value>p.value) return true;
		return false;
	}
	
};
struct supList
{
	private:
	node 	*head,*tail;
	int 	count;
	node 	*getnode();
	
	public:
	supList();
	//them phan tu
	void 	push_back(int value_);		//them vao cuoi danh sach(ds)
	void 	push_front(int value_);		//them vao dau ds

	
	//xoa phan tu
	void 	pop_front();				//xoa phan tu dau ds
	void 	pop_back();					//xoa phan tu cuoi ds

	
	// thao tac
	int 	back();						//xem phan tu cuoi		
	int 	front();					//xem phan tu dau
	int 	at(int pos);				//xem phan tu thong qua chi so
	void 	swap(int i,int j);			//doi cho 2 phan tu
	void 	sort();						//sap xep list theo chieu tang dan
	void 	remove(int value_);			//xoa phan tu co gia tri = value
	bool 	empty();					//kiem tra rong
	int 	size();						//return kich thuoc list
	void 	reverse();					//dao nguoc list
	
	//tai dinh nghia toan tu
	node  *operator[] (int k)				// truy xuat gia tri qua chi so vi tri
	{
		if(k>this->size()-1) return getnode();
		node *p;
		p=this->getnode();
		p=this->head;
		for(int i=1;i<=k;i++)
		{
			p=p->right;
		}
		return p;
	}
};



/************************* Function Of node ******************/
node::node()
{
	left=right=NULL;
}
node *supList::getnode()
{
	return (new node);
}

/************************* Function Of supList ******************/
supList::supList()
{
	head=tail=NULL;
	count=0;
}
//them phan tu
void supList::push_back(int value_)
{
	node *p;
	p=getnode();
	p->value=value_;
	if(this->empty())
		head=tail=p;
	else
	{
		p->left=tail;
		tail->right=p;
		tail=p;
	}
	this->count++;
}
void supList::push_front(int value_)
{
	node *p;
	p=new node;
	p->value=value_;
	if(this->empty())
		head=tail=p;
	else
	{
		p->right=head;
		head->left=p;
		head=p;
	}
	this->count++;
}


	//xoa phan tu
void 	supList::pop_front()				//xoa phan tu dau ds
{
	if(!this->empty())
	{
		node *q;
		q=this->head;
		head=head->right;
		delete q;
		this->count--;
	}
}
void 	supList::pop_back()					//xoa phan tu cuoi ds
{
	if(!this->empty())
	{
		node *q;
		q=this->tail;
		tail=tail->left;
		delete q;
		this->count--;
	}
}




	// thao tac
int supList::size()
{
	return this->count;
}
int supList::back()
{
	if(!this->empty()) return this->tail->value;
	else return 0;
}
int supList::front()
{
	if(!this->empty()) 
		return this->head->value;
	else return 0;
}
int 	supList::at(int pos)				//xem phan tu thong qua chi so
{
	return (*this->operator[](pos)).value;
}
void 	supList::swap(int i,int j)		//doi cho 2 phan tu
{
	if(i>count-1||j>count-1) return;
	int k;
	k=(*this->operator[](i)).value;
	(*this->operator[](i)).value=(*this->operator[](j)).value;
	(*this->operator[](j)).value=k;
}
void 	supList::sort()						//sap xep list theo chieu tang dan
{
	for(int i=0;i<count-1;i++)		//sap xep noi b
	for(int j=i+1;j<count;j++)
	{
		if((*this->operator[](i))>(*this->operator[](j)))
			this->swap(i,j);
	}
}

void 	supList::remove(int value_)		//xoa phan tu theo gia tri
{
	for(int i=0;i<count;i++)
		if((*this->operator[](i)).value==value_) 
		{
			if(i<0||i>=count) return;
			node *p;
			p=this->operator[](i);
			p->right->left=p->left;
			p->left->right=p->right;
			delete p;
			count--;
		}
}

void 	supList::reverse()					//dao nguoc list
{
	int i=(count-1)/2;
	while(i--)
	{
		swap(i,count-1-i);
	}
	
}
bool supList::empty()
{
	if(this->count==0) return true;
	return false;
}

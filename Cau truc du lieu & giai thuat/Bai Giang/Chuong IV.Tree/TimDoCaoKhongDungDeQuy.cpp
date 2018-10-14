#include <iostream>

using namespace std;

//Khai bao Node
struct node{
	int data;
	node *next;	
};

//Stack
template <class S>
class Stack{
	private:
		node *head;
	public:
		node *CreateNode(int value);
		void Push(int value);
		void Pop();
		int Top();
		Stack();
		void Display();
		bool Empty();
		int Size();
};

template <class S>
Stack<S>::Stack()
{
	this->head=NULL;
}

template <class S>
node *Stack<S>::CreateNode(int value)
{
	node *tmp=new node;
	tmp->data=value;
	tmp->next=NULL;
	return tmp;
}

template <class S>
void Stack<S>::Push(int value)
{
	node *tmp=CreateNode(value);
	node *p=head;
	if(head == NULL)
	{
		head=tmp;
		head->next=NULL;
	}
	else
	{
		tmp->next=p;
		head=tmp;
	}
}

template <class S>
int Stack<S>::Top()
{
	node *p=head;
	if(head == NULL)
	{
		cout<<"Stack rong"<<endl;
		return 0;
	}
	else{
		int kq=p->data;
		return kq;
	}
}

template <class S>
void Stack<S>::Pop()
{
	node *p=head;
	head=p->next;
	delete p;
}
template <class S>
bool Stack<S>::Empty()
{
	if(head == NULL)
	return true;
	return false;
}
template <class S>
int Stack<S>::Size()
{
	node *tmp=head;
	int count=0;
	while(tmp != NULL)
	{
		count++;
		tmp=tmp->next;
	}
	return count;
}

/////////////
struct nodeTree {
	int data;
	nodeTree *left,*right;
};

//node *tree=NULL;

//Tao node
nodeTree *CreateNode(int value)
{
	nodeTree *newNode = new nodeTree;
	newNode->data=value;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}

//Duyet cay co 3 cach
//Duyet cay theo thu tu truoc
//

void NodeLeftRight(nodeTree *T)
{
	if(T!=NULL)
	{
		cout<<T->data<<" ";//in node goc
		NodeLeftRight(T->left);//duyet theo thu tu giua sang nhanh cay con ben trai
		NodeLeftRight(T->right);//duyet theo thu tu giau sang nhanh cay con ben phai
	}
}

//Them node vao cay nhi phan tim kiem
void AddNode(nodeTree *T,int value)
{
		nodeTree *p,*q;
		p=q=T;
		while(p->data != value && q != NULL)
		{
			p=q;
			if(value < p->data) q=p->left;
			else q=p->right;
		}
		if(p->data == value) return;
		nodeTree *newNode=CreateNode(value);
		if(value < p->data) p->left=newNode;
			else p->right=newNode;
}

////////////////
int maTran[100][100],n;
bool chuaxet[100];

void KhoiTao()
{
	for(int i=1;i<=n;i++)
	chuaxet[i]=true;
}

void DFS2(int u)
{
	
	int maxSize=1;
	Stack <int> t;
	for(int i=1;i<=19;i++)
	chuaxet[i]=true;
	t.Push(u);
	int size=t.Size();
	//cout<<"Tham dinh "<<u<<endl;
	chuaxet[u]=false;
	while(!t.Empty())
	{
		int h=t.Top();
		t.Pop();
		//cout<<"Tham dinh "<<h<<endl;
		for(int i=1;i<=19;i++)
		if(chuaxet[i] /*&& maTran[h][i]*/ )
		{
			
			//cout<<"Tham dinh "<<i<<endl;
			t.Push(i);
			if(t.Size() > maxSize) maxSize=t.Size();
			chuaxet[i]=false;
			break;
		}
	}
	if(t.Empty()) cout<<"Do cao:"<<maxSize<<endl;
}

main()
{
	nodeTree *T=CreateNode(40);
	AddNode(T,30);
	AddNode(T,60);
	AddNode(T,25);
	AddNode(T,35);
	AddNode(T,50);
	AddNode(T,70);
	AddNode(T,20);
	AddNode(T,28);
	AddNode(T,32);
	AddNode(T,38);
	AddNode(T,65);
	AddNode(T,90);
	AddNode(T,15);
	AddNode(T,22);
	AddNode(T,26);
	AddNode(T,29);
	AddNode(T,62);
	AddNode(T,68);
	NodeLeftRight(T);
	DFS2(1);
}

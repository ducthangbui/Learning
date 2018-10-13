#include <iostream>


using namespace std;

struct node{
	int data;
	node *next;	
};
template <class T>
class Queue{
	private:
		node *head;
	public:
		node *CreateNode(int value);
		void Push(int value);
		void Pop();
		int Top();
		Queue();
	//	~Stack();
		void Display();
		bool Empty();
};

template <class T>
Queue<T>::Queue()
{
	this->head=NULL;
}
/*template <class T>
Queue<T>::~Queue()
{
	node *p;
	while(p!=NULL)
	{
		p=head;
		head=head->next;
		delete p;
	}
}
*/
template <class T>
node *Queue<T>::CreateNode(int value)
{
	node *tmp=new node;
	tmp->data=value;
	tmp->next=NULL;
	return tmp;
}

template <class T>
void Queue<T>::Push(int value)
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
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=tmp;
		tmp->next=NULL;
	}
}

template <class T>
int Queue<T>::Top()
{
	node *p=head;
	if(head == NULL)
	{
		cout<<"Queue rong"<<endl;
		return 0;
	}
	else{
		int kq=p->data;
		return kq;
	}
}

template <class T>
void Queue<T>::Pop()
{
	node *p=head;
	head=p->next;
	delete p;
}
template <class T>
bool Queue<T>::Empty()
{
	if(head == NULL)
	return true;
	return false;
}

template <class T>
void Queue<T>::Display()
{
	node *p=head;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
}

int main()
{
	//node *head=NULL;
	Queue <int> T1,T2;
	for(int i=1;i<=4;i++)
	T1.Push(i);
	cout<<endl<<"Queue:";
	T1.Display();
	cout<<endl<<"Top:"<<T1.Top();
	T1.Pop();
	cout<<endl<<"Queue sau khi Pop:";
	T1.Display();

}

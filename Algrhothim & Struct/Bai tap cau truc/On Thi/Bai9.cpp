#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

struct node{
	int data;
	node *next;	
};
template <class S>
class Stack{
	private:
		node *head;
	public:
		node *CreateNode(int value);
		void Push(int value);
		void Pop();
		int Top();
		int Size();
		Stack();
	//	~Stack();
		void Display();
		bool Empty();
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
void Stack<S>::Display()
{
	node *p=head;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
}

template <class S>
int Stack<S>::Size()
{
	node *p=head;
	int count=0;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	return count;
}
bool LaSo(char c)
{
	return (c>='0' && c<='9');
}
bool LaTT(char c)
{
	return (c=='+' || c=='-' || c=='*' || c=='/');
}
int UT(char c)
{
	if(c=='+' || c=='-') return 1;
	if(c=='*' || c=='/') return 2;
	return 0;
}

string ChuyenTrungToSangHauTo(string str)
{
	string temp="";
	Stack<char> st;
	int s = str.size();
	for(int i=0;i<s;i++)
	{
		if(LaSo(str[i]))
		{
			while(LaSo(str[i]))
			{
				temp +=str[i++];
			}
			
			temp+=' ';
		}
		if(str[i]=='(')
			st.Push(str[i]);
		if(str[i]==')')
		{
			while(st.Top()!='(')
			{
				temp +=st.Top();
				st.Pop();
			}
			st.Pop();
		}
		if(LaTT(str[i]))
		{
			if(!st.Empty() && UT(st.Top()) >= UT(str[i]))
			{
				temp += st.Top();
				temp +=' ';
				st.Pop();
			}
			st.Push(str.at(i));
		}
	}
	while(!st.Empty())
	{
		temp+= st.Top();
		temp+=' ';
		st.Pop();
	}
	return temp;
}

int tinh(string str)
{
	Stack<int> st;
	int x=0,a,b,c;
	int len = str.size();
	for(int i=0;i<len;i++)
	{
		if(LaSo(str[i]))
		{
			while(LaSo(str[i]))
				x = x*10 + str[i++] - 48;
			st.Push(x);
			x=0;
		}
		if(LaTT(str[i]))
		{
			b = st.Top(); st.Pop();
			a = st.Top(); st.Pop();
			if(str[i]=='+') c = a + b;
			if(str[i]=='-') c = a - b;
			if(str[i]=='*') c = a * b;
			if(str[i]=='/') c = a / b;
			st.Push(c);
		}
	}
	return st.Top();
}
main()
{
	Stack<char> s;
	for(int i=1;i<=10;i++)
	s.Push(i);
	
	cout<<endl<<"Size:"<<s.Size()<<endl;
	
	string str;
	cout<<"Nhap bieu thuc can tinh: ";
	getline(cin, str);
	string a=ChuyenTrungToSangHauTo(str);
	cout<<a<<endl;
	cout<<tinh(a)<<endl;
}

#include <iostream>

using namespace std;

struct node{
	int info;//Tha�nh ph��n d�� li��u cu�a con tro�
	node *prev;//Tha�nh ph��n con tro� tr���c
	node *next;//Tha�nh ph��n con tro� sau
};

void CreatList(node *&start,int value)//Ta�o node cu��i cho danh sa�ch ke�p
{
	node *s, *tmp;//
	tmp = new node;
	tmp->info = value;//Thi��t l��p th�ng tin cho tmp;
	tmp->next = NULL;
	if (start == NULL)//N��u danh sa�ch r��ng
	{
		tmp->prev = NULL;//Thi��t l��p li�n k��t tr���c 
		start = tmp;//Node ���u ti�n trong danh sa�ch la� tmp
	}
	else//N��u danh sa�ch kh�ng r��ng
	{
		s = start;//s tro� ���n start
		while (s->next != NULL)//L��p cho ���n khi g��p node cu��i
		{
			s = s->next;//Tro� ���n node ti��p theo
		}
		s->next = tmp;//Thi��t l��p li�n k��t ti��p theo cho node cu��i
		tmp->prev = s;//Thi��t l��p li�n k��t tr���c cho tmp

	}
}

void AddBegin(node *&start)//Th�m ���u
{
	int value;
	cout << "Nhap gia tri them:";
	cin >> value;
	if (start == NULL)//N��u danh sa�ch r��ng
	{
		cout << "Danh sach rong" << endl;
		return;
	}
	node *tmp;
	tmp = new node;
	tmp->prev = NULL;//node ���ng tr���c node ���u ti�n se� la� NULL
	tmp->info = value;//THi��t l��p th�ng tin cho node tmp
	tmp->next = start;
	start->prev = tmp;
	start = tmp;//Node ���u ti�n b�y gi�� la� tmp
	cout << "node da them vao dau" << endl;
}

void AddAfter(node *&start)//Th�m node va�o vi� tri� pos
{
	int value;//Gia� tri� th�m
	int pos;//vi� tri� th�m
	cout << "Nhap gia tri them:";
	cin >> value;
	cout << "Nhap vi tri them:";
	cin >> pos;
	if (start == NULL)//N��u danh sa�ch r��ng
	{
		cout << "Danh sach rong" << endl;
		return;
	}
	node *tmp, *s;
	s = start;
	for (int i = 0; i < pos - 1; i++)
	{
		s = s->next;//Chuy��n q ���n vi� tri� pos
		if (s == NULL)
		{
			cout << "So node nho hon " << pos << endl;
			return;
		}
	}
	tmp = new node;
	tmp->info = value;
	if (s->next == NULL)//N��u s la� node cu��i cu�ng
	{
		s->next = tmp;
		tmp->next = NULL;
		tmp->prev = s;
	}
	else//N��u s k pha�i node cu��i cu�ng
	{
		tmp->next = s->next;//node ti��p theo cua tmp la� node ti��p theo cu�a s
		tmp->next->prev = tmp;
		s->next = tmp;
		tmp->prev = s;
	}
}

void Display(node *&start)
{
	node *s;
	if (start == NULL)
	{
		cout << "Danh sach rong" << endl;
		return;
	}
	s = start;
	cout << "Noi dung danh sach lien ket kep:" << endl;
	while (s != NULL)//L��p cho ���n node cu��i cu�ng
	{
		cout << s->info << "->";//Hi��n thi� th�ng tin node
		s = s->next;//s tro� ���n node ti��p theo
	}
	cout << "NULL" << endl;//Cu��i danh sa�ch la NULL
}

void DeleteElement(node *&start)//Xo�a node coa gia� tri� value
{
	int value;
	cout << "Nhap gia tri can xoa:";
	cin >> value;
	node *tmp;
	node *q;
	if (start->info == value)//N��u node c��n xo�a la� node ���u ti�n
	{
		tmp = start;
		start = start->next;//node sau node ���u ti�n se� la� node ���u ti�n
		start->prev = NULL;
		free(tmp);//xo�a node tmp
		cout << "Node dau tien da bi xoa" << endl;
		return;
	}
	q = start;
	while (q->next->next != NULL)//Chuy��n ���n node tr���c cu�a q->next
	{
		if (q->next->info == value)//N��u node sau q la� node c��n xo�a
		{
			tmp = q->next;//tmp la� node c��n xo�a
			q->next = tmp->next;//tro� ���n sau node xo�a
			tmp->next->prev = q;
			free(tmp);
			cout << "Node da duoc loai bo" << endl;
			return;
		}
		q = q->next;
	}
	if (q->next->info == value)//N��u node c��n xo�a la� node cu��i cu�ng
	{
		tmp = q->next;
		q->next = NULL;
		free(tmp);
		cout << "Node cuoi cung da bi loai bo" << endl;
		return;
	}

}
int main()
{
	node *start = NULL;
	int value;
	int n;
	cout << "Nhap n:";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "Nhap gia tri:";
		cin >> value;
		CreatList(start, value);
		//
	}
	Display(start);
	AddBegin(start);
	Display(start);
	AddAfter(start);
	Display(start);
	DeleteElement(start);
	Display(start);
	system("pause");
	return 0;
}
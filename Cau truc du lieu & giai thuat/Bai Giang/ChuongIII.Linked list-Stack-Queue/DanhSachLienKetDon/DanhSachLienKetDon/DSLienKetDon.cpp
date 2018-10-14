#include <iostream>

using namespace std;

struct node//bi��u di��n node
{
	int data;//tha�nh ph��n th�ng tin cu�a node
	node *next;//con tro� next tro� ���n node ti��p theo
};

node *CreateNode(int value)
{
	node *tmp;//Khai ba�o con tro� tmp la� 1 node
	tmp = new node;//c��p pha�t vu�ng nh�� cho con tro� tmp

	if (tmp == NULL)//N��u kh�ng �u� kh�ng gian nh��
	{
		cout << "Khhong du bo nho de cap phat" << endl;
		return 0;//D��ng ch��ng tri�nh
	}

	else
	{
		tmp->data = value;//Thi��t l��p th�ng tin cho con tro� tmp co� gia� tri� la� value
		tmp->next = NULL;//Thi��t l��p li�n k��t cho node tmp;
		return tmp;//Tra� la�i node tmp �a� ����c thi��t l��p
	}
}

void InsertBegin(node *&start)//che�n node va�o vi� tri� ���u ti�n
{
	int value;//gia� tri� che�n
	cout << "Nhap gia tri can chen vao ds:";
	cin >> value;

	node *tmp, *p;
	tmp = CreateNode(value);//Ta�o node tmp v��i gia� tri� value
	if (start == NULL)//N��u danh sa�ch r��ng
	{
		start = tmp;//Danh sa�ch chi�nh la� node tmp
		start->next = NULL;//Kh�ng co� li�n k��t v��i node kha�c
	}
	else//N��u danh sa�ch kh�ng r��ng
	{
		p = start;//p tro� ���n node ���u ti�n
		start = tmp;//start ����c tro� ���n tmp
		start->next = p;//start tro� ���n g��c cu�
	}
	cout << "Hoan thanh them node vao dau DSLK" << endl;
}

void InsertLast(node *&start)//Th�m node va�o cu��i danh sa�ch 
{
	int value;//Gia� tri� c��n th�m
	cout << "Nhap gia tri can them vao ds:";
	cin >> value;

	node *tmp, *p;
	tmp = CreateNode(value);//Ta�o node tmp v��i gia� tri� value
	p = start;//p tro� ���n node ���u danh sa�ch
	while (p->next != NULL)
	{
		p = p->next;//Di chuy��n p ���n node cu��i cu�ng
	}
	tmp->next = NULL;//tmp kh�ng tro� �i ��u n��a
	p->next = tmp;//Thi��t l��p li�n k��t cho p
	cout << "Hoan thanh them node vao cuoi" << endl;
}

void InsertPos(node *&start)//Th�m node va�o vi� tri� pos
{
	int value;//gia� tri� che�n va�o ds
	int pos;//vi� tri� che�n
	int counter = 0;//bi��n ���m
	cout << "Nhap gia tri node:";
	cin >> value;
	cout << "Nhap vi tri chen node:";
	cin >> pos;
	node *tmp, *p, *ptr=nullptr;
	tmp = CreateNode(value);//ta�o node tmp co� gia� tri�n la� value
	p = start;//p tro� ���n node ���u ti�n
	while (p != NULL)
	{
		p = p->next;
		counter++;//���m s�� node cu�a ds
	}
	if (pos == 1)//N��u pos la� vi� tri� ���u ti�n
	{
		if (start == NULL)//N��u danh sa�ch r��ng
		{
			start = tmp;//node c��n th�m chi�nh la� node tmp
			start->next = NULL;//kh�ng li�n k��t v��i node na�o n��a
		}
		else
		{
			ptr = start;//ptr tro� ���n node ���u ti�n
			start = tmp;//ga�n node ���u ti�n la� node tmp
			start->next = ptr;//kh�ng li�n k��t v��i node na�o n��a
		}
	}
	else//N��u kh�ng pha�i la� node ���u ti�n
	if (pos > 1 && pos <= counter)//Tr���ng h��p pos h��p l��
	{
		p = start;//p tro� ���n node ���u ti�n;
		for (int i = 1; i < pos; i++)//Ti�m ���n vi� tri� cu�a node tr���c node c��n che�n 
		{
			ptr = p;
			p = p->next;
		}
		ptr->next = tmp;
		tmp->next = p;//Thi��t l��p li��n k��t cho node
	}
	else//N��u vi� tri� pos k h��p l��
	{
		cout << "Vuot qua gioi han DSLK" << endl;
	}
}

void DeletePos(node *&start)//Xo�a node ta�i vi� tri� pos
{
	int pos, counter = 0;
	if (start == NULL)//N��u danh sa�ch r��ng
	{
		cout << "Khong thuc hien duoc" << endl;
		return;
	}
	cout << "Nhap vi tri can loai bo:";
	cin >> pos;
	node *p, *ptr = nullptr;
	p = start;
	if (pos == 1)//N��u vi� tri� loa�i bo� la� node ���u ti�n
	{
		start = p->next;
		p->next = NULL;
		free(p);
	}
	else//N��u k pha�i la� vi� tri� ���u ti�n
	{
		while (p != NULL)
		{
			p = p->next;
			counter++;//���m s�� node
		}
		if (pos > 0 && pos <= counter)//N��u vi� tri� h��p l��
		{
			p = start;
			for (int i = 1; i < pos; i++)//Ti�m ���n node ���ng tr���c node c��n xo�a
			{
				ptr = p;
				p = p->next;
			}
			ptr->next = p->next;//Cho node ���ng tr���c node c��n xo�a tro� ���n node sau node c��n xo�a
		}
		else
		{
			cout << "Vi tri ngoai danh sach" << endl;
		}
		free(p);
		cout << "Node da bi loai bo" << endl;
	}
}

void Update(node *&start)//S��a ���i n��i dung node
{
	int value;//gia� tri� s��a ���i
	int pos;//vi� tri� cu�a node c��n s��a ���i
	if (start == NULL)
	{
		cout << "Danh sach rong" << endl;
		return;
	}
	cout << "Nhap vi tri node can sua:";
	cin >> pos;
	cout << "Nhap gia tri node can sua:";
	cin >> value;
	node *p, *ptr = nullptr;
	p = start;//p tro� ���n node ���u ti�n
	if (pos == 1) start->data = value;//N��u node c��n s��a la� node ���u ti�n thi� s��a lu�n
	else//N��u kh�ng pha�i node ���u ti�n
	{
		for (int i = 1; i < pos; i++)//Chuy��n p ���n vi� tri� pos-1
		{
			if (p == NULL)//N��u p la� node sau node cu��i cu�ng
			{
				cout << "Vi� tri� " << pos << " khong hop le";
				return;
			}
			p = p->next;
		}
		p->data = value;//Thay ���i th�ng tin cu�a con tro� p v��i gia� tri� la� value
	}
	cout << "Hoan thanh viec sua doi" << endl;
}

void Search(node *&start)//Ti�m ki��m
{
	int value;//gia� tri� c��n ti�m
	int pos = 0;
	bool flag = false;//c�� �a�nh d��u �a� ti�m th��y hay ch�a
	if (start == NULL)
	{
		cout << "Danh sach rong" << endl;
		return;
	}
	cout << "Nhap gia tri can tim:";
	cin >> value;
	node *p;
	p = start;
	while (p != NULL)
	{
		pos++;
		if (p->data == value)//N��u node p la� node c��n ti�m
		{
			flag = true;
			cout << "Tim thay " << value << " tai vi tri " << pos << endl;
		}
		p = p->next;
	}
	if (!flag) cout << "Gia tri " << value << " khong ton tai" << endl;
}

void Sort(node *&start)
{
	node *p, *s;
	int tmp;//gia� tri� trung gian
	if (start == NULL)
	{
		cout << "Danh sach rong" << endl;
		return;
	}
	p = start;
	while (p != NULL)
	{
		for (s = p->next; s != NULL; s = s->next)
		{
			if (p->data > s->data)//N��u gia� tri� cu�a node p > gia� tri� cu�a node s
			{
				tmp = p->data;//���i ch�� 2 node p va� s
				p->data = s->data;//
				s->data = tmp;//
			}
		}
		p = p->next;
	}
}

void Reverse(node *&start)//�a�o ng���c ca�c node 
{
	node *p1, *p2, *p3;
	if (start == NULL)
	{
		cout << "Danh sach rong" << endl;
		return;
	}
	if (start->next == NULL)//n��u danh sa�ch chi� co� 1 node
	{
		cout << "Vi danh sach chi co 1 node nen dao nguoc chinh la no" << endl;
	}
	p1 = start;//p1 tro� ���n node ���u ti�n
	p2 = p1->next;//p2 tro� ���n node sau node p1
	p3 = p2->next;//p3 tro� ���n node sau node p2
	p1->next = NULL;//ng��t li�n k��t p1
	p2->next = p1;//node p2 b�y gi�� ���ng tr���c node p1
	while (p3 != NULL)
	{
		p1 = p2;//p1 la�i b��t ���u ta�i vi� tri� p2
		p2 = p3;//p2 la�i b��t ���u ta�i vi� tri� p3
		p3 = p3->next;//p3 tro� ���n node k�� ti��p
		p2->next = p1;//Thi��t l��p li�n k��t cho p2
	}
	start = p2;//node ���u ti�n b�y gi�� la� node p2
}

void Display(node *&start)//Hi��n thi� danh sa�ch
{
	node *tmp;
	if (start == NULL)//N��u danh sa�ch r��ng
	{
		cout << "Danh sach rong" << endl;
		return;
	}
	tmp = start;//tmp tro� ���n node ���u ti�n trong DSLK
	cout << "Noi dung DSLK don:" << endl;
	while (tmp != NULL)//L��p cho ���n node cu��i cu�ng
	{
		cout << tmp->data << "->";//hi��n thi�
		tmp = tmp->next;//tro� ���n node k�� ti��p
	}
	cout << "NULL" << endl;//Cu��i cu�ng la� NULL
}

int main()
{
	node *start = NULL;
	int n;
	cout << "Nhap n:";
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		InsertBegin(start);
	}
	cout << endl << "Da nhap xong " << n << " so nguyen" << endl;
	Display(start);

	InsertLast(start);
	Display(start);

	InsertPos(start);
	Display(start);

	DeletePos(start);
	Display(start);

	Update(start);
	Display(start);

	Search(start);

	Reverse(start);
	Display(start);

	Sort(start);
	Display(start);

	system("pause");
	return 0;
}

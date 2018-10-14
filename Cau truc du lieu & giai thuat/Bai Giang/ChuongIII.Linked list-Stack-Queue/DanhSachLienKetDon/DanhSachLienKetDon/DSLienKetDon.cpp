#include <iostream>

using namespace std;

struct node//biêÒu diêŞn node
{
	int data;//thaÌnh phâÌn thông tin cuÒa node
	node *next;//con troÒ next troÒ ğêìn node tiêìp theo
};

node *CreateNode(int value)
{
	node *tmp;//Khai baìo con troÒ tmp laÌ 1 node
	tmp = new node;//câìp phaìt vuÌng nhõì cho con troÒ tmp

	if (tmp == NULL)//Nêìu không ğuÒ không gian nhõì
	{
		cout << "Khhong du bo nho de cap phat" << endl;
		return 0;//DıÌng chıõng triÌnh
	}

	else
	{
		tmp->data = value;//Thiêìt lâòp thông tin cho con troÒ tmp coì giaì triò laÌ value
		tmp->next = NULL;//Thiêìt lâòp liên kêìt cho node tmp;
		return tmp;//TraÒ laòi node tmp ğaŞ ğıõòc thiêìt lâòp
	}
}

void InsertBegin(node *&start)//cheÌn node vaÌo viò triì ğâÌu tiên
{
	int value;//giaì triò cheÌn
	cout << "Nhap gia tri can chen vao ds:";
	cin >> value;

	node *tmp, *p;
	tmp = CreateNode(value);//Taòo node tmp võìi giaì triò value
	if (start == NULL)//Nêìu danh saìch rôŞng
	{
		start = tmp;//Danh saìch chiình laÌ node tmp
		start->next = NULL;//Không coì liên kêìt võìi node khaìc
	}
	else//Nêìu danh saìch không rôŞng
	{
		p = start;//p troÒ ğêìn node ğâÌu tiên
		start = tmp;//start ğıõòc troÒ ğêìn tmp
		start->next = p;//start troÒ ğêìn gôìc cuŞ
	}
	cout << "Hoan thanh them node vao dau DSLK" << endl;
}

void InsertLast(node *&start)//Thêm node vaÌo cuôìi danh saìch 
{
	int value;//Giaì triò câÌn thêm
	cout << "Nhap gia tri can them vao ds:";
	cin >> value;

	node *tmp, *p;
	tmp = CreateNode(value);//Taòo node tmp võìi giaì triò value
	p = start;//p troÒ ğêìn node ğâÌu danh saìch
	while (p->next != NULL)
	{
		p = p->next;//Di chuyêÒn p ğêìn node cuôìi cuÌng
	}
	tmp->next = NULL;//tmp không troÒ ği ğâu nıŞa
	p->next = tmp;//Thiêìt lâòp liên kêìt cho p
	cout << "Hoan thanh them node vao cuoi" << endl;
}

void InsertPos(node *&start)//Thêm node vaÌo viò triì pos
{
	int value;//giaì triò cheÌn vaÌo ds
	int pos;//viò triì cheÌn
	int counter = 0;//biêìn ğêìm
	cout << "Nhap gia tri node:";
	cin >> value;
	cout << "Nhap vi tri chen node:";
	cin >> pos;
	node *tmp, *p, *ptr=nullptr;
	tmp = CreateNode(value);//taòo node tmp coì giaì triòn laÌ value
	p = start;//p troÒ ğêìn node ğâÌu tiên
	while (p != NULL)
	{
		p = p->next;
		counter++;//Ğêìm sôì node cuÒa ds
	}
	if (pos == 1)//Nêìu pos laÌ viò triì ğâÌu tiên
	{
		if (start == NULL)//Nêìu danh saìch rôŞng
		{
			start = tmp;//node câÌn thêm chiình laÌ node tmp
			start->next = NULL;//không liên kêìt võìi node naÌo nıŞa
		}
		else
		{
			ptr = start;//ptr troÒ ğêìn node ğâÌu tiên
			start = tmp;//gaìn node ğâÌu tiên laÌ node tmp
			start->next = ptr;//không liên kêìt võìi node naÌo nıŞa
		}
	}
	else//Nêìu không phaÒi laÌ node ğâÌu tiên
	if (pos > 1 && pos <= counter)//TrıõÌng hõòp pos hõòp lêò
	{
		p = start;//p troÒ ğêìn node ğâÌu tiên;
		for (int i = 1; i < pos; i++)//TiÌm ğêìn viò triì cuÒa node trıõìc node câÌn cheÌn 
		{
			ptr = p;
			p = p->next;
		}
		ptr->next = tmp;
		tmp->next = p;//Thiêìt lâòp liêìn kêìt cho node
	}
	else//Nêìu viò triì pos k hõòp lêò
	{
		cout << "Vuot qua gioi han DSLK" << endl;
	}
}

void DeletePos(node *&start)//Xoìa node taòi viò triì pos
{
	int pos, counter = 0;
	if (start == NULL)//Nêìu danh saìch rôŞng
	{
		cout << "Khong thuc hien duoc" << endl;
		return;
	}
	cout << "Nhap vi tri can loai bo:";
	cin >> pos;
	node *p, *ptr = nullptr;
	p = start;
	if (pos == 1)//Nêìu viò triì loaòi boÒ laÌ node ğâÌu tiên
	{
		start = p->next;
		p->next = NULL;
		free(p);
	}
	else//Nêìu k phaÒi laÌ viò triì ğâÌu tiên
	{
		while (p != NULL)
		{
			p = p->next;
			counter++;//Ğêìm sôì node
		}
		if (pos > 0 && pos <= counter)//Nêìu viò triì hõòp lêò
		{
			p = start;
			for (int i = 1; i < pos; i++)//TiÌm ğêìn node ğıìng trıõìc node câÌn xoìa
			{
				ptr = p;
				p = p->next;
			}
			ptr->next = p->next;//Cho node ğıìng trıõìc node câÌn xoìa troÒ ğêìn node sau node câÌn xoìa
		}
		else
		{
			cout << "Vi tri ngoai danh sach" << endl;
		}
		free(p);
		cout << "Node da bi loai bo" << endl;
	}
}

void Update(node *&start)//SıÒa ğôÒi nôòi dung node
{
	int value;//giaì triò sıÒa ğôÒi
	int pos;//viò triì cuÒa node câÌn sıÒa ğôÒi
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
	p = start;//p troÒ ğêìn node ğâÌu tiên
	if (pos == 1) start->data = value;//Nêìu node câÌn sıÒa laÌ node ğâÌu tiên thiÌ sıÒa luôn
	else//Nêìu không phaÒi node ğâÌu tiên
	{
		for (int i = 1; i < pos; i++)//ChuyêÒn p ğêìn viò triì pos-1
		{
			if (p == NULL)//Nêìu p laÌ node sau node cuôìi cuÌng
			{
				cout << "Viò triì " << pos << " khong hop le";
				return;
			}
			p = p->next;
		}
		p->data = value;//Thay ğôÒi thông tin cuÒa con troÒ p võìi giaì triò laÌ value
	}
	cout << "Hoan thanh viec sua doi" << endl;
}

void Search(node *&start)//TiÌm kiêìm
{
	int value;//giaì triò câÌn tiÌm
	int pos = 0;
	bool flag = false;//cõÌ ğaình dâìu ğaŞ tiÌm thâìy hay chıa
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
		if (p->data == value)//Nêìu node p laÌ node câÌn tiÌm
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
	int tmp;//giaì triò trung gian
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
			if (p->data > s->data)//Nêìu giaì triò cuÒa node p > giaì triò cuÒa node s
			{
				tmp = p->data;//ĞôÒi chôŞ 2 node p vaÌ s
				p->data = s->data;//
				s->data = tmp;//
			}
		}
		p = p->next;
	}
}

void Reverse(node *&start)//ĞaÒo ngıõòc caìc node 
{
	node *p1, *p2, *p3;
	if (start == NULL)
	{
		cout << "Danh sach rong" << endl;
		return;
	}
	if (start->next == NULL)//nêìu danh saìch chiÒ coì 1 node
	{
		cout << "Vi danh sach chi co 1 node nen dao nguoc chinh la no" << endl;
	}
	p1 = start;//p1 troÒ ğêìn node ğâÌu tiên
	p2 = p1->next;//p2 troÒ ğêìn node sau node p1
	p3 = p2->next;//p3 troÒ ğêìn node sau node p2
	p1->next = NULL;//ngãìt liên kêìt p1
	p2->next = p1;//node p2 bây giõÌ ğıìng trıõìc node p1
	while (p3 != NULL)
	{
		p1 = p2;//p1 laòi bãìt ğâÌu taòi viò triì p2
		p2 = p3;//p2 laòi bãìt ğâÌu taòi viò triì p3
		p3 = p3->next;//p3 troÒ ğêìn node kêì tiêìp
		p2->next = p1;//Thiêìt lâòp liên kêìt cho p2
	}
	start = p2;//node ğâÌu tiên bây giõÌ laÌ node p2
}

void Display(node *&start)//HiêÒn thiò danh saìch
{
	node *tmp;
	if (start == NULL)//Nêìu danh saìch rôŞng
	{
		cout << "Danh sach rong" << endl;
		return;
	}
	tmp = start;//tmp troÒ ğêìn node ğâÌu tiên trong DSLK
	cout << "Noi dung DSLK don:" << endl;
	while (tmp != NULL)//Lãòp cho ğêìn node cuôìi cuÌng
	{
		cout << tmp->data << "->";//hiêÒn thiò
		tmp = tmp->next;//troÒ ğêìn node kêì tiêìp
	}
	cout << "NULL" << endl;//Cuôìi cuÌng laÌ NULL
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

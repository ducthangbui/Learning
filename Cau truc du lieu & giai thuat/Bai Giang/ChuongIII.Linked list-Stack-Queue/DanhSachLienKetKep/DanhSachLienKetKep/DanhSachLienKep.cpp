#include <iostream>

using namespace std;

struct node{
	int info;//ThaÌnh phâÌn dıŞ liêòu cuÒa con troÒ
	node *prev;//ThaÌnh phâÌn con troÒ trıõìc
	node *next;//ThaÌnh phâÌn con troÒ sau
};

void CreatList(node *&start,int value)//Taòo node cuôìi cho danh saìch keìp
{
	node *s, *tmp;//
	tmp = new node;
	tmp->info = value;//Thiêìt lâòp thông tin cho tmp;
	tmp->next = NULL;
	if (start == NULL)//Nêìu danh saìch rôŞng
	{
		tmp->prev = NULL;//Thiêìt lâòp liên kêìt trıõìc 
		start = tmp;//Node ğâÌu tiên trong danh saìch laÌ tmp
	}
	else//Nêìu danh saìch không rôŞng
	{
		s = start;//s troÒ ğêìn start
		while (s->next != NULL)//Lãòp cho ğêìn khi gãòp node cuôìi
		{
			s = s->next;//TroÒ ğêìn node tiêìp theo
		}
		s->next = tmp;//Thiêìt lâòp liên kêìt tiêìp theo cho node cuôìi
		tmp->prev = s;//Thiêìt lâòp liên kêìt trıõìc cho tmp

	}
}

void AddBegin(node *&start)//Thêm ĞâÌu
{
	int value;
	cout << "Nhap gia tri them:";
	cin >> value;
	if (start == NULL)//Nêìu danh saìch rôŞng
	{
		cout << "Danh sach rong" << endl;
		return;
	}
	node *tmp;
	tmp = new node;
	tmp->prev = NULL;//node ğãÌng trıõìc node ğâÌu tiên seŞ laÌ NULL
	tmp->info = value;//THiêìt lâòp thông tin cho node tmp
	tmp->next = start;
	start->prev = tmp;
	start = tmp;//Node ğâÌu tiên bây giõÌ laÌ tmp
	cout << "node da them vao dau" << endl;
}

void AddAfter(node *&start)//Thêm node vaÌo viò triì pos
{
	int value;//Giaì triò thêm
	int pos;//viò triì thêm
	cout << "Nhap gia tri them:";
	cin >> value;
	cout << "Nhap vi tri them:";
	cin >> pos;
	if (start == NULL)//Nêìu danh saìch rôŞng
	{
		cout << "Danh sach rong" << endl;
		return;
	}
	node *tmp, *s;
	s = start;
	for (int i = 0; i < pos - 1; i++)
	{
		s = s->next;//ChuyêÒn q ğêìn viò triì pos
		if (s == NULL)
		{
			cout << "So node nho hon " << pos << endl;
			return;
		}
	}
	tmp = new node;
	tmp->info = value;
	if (s->next == NULL)//Nêìu s laÌ node cuôìi cuÌng
	{
		s->next = tmp;
		tmp->next = NULL;
		tmp->prev = s;
	}
	else//Nêìu s k phaÒi node cuôìi cuÌng
	{
		tmp->next = s->next;//node tiêìp theo cua tmp laÌ node tiêìp theo cuÒa s
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
	while (s != NULL)//Lãòp cho ğêìn node cuôìi cuÌng
	{
		cout << s->info << "->";//HiêÒn thiò thông tin node
		s = s->next;//s troÒ ğêìn node tiêìp theo
	}
	cout << "NULL" << endl;//Cuôìi danh saìch la NULL
}

void DeleteElement(node *&start)//Xoìa node coa giaì triò value
{
	int value;
	cout << "Nhap gia tri can xoa:";
	cin >> value;
	node *tmp;
	node *q;
	if (start->info == value)//Nêìu node câÌn xoìa laÌ node ğâÌu tiên
	{
		tmp = start;
		start = start->next;//node sau node ğâÌu tiên seŞ laÌ node ğâÌu tiên
		start->prev = NULL;
		free(tmp);//xoìa node tmp
		cout << "Node dau tien da bi xoa" << endl;
		return;
	}
	q = start;
	while (q->next->next != NULL)//ChuyêÒn ğêìn node trıõìc cuÒa q->next
	{
		if (q->next->info == value)//Nêìu node sau q laÌ node câÌn xoìa
		{
			tmp = q->next;//tmp laÌ node câÌn xoìa
			q->next = tmp->next;//troÒ ğêìn sau node xoìa
			tmp->next->prev = q;
			free(tmp);
			cout << "Node da duoc loai bo" << endl;
			return;
		}
		q = q->next;
	}
	if (q->next->info == value)//Nêìu node câÌn xoìa laÌ node cuôìi cuÌng
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
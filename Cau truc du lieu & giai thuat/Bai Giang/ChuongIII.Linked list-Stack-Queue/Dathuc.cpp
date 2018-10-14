#include <iostream>

using namespace std;

typedef struct node
{
	float somu;
	float heso;
	node *next;
}*dathuc;

node *CreateNode(float somu, float heso)
{
	node *tmp;
	tmp = new node;
	tmp->heso = heso;
	tmp->somu = somu;
	tmp->next = NULL;
	return tmp;
}

void InsertLast(node *&start)
{
	float mu, hso;
	cout << "Nhap so mu:";
	cin >> mu;
	cout << "Nhap he so:";
	cin >> hso;

	node *tmp, *p;
	tmp = CreateNode(mu, hso);
	p = start;
	while (p->next != NULL)
	{
		p = p->next;
	}
	tmp->next = NULL;
	p->next = tmp;
}

void Display(node *&start)//Hiê?n thi? danh sa´ch
{
	node *tmp;

	tmp = start;//tmp tro? dê´n node dâ`u tiên trong DSLK

	while (tmp != NULL)//La?p cho dê´n node cuô´i cu`ng
	{
		cout << "He so:"<< tmp->heso << " So mu:" << tmp->somu << endl;//hiê?n thi?
		tmp = tmp->next;//tro? dê´n node kê´ tiê´p
	}

}

void NhapDaThuc(node *&start, node *&p, node *&q)
{
	float mu, hso;
	int n;
	cout << "Nhap so he so cua da thuc:";
	cin >> n;
	cout << endl << "Nhap da thuc P:" << endl;
	for (int i = 1; i <= n; i++)
	{

	cout << "Nhap so mu:";
	cin >> mu;
	cout << "Nhap he so:";
	cin >> hso;

	node *tmp;
	p = CreateNode(mu, hso);
	tmp = start;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	p->next = NULL;
	tmp->next = p;
	}
	Display(start);
	cout << endl << "Nhap da thuc Q:" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << "Nhap he so thu " << i << " :" ;
		cin >> hso;
		cout << "Nhap so mu thu " << i << " :";
		cin >> mu;
		q = CreateNode(mu, hso);
		InsertLast(start);
	}
}
void CongDaThuc(node *&start,node *p,node *q)
{
	node *r=NULL;
	//r = CreateNode(0, 0);
	while (p!=NULL && q!=NULL)
	{
		if (p->somu > q->somu)
		{
			r->heso = p->heso;
			r->somu = p->somu;
			InsertLast(start);
			p = p->next;
		}
		else 
		if (p->somu < q->somu)
		{
			r->heso = q->heso;
			r->somu = r->somu;
			InsertLast(start);
			q = q->next;
		}
		else
		{
			p->heso = p->heso + q->heso;
			r->heso = q->heso;
			r->somu = q->somu;
			InsertLast(start);
			p = p->next;
			q = q->next;
		}
	}
	Display(start);
}

int main()
{
	node *start = NULL;
	node *p, *q;
	NhapDaThuc(start, p, q);
	Display(start);
	return 0;
}



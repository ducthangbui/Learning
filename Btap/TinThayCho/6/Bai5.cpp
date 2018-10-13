#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct SinhVien
{
	char ten[25];
	float toan,ly,tb;
	char XepLoai[25];
};
typedef struct node
{
	SinhVien Data;
	node* next;
};
node* TaoNut(SinhVien x)
{
	node* n;
	n=(node*)malloc(sizeof(node));
	n->next=NULL;
	n->Data=x;
	return n;
}
void AddFirstNode(node* &head,node* n)
{
	if(head==NULL)
	{
		head=n;
		return;
	}
	n->next=head;
	head=n;
}
void Xuat(node* &head)
{
	if(head==NULL)
	{
		printf("Khong co sinh vien nao\n");
		return;
	}
	node* p=head;
	printf("Ho&Ten\t\t\tToan\tLy\tDiemTb\tXep Loai\t\n");
	while(p!=NULL)
	{
		printf("%s\t\t%.2f\t%.2f\t%.2f\t%s\n",p->Data.ten,p->Data.toan,p->Data.ly,p->Data.tb,p->Data.XepLoai);
		p=p->next;
	}
}
void TinhDiem(node* &head)
{
	if(head==NULL)
	{
		printf("Khong co sinh vien nao\n");
		return;
	}
	node* p=head;
	while(p!=NULL)
	{
		p->Data.tb=(p->Data.toan+p->Data.ly)/2;
		if(p->Data.tb>=8) strcpy(p->Data.XepLoai,"Gioi");
		else if(p->Data.tb<8&&p->Data.tb>=7) strcpy(p->Data.XepLoai,"Kha");
		else if(p->Data.tb<7&&p->Data.tb>=5) strcpy(p->Data.XepLoai,"Trung Binh");
		else strcpy(p->Data.XepLoai,"Kem");
		p=p->next;
	}
}
void Sx(node* &head)
{
	SinhVien tmp;
	for(node* p=head;p->next!=NULL;p=p->next)
	for(node* q=p->next;q!=NULL;q=q->next)
	if(p->Data.tb<q->Data.tb)
	{
		tmp=p->Data;
		p->Data=q->Data;
		q->Data=tmp;
	}
}
main()
{
	node* p;
	node* head=NULL;
	SinhVien x;
	int n,i=0;
	float toan,ly;
	printf("Nhap so sinh vien:");
	scanf("%d",&n);
	do
	{
		printf("Nhap Ho&ten:");
		fflush(stdin);
		gets(x.ten);
		if(strlen(x.ten)>0)
		{
			printf("Nhap diem toan:");
			scanf("%f",&toan);
			x.toan=toan;
			printf("Nhap diem ly:");
			scanf("%f",&ly);
			x.ly=ly;
			p=TaoNut(x);
			AddFirstNode(head,p);
		}
		i++;
	}while(i<n);
	printf("\n==============================================\n");
	printf("\nDanh sach vua nhap la\n");
	Xuat(head);
	printf("\n==============================================\n");
	TinhDiem(head);
	Sx(head);
	Xuat(head);
}

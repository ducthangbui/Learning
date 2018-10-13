#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Sv
{
	char ten[30];
	float diem;
};
typedef struct node
{
	Sv key;
	node* next;
}node;
node* CreateNode(Sv x)
{
	node* n;
	n=(node*)malloc(sizeof(node));
	n->key=x;
	n->next=NULL;
	return n;
}
node* FindEndNode(node* head)
{
	node* p=head;
	if(p==NULL) return NULL;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	return p;
}
void AddLastNode(node* &head,node* n)
{
	if(head==NULL)
	{
		head=n;
		return;
	}
	node* p=FindEndNode(head);
	p->next=n;
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
void FindNode(node* &head,char *x)
{
	node* p=head;
	while(p!=NULL&&strcmp(p->key.ten,x)!=0)
	p=p->next;
	if(p==NULL) printf("\nKhong tim thay SV ten %s\n",x);
	else printf("\nDa thay SV ten %s trong lop co diem so la %.2f\n",p->key.ten,p->key.diem);
}
node* FindBeforeNode(node* head,char *x)
{
	node* p=head;
	while(p->next!=NULL)
	{
		if(strcmp(p->next->key.ten,x)==0)
		return p;
	}
	return NULL;
}
void DelFirstNode(node* &head)
{
	node* p=head;
	if(head==NULL) return;
	head=head->next;
	free(p);
}
void DelNode(node* &head,char *x)
{
	if(strcmp(head->key.ten,x)==0)
	{
		DelFirstNode(head);
		return;
	}
	node* p=FindBeforeNode(head,x);
	if(p==NULL) return;
	node* t=p->next;
	p->next=t->next;
	free(t);
}
void XuatDS(node* &head)
{
	node* p=head;
	printf("Ho&ten\tDiem\n\n");
	while(p!=NULL)
	{
		printf("%s\t%.2f\n",p->key.ten,p->key.diem);
		p=p->next;
	}
}
void Doicho(Sv &x,Sv &y)
{
	Sv tmp=x;
	x=y;
	y=tmp;
	
}
void Sxdiem(node* &head)
{
   Sv temp;//temp co kieu cua info
   for(node* p=head;p->next!=NULL;p=p->next)
       for(node* q=p->next;q!=NULL;q=q->next)
         if(p->key.diem>q->key.diem)
         {
            temp=p->key;
            p->key=q->key;
            q->key=temp;
         }
}
char*ToWestern(const char*s)
{
    char*ptok,name[30];
    strcpy(name,s);
    char*tmp=(char*)malloc(30);
    tmp[0]='\0';
 
    ptok=strtok( name, " " );
    while ( ptok != NULL )
    {
        strcat( tmp, " ");
        strcat( tmp, strrev( ptok ) );
        ptok=strtok( NULL, " " );
    }
    strrev( tmp );
    return tmp;
}
void SxTen(node* &head)
{
	Sv temp;
	for(node* p=head;p->next!=NULL;p=p->next)
	for(node* q=p->next;q!=NULL;q=q->next)
	if(stricmp(ToWestern(p->key.ten),ToWestern(q->key.ten))>0)
	{
		temp=p->key;
		p->key=q->key;
		q->key=temp;
	}
}
main()
{
	node* head=NULL;
	node* p;
	char ten[30];
	Sv s;
	int i=0;
	char xoa[30],tim[30];
	float diem;
	do
	{
		ten[0]='\0';
	printf("Nhap ten:");
	fflush(stdin);
	gets(s.ten);
	if(strlen(s.ten)>0)
	{
		printf("Nhap diem:");
		scanf("%f",&diem);
		s.diem=diem;
		p=CreateNode(s);
		AddFirstNode(head,p);
	}
	}while(strlen(s.ten)>0);
	/*XuatDS(head);
	printf("====================================");
	fflush(stdin);
	printf("Nhap vao ten SV can xoa:");
	gets(xoa);
	DelNode(head,xoa);
	printf("\nDS sau khi xoa hoc sinh %s la:\n",xoa);
	XuatDS(head);
	printf("====================================");
	printf("\nNhap ten SV can tim:");
	gets(tim);
	FindNode(head,tim);
	printf("====================================");*/
	//printf("\nSap xep theo diem:\n");
	printf("\nSap xep theo ten:\n");
	//Sxdiem(head);
	SxTen(head);
	XuatDS(head);
}

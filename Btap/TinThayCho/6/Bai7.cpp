#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct SinhVien
{
	char MSV[9];
	char ten[11];
	char hodem[21];
	float d[11];
	int ngay,thang,nam;
	char gioitinh[4];
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
	n->Data=x;
	n->next=NULL;
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
	printf("Ho&ten\t\t\tMaSv\tGioi Tinh\tNgay/Thang/Nam sinh\t");
	for(int i=0;i<10;i++)
	printf("Diem mon %d\t",i+1);
	while(p!=NULL)
	{
		printf("\n%s\t%s\t%s\t%d/%d/%d\t",p->Data.ten,p->Data.MSV,p->Data.gioitinh,p->Data.ngay,p->Data.thang,p->Data.nam);
		for(int i=0;i<10;i++)
		printf("%.2f\t",p->Data.d[i]);
		p=p->next;
	}
}
/*void Mo(SinhVien x)
{
	FILE *DS;
	int n;
	DS=fopen("DS.txt","rt");
	//node* p=head;
	fscanf(DS,"%d",&n);
	int i=0;
	do
	{
	
	
		fgets(x.ten,100,DS);
		x.ten[strlen((x.ten)-1)]='\0';
		fgets(x.MSV,100,DS);
		x.MSV[strlen((x.MSV)-1)]='\0';
		//fgets(p->Data.hodem,100,DS);
		//p->Data.hodem[(strlen(p->Data.hodem)-1)]='\0';
		fscanf(DS,"%d%d%d",&x.ngay,&x.thang,&x.nam);
		for(int i=0;i<10;i++)
		fscanf(DS,"%f",&x.d[i]);
		//p=p->next;
		i++;
	}while(i<n);
	fclose(DS);
}*/
void Mo(node* &head)
{
	FILE *DS;
	node *p;
	SinhVien x;
	DS=fopen("DS.txt","rb");
	while(fread(&x,sizeof(SinhVien),1,DS)==1)
	{
		//fread(&p->Data,sizeof(SinhVien),1,DS);
		//p=TaoNut(x);
		AddFirstNode(head,p);
	}
	fclose(DS);
}
void Ghi(node* &head)
{
	FILE *DS;
	node* p=head;
	DS=fopen("DS.txt","wb");
	while(p!=NULL)
	{
		fwrite(&p->Data,sizeof(SinhVien),1,DS);
		p=p->next;
	}
	fclose(DS);
}
main()
{
	int n,i=0;
	float d[11];
	SinhVien x;
	node* head=NULL;
	node* p;
	/*FILE *DS;
	DS=fopen("DS.txt","wt");
	printf("Nhap vao so sinh vien:");
	scanf("%d",&n);
	fprintf(DS,"%d",&n);
	do
	{
		printf("Nhap ten:");
		fflush(stdin);
		gets(x.ten);
		//fputs(x.ten,DS);
		if(strlen(x.ten)>0)
		{
			printf("Nhap MSV:");
			scanf("%s",&x.MSV);
			//fputs(x.MSV,DS);
			printf("Nhap gioi tinh:");
			fflush(stdin);
			gets(x.gioitinh);
			//fputs(x.gioitinh,DS);
			printf("Nhap ngay/thang/nam sinh:");
			scanf("%d%d%d",&x.ngay,&x.thang,&x.nam);
			//fprintf(DS,"%d%d%d",x.ngay,x.thang,x.nam);
			for(int i=0;i<10;i++)
			{
				printf("Nhap diem mon %d:",i+1);
				scanf("%f",&d[i]);
				x.d[i]=d[i];
				//fprintf(DS,"%d",&x.d[i]);
			}
			p=TaoNut(x);
			AddFirstNode(head,p);
		}
		i++;
	}while(i<n);
	//Xuat(head);
	//printf("\n============================================\n");*/
	//Ghi(head);
	Mo(head);
	Xuat(head);
}

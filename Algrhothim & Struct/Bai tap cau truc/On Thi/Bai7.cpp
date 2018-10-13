#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
typedef struct node
{
        
    int heso;
    int somu;    
    struct node *next;
}*list;
void init(list *l)
{
    *l=NULL;
}
list getnode(void)
{
    list p;
    p=new node;
    return p;
}

void freenode(list p)
{
    delete p;
}
int empty(list *l)
{
    if(*l==NULL)
    return 1;
    return 0;
}
list thugon(list *&l)//ham thu gon nay su dung trong truong hop neu nhu hai hang thuc co cung so mu thi ta se tien hanh phep cong hai he so cua hai hang thuc do de dat duoc bieu thuc rut gon
{
    list p, q;
    for(p=*l;p!=NULL;p=p->next)
    {
        for(q=p->next;q!=NULL;q=q->next)                       
        {    if(p->somu==q->somu)
            {
            p->heso=(p->heso)+(q->heso);
            p->next=q->next;
            freenode(q);
            }
        }
    }
    return *l;
}
//-------------sap xep so mu giam dan de thu gon sau nay------
void sapxep(list *l)
{
    list p,q;
    int temp;
    for(p=*l;p!=NULL;p=p->next)
    {
        for(q=p->next;q!=NULL;q=q->next)
        {
            if(p->somu<q->somu)
            {
                temp=p->somu;
                p->somu=q->somu;
                q->somu=temp;
                temp=p->heso;
                p->heso=q->heso;
                q->heso=temp;
            }
        }
    }
}
list them_dau(list *l,int x, int y)
{
    list p;
    p=getnode();
    p->somu=x;
    p->heso=y;
    if(empty(l))
    {
        p->next=NULL;
        *l=p;
        return p;
    }
    p->next=*l;
    
    sapxep(l);
          *l=thugon(l);
          *l=p;
    return p;
}
/*bo qua----
void del_apter(list p)
{
    list q;
    if(p->next==NULL) return;
    q=p->next;
    p->next=q->next;
    freenode(q);
} */

void inra(list *l)
{
    
    list p;
    if(empty(l))
    {
        cout<<"\n danh sach rong :";
        return;
    }
    for(p=*l;p!=NULL;p=p->next)
    {
        if((p->heso)<0&&p->heso!=-1)
        cout<<" "<<p->heso<<"x^"<<p->somu;
        else if(p->heso==-1)
        cout<<" -"<<"x^"<<p->somu;
        else if((p->heso)>0&&p!=*l)
        {    
             if(p->heso!=1)
             cout<<" + "<< p->heso<<"x^"<<p->somu<<" ";
             else
             cout<<" + "<<"x^"<<p->somu;
        }    
        else if((p->heso)>0&&p==*l)
        {
             if(p->heso!=1)
             cout<<" "<< p->heso<<"x^"<<p->somu<<" ";
             else
             cout<<" "<<"x^"<<p->somu<<" ";
       }     
    }
}
list khoitao(list *l,int j,int x,int y)
{
    int n;
    init(l);
    cout<<" nhap so phan tu cua da thuc thu "<<j<<" : ";
    cin>>n;
    int i=1;
    while(i<=n)
    {
        cout<<" \n nhap phan tu : ";
        cout<<" \n x^";
        cin>>x;
        cout<<"\n nhap he so cua x^"<<x<<": ";
        do{cin>>y;}
        while(y==0);
        *l=them_dau(l,x,y);
        i++;
        
    }
    cout<<"\n------------------------------------------------\n";
    sapxep(l);
          *l=thugon(l);
    return *l;
}
float tinhgiatri(list *l,float x)
{
     float s;
     list p;
     s=0;
     for(p=*l;p!=NULL;p=p->next)
     {
          s=s+((p->heso)* (pow(x,p->somu)) );                 
     }
     return s;
     
}

/*------------tong da thuc ------------*/

list congdathuc(list *l1,list *l2,list *l3)
{
     list p1,p2;
     p1=*l1;p2=*l2;

     while(p1!=NULL&&p2!=NULL)
     {
          if(p1->somu>p2->somu)
          {
                  *l3=them_dau(l3,p1->somu,p1->heso);
                  p1=p1->next;
          }
          else if(p1->somu<p2->somu)
          {
                  *l3=them_dau(l3,p2->somu,p2->heso);
                  p2=p2->next;
          }
          else if(p1->somu==p2->somu)
          {

                  *l3=them_dau(l3,p1->somu,p1->heso+p2->heso);
                  p1=p1->next;
                  p2=p2->next;
          }
        
     }
     while(p1!=NULL&&p2==NULL)
          {
              *l3= them_dau(l3,p1->somu,p1->heso);
               p1=p1->next;
          }
    while(p1==NULL&&p2!=NULL)    
          {
               *l3=them_dau(l3,p2->somu,p2->heso);
               p2=p2->next;
          }
          sapxep(l3);
          *l3=thugon(l3);
     return *l3;
}

/*------------hieu da thuc ------------*/

list hieudathuc(list *l1,list *l2,list *l3)
{
     list p1,p2;
     p1=*l1;
     p2=*l2;
     while(p1!=NULL&&p2!=NULL)
     {
               if(p1->somu>p2->somu)
               {
                    *l3=them_dau(l3,p1->somu,p1->heso);
                       p1=p1->next;
               }
                else if(p1->somu<p2->somu)
                 {
                       *l3=them_dau(l3,p2->somu,-p2->heso);
                        p2=p2->next;
                }
                else if(p1->somu==p2->somu)
                {
                  
                     *l3=them_dau(l3,p2->somu,((p1->heso)-(p2->heso)));
                    p1=p1->next;
                       p2=p2->next;
               }               
     }
     while(p1!=NULL&&p2==NULL)
          {
              *l3= them_dau(l3,p1->somu,p1->heso);
               p1=p1->next;
          }
    while(p1==NULL&&p2!=NULL)    
          {              
               *l3=them_dau(l3,p2->somu,-p2->heso);
               p2=p2->next;
          }
          
          sapxep(l3);
          *l3=thugon(l3);
     return *l3;
     
}
/*-------------nhan da thuc ---------*/
list tichdathuc(list *l1,list *l2,list *l3)
{
     init(l3);
     list p1,p2;
     for(p1=*l1;p1!=NULL;p1=p1->next)
     {
            for(p2=*l2;p2!=NULL;p2=p2->next)
            {
                         
                  *l3=them_dau(l3,p1->somu+p2->somu,p1->heso* p2->heso  );                         
            }
                                     
     }
     sapxep(l3);
          *l3=thugon(l3);
     return *l3;
}
/*-----------------chia da thuc -------------------------*/
list chiadathuc(list *l1,list *l2,list *l3)
{
     init(l3);
     list p1;
     p1=*l1;
     list p2=*l2; 
     while(p1->somu>=p2->somu)
     {
               
                list temp1;
                *l3=them_dau(l3,p1->somu-p2->somu,p1->heso/p2->heso)  ;
                //temp1 la de luu cai tam thoi vua chi duoc de nhan lai voi-
                //- so bi chia 
                init(&temp1);
                temp1=them_dau(&temp1,p1->somu-p2->somu,p1->heso/p2->heso)  ;
               list l9; 
               init(&l9);
               l9=tichdathuc(&temp1,l2,&l9);  
               list l7; 
               init(&l7);
               l7=hieudathuc(l1,&l9,&l7);  
              
                
                 init(l1);
              *l1=l7;
               
     }
     
     return *l3;
     
}
main()
{
    int x,y;
    list l1,l2;
    float s1,s2,x1,x2;
    l1=khoitao(&l1,1,x,y);
    /*---------------------------*/
    l2=khoitao(&l2,2,x,y);
    /*----------------------------*/
    cout<<" P(x)= "; 
    inra(&l1);
    
    cout<<"\n Q(x)= ";
    inra(&l2);
    /*----------------------------*/
    cout<<"\n nhap gia tri cua x1 = ";cin>>x1;
    s1=tinhgiatri(&l1,x1);
    cout<<"P(x1)= "<<s1;
    cout<<"\n nhap gia tri cua x2 = ";cin>>x2;
    s2=tinhgiatri(&l2,x2);
    cout<<"Q(x2)= "<<s2;
    /*------------cong-------------------*/
    list l3; 
    init(&l3);
    l3=congdathuc(&l1,&l2,&l3);  
    cout<<"\n---------------------\n";
    cout<<"\n\n S(x)= P(x)+ Q(x) = ";
    inra(&l3);
    /*------------tru----------------*/
    list l4; 
    init(&l4);
    l4=hieudathuc(&l1,&l2,&l4);  
    cout<<"\n---------------------\n";
    cout<<"\n\n F(x)= P(x)- Q(x) = ";
    inra(&l4);

    /*------------tich----------------*/
    list l5; 
    l5=tichdathuc(&l1,&l2,&l5);  
    cout<<"\n---------------------\n";
    cout<<"\n\n H(x)= P(x)* Q(x) = ";
    inra(&l5);
    /*------------chia lay nguyen ---------*/

       list l6; 
    l6=chiadathuc(&l1,&l2,&l6); 
    cout<<"\n---------------------\n";
    cout<<"\n\n G(x)= P(x)/ Q(x) = ";
 
    inra(&l6);    
    
    
    
    getch();
}  

#include <iostream>

using namespace std;

struct node{
    int heso;
    int somu;
    node* next;
};
typedef node* DaThuc;
 
void KiemTra(DaThuc &dathuc){
    dathuc = new node;
    dathuc->next = NULL;
}
void Them(int heso,int somu, DaThuc &dathuc){
    if (heso==0)
        return;
    DaThuc p = dathuc;
    while(p->next!=NULL){
        p=p->next;
    }
    node* tmp = new node;
    tmp->heso = heso;
    tmp->somu = somu;
    tmp->next = NULL;
 
    p->next = tmp;
 
}
void Cong(DaThuc dathuc1,DaThuc dathuc2, DaThuc &ketqua){
    DaThuc p = dathuc1;
    DaThuc q = dathuc2;
    
    while(p->next!=NULL && q->next!=NULL){
        if (p->next->somu > q->next->somu){
            Them(p->next->heso,p->next->somu,ketqua);
            p=p->next;
        }
        else   if (p->next->somu < q->next->somu){
            Them(q->next->heso,q->next->somu,ketqua);
            q=q->next;
        }
        else{
            Them(p->next->heso + q->next->heso,p->next->somu,ketqua);
            p=p->next;
            q=q->next;
        }
    }
    while(p->next != NULL){
        Them(p->next->heso,p->next->somu,ketqua);
        p=p->next;
    }
    while(q->next != NULL){
        Them(q->next->heso,q->next->somu,ketqua);
        q=q->next;
    }
}
void Xuat(DaThuc dathuc){
    DaThuc p = dathuc->next;
    while(p!=NULL){
 
        if (p->somu==1)
            cout<<p->heso<<"x";
        else if (p->somu==0)
            cout<<p->heso;
        else
            cout<<p->heso<<"x^"<<p->somu;
        p=p->next;
        if (p!=NULL && p->heso>=0)
            cout<<"+";
 
    }
}
 
int main(){
 
    DaThuc dathuc1,dathuc2;
    
    KiemTra(dathuc1);
    KiemTra(dathuc2);
    
    int hso,smu;
    int n1,n2;
    cout<<"Nhap so he so cua da thuc 1:";
    cin>>n1;
    for(int i=1;i<=n1;i++)
    {
    	cout<<"Nhap he so cua da thuc 1:";
    	cin>>hso;
    	cout<<"Nhap so mu cua da thuc 1:";
    	cin>>smu;
    	Them(hso,smu,dathuc1);
    }

    cout<<"Nhap so he so cua da thuc 2:";
    cin>>n2;
    for(int i=1;i<=n2;i++)
    {
    	cout<<"Nhap he so cua da thuc 2:";
    	cin>>hso;
    	cout<<"Nhap so mu cua da thuc 2:";
    	cin>>smu;
    	Them(hso,smu,dathuc2);
    }   

    cout<<"Da thuc 1: ";
    Xuat(dathuc1);
    cout<<"\nDa thuc 2: ";
    Xuat(dathuc2);
    DaThuc ketqua;
    KiemTra(ketqua);
    Cong(dathuc1,dathuc2,ketqua);
    cout<<"\nDa thuc 3: ";
    Xuat(ketqua);
    return 0;
}

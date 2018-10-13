#include<stdio.h>
#include<conio.h>
 
int p[100];
int n;
 
void doiCho();
void dao();
void inRa();
void tdNguoc();
void nhapHoanVi();
 
void nhapHoanVi(int n){
  int i;
  for (i=1;i<=n;i++){
    printf("p[%d] = ",i);
    scanf("%d",&p[i]);
  }
}
 
void doiCho(int i, int j){
  int tg;
  tg=p[i];
  p[i]=p[j];
  p[j]=tg;
}
 
void dao(int m){
  int i=1;
  int j=m;
  while (i<j) {
    doiCho(i,j);
    i=i+1;
    j=j-1;
  }
}
 
void inRa(int n){
  int i;
  printf("\n\t  ");
  for (i=1;i<=n;i++)
    printf("  %d  ",p[i]);
}
 
void tdNguoc(int m){
  int i;
  if (m==1)
    inRa(n);
  else
    for(i=1;i<=m;i++){
      tdNguoc(m-1);
      if(i<m){
    doiCho(i,m);
    dao(m-1);
      }
    }
}
 
main(){
  int i;
  printf("\nNhap so phan tu cua tap hop: n= ");
  scanf("%d",&n);
  nhapHoanVi(n);
  tdNguoc(n);
  getch();
}

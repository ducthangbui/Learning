#include<stdio.h>
FILE *f1=fopen("Bai2.2.INP","r");
FILE *f2=fopen("Bai2.2.OUT","w");
int k,n,m,a[50][50],b[50][50];
void in(int h, int c, int matrix[][50]){
  for (int i=0;i<h;i++)
  {  for (int j=0;j<c;j++)
      fprintf(f2,"%d ",matrix[i][j]);
    fprintf(f2,"\n"); }
}
void chuyenvi()
{
  int i,j;
  for (i=0;i<n;i++)
    for (j=0;j<m;j++)
    b[j][i]=a[i][j];
}
void tichmatran(){
  int i,j,l,c[50][50];
  for (i=0;i<n;i++)
    for (j=0;j<n;j++)
      { c[i][j]=0;
	    for (l=0;l<m;l++)
         c[i][j]+= a[i][l]*b[l][j];
      }
  in(n,n,c);
}
main(){
  int i,j;
  fscanf(f1,"%d",&k);
  while (k--){
    fscanf(f1,"%d%d",&n,&m);
    for (i=0;i<n;i++)
       for (j=0;j<m;j++)
         fscanf(f1,"%d",&a[i][j]);
	chuyenvi();
	tichmatran();
	}
}

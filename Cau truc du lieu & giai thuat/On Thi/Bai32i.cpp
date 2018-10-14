#include <stdio.h>
#define SIZE 9 //kich thuoc o sudoku la SIZE x SIZE
#define DELTA 2
int a[SIZE+DELTA][SIZE+DELTA];
int n = SIZE;
int lastK;
 
int Nhap(); //nhap de bai sudoku
int Xuat(); //xuat bang sudoku
int Try(int k);
int isOK(int i, int j, int x); //kiem tra xem vi tri i, j dat gia tri x co hop le khong
int findLastK(); //tra ve chi so k cuoi cung ma khong phai la de bai
 
int main()
{
    printf("Nhap so lieu de bai...n");
    Nhap();
    lastK = findLastK();
    printf("De bai:n\n");
    Xuat();
    printf("Bam enter de bat dau giai...");
    getchar();
    Try(0);
    getchar();
    return 0;
}
 
int Nhap()
{
    int i, j, tmp;
    FILE *fp = NULL;
    fp = fopen("sodoku.txt", "r");
    for (i=0; i<n; i++)
    {
        //printf("Nhap %d so hang thu %d, o nao trong thi nhap 0:n", n, i+1);
        for (j=0; j<n; j++)
        {
            //scanf("%d", &tmp);
            fscanf(fp, "%d", &tmp);
            a[i][j] = tmp;
        }
    }
    fclose(fp);
    return 0;
}
 
int Xuat()
{
    int i, j;
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
            printf(" %d", a[i][j]);
        printf("\n");
    }
    return 0;
}
 
int Try(int k)
{
    int i, j, x;
    while (a[k/n][k%n]!=0) //bo qua cac o de bai
        k++;
    i = k/n; j = k%n;
    for (x=1; x<=n; x++)
        if (isOK(i, j, x)) 
        {
            a[i][j] = x;
            if (k==lastK)
                Xuat();
            else
                Try(k+1);
            a[i][j] = 0;
        }
    return 0;
}
 
int isOK(int i, int j, int x)
{
    int k, t;
    int tmpX, tmpY;
    //kiem tra hang thu i da co cai nao trung chua
    for (k=0; k<n; k++)
        if (a[i][k] == x)
            return 0;
    //kiem tra cot thu j da co cai nao trung chua
    for (k=0; k<n; k++)
        if (a[k][j] == x)
            return 0;
 
    //kiem tra trong o 3x3
    tmpX = i%3; tmpY = j%3;
    for (k=i-tmpX; k<=i-tmpX+2; k++)
        for (t=j-tmpY; t<=j-tmpY+2; t++)
            if (a[k][t] == x)
                return 0;
    return 1;
}
 
int findLastK()
{
    int i, j;
    for (i=n-1; i>=0;i--)
        for (j=n-1; j>=0; j--)
            if (a[i][j]==0)
            {
                return (i*n + j);
            }
}  

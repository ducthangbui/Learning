
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    float A[10][10], det=1, a, b;
    int n, i, j, k;
    do{
        cout << "Nhap so dong, so hang: ";
        cin >> n;
    }while (n<1||n>10);
    for (i=0;i<n;i++)
        for (j=0;j<n;j++){
            cout << "A[" << i << "][" << j << "]:";
            cin >> A[i][j];
        }
    for (i=0;i<(n-1);i++)
    {
        if(A[i][i]==0) //xet cac phan tu thuoc duong cheo chinh
        {
            k=i+1;
            while ((k<n)&&(A[k][i]==0))
                k++;
            if (k>(n-1))
            {
                det=0;
                break;
            }
            else //neu co A[k][i] khac 0 thi thuc hien viec doi cho 2 hang k va i
            {
                det=-det;
                for (j=i;j<n;j++)
                {
                    float tmp=A[i][j];
                    A[i][j]=A[k][j];
                    A[k][j]=tmp;
                }
            }
        }
        for (k=i+1;k<n;k++) //dua ma tran ve ma tran tam giac tren
        {
            float a=-A[k][i]/A[i][i];
            for (j=i;j<n;j++)
                A[k][j]+=a*A[i][j];
        }
    }
    for (i=0;i<n;i++)
        det *=A[i][i];
    cout << "Dinh thuc cua A = " << det << endl;
    system("pause");
    return 0;
}

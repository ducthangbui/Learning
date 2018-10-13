/*Eratosthene*/
#include <iostream>
#include <math.h>
using namespace std;

const int TRUE=1;
const int FALSE=0;

int main()
{
    int n;
    cout<<"Enter n = ";
    cin>>n;
    int *prime;
    prime = new int [n+1];
    int i;
    for ( i=1; i <= n; i++) prime[i]=TRUE;
    prime[1]=FALSE;
    int k=0,m=sqrt(n),j;
    while (k<m)
    {
        i=k+1;                    
        while (prime[i]==FALSE) i++;
        k=i;
        j=2;
        prime[k]=TRUE;
        while (k*j<=n)
        {
            prime[k*j]= FALSE;
            j++;
        }
    }
    for (i=1; i <= n; i++)
        if (prime[i]==TRUE) cout<<"   "<<i;
    delete[] prime;
}

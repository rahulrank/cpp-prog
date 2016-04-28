#include <iostream>

using namespace std;
void quicksort(int[][20],int,int,int);
void swaap(int[][20],int,int,int);
int partit(int[][20],int,int,int);
int main()
{
    int a[20][20],s[20],avg[20],n,i,t,j,z;
    cout << "enter t:" << endl;
    cin >> t;
    for(i=0;i<t;i++)
    {
        s[i]=0;
        do
        {
          cin >> n >> z;
          if(2*z>=n)
          cout << "n must be greater than 2z" << endl;
        }while(2*z>=n);
        cout << "enter array" << endl;
        for(j=0;j<n;j++)
        cin >> a[i][j];
        quicksort(a,i,0,j-1);
        for(j=z;j<n-z;j++)
        {
           s[i] = s[i] + a[i][j];
           avg[i]=s[i]/(n-2*z);
        }
    }
    for(i=0;i<t;i++)
    cout << avg[i] << endl;
    return 0;
}

void quicksort(int a[][20], int i, int p, int r)
{
    int q;
    if(p<r)
    {
       q = partit(a, i, p, r);
       quicksort(a, i, p, q-1);
       quicksort(a, i, q+1, r);
    }
}

int partit(int a[][20], int i, int p, int r)
{
    int j,x;
    x = a[i][r];
    for(j=p;j<r;j++)
    {
       if(a[i][j]<=x)
       {
          if(j!=p)
          swaap(a,i,j,p);
          p++;
       }
    }
    swaap(a,i,r,p);
    return p;
}

void swaap(int a[][20], int i, int x, int y)
{
     int t;
     t = a[i][x];
     a[i][x] = a[i][y];
     a[i][y] = t;
}

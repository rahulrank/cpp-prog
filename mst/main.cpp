#include <iostream>

using namespace std;

const int mx = 999;

int findmin(int key[],bool e[],int n)
{
    int mk,m=mx;
    for(int i=0;i<n;i++)
    {
        if(e[i]==true && m>=key[i])
        {
            mk=i;
            m=key[i];
        }
    }
    e[mk]=false;
    return mk;
}

void primTree(int *g,int n)
{                                  //p[n] for saving parent info of node, key[n] to store key value, e[n] for checking if
    int p[n],key[n],m,v;           //node is in queue or not
    int cnt = n;
    bool e[n];
    for(int i=0; i<n;i++)
    {
        key[i]=mx;
        e[i]=true;
    }
    key[0]=0;
    p[0]=0;
    while(cnt!=0)
    {
        m=findmin(key,e,n);
        for(int i=0;i<n;i++)
        {
            v=(*(g+m*n+i));
            if(v!=mx && i!=m && v<key[i])
            {
               key[i]=v;
               p[i]=m;
            }
        }
        --cnt;
    }
    for(int i=0;i<n;i++)
    {
     for(int j=0;j<n;j++)
     {
        if(p[j]==i || i==j)
        cout<<(*(g+i*n+j))<<" ";
        else
        cout<<"NIL"<<" ";
     }
     cout<<endl;
    }
}


int main()
{
    int g[4][4] = {{0,4,999,10},{4,0,7,5},{999,7,0,15},{10,5,15,0}};
    cout<<"hello world"<<endl;
    primTree((int *)g,4);
    return 0;
}

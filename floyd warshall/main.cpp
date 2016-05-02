#include <iostream>
#include <vector>

using namespace std;

const int MAX = 999;

class FW
{
    vector<vector<int>> m;
    int n;

    public:
    FW(int x)
    {
        n=x;
        m.resize(n);
        for(int i=0;i<n;i++)
            m[i].resize(n, MAX);
    }

    void setValue();
    void findminDistance();
    int findmin(int, int);
};

void FW::setValue()
{
    int w;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                m[i][j]=0;
                continue;
            }
            cout<<"enter m["<<i<<"]["<<j<<"]"<<endl;
            cin>>w;
            if(w==999)
            continue;
            else
            m[i][j]=w;
        }
}

void FW::findminDistance()
{
    vector<vector<int>> d;
    vector<vector<int>> *temp;
    vector<vector<int>> *a = &m;
    vector<vector<int>> *b = &d;
    d.resize(n);
    for(int i=0;i<n;i++)
        d[i].resize(n, 0);
     for(int i=0;i<n;i++)
     {
            for(int j=0;j<n;j++)
               cout<<(*a)[i][j]<<" ";
            cout<<endl;
     }

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                (*b)[i][j] = findmin((*a)[i][k]+(*a)[k][j],(*a)[i][j]);
        temp = a;
        a = b;
        b = temp;
    }
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<n;j++)
               cout<<(*a)[i][j]<<" ";
            cout<<endl;
    }
}

int FW::findmin(int a, int b)
{
    if(a<b)
    return a;
    else
    return b;
}

int main()
{
    int n;
    cout<<"Enter number of vertices:";
    cin>>n;
    FW g(n);
    g.setValue();
    g.findminDistance();
    return 0;
}

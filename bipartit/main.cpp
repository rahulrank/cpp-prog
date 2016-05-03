#include <iostream>
#include <list>

using namespace std;
enum Color
{
    BLACK,
    RED,
    BLUE
};
class Graph
{
    int v;
    list<int> *adj;

    public:

    Graph(int x)
    {
        v=x;
        adj = new list<int>[v];
    }
    ~Graph()
    {
        delete[] adj;
    }

    void addEdge(int,int);
    bool isBipartit();
};

void Graph::addEdge(int a, int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}

bool Graph::isBipartit()
{
    int i,n;
    Color c[v],nc;
    list<int> s;
    for(i=0;i<v;i++)
    {
        c[i] = BLACK;
    }
    i=0;
    s.push_back(i);
    c[i]=RED;
    while(!s.empty())
    {
        n=s.back();
        s.pop_back();
        if(c[n]==RED)
        nc=BLUE;
        else
        nc=RED;
        for(auto x : adj[n])
        {
            if(c[x]==BLACK)
            {
                s.push_back(x);
                c[x]=nc;
            }
            else if(c[x]==c[n])
                return false;
        }
    }

    for(i=0;i<v;i++)
    {
        if(c[i]==BLACK)
        return false;
    }
    return true;
}

int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(0,4);
    if(g.isBipartit())
    cout<<"Graph is Bipartit";
    else
    cout<<"Graph is not Bipartit";
    return 0;
}

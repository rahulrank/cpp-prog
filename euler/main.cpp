#include <iostream>
#include <list>

using namespace std;

class Graph
{
    list<int> *adj;
    int v;

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

    void addEdge(int, int);
    bool isConnected();
    int isEulerian();
    void test();
};

void Graph::addEdge(int a, int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}

bool Graph::isConnected()
{
    bool visited[v], seen[v];
    list<int> s;
    int i,n;
    for(i=0;i<v;i++)
    {
        visited[i] = false;
        seen[i] = false;
    }
    for(i=0;i<v;i++)
        if(adj[i].size()!=0)
        break;
    if(i==v)
    return true;
    s.push_back(i);
    seen[i] = true;
    while(!s.empty())
    {
        n=s.back();
        s.pop_back();
        visited[n] = true;
        for(auto x : adj[n])
        {
            if(!seen[x])
            {
                s.push_back(x);
                seen[x] = true;
            }
        }
    }

    for(i=0;i<v;i++)
        if(visited[i]==false && adj[i].size()>0)
            return false;
    return true;
}

int Graph::isEulerian()
{
    if(isConnected()==false)
    return 0;
    int odd=0;
    for(int i=0;i<v;i++)
        if(adj[i].size() & 1)
            odd++;
    if(odd>2)
    return 0;
    return (odd) ? 1 : 2;
}

void Graph::test()
{
    if(isEulerian()==0)
        cout<<"Graph is not Eulerian";
    else if(isEulerian()==1)
        cout<<"Graph has Eulerian path";
    else
        cout<<"Graph has Eulerian Cycle";
}

int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,1);
    g.addEdge(0,3);
    g.addEdge(3,4);
    g.test();
    return 0;
}

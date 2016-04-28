#include <iostream>
#include<list>
#include<stack>

using namespace std;

class Graph
{
    private:
        int v;
        list<int> *adj;

    public:

        Graph(int v)
        {
            this->v = v;
            adj = new list<int>[v];
        }

        ~Graph()
        {
            delete[] adj;
        }

        void addEdge(int v, int w);
        void bfs(int s, bool visited[]);
        void dfs(int s, bool visited[]);
        bool isConnected();
        Graph getTranspose();
        void fillOrder(int v, bool visited[], stack<int> &stk);
        int printSSC();
        bool isCyclic();
        bool isCyclicUtil(int s, bool visited[], bool rec[]);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

Graph Graph::getTranspose()
{
    Graph g(v);
    list<int>::iterator i;
    for(i=adj[v].begin(); i!=adj[v].end(); i++)
        g.adj[*i].push_back(v);
    return g;
}

void Graph::fillOrder(int s, bool visited[], stack<int> &stk)
{
    visited[s]  = true;
    list<int>::iterator i;
    for(i=adj[s].begin(); i!=adj[s].end(); i++)
        if(!visited[*i])
            fillOrder(*i, visited, stk);
    stk.push(s);
}

void Graph::bfs(int s, bool visited[])
{
    list<int> q;
    visited[s] = true;
    list<int>::iterator i;
    q.push_back(s);
    while(!q.empty())
    {
        s = q.front();
        q.pop_front();
        for(i=adj[s].begin(); i!=adj[s].end(); i++)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                q.push_back(*i);
            }
        }
    }
}

void Graph::dfs(int s, bool visited[])
{
    list<int>::iterator i;
    visited[s] = true;
    cout<<s<<" ";
    for(i=adj[s].begin(); i!=adj[s].end(); i++)
        if(!visited[*i])
            dfs(*i, visited);
}

int Graph::printSSC()
{
    stack<int> stk;
    int a, c=0;
    bool visited[v];
    for(int i=0; i<v; i++)
        visited[i] = false;
    for(int i=0; i<v; i++)
        if(!visited[i])
            fillOrder(i, visited, stk);
    Graph g = getTranspose();
    for(int i=0; i<v; i++)
        visited[i] = false;
    while(!stk.empty())
    {
        a = stk.top();
        stk.pop();
        if(!visited[a])
        {
            g.dfs(a, visited);
            cout<<endl;
            c++;
        }
    }
    return c;
}

bool Graph::isConnected()
{
    bool visited[v];
    for(int i = 0; i<v; i++)
        visited[i] = false;
    bfs(0, visited);
    for(int i =0; i<v; i++)
        if(visited[i]==false)
            return false;
    return true;
}

bool Graph::isCyclic()
{
    bool visited[v];
    bool rec[v];
    for(int i=0; i<v; i++)
    {
        visited[i]=false;
        rec[v]=false;
    }

    for(int i=0; i<v; i++)
    {
        if(isCyclicUtil(i, visited, rec))
            return true;
    }
    return false;
}

bool Graph::isCyclicUtil(int s, bool visited[], bool rec[])
{
    if(!visited[s])
    {
        visited[s]=true;
        rec[s]=true;
        list<int>::iterator i;
        for(i=adj[s].begin(); i!=adj[s].end(); i++)
        {
            if(!visited[*i])
            {
                if(isCyclicUtil(*i, visited, rec))
                    return true;
            }
            else if(rec[*i])
                return true;
        }
    }
    rec[s] = false;
    return false;
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    if(g.isCyclic())

        cout<<"The Graph is Cyclic"<<endl;

    else

        cout<<"The Graph is not Cyclic"<<endl;

    bool visited[4]{false,false,false,false};
    g.dfs(0,visited);
    return 0;
}

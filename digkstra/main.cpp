#include <iostream>
#include <vector>
#include <list>
#include <limits>

using namespace std;

const int MAX = numeric_limits<int>::max();
struct node;
struct edge
{
    node *from;
    node *to;
    int cost;
};
struct node
{
    int no;
    int key;
    node *p;
    list<edge *> *e = nullptr;
};

class Graph
{
    int n;
    vector<node *> v;
    vector<edge> ed;
    list<edge *> *el;

    public:

    Graph(int x)
    {
        n = x;
        node *q;
        v.resize(n);
        ed.reserve(n);
        el = new list<edge *>[n];
        for(int i=0;i<n;i++)
        {
            q = new node;
            q->no = i;
            q->key = MAX;
            q->p = nullptr;
            q->e = &el[i];
            v[i] = q;
        }
    }

    ~Graph()
    {
        delete[] el;
    }

    void addEdge(int,int,int);
   // void display();
    void minHeapify(int,int);
    void dijkstraPath();
};

void Graph::addEdge(int a, int b, int c)
{
    edge x;
    x.from = v[a];
    x.to = v[b];
    x.cost = c;
    ed.push_back(x);
    el[a].push_back(&ed.back());
}

void Graph::minHeapify(int i, int s)
{
    int l,r,mn;
    node *temp;
    l=2*i+1;
    r=2*i+2;
    mn = i;
    if(l<=s && v[l]->key<v[i]->key)
        mn = l;
    if(r<=s && v[r]->key<v[mn]->key)
    mn = r;
    if(mn!=i)
    {
        temp = v[mn];
        v[mn] = v[i];
        v[i] = temp;
        minHeapify(mn, s);
    }
}

void Graph::dijkstraPath()
{
    node *u;
    node *temp;
    int j=1;
    v[0]->key = 0;
    for(int i=0;i<n;i++)
    {
        minHeapify(0, n-j);
        u=v[0];
        for(auto a : *(u->e))
        {
            if((a->to)->key > u->key + a->cost)
            {
                (a->to)->key = u->key + a->cost;
                a->to->p = u;
            }
        }
        temp = v[n-j];
        v[n-j] = v[0];
        v[0] = temp;
        j++;
    }
    cout<<"Distance from source node 0"<<endl;
    cout<<"node distance"<<endl;
    for(auto a : v)
    cout<<a->no<<"      "<<a->key<<endl;
}

//void Graph::display()
//{
//    cout<<((v[0].e)->back())->cost;   ((v[0].e)->back())->cost; --> To access struct element of node
//}

int main()
{
    Graph g(5);
    g.addEdge(0,1,10);
    g.addEdge(0,2,5);
    g.addEdge(1,2,2);
    g.addEdge(1,3,1);
    g.addEdge(2,4,2);
    g.addEdge(2,3,9);
    g.addEdge(2,1,3);
    g.addEdge(4,3,6);
    g.addEdge(3,4,4);
    g.addEdge(4,0,7);
    g.dijkstraPath();
    return 0;
}

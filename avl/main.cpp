#include <iostream>

using namespace std;

struct node
{
    int key;
    int w;
    node *leftc;
    node *rightc;
    node *parent;
};

class Tree
{
    node *root;
    public:

    Tree()
    {
        root = nullptr;
    }
    void addNode(int);
    void deleteNode(int);
    void binarySearch(node *);
    void balance(node *);
    void rotation(node *, node *, node *);
};

void Tree::addNode(int x)
{
    node *temp = root;
    node *prev;
    bool c;
    node *n = new node;
    n->key = x;
    n->w = 0;
    n->leftc = nullptr;
    n->rightc = nullptr;
    n->parent = nullptr;
    if(root==nullptr)
        root = n;
    else
    {
        while(temp!=nullptr)
        {
            prev = temp;
            if(n->key>=temp->key)
            {
                temp = temp->rightc;
                c = true;
            }

            else
            {
                temp = temp->leftc;
                c = false;
            }
        }
        n->parent = prev;
        if(c)
        prev->rightc = n;
        else
        prev->leftc = n;
        balance(n);
    }
}

void Tree::balance(node *n)
{
    node *p, *g, *u, *m, *l;
    bool c = false;
    int pv=0;
    l=n;
    p = n->parent;
    g = n->parent;
    if(p->w !=0)
    {
        p->w = 0;
        return;
    }
    else
    {
        if(n == p->leftc)
        p->w = -1;
        else
        p->w = 1;
        while(pv == 0 || p != root)
        {
            u=g;
            m=p;
            if(c)
                l=l->parent;  // lift up l only after 1st iteration.
            pv = g->w;
            if(p == g->leftc)
            g->w = pv-1;
            else
            g->w = pv+1;
            p=g;
            g=g->parent;
            c = true;
        }
        if(p->w != 2 && p->w != -2)
        return;
        else
        {
            rotation(u,m,l);
        }
    }
}

void Tree::rotation(node *u, node *m, node *l)
{
    if(m == u->leftc && l == m->leftc)
    {
        m->parent = u->parent;
        m->rightc = u;
    }
    else if(m == u->rightc && l == m->rightc)
    {
        m->parent = u->parent;
        m->leftc = u;
    }
    else if(m == u->leftc && l == m->rightc)
    {

    }
    else
    {
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

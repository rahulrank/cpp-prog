#include <iostream>

using namespace std;

struct node
{
    int key;
    int w;
    int lh;
    int rh;
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
    void updateHight(node *);
    int hight(node *);
};

void Tree::addNode(int x)
{
    node *temp = root;
    node *prev;
    bool c;
    node *n = new node;
    n->key = x;
    n->w = 0;
    n->lh = 0;
    n->rh = 0;
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
        {
            prev->rightc = n;
            prev->rh = 1;
        }
        else
        {
            prev->leftc = n;
            prev->lh = 1;
        }
        prev->w = prev->rh - prev->lh;
        balance(prev);
    }
}

void Tree::balance(node *n)
{
    node *u, *m, *l;
    if(n->w ==0)
        return;
    else
    {
        while(n->w != 2 && n->w != -2 && n != root)
        {
            n = n->parent;
            updateHight(n);
        }
        if(n->w != 2 && n->w != -2)
        return;
        else
        {
            u = n;
            if(n->w == -2)
            m = u->leftc;
            else
            m = u->rightc;
            if(m->w < 0)
            l = m->leftc;
            else
            l = m->rightc;
            rotation(u,m,l);
        }
    }
}

void Tree::rotation(node *u, node *m, node *l)
{
    if(m == u->leftc && l == m->leftc)
    {
        m->parent = u->parent;
        if(u->parent != nullptr)
        {
            if(u == m->parent->leftc)
            m->parent->leftc = m;
            else
            m->parent->rightc = m;
        }
        u->leftc = m->rightc;
        if(u->leftc != nullptr)
        u->leftc->parent = u;
        m->rightc = u;
        u->parent = m;
        if(u == root)
        root == m;
        while(u != nullptr)
        {
            updateHight(u);
            u = u->parent;
        }
    }
    else if(m == u->rightc && l == m->rightc)
    {
        m->parent = u->parent;
        if(u->parent != nullptr)
        {
            if(u == m->parent->leftc)
            m->parent->leftc = m;
            else
            m->parent->rightc = m;
        }
        u->rightc = m->leftc;
        if(u->rightc != nullptr)
        u->rightc->parent = u;
        m->leftc = u;
        u->parent = m;
        if(u == root)
        root == m;
        while(u != nullptr)
        {
            updateHight(u);
            u = u->parent;
        }
    }
    else if(m == u->leftc && l == m->rightc)
    {
        l->parent = u->parent;
        if(u->parent != nullptr)
        {
            if(u == l->parent->leftc)
            l->parent->leftc = l;
            else
            l->parent->rightc = l;
        }
        m->rightc = l->leftc;
        if(m->rightc != nullptr)
        m->rightc->parent = m;
        u->leftc = l->rightc;
        if(u->leftc != nullptr)
        u->leftc->parent = u;
        l->leftc = m;
        m->parent = l;
        l->rightc = u;
        u->parent = l;
        if(u == root)
        root == l;
        updateHight(m);
        while(u != nullptr)
        {
            updateHight(u);
            u = u->parent;
        }
    }
    else
    {
        l->parent = u->parent;
        if(u->parent != nullptr)
        {
            if(u == l->parent->leftc)
            l->parent->leftc = l;
            else
            l->parent->rightc = l;
        }
        m->leftc = l->rightc;
        if(m->leftc != nullptr)
        m->leftc->parent = m;
        u->rightc = l->leftc;
        if(u->rightc != nullptr)
        u->rightc->parent = u;
        l->rightc = m;
        m->parent = l;
        l->leftc = u;
        u->parent = l;
        if(u == root)
        root == l;
        updateHight(m);
        while(u != nullptr)
        {
            updateHight(u);
            u = u->parent;
        }
    }
}

int Tree::hight(node *n)
{
    if(n == nullptr)
    return 0;
    else
    {
        if(n->lh>n->rh)
        return n->lh + 1;
        else
        return n->rh + 1;
    }
}

void Tree::updateHight(node *n)
{
    n->lh = hight(n->leftc);
    n->rh = hight(n->rightc);
    n->w = n->rh - n->lh;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

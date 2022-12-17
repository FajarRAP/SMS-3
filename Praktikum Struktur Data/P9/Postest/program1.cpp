#include <iostream>
#include "lqueue.h"
#include "btnode.h"
#include "xcept.h"
template <class T>
void Visit(BinaryTreeNode<T> *x)
{
    std::cout << x->data << ' ';
}
template <class T>
void PreOrder(BinaryTreeNode<T> *t)
{
    if (t)
    {
        Visit(t);
        PreOrder(t->LeftChild);
        PreOrder(t->RightChild);
    }
}
template <class T>
void InOrder(BinaryTreeNode<T> *t)
{
    if (t)
    {
        InOrder(t->LeftChild);
        Visit(t);
        InOrder(t->RightChild);
    }
}
template <class T>
void PostOrder(BinaryTreeNode<T> *t)
{
    if (t)
    {
        PostOrder(t->LeftChild);
        PostOrder(t->RightChild);
        Visit(t);
    }
}
template <class T>
void LevelOrder(BinaryTreeNode<T> *t)
{
    LinkedQueue<BinaryTreeNode<T> *> Q;
    while (t)
    {
        Visit(t);
        if (t->LeftChild)
            Q.Add(t->LeftChild);
        if (t->RightChild)
            Q.Add(t->RightChild);
        try
        {
            Q.Delete(t);
        }
        catch (OutOfBounds)
        {
            return;
        }
    }
}
int main()
{
    BinaryTreeNode<char> h, p, a, f, q, g, t, e, m, r, d, j;
    h.bikinPohon('H', 0, 0);
    p.bikinPohon('P', 0, 0);
    g.bikinPohon('G', &h, &p);
    a.bikinPohon('A', 0, 0);
    f.bikinPohon('F', 0, 0);
    t.bikinPohon('T', &a, &f);
    r.bikinPohon('R', &g, &t);
    q.bikinPohon('Q', 0, 0);
    e.bikinPohon('E', 0, &q);
    m.bikinPohon('M', 0, 0);
    d.bikinPohon('D', &e, &m);
    j.bikinPohon('J', &r, &d);
    std::cout << "Kunjungan Inorder     : ";
    InOrder(&j);
    std::cout << std::endl;
    std::cout << "Kunjungan Preorder    : ";
    PreOrder(&j);
    std::cout << std::endl;
    std::cout << "Kunjungan Postorder   : ";
    PostOrder(&j);
    std::cout << std::endl;
    std::cout << "Kunjungan Level order : ";
    LevelOrder(&j);
    std::cout << std::endl;
    return 0;
}
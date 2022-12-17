#ifndef __btnode
#define __btnode

// template <class T>
// class BinaryTree;
template <class T>
class BinaryTreeNode
{
    // friend void Visit(BinaryTreeNode<T> *);
    // friend void InOrder(BinaryTreeNode<T> *);
    // friend void PreOrder(BinaryTreeNode<T> *);
    // friend void PostOrder(BinaryTreeNode<T> *);
    // friend void LevelOrder(BinaryTreeNode<T> *);
    // friend void main(void);

public:
    BinaryTreeNode() { LeftChild = RightChild = 0; }
    BinaryTreeNode(const T &e)
    {
        data = e;
        LeftChild = RightChild = 0;
    }
    BinaryTreeNode(const T &e, BinaryTreeNode *l,
                   BinaryTreeNode *r)
    {
        data = e;
        LeftChild = l;
        RightChild = r;
    }

    void bikinPohon(const T &e, BinaryTreeNode *l,
                    BinaryTreeNode *r)
    {
        data = e;
        LeftChild = l;
        RightChild = r;
    }

    // private:
    T data;
    BinaryTreeNode<T> *LeftChild, *RightChild;
};

#endif
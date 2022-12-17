#ifndef __node
#define __node

template <typename T>
class Node
{
public:
    T data;
    Node<T> *berikut;
    Node<T> *sebelum;
};

template <typename T>
Node<T> *calo(T &data)
{
    Node<T> *temp = new Node<T>();
    temp->data = data;
    temp->berikut = 0;
    temp->sebelum = 0;
    return temp;
}

#endif
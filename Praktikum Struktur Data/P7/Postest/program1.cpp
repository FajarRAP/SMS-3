#include <iostream>
#include "Node.hpp"
Node<char> *kepala, *ekor, *tambah, *hapus, *jalan;
#include "QueueDLL.hpp"

int main()
{
    QueueDLL<char> queue;
    queue.enqueue('F');
    queue.enqueue('A');
    queue.enqueue('T');
    queue.deque();
    queue.display();
    return 0;
}
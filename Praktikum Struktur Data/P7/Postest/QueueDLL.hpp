#ifndef __dll
#define __dll
#include "Node.hpp"

template <typename T>
class QueueDLL
{
public:
    ~QueueDLL()
    {
        for (jalan = kepala; jalan != 0;)
        {
            hapus = jalan;
            jalan = jalan->berikut;
            delete hapus;
        }
    }

    void enqueue(T data)
    {
        if (isEmpty())
        {
            kepala = calo(data);
            kepala->berikut = 0;
            kepala->sebelum = 0;
            ekor = kepala;
            return;
        }
        tambah = calo(data);
        ekor->berikut = tambah;
        tambah->sebelum = ekor;
        ekor = tambah;
    }

    void deque()
    {
        hapus = kepala;
        kepala = kepala->berikut;
        kepala->sebelum = 0;
        delete hapus;
    }

    void display()
    {
        for (jalan = kepala; kepala != 0; kepala = kepala->berikut)
        {
            std::cout << kepala->data << " ";
        }
    }

    void clear()
    {
        for (jalan = kepala; jalan != 0;)
        {
            hapus = jalan;
            jalan = jalan->berikut;
            delete hapus;
        }
        kepala = 0;
        ekor = 0;
    }

    bool isEmpty()
    {
        return kepala == 0;
    }

    T getFront()
    {
        return kepala->data;
    }

    T getRear()
    {
        return ekor->data;
    }
};

#endif
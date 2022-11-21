#include<iostream>

template <typename T>
class List;

template <typename T>
class Node{
    friend class List<T>;
    friend std::ostream &operator<<(std::ostream &, const List<T> &);
    public:
        Node(T &t, Node<T> *p) : info(t), berikut(p){}
    protected:
        T info;
        Node *berikut;
};

template <typename T>
class List{
    friend std::ostream &operator<<(std::ostream &, const List<T> &);
    public:
        List() : kepala(0){}
        ~List();
        void sisip(T t);
        int hapus(T &t);
        int kosong(){return (kepala == 0);}
        void cetak();
    protected:
        Node<T> *kepala;
        Node<T> *nodeBaru(T &t, Node<T> *p){
            Node<T> *q = new Node<T>(t, p);
            return q;
        }
};

template<typename T>
std::ostream &operator<<(std::ostream &out, const List<T> &obj){
    for(Node<T> *p = obj.kepala; p; p = p->berikut){
        out<<p->info<<"->";
    }
    out<<"*\n";
    return out;
}

template <typename T>
List<T>::~List(){
    Node<T> *temp;
    for(Node<T> *p = kepala; p;){
        temp = p;
        p = p->berikut;
        delete temp;
    }
}

template <typename T>
void List<T>::sisip(T t){
    std::cout<<t<<" Masuk list : ";
    Node<T> *p = nodeBaru(t, kepala);
    kepala = p;
}

template <typename T>
int List<T>::hapus(T &t){
    if(kosong()){
        return 0;
    }
    t = kepala->info;
    Node<T> *p = kepala;
    kepala = kepala->berikut;
    delete p;
    return 1;
}

template <typename T>
void List<T>::cetak(){
    for(Node<T> *p = kepala; p; p = p->berikut){
        std::cout<<p->info<<"->";
    }
    std::cout<<"*\n";
}

int main(){
    List<char> x;
    return 0;
}
#include<iostream>

class Node{
    public:
        int data;
        Node *next;
        Node *prev;
};

Node *head, *tail, *jalan, *hapus, *temp;

void tambahBelakang(int data){
    Node *temp = new Node();
    if(head == 0){
        head = new Node();
        head->data = data;
        head->next = 0;
        head->prev = 0;
        tail = head;
        return;
    }
    temp->data = data;
    temp->next = 0;
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}

void tambahDepan(int data){
    Node *temp = new Node();
    if(head == 0){
        head = new Node();
        head->data = data;
        head->next = 0;
        head->prev = 0;
        tail = head;
        return;
    }
    temp->data = data;
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void hapusBelakang(){
    hapus = tail;
    tail = tail->prev;
    tail->next = 0;
    delete hapus;
}

void hapusDepan(){
    hapus = head;
    head = head->next;
    head->prev = 0;
    delete hapus;
}

void tambahTengah(int data, int posisi){
    Node *temp = new Node();
    int n = 0;
    for(jalan = head; jalan != 0; jalan = jalan->next){
        if(n == posisi - 1){
            break;
        }
        n++;
    }
    // std::cout<<jalan->next->data<<std::endl;
    temp->data = data;
    temp->next = jalan->next;
    temp->prev = jalan;
    jalan->next->prev = temp;
    jalan->next = temp;
}

void hapusTengah(int posisi){
    Node *temp = new Node();
    int n = 0;
    for(jalan = head; jalan != 0; jalan = jalan->next){
        if(n == posisi - 2){            
            break;
        }
        n++;
    }
    hapus = jalan->next;
    temp = hapus->next;
    jalan->next = temp;
    temp->prev = jalan;
    hapus->next = 0;
    hapus->prev = 0;
    delete hapus;
}

void cetakMaju(){
    for(jalan = head; jalan != 0; jalan = jalan->next){
        std::cout<<jalan->data<<" ";
    }
    std::cout<<std::endl;
}

void cetakMundur(){
    for(jalan = tail; jalan != 0; jalan = jalan->prev){
        std::cout<<jalan->data<<" ";
    }
    std::cout<<std::endl;
}

int getLen(){
    int n = 0;
    for(jalan = head; jalan != 0; jalan = jalan->next){
        n++;
    }
    return n;
}

int main(){
    tambahBelakang(3);
    tambahBelakang(2);
    tambahBelakang(4);
    tambahBelakang(8);
    tambahBelakang(6);
    tambahDepan(20);
    tambahDepan(11);
    // hapusBelakang();
    // hapusDepan();
    // tambahTengah(5, 3);
    hapusTengah(3);
    cetakMaju();
    cetakMundur();
    return 0; 
}
#include <iostream>
#include <assert.h>
#include <vector>

using namespace std;

class D_Node
{
public:
    D_Node(int);
    ~D_Node();

    void set(D_Node* , D_Node*);

    int data {};

    D_Node* next = nullptr;
    D_Node* prev = nullptr;
    
private:


};

D_Node::D_Node(int data) : data(data){

}

D_Node::~D_Node(){

}

void D_Node::set(D_Node* next , D_Node* prev){

    this->next = next;

    this->prev = prev;
}

class DoublyLinkedList
{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insert_end_v1(int);
    void insert_end_v2(int);
    void insert_front(int);
    void insert_sorted(int);
    void embed_after(D_Node* , int);
    void link(D_Node*,D_Node*);
    void delete_front();
    void delete_end();
    void delete_wiht_key(int);
    void delete_all_nodes_wiht_key(int);
    D_Node* delete_and_link(D_Node*);
    void delete_node(D_Node*);
    void print();
    void delete_even_positions();
    bool is_palindorme();
    int find_middle();
private:

    D_Node* head {};

    D_Node* tail {};

    int lenght {};

    vector<D_Node*> debug_data;

};

DoublyLinkedList::DoublyLinkedList(){}

DoublyLinkedList::~DoublyLinkedList(){

}

void DoublyLinkedList::insert_end_v1(int value){

    D_Node* item = new D_Node(value);

    if(!head){

        head = tail = item;

        head ->prev = nullptr;
    }

    tail->next = item;

    item ->prev = tail;

    tail = item;

    ++lenght;
}

void DoublyLinkedList::insert_end_v2(int value){

    D_Node* item = new D_Node(value);

    if(!head)
        head = tail = item;

    else {
        link(tail , item);

        tail = item;
    }
    ++lenght;
}

void DoublyLinkedList::insert_front(int value){

    D_Node* item = new D_Node(value);

    if(!head)
        head = tail = item;

    else {

        link(item , head);

        head = item;
    }

    ++lenght;
}

void DoublyLinkedList::insert_sorted(int value){

    if(!lenght || value <= head->data)
        insert_front(value);

    else if(tail->data <= value)
        insert_end_v2(value);

    else{

        for(D_Node* cur = head ; cur ; cur = cur->next){

            if(cur->data >= value){

                embed_after(cur->prev , value);
                break;
            }
        }
    }

    ++lenght;
}

void DoublyLinkedList::embed_after(D_Node* node_before , int value){

    D_Node* middle = new D_Node(value);
    ++lenght;

    D_Node* node_after = node_before->next;

    link(node_before , middle);
    link(middle , node_after);
}

void DoublyLinkedList::link(D_Node* first , D_Node* second){

    if(first)
        first->next = second;

    if(second)
        second->prev = first;
}

void DoublyLinkedList::delete_front(){

    if(!head)
        return;

    D_Node* cur = head ->next;

    delete head;

    --lenght;

    head = cur;

    if(head)
        head->prev = nullptr;

    else if(!lenght)
        tail = nullptr;
}

void DoublyLinkedList::delete_end(){

    if(!head)
        return;

    D_Node* cur = tail->prev;

    delete tail;

    --lenght;

    tail = cur;

    if(tail)
        tail->next = nullptr;

    else if(!lenght)
        head = nullptr;
} 

D_Node* DoublyLinkedList::delete_and_link(D_Node* cur){

    D_Node* ret = cur->prev;

    link(cur->prev , cur->next);

    delete cur;
    --lenght;

    return ret;
}

void DoublyLinkedList::delete_wiht_key(int value){

    if(!lenght)
        return;

    if(head->data == value)
        delete_front();

    else{

        for(D_Node* cur = head ; cur ; cur = cur->next){

            if(cur ->data == value){

                cur = delete_and_link(cur);

                if(!cur->next)
                    tail = cur;
                
                break;
            }
        }
    }
}

void DoublyLinkedList::delete_all_nodes_wiht_key(int value){

    if(!lenght)
        return;

    if(head->data == value)
        delete_front();

    else{

        for(D_Node* cur = head ; cur ; cur = cur->next){

            if(cur ->data == value){

                cur = delete_and_link(cur);

                if(!cur->next)
                    tail = cur;
            }
        }
    }
}

void DoublyLinkedList::delete_even_positions(){

    if(!head)
        return;

    D_Node* cur = head;

    while (cur && cur->next){

        delete_and_link(cur->next);

        if(!cur->next)
            tail = cur;

        cur = cur->next;
        
    }
    
}

bool DoublyLinkedList::is_palindorme(){

    assert(lenght);

    D_Node* h = head;
    D_Node* t = tail;

    while(h <= t){

        if(h->data != t->data)
            return false;

        h = h->next;
        t = t->prev;
    }

    return true;
}

int DoublyLinkedList::find_middle(){

    assert(lenght);

    D_Node* h = head;
    D_Node* t = tail;

    while(h < t){

        h = h->next;
        t = t->prev;
    }

    return h->data;

}

void DoublyLinkedList::print(){

    assert(lenght);

    for(D_Node* cur = head ; cur ; cur = cur->next)
        cout<<cur->data<<" ";

    cout<<"\n";
}

int main(){

    return 0;
}
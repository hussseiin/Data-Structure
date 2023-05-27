#include "Head_Based_Linked_List.h"

Head_Based_Linked_List::Head_Based_Linked_List(){

}

Head_Based_Linked_List::~Head_Based_Linked_List(){

}

void Head_Based_Linked_List::add_element(int value){

    Node* item = new Node(value);

    if(!head)
        head = item;

    else{

        item -> next = head;

        head = item;
    }
}

void Head_Based_Linked_List::print(){

    for(Node* cur = head ; cur ; cur = cur->next)
        cout<<cur->data<<" ";

    cout<<"\n";
}

Node* Head_Based_Linked_List::get_tail(){

    if(!head)
        return nullptr;

    Node* cur = head;

    while(cur->next != nullptr)
        cur = cur->next;

    return cur;
}
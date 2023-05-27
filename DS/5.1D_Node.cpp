#include "D_Node.h"

D_Node::D_Node(int data) : data(data){

}

D_Node::~D_Node(){

}

void D_Node::set(D_Node* next , D_Node* prev){

    this->next = next;

    this->prev = prev;
}
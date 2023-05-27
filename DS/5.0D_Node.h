#ifndef D_NODE_H
#define D_NODE_H

#pragma once

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

#endif
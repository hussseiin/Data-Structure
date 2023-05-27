#ifndef NODE_H
#define NODE_H

#pragma once

class Node
{
public:
    Node(int);
    ~Node();

    int data;

    Node* next = nullptr;

private: 

};

#endif
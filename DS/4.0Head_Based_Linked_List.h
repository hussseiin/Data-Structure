#ifndef HEAD_BASED_LINKED_LIST_H
#define HEAD_BASED_LINKED_LIST_H

#include <iostream> 
#include "Node.h"

using namespace std;

#pragma once

class Head_Based_Linked_List
{
public:
    Head_Based_Linked_List();
    ~Head_Based_Linked_List();

    void print();

    void add_element(int);

    Node* get_tail();

private:

    Node* head {};
};

#endif
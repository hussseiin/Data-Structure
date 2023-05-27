#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "D_Node.h"
#include <iostream>
#include <assert.h>
#include <vector>

using namespace std;

#pragma once

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

#endif
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <algorithm>
#include <iostream>
#include <assert.h>
#include <sstream>
#include <vector>
#include "Node.h"

using namespace std;

#pragma once

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList& another) = delete;

    void print();
    void insert_end(int);
    void insert_front(int);
    Node* get_nth(int);
    Node* get_nth_back(int);
    int search(int);
    int improved_search(int);
    int improved_search2(int);
    void debug_verify_data_intergriy();
    string debug_to_string();
    void delete_front();
    void delete_end();
    void delete_nth(int);
    void delete_value(int);
    bool is_same(const LinkedList&);
    void swap_pairs();
    void delete_even_positions();
    void insert_sorted(int);
    void test1();
    void debug_add_node(Node*);
    void debug_remove_node(Node*);


private:

    Node* head {}; // to initialize it with "nullptr"
    
    Node* tail {};

    int length = 0;

    vector<Node*> debug_data;
};

#endif
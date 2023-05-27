#ifndef VECTOR_H
#define VECTOR_H

#include <assert.h>
#include <iostream>

using namespace std;

#pragma once

class Vector
{
public:
    Vector(int);
    ~Vector();

    void set(int , int);
    int get(int);
    int find(int);
    void print();
    int get_front();
    int get_back();
    void push_back(int);
    void expand_capacity();
    void insert(int , int);
    void right_rotate();
    void right_rotate(int);
    void left_rotate();
    int pop(int);
    int find_transposition(int);

private:

    int* arr = nullptr;

    int size = 0;

    int capacity;

};

#endif
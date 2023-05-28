#include <iostream>
#include <assert.h>

using namespace std;

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

Vector::Vector(int size) : size(size) {

    if(size < 0)
        size = 1;

    capacity = size + 10;

    arr = new int[capacity] {}; // initialize all the items with 0
}

Vector::~Vector(){

    delete [] arr;

    arr = nullptr;
}

void Vector::set(int idx , int value){

    //assert(idx >= 0 && idx < size);

    assert(idx >= 0 && idx < capacity);

    arr[idx] = value;
}

int Vector::get(int idx){

    assert(idx >= 0 && idx < size);

    return arr[idx];
}

void Vector::print(){

    for(int i = 0 ; i < size ; i++)
        cout<<arr[i]<<" ";

    cout<<"\n";
}

int Vector::find(int value){

    //for(int i = 0 ; i < size ; ++i)

    for(int i = 0 ; i < capacity ; ++i)
        if(arr[i] == value)
            return i;
    
    return -1;
}

int Vector::get_front(){

    return arr[0];
}

int Vector::get_back(){

    //return arr[size - 1];

    return arr[capacity - 1];
}

void Vector::expand_capacity(){

    capacity *= 2;

    int* arr2 = new int[capacity] {};

    for (int i = 0 ; i < size ; i++)
        arr2[i] = arr[i];

    swap(arr, arr2);

    delete [] arr2;
}

void Vector::push_back(int value){

    if(size == capacity)
        expand_capacity();

    arr[size++] = value;
}

void Vector::insert(int idx , int value){

    assert(idx >= 0 && idx < capacity);

    if(size == capacity)
        expand_capacity();

    // int* arr2 = new int[capacity];

    // for(int i = 0 ; i < idx ; i++)
    //     arr2[i] = arr[i];

    // arr2[idx] = value;

    // for(int i = idx + 1 ; i < capacity ; i++)
    //     arr2[i] = arr[i];

    for(int p = size -1 ; p >= idx ; --p)
        arr[p+1] = arr[p];

    arr[idx] = value;

    ++size;
}

void Vector::right_rotate(){

    int item = arr[size -1 ];

    for(int i = size -1 ; i > 0 ; --i)
        arr[i] = arr[i-1];

    arr[0] = item;
}

void Vector::right_rotate(int steps){

    while(steps--){

        // int item = arr[size -1 ];

        // for(int i = size -1 ; i > 0 ; --i)
        //     arr[i] = arr[i-1];

        // arr[0] = item;

        right_rotate();
    }
}

void Vector::left_rotate(){

    int item = arr[0];

    for(int i = 1 ; i < size ; ++i)
        arr[i-1] = arr[i];

    arr[size - 1] = item;
}

int Vector::pop(int idx){

    assert(idx >= 0 && idx < size);

    int item = arr[idx];

    for(int i = idx ; i < size ; i++)
        arr[i] = arr[i + 1];

    arr[size -1] = 0;

    --size;

    return item;
}

int Vector::find_transposition(int value){

    for(int i = 0 ; i < size ; ++i){

        if(arr[i] == value){

            if(i > 0){

                swap(arr[i], arr[i-1]);

                return i-1; // the position of i was changed
            }

            return i;
        }
    }

}

int main(){

    

    return 0;
}
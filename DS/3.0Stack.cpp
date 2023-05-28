#include <iostream>
#include <assert.h>
#include <stack>

using namespace std;

class Stack;
class R_Stack;
class Stack2D;

class Stack
{
public:
    Stack(int);
    ~Stack();

    void push(int);
    int pop();
    int peek();
    void display();
    bool isFull();
    bool isEmpty();

private:

    int size {};

    int top {};

    int* arr {};
};

Stack::Stack(int size) : size(size) , top(-1){

    arr = new int[size];
}

Stack::~Stack(){

}

void Stack::push(int value){

    assert(!isFull());

    arr[++top] = value;
}

int Stack::pop(){

    assert(!isEmpty());

    return arr[top--];
}

int Stack::peek(){

    assert(!isEmpty());
    
    return arr[top];
}

bool Stack::isFull(){

    return top == size -1;
}

bool Stack::isEmpty(){

    return top == -1;
}

void Stack::display(){

    for(int i = top ; i >= 0 ; i--)
        cout<<arr[i]<<" ";

    cout<<"\n";
}

class R_Stack
{
public:
    R_Stack(int);
    ~R_Stack();

    bool push(int);
    bool pop();
    int peek();
    bool isFull();
    bool isEmpty();
    void display();

private:

    int added_elements {};

    int size {};

    int* arr;
};

R_Stack::R_Stack(int size) : size(size) , added_elements(size){

    arr = new int [size];
}

R_Stack::~R_Stack(){

    delete [] arr;
}

bool R_Stack::push(int value){

    if(isFull())
        return false;
    
    arr[--added_elements] = value;

    return true;
}

bool R_Stack::pop(){

    if(isEmpty())
        return false;

    added_elements++;
    return true;
}

int R_Stack::peek(){

    if(isEmpty()) 
        return -1;

    return arr[added_elements];

}

bool R_Stack::isEmpty(){

    return added_elements == size;
}

bool R_Stack::isFull(){

    return added_elements == 0; 
}

void R_Stack::display(){

    for(int i = added_elements ; i < size ; i++)
        cout<<arr[i]<<" ";

    cout<<"\n";
}

string reverse_subwords(string line){

    string r = "";

    stack <char> s;

    for(int i = 0 ; i < line.size() ; i++){

        if(line[i] == ' '){

            int len = s.size();

            for(int j = 0 ; j < len ; j++){

                r += s.top();

                s.pop();
            }
            r += " ";
        }

        else
            s.push(line[i]);

    }

    return r;
}

int rotate(Stack& s){

    int number {} , m = 1;

    while(!s.isEmpty()){

        number += s.pop() * m;

        m *= 10;
    }

    return number;
}

int reverse_number(int number){

    Stack s(10);

    while(number){

        s.push(number % 10);

        number /= 10;
    }

    return rotate(s);
}

void valid_parentheses(string str){

    stack<char> s1;
    stack<char> s2;

    for(int i = 0 ; i < str.size() ; i++){

        if(str[i] == '(' || str[i] == '[' || str[i] == '{')
            s1.push(str[i]);

        else{
            s2.push(str[i]);

            if(s2.top() == ')')
                if(s1.top() == '(')
                    s1.pop() , s2.pop();

            else if(s2.top() == '[')
                if(s1.top() == ']')
                    s1.pop() , s2.pop();

            else if(s2.top() == '{')
                if(s1.top() == '}')
                    s1.pop() , s2.pop();
        }
    }

    if(s1.size() == s2.size())
        cout<<"Valid";
    
    else
        cout<<"Not valid";
}

string remove_duplicates(string str){

    stack<char> s;

    for(int i = 0 ; i < str.size() ; i++){

        if(s.empty())
            s.push(str[i]);

        else if(str[i] == s.top())
            s.pop();
        
        else
            s.push(str[i]);
    }

    str = "";

    while(!s.empty())
        str += s.top() , s.pop();

    return str;
}

class Stack2D {
public: 
    Stack2D::Stack2D(int);
    Stack2D::~Stack2D();

    void push(int,int);
    void pop(int);
    int peek(int);
    bool isFull();
    bool isEmpty(int);
    void display();

private:
    int start , end , size , *arr;
};

Stack2D::Stack2D(int size) : size(size) , start(-1) , end(size) {

    arr = new int[size];
}

Stack2D::~Stack2D(){

    delete [] arr;
}

void Stack2D::push(int id , int value){

    if(id == 1){
        assert(!isFull());

        arr[++start] = value;
    }

    else if(id == 2){
        assert(!isFull());

        arr[--end] = value;
    }
}

void Stack2D::pop(int id){

    if(id == 1){
        assert(!isEmpty(1));

        --start;
    }

    else if(id == 2){
        assert(!isEmpty(2));

        ++end;
    }
}

int Stack2D::peek(int id){

    if(id == 1){
        assert(!isEmpty(1));

        return arr[start];
    }

    else if(id == 2){
        assert(!isEmpty(2));

        return arr[end];
    }
}

bool Stack2D::isEmpty(int id){

    if(id == 1)
        return start == -1;

    return end == size;
}

bool Stack2D::isFull(){

    return start > end;
}

void Stack2D::display(){

    assert(!isEmpty(1));

    for(int i = 0 ; i <= start ; i++)
        cout<<arr[i]<<" ";

    assert(!isEmpty(2));

    for(int i = size -1 ; i >= end ; i++)
        cout<<arr[i]<<" ";

    cout<<"\n";
}

int main(){

    return 0;
}
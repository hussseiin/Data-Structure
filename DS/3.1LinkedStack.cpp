#include <iostream>
#include <assert.h>
#include <stack>

using namespace std;

class Node
{
public:
    Node(int);
    ~Node();

    int data;

    Node* next = nullptr;

private: 

};

Node::Node(int data) : data(data) {

}

Node::~Node(){
    //cout<<"Destroy Value : "<<data<<" at address : "<<this<<"\n";
}

class LinkedStack {
public:
    void push(int);
    int isEmpty();
    int peek();
    int pop();

private:
    Node* head {};
};

void LinkedStack::push(int value){

    Node* item = new Node(value);

    item->next = head;

    head = item;
}

int LinkedStack::isEmpty(){
    return !head;
}

int LinkedStack::peek(){

    assert(!isEmpty());

    int item = head -> data;

    return item;
}

int LinkedStack::pop(){

    assert(!isEmpty());

    int item = head -> data;

    Node* temp = head;

    head = head -> next;

    delete temp;

    return item;
}

int precedence(char op){

    if(op == '+' || op == '-')
        return 1;

    if(op == '*' || op == '/')
        return 2;

    return 0;
}

string infixToPostfix(string infix) {

	stack<char> operators;
	string postfix;

	infix += '-';		
	operators.push('#');

	for (int i = 0; i < (int) infix.size(); ++i) {

		if (isdigit(infix[i]))
			postfix += infix[i];

		else {
            
			while (precedence(operators.top()) >= precedence(infix[i]))
				postfix += operators.top() , operators.pop();

			operators.push(infix[i]);
		}
	}

	return postfix;
}

int main(){

    cout<<infixToPostfix("1*2+3");

}
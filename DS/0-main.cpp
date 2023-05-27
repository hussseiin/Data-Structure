#include <iostream>
#include "Vector.cpp"
#include "Node.cpp"
#include "D_Node.cpp"
#include "LinkedList.cpp"
#include "DoublyLinkedList.cpp"

using namespace std;

int main(){
    
    DoublyLinkedList list;

    list.insert_end_v2(1);
    list.insert_end_v2(2);
    list.insert_end_v2(3);
    list.insert_end_v2(4);
    list.insert_end_v2(5);
    list.insert_end_v2(6);
    list.insert_end_v2(7);
    list.insert_end_v2(8);

    cout<<list.find_middle();

    //list.print();
}
#include "LinkedList.h"

LinkedList::LinkedList(){

}

LinkedList::~LinkedList(){

    if(head == tail)
        delete head , tail ;

    else {

        Node* temp = head;

        while(temp){

            head = head -> next;

            delete temp;

            temp = head;
        }
    }
}

void LinkedList::print(){

    Node* temp_head = head; 

    while(temp_head != nullptr){

        cout<<temp_head->data<<" ";

        temp_head = temp_head->next;
    }

    cout<<"\n";
}

void LinkedList::insert_end(int value){

    Node* item = new Node(value);

    if(!head)
        head = tail = item;

    else{

        tail->next = item;

        tail = item;
    }
    ++length;
}

void LinkedList::insert_front(int value){

    Node* item = new Node(value);

    if(!head)
        head = tail = item;

    else {

        item->next = head;

        head = item;
    }

    ++length;
}

void LinkedList::delete_front(){

    assert(length);

    if(head == tail){
        
        delete head;

        head = tail = nullptr;
    }

    else{

        Node* item = head;

        head = head->next;

        delete item;
    }

        --length;

}

Node* LinkedList::get_nth(int steps){

    Node* cur = head;

    while(cur != nullptr && --steps)
        cur = cur->next;

    if(cur)
        return cur;
    
    return nullptr;
}

Node* LinkedList::get_nth_back(int steps){

    assert(steps <= length);

    int idx = length - steps;

    Node* cur = head;

    while(idx--)
        cur = cur->next;

    return cur;
}

int LinkedList::search(int value){

    int idx = 0;

    for(Node* cur = head ; cur ; cur = cur->next , idx++)
        if(cur->data == value)
            return idx;

    return -1;
}

int LinkedList::improved_search(int value){

    int idx = 0;

    Node* previous = nullptr;

    for(Node* cur = head ; cur ; cur = cur->next , idx++){

        if(cur->data == value){

            if(!previous)  // the value is in the head
                return idx;

            swap(previous->data , cur->data);

            return idx - 1;
        }
        previous = cur;
    }
}

int LinkedList::improved_search2(int value){

    int idx = 0;

    for(Node* cur = head , *previous = nullptr ; cur ; previous = cur , cur = cur->next){

        if(cur->data == value){

            if(!previous)
                return idx;

            swap(previous->data , cur->data);

            return idx - 1;
        }
        ++idx;
    }
}

void LinkedList::debug_verify_data_intergriy(){

    if(length == 0){

        assert(head == nullptr);
        assert(tail == nullptr);
    }
    else {

        assert(head != nullptr);
        assert(tail != nullptr);

        if(length == 1)
            assert(head == tail);
        
        else
            assert(head != tail);

        assert(!tail->next);
    }

    int len = 0;

    for(Node* cur = head ; cur ; cur = cur->next , len++)
        assert(len < 10000);

    assert(length == len);

    assert(length == (int)debug_data.size());
}

string LinkedList::debug_to_string(){

    if(length == 0)
        return "";
    
    ostringstream oss;

    for(Node* cur = head ; cur ; cur = cur->next){

        oss<<cur->data;

        if(cur->next)
            oss<<" ";
    }

    return oss.str();

}

bool LinkedList::is_same(const LinkedList& other){

    Node* h1 = head , *h2 = other.head;

    while(h1 && h2){

        if(h1->data != h2->data)
            return false;

        h1 = h1 ->next , h2 = h2->next;
    }

    return !h1 && !h2;
}

void LinkedList::delete_end(){

    assert(length);

    if(head == tail){

        delete head;

        head = tail = nullptr;

    }
    else{

        Node* cur = head;

        while(cur->next != tail)
            cur = cur->next;

        delete tail;

        cur->next = nullptr;

        tail = cur;
    }

    --length;

}

void LinkedList::delete_nth(int idx){

    assert(idx <= length);

    Node* cur = head;
    Node* previous = nullptr;

    if(idx == 1){

        head = head->next;

        delete cur;

        return;
    }

    while(--idx){

        previous = cur;

        cur = cur->next;
    }

    previous->next = cur->next;

    delete cur;

    --length;
}

void LinkedList::delete_value(int value){

    assert(length);

    Node* cur = head,
            *previous = nullptr;

    while(cur){

        if(cur->data == value){

            if(head == tail){

                delete head;

                head = tail = nullptr;
            }

            else{

                if(!previous){

                    head = head->next;

                    delete cur;
                }

                else{

                    previous->next = cur ->next;

                    delete cur;
                }  
            }

            --length;

            return;

        }

        previous = cur;

        cur = cur->next;
    } 
}

void LinkedList::swap_pairs(){

    assert(length);

    if(head == tail)
        return;

    Node* cur = head->next;
    Node* previous = head;

    while(cur){

        swap(previous->data , cur->data);

        previous = cur->next;

        cur = cur->next->next;
    }
}

void LinkedList::delete_even_positions(){

    assert(length);

    if(head == tail)
        return;

    Node* previous = head,
        *cur = head->next;

    while(previous->next){

        previous->next = cur->next;

        previous = cur->next;

        delete cur;

        --length;

        cur  = previous->next;
    }
}

void LinkedList::insert_sorted(int value){

    Node* item = new Node(value);

    if(!head)
        head = tail = item;

    for(Node* cur = head , *previous = nullptr; cur ; previous = cur , cur = cur->next){

        if(cur->data > value){

            if(!previous){

                item->next = head;

                head = item;
            }

            else{

                item->next = cur;

                previous->next = item;
            }

            ++length;

            return;
        }
    }

    insert_end(value);

    ++length;
}

void LinkedList::test1(){

    cout<<"\ntest1\n";

    LinkedList list;

    list.insert_end(1);
    list.insert_end(2);
    list.insert_end(3);
    list.insert_end(4);

    list.print();

    string expected = "1 2 3 4";

    string result = list.debug_to_string();

    if(expected != result){

        cout<<"No match : \n"
            <<"Expected : "<<expected
            <<"\nResult   : "<<result<<"\n";

        assert(false);
    }

    //list.debug_print_list("********");
}

void LinkedList::debug_add_node(Node* node){

    debug_data.push_back(node);
}

void LinkedList::debug_remove_node(Node* node){

    auto it = std::find(debug_data.begin() , debug_data.end() , node);

    if(it == debug_data.end())
        cout<<"Node does not exist \n";

    else 
        debug_data.erase(it);

}
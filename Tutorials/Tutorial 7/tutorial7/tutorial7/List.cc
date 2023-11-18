#include "List.h"
#include "Message.h"
List::List():head(nullptr),tail(nullptr) {}

List::~List(){
    Node* curr = head;
    Node* prev;
    
    while(curr!= nullptr){
        prev = curr;
        curr = curr->next;
        delete prev;
    }
}

bool List::isEmpty() const{
    return head == nullptr; //if head is null means nothing in it
}

int List::getSize() const{
    Node* curr = head;
    int count = 0;
    while(curr!= nullptr){
        curr = curr->next;
        count++;
    }
    return count;
}
Message *List::removeFirst(){
    Node* curr = head;
    if(curr){
        Message* goner = curr->data;
        head = curr->next; //head is now the next node
        delete curr;
        // Ensure that you delete the 'goner' object when it's no longer needed
        return goner;
    }
    return nullptr;
}

void List::add(Message * msg){
    Node* newNode = new Node;
    newNode->data = msg;
    newNode->next = nullptr;
    if (head == nullptr) { //if empty then...
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void List::print() const{
    Node* curr = head;
    while(curr!= nullptr){
        curr->data->print();
        curr = curr->next;
    }
}

void List::getMessagesWith(const string &id, List &outputList){
    Node* curr = head;
    while(curr!= nullptr){
        if(curr->data->getReciever() == id || curr->data->getSender() == id){
            outputList.add(curr->data);
        }
        curr = curr->next; // advance the pointer
    }
}

void List::getMessagesWith(const string &id1, const string &id2, List &outputList){
    Node* curr = head;
    while(curr!= nullptr){
        if(curr->data->getReciever() == id1 && curr->data->getSender() == id2){
            outputList.add(curr->data);
        }else if (curr->data->getReciever() == id2 && curr->data->getSender() == id1){
            outputList.add(curr->data);
        }
        curr = curr->next;
    }    
}

void List::removeMessagesWith(const string &id, List &outputList){
    Node* curr = head;
    Node* prev = nullptr;
    Node* deleting = nullptr;
    if (curr == nullptr){
        return;
    }
    while(curr!= nullptr){

        if(curr->data->getReciever() == id || curr->data->getSender() == id){
            if(prev == nullptr){
                head = curr->next;
            }else{
                prev->next = curr->next;
            }
            deleting = curr;
            curr = curr->next;
            outputList.add(deleting->data); //makes a copy in outputlist
            deleting->next = nullptr; 
            delete deleting;
        }else{
            prev = curr;
            curr = curr->next;
        }
    }
}

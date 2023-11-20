#include "List.h"

List::List(){
    head = NULL;
    tail = NULL;
    size = 0;
}

List::~List(){
    Node* current;
    while (head != nullptr){
        current = head;
        head = head->next;
        delete current;
    }
}

bool List::isEmpty() const{
    return size == 0;
}

int List::getSize() const{
    return size;
}


Message *List::removeFirst(){
    Node* current = head;
    if(current){
        Message* goner = current->data;
        head = current->next; 
        delete current;
        --size;
        return goner;
    }
    return nullptr;
}

void List::add(Message * message){
    Node* newNode = new Node;
    newNode->data = message;
    newNode->next = nullptr;
    if (head == nullptr) { //if empty then...
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    ++size;
}

void List::print() const{
    cout << "Printing Messages from the list... " << endl;
    Node* current = head;
    while (current != nullptr){
        current->data->print();
        current = current->next;
    }
}

void List::getMessagesWith(const string& id, List& outputList){
    Node* current = head;
    while (current != nullptr){
        if (current->data->getSender() == id || current->data->getReceiver() == id){
            outputList.add(current->data);
        }
        current = current->next;
    }
}

void List::getMessagesWith(const string& id1, const string& id2, List& outputList){
    Node* current = head;
    while (current != nullptr){
        if (current->data->getSender() == id2 || current->data->getReceiver() == id1 ){
            outputList.add(current->data);
        }else if (current->data->getReceiver() == id2 && current->data->getSender() == id1){
            outputList.add(current->data);
        }
        current = current->next;
    }
}

void List::removeMessagesWith(const string& id,List& outputList){
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr){
        Node* removing = current;
        if (current->data->getSender() == id || current->data->getReceiver() == id){
            outputList.add(current->data);
            if (previous == nullptr) {
                head = current->next;
                current = head;
            }else if (previous != nullptr){
                previous->next = current->next;
                current = current->next;
            }
            delete removing;
            --size;
        }else{
            previous = current;
            current = current->next;
        }
    }
}

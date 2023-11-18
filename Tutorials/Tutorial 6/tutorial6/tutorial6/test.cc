#include <istream>
#include <string>

#include "defs.h"
#include "Message.h"
#include "List.h"
#include "Tester.h"

#define ARR 3
#define PHONES 3

using namespace std;

const string ids[5] = {"C1","C2","C3","C4","C5"};
extern string messageText[9];

int listTest();
int messagesWithTest();
int removeMessagesWithTest();

int main(){

  
    int choice = 0;
    cout << "Which test would you like to run?"<< endl;
    cout << "  (0) Messages are in correct order in the List test." << endl;
    cout << "  (1) getMessagesWith(id) test" <<endl;
    cout << "  (2) removeMessagesWith(id) test" <<endl;
    cin >> choice;
    int ret = 0;
    switch(choice){
      case 0: ret = listTest(); break;
      case 1: ret = messagesWithTest(); break;
      case 2: ret = removeMessagesWithTest(); break;
    }

    return ret;
  
}

int listTest(){
    Message* messages[5];
    for (int i = 0; i < 5; ++i){  
            messages[i] = new Message(ids[i], ids[0], messageText[i]);
    }

    List* list = new List();

    cout<<"Adding 5 Messages to list"<<endl;
    for (int i = 0; i < 5; ++i){
        cout<<"Adding ";
        messages[i]->print();
        list->add(messages[i]);
    }

    if (list->getSize() != 5){
        cout<<"Error, wrong size, should be 5, you have "<<list->getSize()<<" instead"<<endl;
        return 1;
    }   

    Message* message;

    cout<<endl<<"Removing 5 Messages from list"<<endl;

    for (int i = 0; i < 5; ++i){
        message = list->removeFirst();
        if (message != messages[i]){
            cout<<"Error, wrong message"<<endl;
            return 1;
        }
        cout<<"Removing: ";
        message->print();
    }

    cout<<"Removed successfully in message, deleting list, then deleting messages..."<<endl;

    delete list;

    //you may uncomment if you wish, depending on how you manage memory
    for (int i = 0; i < 5; ++i){
        delete messages[i];
    }
    return 0;
}


int messagesWithTest(){
    List* list = new List();
    Tester tester;

    Message* messages[PHONES][PHONES];
    for (int i = 0; i < PHONES; ++i){
        for (int j = 0; j < PHONES; ++j){
            messages[i][j] = new Message(ids[i], ids[j], messageText[i*PHONES+j]);
            list->add(messages[i][j]);
        }
    }

    if (list->getSize() != PHONES*PHONES){
        cout<<"Error, wrong size, should be "<<PHONES*PHONES<<", you have "<<list->getSize()<<" instead"<<endl;
        return 1;
    }

    List* list2 = new List();
    cout<<"Getting messages with "<<ids[0]<<endl;
    list->getMessagesWith(ids[0], *list2);
    cout<<"Printing messages with "<<ids[0]<<endl;  
    tester.initCapture();
    list2->print();
    tester.endCapture();
    int count = 2*PHONES-1;
    if (list2->getSize() != count){
        cout<<"Error, wrong size, should be "<<count<<", you have "<<list2->getSize()<<" instead"<<endl;
        return 1;
    }

    string output = tester.getOutput();

    int error = 0;

    vector<int> keys = {0,1,2,3,6};
    tester.find(keys, messageText, error);

    if (error>0){
        cout<<"Error, messages not found"<<endl;
        return 1;
    }

    cout<<"All messages found"<<endl<<endl;

    cout<<"Looking for extra messages..."<<endl<<endl;
    keys = {4,5,7,8};
    tester.confirmAbsent(keys, messageText, error);

    if (error>0){
        cout<<"Error, messages found that should not be"<<endl;
        return 1;
    }

    cout<<"Did not find any extra messages"<<endl<<endl;
    delete list;
    delete list2;

  //  you may uncomment if you wish, depending on how you manage memory
    for (int i = 0; i < PHONES; ++i){
        for (int j = 0; j < PHONES; ++j){
            delete messages[i][j];
        }
    }

    return 0;

}

int removeMessagesWithTest(){
    List* list = new List();
    Tester tester;

    Message* messages[PHONES][PHONES];
    for (int i = 0; i < PHONES; ++i){
        for (int j = 0; j < PHONES; ++j){
            messages[i][j] = new Message(ids[i], ids[j], messageText[i*PHONES+j]);
            list->add(messages[i][j]);
        }
    }
    
    if (list->getSize() != PHONES*PHONES){
        cout<<"Error, wrong size, should be "<<PHONES*PHONES<<", you have "<<list->getSize()<<" instead"<<endl;
        return 1;
    }

    cout<<"Removing messages with "<<ids[0]<<endl;
    List goners;
    list->removeMessagesWith(ids[0], goners);
    cout<<"passed this part"<<endl;
    cout<<"Goner size (should be 5): "<<goners.getSize()<<endl;
    cout<<"Printing messages without "<<ids[0]<<endl;  
    tester.initCapture();
    list->print();
    tester.endCapture();
    int count = (PHONES-1)*(PHONES-1);
    cout<<"List size (should be "<<count<<"): "<<list->getSize()<<endl;
    if (list->getSize() != count){
        cout<<"Error, wrong size, should be "<<count<<", you have "<<list->getSize()<<" instead"<<endl;
        return 1;
    }

    string output = tester.getOutput();

    int error = 0;

    vector<int> keys =  {4,5,7,8};
    tester.find(keys, messageText, error);

    if (error>0){
        cout<<"Error, messages not found"<<endl;
        return 1;
    }

    cout<<"All messages found"<<endl<<endl;

    cout<<"Looking for extra messages..."<<endl<<endl;
    keys ={0,1,2,3,6};
    tester.confirmAbsent(keys, messageText, error);

    if (error>0){
        cout<<"Error, messages found that should not be"<<endl;
        return 1;
    }

    cout<<"Did not find any extra messages"<<endl<<endl;
    cout<<"Checking list of deleted messages (all messages with "<<ids[0]<<")"<<endl<<endl;
    tester.initCapture();
    goners.print();
    tester.endCapture();
    output = tester.getOutput();
    keys = {0,1,2,3,6};
    error = 0;
    tester.find(keys, messageText, error);

    if (error>0){
        cout<<"Error, removed messages not found"<<endl;
        return 1;
    }

    cout<<"All deleted messages found"<<endl;
    keys = {4,5,7,8};
    error=0;
    tester.confirmAbsent(keys, messageText, error);
    if (error>0){
        cout<<"Error, messages found that should not be"<<endl;
        return 1;
    }
    cout<<"Did not find any extra messages"<<endl<<endl;
    delete list;

  //  you may uncomment if you wish, depending on how you manage memory
    for (int i = 0; i < PHONES; ++i){
        for (int j = 0; j < PHONES; ++j){
            delete messages[i][j];
        }
    }

    return 0;

}



string messageText[9] = {
    "C1: Hello C1", "C1: Hello C2", "C1: Hello C3", 
    "C2: Hello C1", "C2: Hello C2", "C2: Hello C3", 
    "C3: Hello C1", "C3: Hello C2", "C3: Hello C3"};



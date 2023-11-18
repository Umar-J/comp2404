#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <string>

using namespace std;

class Message {
public:
  // Constructor
    Message(const string& sender, const string& reciever, const string& message):sender(sender),reciever(reciever),message(message){};

  // Getters
    string getSender() const{
        return sender;
    };
    string getReciever() const{
        return reciever;
    };
    //string getContent() const;

    void print() const;

private:
    string sender;
    string reciever;
    string message;
};

#endif
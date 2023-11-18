#include "Message.h"

void Message::print() const{
    cout<<"(sender) From: "<<sender<<endl;
    cout<<"(reciever) To: "<<reciever<<endl;
    cout<<"(message) Message: "<<message<<endl;
}
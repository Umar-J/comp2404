#include "Search.h"
H_Search::H_Search(string h): host(h){}

bool H_Search::matches(const Episode* e) const{
    return e->getHost() == host;
}

void H_Search::print(ostream& ost) const{
    ost<< "this matches an episode with the given host:  "<<host<<endl;
}

C_Search::C_Search(string cat): category(cat) {};

bool C_Search::matches(const Episode* e) const{
    return e->getCategory() == category;
}
void C_Search::print(ostream& ost) const{
    ost<< "this matches an episode with the given category:  "<<category<<endl;
}

HorC_Search::HorC_Search(string h, string cat):H_Search(h), C_Search(cat){}

bool HorC_Search::matches(const Episode* e) const{
    return H_Search::matches(e) || C_Search::matches(e);
}
void HorC_Search::print(ostream& ost) const{
    C_Search::print(ost);
    ost<< " or "<<endl;
    H_Search::print(ost);
}        

ostream& operator<<(ostream& os, const Search& s){
    s.print(os); // polymorphism
    return os;
}

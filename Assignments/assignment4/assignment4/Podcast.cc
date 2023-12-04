#include "Podcast.h"

bool Podcast::equals(const string& title) const{
    return this->title == title;
}
Episode* Podcast::get(int index) const{
    return episodes[index]; //if oob then array calls exit(1)
}
int Podcast::getSize() const{
    return episodes.getSize();
}
void Podcast::print(ostream& os) const{
    os<<"Title: "<<this->title<<endl;
    os<<"Host:  "<<this->host<<endl;
}
void Podcast::printWithEpisodes(ostream& os) const{
    os<<"Title: "<<this->title<<endl;
    os<<"Host:  "<<this->host<<endl;
    for(int i =0; i < episodes.getSize(); i++){
        episodes[i]->print(os);
    }
}
void Podcast::addEpisode(Episode* episode){
    episodes+=episode;
}
ostream& operator<<(ostream& os, const Podcast& p){
    p.print(os);
    return os;
}
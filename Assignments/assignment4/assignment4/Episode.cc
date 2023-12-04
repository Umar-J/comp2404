#include "Episode.h"

Episode::Episode(string pt, string h, string et, string c, string a, string v): podcastTitle{pt}, host{h}, episodeTitle{et}, category{c}, audio{a}, videoFile{v}{}

void Episode::print(ostream& os) const{
            os<< "Podcast Title: "<<podcastTitle<<endl;
            os<< "Host         : "<<host<<endl;
            os<< "Category     : "<<category<<endl;
            os<< "Episode Title: "<<episodeTitle<<endl;
}
ostream& operator<<(ostream& os, const Episode& e){
    e.print(os);
    return os;
}
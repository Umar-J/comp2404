#include "Podify.h"


void Podify::addPodcast(Podcast *p){
    podcasts+=p;
}
void Podify::addEpisode(Episode* e, const string& podcastTitle){
    for(int i =0; i < podcasts.getSize(); i++){
        if (podcasts[i]->equals(podcastTitle)){
            podcasts[i]->addEpisode(e);
        }
    }
}
const Array<Podcast*> Podify::getPodcasts() const{
    return podcasts;
}
Podcast* Podify::getPodcast(int index) const{
    return podcasts[index];
}
Podcast* Podify::getPodcast(const string& title) const{
    for(int i =0; i < podcasts.getSize(); i++){
        if (podcasts[i]->equals(title)){
            return podcasts[i];
        }
    }
    cerr<<"Podcast with this name doesnt exist"<<endl;
	exit(1);
}
void Podify::getEpisodes(Search& s, Array<Episode*>& a){
  //  cout<<"Search results:"<<endl;
   // s.print(cout);
    //to return 1 episode: podcasts[1].get(1) <- check if search matches that then a+= that
    for (int i =0; i< podcasts.getSize();i++){ //loop podcasts
        for (int j =0; j< podcasts[i]->getSize();j++){ //loop episodes
     //   cout<<"checking if "<<s<<" is the smame as "<<podcasts[i]->get(j)->getHost()<<endl;
            if(s.matches(podcasts[i]->get(j))){ //check
                a+=podcasts[i]->get(j); //add
                
            }
        }
    }

}
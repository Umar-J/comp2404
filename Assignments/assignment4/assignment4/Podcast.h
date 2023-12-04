#ifndef PODCAST_H
#define PODCAST_H
#include <iostream>
#include <string>
#include "Array.h"
#include "Episode.h"
using namespace std;


class Podcast{
    friend ostream& operator<<(ostream& os, const Podcast& p);
    public:
        Podcast(string title, string host): title(title), host(host){}
        bool equals(const string& title) const;
        Episode* get(int index) const;
        int getSize() const;
        void print(ostream&) const;
        void printWithEpisodes(ostream&) const;
        void addEpisode(Episode* episode); // maybe make it return a bool

        
    private:
        Array<Episode*> episodes;
        string title,host;
};

#endif
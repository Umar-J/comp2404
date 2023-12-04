#ifndef PODCASTPLAYER_H
#define PODCASTPLAYER_H
#include <iostream>
#include <string>
#include "Podcast.h"
#include "Episode.h"
#include "Search.h"
#include <fstream>
using namespace std;


class PodcastPlayer{
   // friend ostream& operator<<(ostream& os, const PodcastPlayer& Pp); //needed?
    public:
        virtual void play(const Episode& m, ostream& ost) = 0;
};


// other 2 subclasses
class AudioPlayer: public PodcastPlayer{
    friend ostream& operator<<(ostream& os, const AudioPlayer& aP);
    public:
        virtual void play(const Episode& m, ostream& ost);

};

class VideoPlayer: public PodcastPlayer{
    friend ostream& operator<<(ostream& os, const VideoPlayer& vP);
    public:
        virtual void play(const Episode& m, ostream& ost);

};


#endif
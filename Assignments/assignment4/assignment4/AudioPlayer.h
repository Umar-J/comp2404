#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H
#include <iostream>
#include <string>
#include "PodcastPlayer.h"
using namespace std;


class AudioPlayer: public PodcastPlayer{
    friend ostream& operator<<(ostream& os, const AudioPlayer& aP);
    public:
        virtual void play(const Episode& m, ostream& ost);

};


#endif
#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H
#include <iostream>
#include <string>
#include "PodcastPlayer.h"
using namespace std;


class VideoPlayer: public PodcastPlayer{
    friend ostream& operator<<(ostream& os, const VideoPlayer& vP);
    public:
        virtual void play(const Episode& m, ostream& ost);

};

#endif
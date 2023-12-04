#include "VideoPlayer.h"

void VideoPlayer::play(const Episode &m, ostream &ost){
    ost<<m.getAudio()<<endl;
}

ostream& operator<<(ostream& os, const VideoPlayer& aP){
    os<< "this is audio player class"<<endl;
    return os;
}
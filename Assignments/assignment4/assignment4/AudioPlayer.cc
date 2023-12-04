#include "AudioPlayer.h"

void AudioPlayer::play(const Episode &m, ostream &ost){
    ost<<m.getAudio()<<endl;
}

ostream& operator<<(ostream& os, const AudioPlayer& aP){
    os<< "this is audio player class"<<endl;
    return os;
}
#include "PodcastPlayer.h"

void AudioPlayer::play(const Episode &m, ostream &ost){
    
    ost<<m.getAudio()<<endl;
}

ostream& operator<<(ostream& os, const AudioPlayer& aP){
    os<< "this is audio player class"<<endl;
    return os;
}

void VideoPlayer::play(const Episode &m, ostream &ost){
    ost<<m.getAudio()<<endl;
    //load ascii art
    ifstream inputFile(m.getVideoFile());
    
    if (inputFile.is_open()) {
    string line;

   
    while (getline(inputFile, line)) {
        cout << line << endl;
    }
        inputFile.close(); // Close the file
    } else {
        cerr << "file doesnt exist......" << endl;
    }
}

ostream& operator<<(ostream& os, const VideoPlayer& aP){
    os<< "this is video player class"<<endl;
    return os;
}
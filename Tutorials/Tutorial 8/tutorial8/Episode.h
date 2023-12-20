#ifndef EPISODE_H
#define EPISODE_H
#include <iostream>
#include <string>
using namespace std;


class Episode{
    friend ostream& operator<<(ostream& os, const Episode& e);
    public:
        Episode(string pt, string h, string et, string c, string a, string v);
        string getPodcastTitle() const {return podcastTitle;}
        string getHost() const {return host;}
        string getEpisodeTitle() const {return episodeTitle;}
        string getCategory() const {return category;}
        string getAudio() const {return audio;}
        string getVideoFile() const {return videoFile;}
        virtual void print(ostream& os) const;
    private:
        string podcastTitle, host, episodeTitle, category, audio, videoFile;
};

#endif
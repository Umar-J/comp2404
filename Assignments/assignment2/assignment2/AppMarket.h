// cout message if somethbing fails
//add header guards
#include "AppArray.h"
#ifndef APPMARKET_H
#define APPMARKET_H

class AppMarket{
    public:
        void addApp(const string& title, const string& description, const string & icon);
        void deleteApp(int index);
        App* getApp(int index) const;
        void printApps() const;
        void printAppDetails(int index) const;
    private:
        AppArray arrayOfApps;
};

#endif

#ifndef SEARCH_H
#define SEARCH_H
#include <iostream>
#include <string>
#include "Episode.h"

using namespace std;

class Search{
    public:
        virtual bool matches(const Episode*) const = 0;
        virtual void print(ostream&) const = 0;
        // override << operator
        friend ostream& operator<<(ostream& ost, const Search& s);
};


class H_Search: virtual public Search{
    public:
        H_Search(string);
        virtual bool matches(const Episode* e) const;
        virtual void print(ostream& ost) const;
    private:
        string host;
};

class C_Search: virtual public Search{
    public:
        C_Search(string cat);
        virtual bool matches(const Episode* e) const;
        virtual void print(ostream& ost) const;
    private:
        string category;
};

class HorC_Search: public C_Search, public H_Search{
    public: 
        HorC_Search(string h, string cat);
        virtual bool matches(const Episode* e) const;
        virtual void print(ostream& ost) const;
    private:
};


#endif
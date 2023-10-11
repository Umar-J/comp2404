#ifndef PLANNER_H
#define PLANNER_H
#include "PlannerDate.h"
#include "Date.h"
#include "Event.h"
#define MAX_PLANS 20

class Planner{
    public:
        ~Planner();
        Planner();
        void addEvent(string title, string description, Date& date, int startTime, int duration);
        void addDailyEvent(string title,string description,Date& startDate,Date& endDate,int startTime,int duration);
        void addWeeklyEvent(string title,string description,Date& startDate,Date& endDate,int startTime,int duration);
        void printAllDates();
        void printDate(Date&);
        void printDatesInRange(Date&startDate,Date&endDate);
        void printDatesWithEvent(string title);
        void printDatesWithConflict();

    private:
        PlannerDate* plans[MAX_PLANS];
        int numPlans;
        PlannerDate* getDate(Date&);
};


#endif
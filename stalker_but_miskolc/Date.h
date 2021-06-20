//
// Created by zsozszsozsi on 2021. 06. 11..
//

#pragma once

#include <iostream>
#include <ostream>

enum TimeOfDay{MORNING, AFTERNOON, EVENING};

struct dateForm
{
    int year;
    int month;
    int day;
    TimeOfDay timeOfDay;

    friend std::ostream& operator<< (std::ostream& o, dateForm& d)
    {
        if(d.month < 10)
        {
            if(d.day < 10)
            {
                o << d.year << ".0" << d.month << ".0" << d.day << ".";
            }
            else
            {
                o << d.year << ".0" << d.month << "." << d.day << ".";
            }

        }
        else
        {
            if(d.day < 10)
            {
                o << d.year << "." << d.month << ".0" << d.day << ".";
            }
            else
            {
                o << d.year << "." << d.month << "." << d.day << ".";
            }
        }

        o << " ";

        switch (d.timeOfDay) {
            case MORNING:
                o << "Morning.";
                break;
            case AFTERNOON:
                o << "Afternoon.";
                break;
            case EVENING:
                o << "Evening.";
                break;
        }

        return o;
    }
}typedef dateForm;

class Date
{
    public:
        static bool isLeap(int y);
        static int offsetDays(int d, int m, int y);
        static void revoffsetDays(int offset, int y, int *d, int *m);
        static dateForm addDays(int d1, int m1, int y1, int x);


};

#ifndef DATE_DATE_H
#define DATE_DATE_H


#include <iostream>
#include <string>





class Date {
    int day, month, year;
    public:
        Date::Date();
        Date(int day_, int month_, int year_);
};

#endif